// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"
#include "Extrinsic.h"
#include "../Hash.h"
#include "../PrivateKey.h"

namespace TW::Polkadot {

static constexpr size_t hashTreshold = 256;

TWCurve TWCurveType(Proto::Curve curve) {
    switch (curve) {
    case Proto::Curve::SR25519:
        return TWCurveSR25519;
    default:
        return TWCurveED25519;
    }
}

TWPublicKeyType TWPublicKeyType(Proto::Curve curve) {
    switch (curve) {
    case Proto::Curve::SR25519:
        return TWPublicKeyTypeSR25519;
    default:
        return TWPublicKeyTypeED25519;
    }
}

Proto::SigningOutput Signer::sign(const Proto::SigningInput &input) noexcept {
    auto curve = TWCurveType(input.curve());
    auto publicKeyType = TWPublicKeyType(input.curve());

    auto privateKey = PrivateKey(Data(input.private_key().begin(), input.private_key().end()));
    auto publicKey = privateKey.getPublicKey(publicKeyType);
    auto extrinsic = Extrinsic(input);
    auto payload = extrinsic.encodePayload();
    // check if need to hash
    if (payload.size() > hashTreshold) {
        payload = Hash::blake2b(payload, 32);
    }
    auto signature = privateKey.sign(payload, curve);
    auto encoded = extrinsic.encodeSignature(publicKey, signature);

    auto protoOutput = Proto::SigningOutput();
    protoOutput.set_encoded(encoded.data(), encoded.size());
    return protoOutput;
}

} // namespace TW::Polkadot
