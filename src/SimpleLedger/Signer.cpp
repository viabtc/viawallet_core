// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"

#include <utility>
#include "Address.h"
#include "../HexCoding.h"
#include "../BinaryCoding.h"
#include "Bitcoin/SigHashType.h"
#include "Bitcoin/SignatureVersion.h"


using namespace TW;
using namespace TW::SimpleLedger;

SimpleLedger::Proto::TransactionPlan Signer::plan(const Proto::SigningInput &input) noexcept {
    auto signer = Signer(input);
    return signer.txPlan.proto();
}

SimpleLedger::Proto::SigningOutput Signer::sign(const Proto::SigningInput &input) noexcept {
    auto signer = Signer(input);
    auto result = signer.sign();
    auto output = Proto::SigningOutput();
    if (!result) {
        output.set_error(result.error());
        return output;
    }

    const auto &tx = result.payload();
    *output.mutable_transaction() = tx.proto();

    Data encoded;
    tx.encode(encoded);
    output.set_encoded(encoded.data(), encoded.size());

    auto txHash = Hash::sha256d(encoded.data(), encoded.size());
    output.set_transaction_id(hex(txHash));
    return output;
}

Result<Bitcoin::Transaction> Signer::sign() {
    if (txPlan.simpleLedgerPlan.utxos.empty() || transaction.inputs.empty()) {
        return Result<Bitcoin::Transaction>::failure("Missing inputs or UTXOs");
    }

    signedInputs.clear();
    std::copy(std::begin(transaction.inputs),
              std::end(transaction.inputs),
              std::back_inserter(signedInputs));

    std::vector<Bitcoin::Proto::UnspentTransaction> utxos;
    for (const Proto::UnspentTransaction &u : txPlan.simpleLedgerPlan.utxos) {
        Bitcoin::Proto::UnspentTransaction bitcoinUTXO;
        bitcoinUTXO.set_amount(u.amount());
        bitcoinUTXO.set_script(u.script().data(), u.script().size());
        bitcoinUTXO.mutable_out_point()->set_index(u.out_point().index());
        bitcoinUTXO.mutable_out_point()->set_sequence(u.out_point().sequence());
        bitcoinUTXO.mutable_out_point()->set_hash(u.out_point().hash().data(), u.out_point().hash().size());
        utxos.push_back(bitcoinUTXO);
    }
    utxos.insert(utxos.end(), txPlan.bitcoinCashPlan.utxos.begin(), txPlan.bitcoinCashPlan.utxos.end());

    auto hashType = static_cast<enum TWBitcoinSigHashType>(TWBitcoinSigHashTypeFork | TWBitcoinSigHashTypeAll);
    const auto hashSingle = Bitcoin::hashTypeIsSingle(hashType);
    for (auto i = 0; i < utxos.size(); i++) {
        // Only sign TWBitcoinSigHashTypeSingle if there's a corresponding output
        if (hashSingle && i >= transaction.outputs.size()) {
            continue;
        }
        auto &utxo = utxos[i];
        auto script = Bitcoin::Script(utxo.script().begin(), utxo.script().end());
        if (i < transaction.inputs.size()) {
            auto result = sign(script, i, utxo);
            if (!result) {
                return Result<Bitcoin::Transaction>::failure(result.error());
            }
        }
    }

    Bitcoin::Transaction tx(transaction);
    tx.inputs = move(signedInputs);
    tx.outputs = transaction.outputs;
    return Result<Bitcoin::Transaction>::success(std::move(tx));
}

Result<void> Signer::sign(const Bitcoin::Script& script, size_t index, const Bitcoin::Proto::UnspentTransaction &utxo) {
    assert(index < transaction.inputs.size());
    std::vector<Data> results;
    auto result = signStep(script, index, utxo);
    if (!result) {
        return Result<void>::failure(result.error());
    }
    results = result.payload();
    assert(results.size() >= 1);
    auto txin = transaction.inputs[index];

    signedInputs[index] = Bitcoin::TransactionInput(txin.previousOutput,
                                                    Bitcoin::Script(pushAll(results)),
                                                    txin.sequence);
    return Result<void>::success();
}

