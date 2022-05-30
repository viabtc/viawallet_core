// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWNervosCKBAddress.h>
#include "../NervosCKB/Address.h"

using namespace TW::NervosCKB;

bool TWNervosCKBAddressEqual(struct TWNervosCKBAddress *_Nonnull lhs, struct TWNervosCKBAddress *_Nonnull rhs) {
    return lhs->impl.payload == rhs->impl.payload;
}

bool TWNervosCKBAddressIsValid(TWString *_Nonnull string) {
    auto& s = *reinterpret_cast<const std::string*>(string);
    return Address::isValid(s);
}

struct TWNervosCKBAddress *_Nonnull TWNervosCKBAddressCreateWithPublicKey(struct TWPublicKey *_Nonnull publicKey) {
    return new TWNervosCKBAddress{ Address(publicKey->impl)  };
}

void TWNervosCKBAddressDelete(struct TWNervosCKBAddress *_Nonnull address) {
    delete address;
}

TWString *_Nonnull TWNervosCKBAddressConvertToBech32mFullAddress(TWString *_Nonnull address) {
    auto str = reinterpret_cast<const std::string*>(address);
    return TWStringCreateWithUTF8Bytes(Address::convertToBech32mFullAddress(*str).c_str());
}

TWString *_Nonnull TWNervosCKBAddressDescription(struct TWNervosCKBAddress *_Nonnull address) {
    const auto str = address->impl.string();
    return TWStringCreateWithUTF8Bytes(str.c_str());
}
