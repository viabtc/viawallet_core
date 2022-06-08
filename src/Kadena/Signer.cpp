// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"
#include "Serialization.h"
#include "Hash.h"
#include "Base64.h"
#include "HexCoding.h"

using namespace TW;
using namespace TW::Kadena;

using json = nlohmann::json;

Proto::SigningOutput Signer::sign(const Proto::SigningInput &input) noexcept {
    auto protoOutput = Proto::SigningOutput();

    if (input.privatekey().empty()) {
        protoOutput.set_error("Missing private key.");
        return protoOutput;
    }
    if (input.networkid().empty()) {
        protoOutput.set_error("Missing networkId.");
        return protoOutput;
    }
    if (input.sender().empty()) {
        protoOutput.set_error("Missing sender.");
        return protoOutput;
    }
    if (input.receiver().empty()) {
        protoOutput.set_error("Missing receiver.");
        return protoOutput;
    }
    if (input.amount().empty()) {
        protoOutput.set_error("Missing amount.");
        return protoOutput;
    }
    if (input.gasprice().empty()) {
        protoOutput.set_error("Missing gasPrice.");
        return protoOutput;
    }
    if (input.gaslimit() == 0) {
        protoOutput.set_error("Missing gasLimit.");
        return protoOutput;
    }
    if (input.nonce().empty()) {
        protoOutput.set_error("Missing nonce.");
        return protoOutput;
    }
    if (input.creationtime() == 0) {
        protoOutput.set_error("Missing creationTime.");
        return protoOutput;
    }
    if (input.ttl() == 0) {
        protoOutput.set_error("Missing TTL.");
        return protoOutput;
    }
    if (input.chainid().empty()) {
        protoOutput.set_error("Missing chainId.");
        return protoOutput;
    }
    if (input.targetchainid().empty()) {
        protoOutput.set_error("Missing targetChainId.");
        return protoOutput;
    }
    if (input.receiverpubkeys().empty()) {
        protoOutput.set_error("Missing Receiver PubKeys.");
        return protoOutput;
    }
    if (input.pred().empty()) {
        protoOutput.set_error("Missing Receiver Pred.");
        return protoOutput;
    }

    auto transactionJson = transactionJSON(input);

    auto cmd = transactionJson.dump();

    auto hshBin = Hash::blake2b(cmd, 32);

    auto hsh = Base64::encodeBase64UrlNoPadding(hshBin);

    auto key = PrivateKey(input.privatekey());

    auto signature = key.sign(hshBin, TWCurveED25519ExtendedKDA);

    auto signedResult = signedTransactionJSON(cmd, hex(signature), hsh);

    protoOutput.set_json(signedResult.dump());

    protoOutput.set_hash(hsh);

    return protoOutput;
}

