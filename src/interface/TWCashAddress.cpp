// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "../Base58.h"
#include "../Bitcoin/Address.h"
#include "../Bitcoin/CashAddress.h"
#include <TrezorCrypto/ecdsa.h>
#include <TrustWalletCore/TWCashAddress.h>
#include <TrustWalletCore/TWPublicKey.h>

#include <cstring>

bool TWCashAddressEqual(struct TWCashAddress *_Nonnull lhs, struct TWCashAddress *_Nonnull rhs) {
    return lhs->impl == rhs->impl;
}

bool TWCashAddressIsValid(TWData *_Nonnull data) {
    return TWDataSize(data) == TW::Bitcoin::CashAddress::size;
}

bool TWCashAddressIsValidString(TWString *_Nonnull hrp, TWString *_Nonnull string) {
    auto& h = *reinterpret_cast<const std::string*>(hrp);
    auto& s = *reinterpret_cast<const std::string*>(string);
    return TW::Bitcoin::CashAddress::isValid(h, s);
}

struct TWCashAddress *_Nullable TWCashAddressCreateWithString(TWString *_Nonnull hrp, TWString *_Nonnull string) {
    auto& h = *reinterpret_cast<const std::string*>(hrp);
    auto& s = *reinterpret_cast<const std::string*>(string);
    try {
        return new TWCashAddress{ TW::Bitcoin::CashAddress(h, s) };
    } catch (...) {
        return nullptr;
    }
}

struct TWCashAddress *_Nullable TWCashAddressCreateWithPublicKey(TWString *_Nonnull hrp, struct TWPublicKey *_Nonnull publicKey) {
    auto& h = *reinterpret_cast<const std::string*>(hrp);
    try {
        return new TWCashAddress{ TW::Bitcoin::CashAddress(h, publicKey->impl) };
    } catch (...) {
        return nullptr;
    }
}

void TWCashAddressDelete(struct TWCashAddress *_Nonnull address) {
    delete address;
}

TWString *_Nonnull TWCashAddressDescription(struct TWCashAddress *_Nonnull address) {
    return TWStringCreateWithUTF8Bytes(address->impl.string().c_str());
}

TWData *_Nonnull TWCashAddressKeyhash(struct TWCashAddress *_Nonnull address) {
    return TWDataCreateWithBytes(address->impl.getData().data() + 1, TW::Bitcoin::Address::size - 1);
}
