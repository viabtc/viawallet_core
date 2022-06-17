// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.


#include "PublicKey.h"
#include "../Data.h"
#include "../Bech32.h"

using namespace TW::Cosmos;

std::pair<PublicKey, bool> PublicKey::decode(const std::string& publicKey) {
    auto dec = Bech32::decode(publicKey);
    if (std::get<1>(dec).empty()) {
        return std::make_pair(PublicKey(std::string(), Data()), false);
    }

    Data conv;
    auto success = Bech32::convertBits<5, 8, false>(conv, Data(std::get<1>(dec).begin(), std::get<1>(dec).end()));
    if (!success) {
        return std::make_pair(PublicKey(std::string(), Data()), false);
    }

    return std::make_pair(PublicKey(std::get<0>(dec), conv), true);
}

std::string PublicKey::string() const {
    auto key = Data({0xeb, 0x5a, 0xe9, 0x87, 0x21});
    key.insert(key.end(), data.begin(), data.end());

    Data enc;
    Bech32::convertBits<8, 5, true>(enc, key);
    std::string result = Bech32::encode(hrp, enc, Bech32::Bech32);
    if (!decode(result).second) {
        return {};
    }
    return result;
}
