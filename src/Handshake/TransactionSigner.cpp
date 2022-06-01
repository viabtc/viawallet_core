// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "TransactionSigner.h"
#include "Bitcoin/SigHashType.h"
#include "Transaction.h"
#include "TransactionInput.h"
#include "TransactionOutput.h"
#include "../BinaryCoding.h"
#include <Bitcoin/SegwitAddress.h>

using namespace TW;
using namespace TW::Handshake;

Result<Transaction, Common::Proto::SigningError> TransactionSigner::sign() {
    if (transaction.inputs.size() == 0 || plan.utxos.size() == 0) {
        return Result<Transaction, Common::Proto::SigningError>::failure(Common::Proto::Error_missing_input_utxos);
    }

    signedInputs.clear();
    std::copy(std::begin(transaction.inputs), std::end(transaction.inputs),
              std::back_inserter(signedInputs));

    const auto hashSingle = TW::Bitcoin::hashTypeIsSingle(static_cast<enum TWBitcoinSigHashType>(input.hash_type()));
    for (auto i = 0; i < plan.utxos.size(); i++) {
        // Only sign TWBitcoinSigHashTypeSingle if there's a corresponding output
        if (hashSingle && i >= transaction.outputs.size()) {
            continue;
        }
        auto& utxo = plan.utxos[i];
        auto script = Script(utxo.script.bytes);
        if (i < transaction.inputs.size()) {
            auto result = sign(script, i, utxo);
            if (!result) {
                return Result<Transaction, Common::Proto::SigningError>::failure(result.error());
            }
        }
    }

    Transaction tx(transaction);
    tx.inputs = move(signedInputs);
    tx.outputs = transaction.outputs;
    // save estimated size
    if ((input.byte_fee()) > 0 && (plan.fee > 0)) {
        tx.previousEstimatedVirtualSize = static_cast<int>(plan.fee / input.byte_fee());
    }

    return Result<Transaction, Common::Proto::SigningError>::success(std::move(tx));
}

Result<void, Common::Proto::SigningError> TransactionSigner::sign(Script script, size_t index,
                                                  const Bitcoin::UTXO& utxo) {
    assert(index < transaction.inputs.size());

    Script redeemScript;
    std::vector<Data> results;

    auto result = signStep(script, index, utxo);
    if (!result) {
        return Result<void, Common::Proto::SigningError>::failure(result.error());
    }
    results = result.payload();
    assert(results.size() >= 1);
    auto txin = transaction.inputs[index];

    if (script.isPayToScriptHash()) {
        script = Script(results[0]);
        auto result = signStep(script, index, utxo);
        if (!result) {
            return Result<void, Common::Proto::SigningError>::failure(result.error());
        }
        results = result.payload();
        results.push_back(script.bytes);
        redeemScript = script;
    }

    std::vector<Data> witnessStack;
    Data data;
    if (script.matchPayToWitnessPublicKeyHash(data)) {
        auto witnessScript = Script::buildPayToPublicKeyHash(results[0]);
        auto result = signStep(witnessScript, index, utxo);
        if (!result) {
            return Result<void, Common::Proto::SigningError>::failure(result.error());
        }
        witnessStack = result.payload();
        results.clear();
    } else if (script.matchPayToWitnessScriptHash(data)) {
        auto witnessScript = Script(results[0]);
        auto result = signStep(witnessScript, index, utxo);
        if (!result) {
            return Result<void, Common::Proto::SigningError>::failure(result.error());
        }
        witnessStack = result.payload();
        witnessStack.push_back(move(witnessScript.bytes));
        results.clear();
    } else if (script.isWitnessProgram()) {
        // Error: Unrecognized witness program.
        return Result<void, Common::Proto::SigningError>::failure(Common::Proto::Error_script_witness_program);
    }

    if (!redeemScript.bytes.empty()) {
        results.push_back(redeemScript.bytes);
    }

    signedInputs[index] =
        TransactionInput(txin.previousOutput, Script(), txin.sequence);
    signedInputs[index].scriptWitness = witnessStack;
    return Result<void, Common::Proto::SigningError>::success();
}

