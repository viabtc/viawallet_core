// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWConfluxNetworkAddress.h>
#include <TrustWalletCore/TWPublicKey.h>

#include "../ConfluxNetwork/Address.h"

#include <cstring>

using namespace TW::ConfluxNetwork;

bool TWConfluxNetworkAddressEqual(struct TWConfluxNetworkAddress *_Nonnull lhs, struct TWConfluxNetworkAddress *_Nonnull rhs) {
    return lhs->impl.bytes == rhs->impl.bytes;
}

bool TWConfluxNetworkAddressIsValidString(TWString *_Nonnull string) {
    auto& s = *reinterpret_cast<const std::string*>(string);
    return Address::isValid(s);
}

struct TWConfluxNetworkAddress *_Nullable TWConfluxNetworkAddressCreateWithString(TWString *_Nonnull string) {
    auto& s = *reinterpret_cast<const std::string*>(string);
    if (!Address::isValid(s)) {
        return nullptr;
    }
    return new TWConfluxNetworkAddress{ Address(s) };
}

struct TWConfluxNetworkAddress *_Nonnull TWConfluxNetworkAddressCreateWithPublicKey(struct TWPublicKey *_Nonnull publicKey) {
    return new TWConfluxNetworkAddress{ Address(publicKey->impl) };
}

TWString *_Nonnull TWConfluxNetworkAddressEncode(TWString *_Nonnull string) {
    auto& s = *reinterpret_cast<const std::string*>(string);
    auto encodeAddr = Address::encode(s);
    return TWStringCreateWithUTF8Bytes(encodeAddr.c_str());
}

void TWConfluxNetworkAddressDelete(struct TWConfluxNetworkAddress *_Nonnull address) {
    delete address;
}

TWString *_Nonnull TWConfluxNetworkAddressDescription(struct TWConfluxNetworkAddress *_Nonnull address) {
    const auto str = address->impl.string();
    return TWStringCreateWithUTF8Bytes(str.c_str());
}