Result<std::vector<Data>>
Signer::signStep(const Bitcoin::Script &script, size_t index, const Bitcoin::Proto::UnspentTransaction &utxo) {
    Bitcoin::Transaction transactionToSign(transaction);
    transactionToSign.inputs = signedInputs;
    transactionToSign.outputs = transaction.outputs;

    Data data;
    std::vector<Data> keys;

    if (script.matchPayToPublicKey(data)) {
        auto keyHash = TW::Hash::ripemd(TW::Hash::sha256(data));
        auto key = keyForPublicKeyHash(keyHash);
        if (key.empty()) {
            // Error: Missing key
            return Result<std::vector<Data>>::failure("Missing private key.");
        }
        auto signature = createSignature(transactionToSign, script, key, index, utxo.amount());
        if (signature.empty()) {
            // Error: Failed to sign
            return Result<std::vector<Data>>::failure("Failed to sign.");
        }
        return Result<std::vector<Data>>::success({signature});
    }
    if (script.matchPayToPublicKeyHash(data)) {
        auto key = keyForPublicKeyHash(data);
        if (key.empty()) {
            // Error: Missing keys
            return Result<std::vector<Data>>::failure("Missing private key.");
        }
        auto pubkey = PrivateKey(key).getPublicKey(TWPublicKeyTypeSECP256k1);
        auto signature = createSignature(transactionToSign, script, key, index, utxo.amount());
        if (signature.empty()) {
            // Error: Failed to sign
            return Result<std::vector<Data>>::failure("Failed to sign.");
        }
        return Result<std::vector<Data>>::success({signature, pubkey.bytes});
    }
    // Error: Invalid output script
    return Result<std::vector<Data>>::failure("Invalid output script.");
}

Data Signer::createSignature(const Bitcoin::Transaction &transaction,
                             const Bitcoin::Script &script,
                             const Data &key,
                             size_t index,
                             uint64_t amount) {
    auto hashType = static_cast<TWBitcoinSigHashType>(TWBitcoinSigHashTypeAll | TWBitcoinSigHashTypeFork);
    auto version = Bitcoin::SignatureVersion::WITNESS_V0;
    Data sighash = transaction.getSignatureHash(script, index, hashType, amount, version);
    auto pk = PrivateKey(key);
    auto sig = pk.signAsDER(sighash, TWCurveSECP256k1);
    if (!sig.empty()) {
        sig.push_back(static_cast<uint8_t>(hashType));
    }
    return sig;
}

Data Signer::keyForPublicKeyHash(const Data &hash) const {
    for (auto &key : input.simple_ledger_input().private_key()) {
        auto publicKey = PrivateKey(key).getPublicKey(TWPublicKeyTypeSECP256k1);
        auto keyHash = TW::Hash::ripemd(TW::Hash::sha256(publicKey.bytes));
        if (keyHash == hash) {
            return Data(key.begin(), key.end());
        }
    }
    for (auto &key : input.bitcoin_cash_input().private_key()) {
        auto publicKey = PrivateKey(key).getPublicKey(TWPublicKeyTypeSECP256k1);
        auto keyHash = TW::Hash::ripemd(TW::Hash::sha256(publicKey.bytes));
        if (keyHash == hash) {
            return Data(key.begin(), key.end());
        }
    }
    return {};
}

Data Signer::pushAll(const std::vector<Data> &results) {
    Data data;
    for (auto &result : results) {
        if (result.empty()) {
            data.push_back(OP_0);
        } else if (result.size() == 1 && result[0] >= 1 && result[0] <= 16) {
            data.push_back(Script::encodeNumber(result[0]));
        } else if (result.size() < OP_PUSHDATA1) {
            data.push_back(static_cast<uint8_t>(result.size()));
        } else if (result.size() <= 0xff) {
            data.push_back(OP_PUSHDATA1);
            data.push_back(static_cast<uint8_t>(result.size()));
        } else if (result.size() <= 0xffff) {
            data.push_back(OP_PUSHDATA2);
            encode16LE(static_cast<uint16_t>(result.size()), data);
        } else {
            data.push_back(OP_PUSHDATA4);
            encode32LE(static_cast<uint32_t>(result.size()), data);
        }
        std::copy(begin(result), end(result), back_inserter(data));
    }
    return data;
}
