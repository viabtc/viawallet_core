// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"
#include "Address.h"
#include "Bitcoin/SigHashType.h"
#include "../BinaryCoding.h"
#include "../HexCoding.h"
#include <PrivateKey.h>
#include <utility>


using namespace TW;
using namespace TW::Horizen;

TransactionPlan Signer::plan(const SigningInput& input) noexcept {
    auto signer = Signer(input);
    return signer.txPlan.proto();
}

SigningOutput Signer::sign(const SigningInput& input) noexcept {
    auto signer = Signer(input);
    auto result = signer.sign();
    auto output = Bitcoin::Proto::SigningOutput();
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

Result<Bitcoin::Transaction, Common::Proto::SigningError> Signer::sign() {
    if (txPlan.utxos.empty() || transaction.inputs.empty()) {
        return Result<Bitcoin::Transaction, Common::Proto::SigningError>::failure(Common::Proto::Error_missing_input_utxos);
    }

    signedInputs.clear();
    std::copy(std::begin(transaction.inputs),
              std::end(transaction.inputs),
              std::back_inserter(signedInputs));

    for (auto i = 0; i < txPlan.utxos.size(); i++) {
        auto &utxo = txPlan.utxos[i];
        auto script = Horizen::Script(utxo.script.bytes);
        auto result = sign(script, i, utxo);
        if (!result) {
            return Result<Bitcoin::Transaction, Common::Proto::SigningError>::failure(result.error());
        }
        signedInputs[i].script = result.payload();
    }

    Bitcoin::Transaction tx(transaction);
    tx.inputs = move(signedInputs);
    tx.outputs = transaction.outputs;
    return Result<Bitcoin::Transaction, Common::Proto::SigningError>::success(std::move(tx));
}

Result<Horizen::Script, Common::Proto::SigningError> Signer::sign(Script& script, size_t index, const Bitcoin::UTXO &utxo) {
    assert(index < transaction.inputs.size());

    Bitcoin::Transaction transactionToSign(transaction);
    transactionToSign.inputs = signedInputs;
    transactionToSign.outputs = transaction.outputs;

    auto sighash = transactionToSign.getSignatureHash(script, index, TWBitcoinSigHashTypeAll,
                                                            0, Bitcoin::SignatureVersion::BASE);
    auto pkBytes = searchKey(script);
    if (pkBytes.empty()) {
        return Result<Horizen::Script, Common::Proto::SigningError>::failure(Common::Proto::Error_missing_private_key);
    }

    auto pk = PrivateKey(pkBytes);

    auto sig = pk.signAsDER(sighash, TWCurveSECP256k1);

    if (!sig.empty()) {
        sig.push_back(static_cast<uint8_t>(TWBitcoinSigHashTypeAll));
    }

    if (sig.empty()) {
        // Error: Failed to sign
        return Result<Horizen::Script, Common::Proto::SigningError>::failure(Common::Proto::Error_signing);
    }

    auto pubkey = pk.getPublicKey(TWPublicKeyTypeSECP256k1);

    Data result;

    encodeVarInt(sig.size(), result);

    result.insert(result.end(), sig.begin(), sig.end());

    encodeVarInt(pubkey.bytes.size(), result);

    result.insert(result.end(), pubkey.bytes.begin(), pubkey.bytes.end());

    return Result<Horizen::Script, Common::Proto::SigningError>::success(Horizen::Script(result));
}

Data Signer::searchKey(Script& script) {
    Data data;
    if (script.matchPayToPublicKeyHash(data)) {
        return keyForPublicKeyHash(data);
    }
    return {};
}

Data Signer::keyForPublicKeyHash(const Data& hash) {
    for (auto& key : input.private_key()) {
        auto publicKey = PrivateKey(key).getPublicKey(TWPublicKeyTypeSECP256k1);
        auto keyHash = TW::Hash::ripemd(TW::Hash::sha256(publicKey.bytes));
        if (keyHash == hash) {
            return Data(key.begin(), key.end());
        }
    }
    return {};
}