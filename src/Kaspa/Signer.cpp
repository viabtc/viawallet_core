// Copyright © 2017-2023 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"
#include "Address.h"
#include "Transation.h"
#include "HexCoding.h"
#include "OpCode.h"
#include "KaspaOutput.h"
#include "BitcoinUnspentOutput.h"
#include "Hash.h"
#include "KaspaScriptPublicKey.h"
#include "Serializer.h"
#include "proto/Common.pb.h"

namespace TW::Kaspa {

static int maxInputCount = 84;
static int feePerUtxo = 10000;
static int64_t kMinAmount = 10000;

Data scriptPublicKey(const std::string &address) {
    auto addressComponents= Address::parse(address);
    auto addressType = addressComponents.type;
    uint8_t startOpCode = 0;
    uint8_t endOpCode = 0;
    if (addressType == Address::AddressType::schnorr) {
        startOpCode = 0;
        endOpCode = CHECKSIG;
    } else if (addressType == Address::AddressType::ecdsa) {
        startOpCode = 0;
        endOpCode = SEPARATOR;
    } else {
        startOpCode = HASH256;
        endOpCode = EQUAL;
    }
    Data startOpCodeData;
    Data endOpCodeData;
    startOpCodeData.resize(0);
    endOpCodeData.resize(0);
    endOpCodeData.push_back(endOpCode);
    Data result;
    result.resize(0);
    if (startOpCode == 0) {
        uint8_t size = static_cast<uint8_t>(addressComponents.hash.size());
        append(result, startOpCodeData);
        append(result, size);
        append(result, addressComponents.hash);
        append(result, endOpCodeData);
        return result;
    } else {
        startOpCodeData.push_back(startOpCode);
        uint8_t size = static_cast<uint8_t>(addressComponents.hash.size());
        append(result, startOpCodeData);
        append(result, size);
        append(result, addressComponents.hash);
        append(result, endOpCodeData);
        return result;
    }
}

static std::vector<BitcoinUnspentOutput> messageUnspentOutputToUnspentOutput(Proto::TransferMessage utxos) {
    std::vector<BitcoinUnspentOutput> outputs;
    auto count = utxos.unspentoutput().size() > maxInputCount ? maxInputCount : utxos.unspentoutput().size();
    for (int index = 0; index < count; index++) {
        auto value = utxos.unspentoutput()[index];
        auto transactionHash = value.transactionhash();
        auto outputIndex = value.outputindex();
        auto amount = value.amount();
        auto outputScript = value.outputscript();
        auto address = value.address();
        auto const utxo = BitcoinUnspentOutput(transactionHash, outputIndex, amount, outputScript, address);
        outputs.emplace_back(utxo);
    }
    return outputs;
}

static int64_t changeAmount(int64_t amount, int64_t fee, std::vector<BitcoinUnspentOutput> &utxos) {
    int64_t total = 0;
    for (const auto &value: utxos) {
        total += value.amount;
    }
    int64_t amountCharged = amount + fee;
    if (total > amountCharged) {
        return total - amountCharged;
    } else if (total == amountCharged) {
        return 0;
    } else {
        throw std::invalid_argument("Failed to build transaction");
    }
}

static Transaction unsignedTransaction(const Proto::TransferMessage &message) {
    auto utxos = messageUnspentOutputToUnspentOutput(message);
    std::string destinationAddressScript = hex(scriptPublicKey(message.to()));
    std::vector<KaspaOutput> output;
    output.push_back(KaspaOutput( message.amount(), KaspaScriptPublicKey(destinationAddressScript)));
    int64_t change = changeAmount(message.amount(), message.fee(), utxos);
    if (change > 0 ) {
        std::string sourceAddressScript = hex(scriptPublicKey(message.changeaddress()));
        output.push_back(KaspaOutput(change, KaspaScriptPublicKey(sourceAddressScript)));
    }
    Transaction tx = Transaction(utxos, output);
    std::vector<std::string> hashs;
    std::vector<Data> privateKeyDatas;
    std::map<std::string, Data> privateKeys;
    std::vector<std::string> addresses;
    for (unsigned long index = 0; index<utxos.size(); index++) {
        BitcoinUnspentOutput unspentOutput = utxos[index];
        int64_t amount = unspentOutput.amount;
        Data witness = tx.hashForSignatureWitness(static_cast<int>(index), parse_hex(unspentOutput.outputScript), amount);
        hashs.push_back(hex(witness));
        if (!Address::isValid(unspentOutput.address)) {
            throw std::invalid_argument("Invalid address string");
        }
        addresses.emplace_back(unspentOutput.address);
    }

    for (int index = 0; index<message.private_key_size(); index++) {
        const auto privateKeyData = data(message.private_key(index));
        if (!PrivateKey::isValid(privateKeyData)) {
            throw std::invalid_argument("Invalid private key");
        }
        const auto privateKey = PrivateKey(privateKeyData);
        const auto publicKey = privateKey.getPublicKey(TWPublicKeyTypeSECP256k1);
        const auto address = Address(publicKey);
        privateKeys[address.string()] = privateKeyData;
    }

    std::vector<std::string> addressesUnique;
    for (auto& a: addresses) {
        if (find(addressesUnique.begin(), addressesUnique.end(), a) == addressesUnique.end()) {
            addressesUnique.emplace_back(a);
        }
    }

    for (auto& a : addressesUnique) {
        const auto privateKeyFind = privateKeys.find(a);
        Data privateKeyData;
        if (privateKeyFind != privateKeys.end()) {
            privateKeyData = privateKeyFind->second;
        } else {
            throw std::invalid_argument("Error missing private key");
        }
        privateKeyDatas.push_back(privateKeyData);
    }
    tx.hashes = hashs;
    tx.privateKeyDatas = privateKeyDatas;
    return tx;
}

static TransactionData signTransaction(const Transaction &tx, std::vector<std::string> signatures) {
    std::vector<KaspaInput> inputData;
    for (unsigned long index = 0; index < tx.inputs.size(); index++) {
        auto input = tx.inputs[index];
        uint8_t sigHashAll = 1;
        auto script = parse_hex(signatures[index]);
        append(script, sigHashAll);
        auto size = static_cast<uint8_t>(script.size());
        Data signatureScript;
        signatureScript.resize(0);
        append(signatureScript, size);
        append(signatureScript, script);
        std::string signatureScriptHex = hex(signatureScript);
        KaspaPreviousOutpoint outpoint = KaspaPreviousOutpoint(input.transactionHash, input.outputIndex);
        KaspaInput result = KaspaInput(outpoint, signatureScriptHex);
        inputData.push_back(result);
    }
    TransactionData data = TransactionData(inputData, tx.outputs);
    return data;
}

Proto::SigningOutput Signer::sign(const Proto::SigningInput &input) noexcept {
    auto protoOutput = Proto::SigningOutput();
    if (input.has_transfer()) {
        Transaction tx = unsignedTransaction(input.transfer());
        std::vector<std::string> signatures;
        for (int index = 0; index < tx.hashes.size(); ++index) {
            const auto hash = parse_hex(tx.hashes[index]);
            const auto privateData = tx.privateKeyDatas[index];
            const PrivateKey privateKey = PrivateKey(privateData);
            auto sign = privateKey.signKASECDSA(hash);
            signatures.push_back(hex(sign));
        }
        auto data = signTransaction(tx, signatures);
        auto txJson = transactionJSON(data);
        protoOutput.set_json(txJson.dump());
        return protoOutput;
    }
    return protoOutput;
}

inline int64_t sumTotalAmount(const std::vector<BitcoinUnspentOutput> &inputs) {
    int64_t sum = 0;
    for (auto &cell : inputs) {
        sum += cell.amount;
    }
    return sum;
}

static void transferPlan(const Proto::TransferMessage &message, Proto::TransferPlan &plan) {
    auto utxos = messageUnspentOutputToUnspentOutput(message);
    auto utxosTotalAmount = sumTotalAmount(utxos);
    if (utxos.capacity() <= 0) {
        plan.set_error(Proto::TransferError::InvalidUTXOAmount);
        return;
    }

    if (message.amount() > utxosTotalAmount) {
        plan.set_error(Proto::TransferError::InsufficientBalance);
        return;
    }

    if (message.amount() < kMinAmount) {
        plan.set_error(Proto::TransferError::TransferAmountLessThanMinCapacity);
        return;
    }
    auto feeRate = message.bytefee() > 0 ? message.bytefee() : feePerUtxo;
    auto fee = feeRate * utxos.capacity();
    auto amount = message.amount();
    if (message.usemaxamount()) {
        amount = utxosTotalAmount - fee;
    }
    auto send = fee + amount;
    if (send > utxosTotalAmount) {
        plan.set_error(Proto::TransferError::InsufficientBalance);
        return;
    }
    plan.set_error(Proto::TransferError::NONE);
    int64_t change = changeAmount(amount, fee, utxos);
    plan.set_availableamount(utxosTotalAmount);
    plan.set_fee(fee);
    plan.set_change(change);
    plan.set_amount(amount);
}

Proto::TransactionPlan Signer::plan(const Proto::SigningInput &input) noexcept {
    auto plan = Proto::TransactionPlan();
    if (input.has_transfer()) {
        transferPlan(input.transfer(), *plan.mutable_transfer());
    }
    return plan;
}

} // namespace TW::Kaspa
