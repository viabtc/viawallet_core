// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"
#include "ErgoBox.h"
#include "Transaction.h"
#include "Base64.h"
#include <TrezorCrypto/secp256k1.h>
#include <TrezorCrypto/rand.h>
#include <uint1024.h>

using namespace TW;
using namespace TW::Ergo;


/**
 * Data to uint1024_t, To avoid being overwritten by uint256's load method
 * @param data input data
 * @return uint1024_t
 */
inline uint1024_t load1024(const Data& data) {
    using boost::multiprecision::cpp_int;
    if (data.empty()) {
        return uint1024_t(0);
    }
    uint1024_t result;
    import_bits(result, data.begin(), data.end());
    return result;
}

Proto::SigningOutput Signer::sign(const Proto::SigningInput &input) noexcept {

    auto protoOutput = Proto::SigningOutput();
    
    auto creationHeight = input.creation_height();
    auto fee = input.fee();
    auto feeAddress = input.fee_address();
    auto value = input.value();
    auto toAddress = input.to_address();
    auto changeAddress = input.change_address();
    auto unspentOutputList = input.unspentoutput();

    // check private key
    if (input.private_key().empty()) {
        protoOutput.set_error("Missing private key");
        return protoOutput;
    }

    // check unspent ergo box
    if (unspentOutputList.size() == 0) {
        protoOutput.set_error("Missing UTXOs");
        return protoOutput;
    }

    if (value < 100000) {
        protoOutput.set_error("dust value");
        return protoOutput;
    }

    // payload
    auto payloadOuts = ErgoBox("", value, creationHeight, toAddress);
    // fee box
    auto feeBox = ErgoBox("", fee, creationHeight, feeAddress);

    // outputs box
    std::vector<ErgoBox> outputs;

    outputs.emplace_back(payloadOuts);
    outputs.emplace_back(feeBox);


    // find unspent ergo box
    std::vector<ErgoBox> boxesToSpend;
    auto needErgo = value + fee;
    uint64_t sum = 0;
    int i = 0;
    for(; sum < needErgo && i < unspentOutputList.size(); i++) {
        auto box = unspentOutputList[i];
        sum += box.value();
        boxesToSpend.emplace_back(box);
    }

    // check balance
    if (sum < needErgo) {
        protoOutput.set_error("Insufficient balance");
        return protoOutput;
    }

    // dust box process
    if(sum - needErgo > 0 && sum - needErgo < 100000) {
        if (i == unspentOutputList.size()) {
            protoOutput.set_error("dust change");
            return protoOutput;
        } else {
            for(; sum - needErgo < 100000 && i < unspentOutputList.size(); i++) {
                auto box = unspentOutputList[i];
                sum += box.value();
                boxesToSpend.emplace_back(box);
            }

            if(sum - needErgo > 0 && sum - needErgo < 100000) {
                protoOutput.set_error("dust change");
                return protoOutput;
            }
        }
    }

    // change box
    auto changeAmount = sum - needErgo;
    if (changeAmount > 0) {
        auto changeBox = ErgoBox("", changeAmount, creationHeight, changeAddress);
        outputs.emplace_back(changeBox);
    }

    // inputs
    std::vector<Input> inputs;
    for(auto box: boxesToSpend) {
        inputs.emplace_back(Input(box.boxId));
    }

    // dataInputs
    std::vector<Input> dataInputs;

    // unsignedTx
    Transaction unsignedTx(inputs, outputs, dataInputs);

    // serialize unsignedTx
    auto serializeTx = unsignedTx.serialize();


    // construct signed inputs
    std::vector<Input> signedInputs;

    for(int i = 0; i < inputs.size(); i++) {
        auto in = inputs[i];

        // privateKey
        auto privateKey = Data(input.private_key()[i].begin(), input.private_key()[i].end());

        // sign serialize Tx
        auto proofBytes = sign(serializeTx, privateKey);

        // spendingProof
        std::string proofHex = hex(proofBytes);
        auto sp = SpendingProof(proofHex);

        signedInputs.emplace_back(Input(in.boxId, sp));
    }

    // construct signed transaction
    Transaction signedTx(signedInputs, outputs, dataInputs);

    // json of signed transaction
    std::string json = signedTx.toJson().dump();

    // base64 encode json
    auto encode = Base64::encode(TW::data(json));

    protoOutput.set_encode(encode);
    protoOutput.set_json(json);

    return protoOutput;
}

Data Signer::sign(const Data &msg, const Data &key) noexcept {

    Data orderData(32);
    bn_write_be(&secp256k1.order, orderData.data());
    const uint1024_t _n = load1024(orderData);

    Data randBuf(32);
    random_buffer(randBuf.data(), randBuf.size());

    uint1024_t _y = load1024(randBuf) % _n;
    Data dataY;
    encode1024BE(dataY, _y, 32);

    //auto strY = "0x16a2e52ae6e7b409156b0811ca986f226e385a9246330b3b4b871780b0e86c28";

    const uint1024_t zero = uint1024_t(0);
    if (_y == zero) {
        return sign(msg, key);
    }

    Data pk;
    pk.resize(PublicKey::secp256k1Size);
    ecdsa_get_public_key33(&secp256k1, key.data(), pk.data());

    Data w;
    w.resize(PublicKey::secp256k1Size);
    ecdsa_get_public_key33(&secp256k1, dataY.data(), w.data());

    auto commitment = genCommitment(pk, w);

    Data s;
    append(s, commitment);
    append(s, msg);

    auto hash = Hash::blake2b(reinterpret_cast<const byte*>(s.data()), s.size(), s.size());
    auto c = TW::subData(hash, 0, 24);

    if (c.empty()) {
        return TW::Data();
    }

    const uint1024_t _sk = load1024(key);
    const uint1024_t _c = load1024(c);

    uint1024_t _z = (_sk * _c + _y) % _n;

    Data result;
    encode1024BE(result, _c, 24);
    encode1024BE(result, _z, 32);

    return result;
}

Data Signer::genCommitment(const Data &pk, const Data &w) noexcept {
    auto prefix = parse_hex("010027100108cd");
    auto postfix = parse_hex("73000021");

    Data data;
    append(data, prefix);
    append(data, pk);
    append(data, postfix);
    append(data, w);

    return data;
}