Result<std::vector<Data>, Common::Proto::SigningError> TransactionSigner::signStep(
    Script script, size_t index, const Bitcoin::UTXO& utxo) const {
    Transaction transactionToSign(transaction);
    transactionToSign.inputs = signedInputs;
    transactionToSign.outputs = transaction.outputs;

    Data data;
    std::vector<Data> keys;
    int required;

    if (script.matchPayToScriptHash(data)) {
        auto redeemScript = scriptForScriptHash(data);
        if (redeemScript.empty()) {
            // Error: Missing redeem script
            return Result<std::vector<Data>, Common::Proto::SigningError>::failure(Common::Proto::Error_script_redeem);
        }
        return Result<std::vector<Data>, Common::Proto::SigningError>::success({redeemScript});
    }
    if (script.matchPayToWitnessScriptHash(data)) {
        auto scripthash = TW::Hash::ripemd(data);
        auto redeemScript = scriptForScriptHash(scripthash);
        if (redeemScript.empty()) {
            // Error: Missing redeem script
            return Result<std::vector<Data>, Common::Proto::SigningError>::failure(Common::Proto::Error_script_redeem);
        }
        return Result<std::vector<Data>, Common::Proto::SigningError>::success({redeemScript});
    }
    if (script.matchPayToWitnessPublicKeyHash(data)) {
        return Result<std::vector<Data>, Common::Proto::SigningError>::success({data});
    }
    if (script.isWitnessProgram()) {
        // Error: Invalid sutput script
        return Result<std::vector<Data>, Common::Proto::SigningError>::failure(Common::Proto::Error_script_output);
    }
    if (script.matchMultisig(keys, required)) {
        auto results = std::vector<Data>{{}}; // workaround CHECKMULTISIG bug
        for (auto& pubKey : keys) {
            if (results.size() >= required + 1) {
                break;
            }
            auto keyHash = TW::Hash::ripemd(TW::Hash::sha256(pubKey));
            auto key = keyForPublicKeyHash(keyHash);
            if (key.empty() && !estimationMode) {
                // Error: missing key
                return Result<std::vector<Data>, Common::Proto::SigningError>::failure(Common::Proto::Error_missing_private_key);
            }
            auto signature =
                createSignature(transactionToSign, script, key, index, utxo.amount);
            if (signature.empty()) {
                // Error: Failed to sign
                return Result<std::vector<Data>, Common::Proto::SigningError>::failure(Common::Proto::Error_signing);
            }
            results.push_back(signature);
        }
        results.resize(required + 1);
        return Result<std::vector<Data>, Common::Proto::SigningError>::success(std::move(results));
    }
    if (script.matchPayToPublicKey(data)) {
        auto keyHash = TW::Hash::ripemd(TW::Hash::sha256(data));
        auto key = keyForPublicKeyHash(keyHash);
        if (key.empty() && !estimationMode) {
            // Error: Missing key
            return Result<std::vector<Data>, Common::Proto::SigningError>::failure(Common::Proto::Error_missing_private_key);
        }
        auto signature =
            createSignature(transactionToSign, script, key, index, utxo.amount);
        if (signature.empty()) {
            // Error: Failed to sign
            return Result<std::vector<Data>, Common::Proto::SigningError>::failure(Common::Proto::Error_signing);
        }
        return Result<std::vector<Data>, Common::Proto::SigningError>::success({signature});
    }
    if (script.matchPayToPublicKeyHash(data)) {
        auto key = keyForPublicKeyHash(data);
        if (key.empty() && !estimationMode) {
            // Error: Missing keys
            return Result<std::vector<Data>, Common::Proto::SigningError>::failure(Common::Proto::Error_missing_private_key);
        }

        auto signature =
            createSignature(transactionToSign, script, key, index, utxo.amount);
        if (signature.empty()) {
            // Error: Failed to sign
            return Result<std::vector<Data>, Common::Proto::SigningError>::failure(Common::Proto::Error_signing);
        }
        if (key.empty() && estimationMode) {
            // estimation mode, key is missing: use placeholder for public key
            return Result<std::vector<Data>, Common::Proto::SigningError>::success({signature, Data(PublicKey::secp256k1Size)});
        }
        auto pubkey = PrivateKey(key).getPublicKey(TWPublicKeyTypeSECP256k1);
        return Result<std::vector<Data>, Common::Proto::SigningError>::success({signature, pubkey.bytes});
    }
    // Error: Invalid output script
    return Result<std::vector<Data>, Common::Proto::SigningError>::failure(Common::Proto::Error_script_output);
}

Data TransactionSigner::createSignature(const Transaction& transaction,
                                                     const Script& script, const Data& key,
                                                     size_t index, Bitcoin::Amount amount) const {
    if (estimationMode) {
        return Data(72);
    }
    Data sighash = transaction.getSignatureHash(script, index, static_cast<TWBitcoinSigHashType>(input.hash_type()), amount);

    auto pk = PrivateKey(key);
    auto sig = pk.sign(sighash, TWCurveSECP256k1);

    Data data;
    data.reserve(65);
    std::copy(sig.begin(), sig.end() - 1, std::back_inserter(data));
    if (!data.empty()) {
        data.push_back(static_cast<uint8_t>(input.hash_type()));
    }
    return data;
}

Data TransactionSigner::keyForPublicKeyHash(const Data& hash) const {
    //hash == witProgram
    for (auto& key : input.private_key()) {
        auto publicKey = PrivateKey(key).getPublicKey(TWPublicKeyTypeSECP256k1);
        auto addr0 = Bitcoin::SegwitAddress(publicKey, 0, "hs", HasherType::HASHER_BLAKE2B);
        auto keyHash = addr0.witnessProgram;
        if (keyHash == hash) {
            return Data(key.begin(), key.end());
        }
    }
    return {};
}

Data TransactionSigner::scriptForScriptHash(const Data& hash) const {
    auto hashString = hex(hash);
    auto it = input.scripts().find(hashString);
    if (it == input.scripts().end()) {
        // Error: Missing redeem script
        return {};
    }
    return Data(it->second.begin(), it->second.end());
}