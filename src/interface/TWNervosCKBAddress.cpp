// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "../Base58.h"
#include "../NervosCKB/Address.h"

#include <TrustWalletCore/TWNervosCKBAddress.h>


bool TWNervosCKBAddressEqual(struct TWNervosCKBAddress*_Nonnull lhs, struct TWNervosCKBAddress*_Nonnull rhs) {
    return lhs->impl == rhs->impl;
}

bool TWNervosCKBAddressIsValidString(TWString *_Nonnull string) {
    auto& s = *reinterpret_cast<const std::string*>(string);
    return TW::NervosCKB::Address::isValid(s);
}

struct TWNervosCKBAddress*_Nullable TWNervosCKBAddressCreateWithString(TWString *_Nonnull string) {
    auto& s = *reinterpret_cast<const std::string*>(string);
    try {
        return new TWNervosCKBAddress{ TW::NervosCKB::Address(s) };
    } catch (...) {
        return nullptr;
    }
}

void TWNervosCKBAddressDelete(struct TWNervosCKBAddress*_Nonnull address) {
    delete address;
}

TWString *_Nonnull TWNervosCKBAddressDescription(struct TWNervosCKBAddress*_Nonnull address) {
    return TWStringCreateWithUTF8Bytes(address->impl.string().c_str());
}

TWString *_Nonnull TWNervosCKBAddressConvertToBech32mFullAddress(TWString *_Nonnull address) {
    auto str = reinterpret_cast<const std::string*>(address);
    return TWStringCreateWithUTF8Bytes(TW::NervosCKB::Address::convertToBech32mFullAddress(*str).c_str());
}
