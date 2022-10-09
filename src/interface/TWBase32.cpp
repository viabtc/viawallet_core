// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBase32.h>

#include "../Base32.h"

#include <string>

using namespace TW;

TWString *_Nonnull TWBase32Encode(TWData *_Nonnull data) {
    const auto& d = *reinterpret_cast<const Data*>(data);
    const auto str = Base32::encode(d);
    return TWStringCreateWithUTF8Bytes(str.c_str());
}

TWData *_Nullable TWBase32Decode(TWString *_Nonnull string) {
    auto& s = *reinterpret_cast<const std::string*>(string);
    Data decoded;
    Base32::decode(s, decoded);
    if (decoded.empty()) {
        return nullptr;
    }

    return TWDataCreateWithBytes(decoded.data(), decoded.size());
}
