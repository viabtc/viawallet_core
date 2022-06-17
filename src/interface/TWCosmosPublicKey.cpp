// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWCosmosPublicKey.h>
#include "../Cosmos/PublicKey.h"

using namespace TW;
using namespace TW::Cosmos;

bool TWCosmosPublicKeyEqual(struct TWCosmosPublicKey *_Nonnull lhs, struct TWCosmosPublicKey *_Nonnull rhs) {
   return lhs->impl == rhs->impl;
}

struct TWCosmosPublicKey *_Nullable TWCosmosPublicKeyCreateWithData(TWString *_Nonnull hrp, TWData *_Nonnull data) {
    auto s = reinterpret_cast<const std::string*>(hrp);
    auto d = reinterpret_cast<const std::vector<uint8_t>*>(data);
    return new TWCosmosPublicKey{ PublicKey(*s, *d) };
}

void TWCosmosPublicKeyDelete(struct TWCosmosPublicKey *_Nonnull publicKey) {
    delete publicKey;
}

TWString *_Nonnull TWCosmosPublicKeyDescription(struct TWCosmosPublicKey *_Nonnull publicKey) {
    const auto string = publicKey->impl.string();
    return TWStringCreateWithUTF8Bytes(string.c_str());
}

TWData *_Nonnull TWCosmosPublicKeyData(struct TWCosmosPublicKey *_Nonnull publicKey) {
    return TWDataCreateWithBytes(publicKey->impl.data.data(), publicKey->impl.data.size());
}

TWString *_Nonnull TWCosmosPublicKeyHrp(struct TWCosmosPublicKey *_Nonnull publicKey) {
    const auto string = publicKey->impl.hrp;
    return TWStringCreateWithUTF8Bytes(string.c_str());
}
