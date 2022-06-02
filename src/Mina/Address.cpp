// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Address.h"
#include "Base58.h"

using namespace TW::Mina;

bool Address::isValid(const std::string& string) {
    if (string.empty()) return false;

    auto decodeData = Base58::bitcoin.decodeCheck(string);
    return decodeData.size() == size;
}

Address::Address(const std::string& string) {
    if (!isValid(string)) {
        throw std::invalid_argument("Invalid address string");
    }
    auto decodeData = Base58::bitcoin.decodeCheck(string);
    std::copy(decodeData.begin(), decodeData.end(), bytes.begin());
}

Address::Address(const PublicKey& publicKey) {
    std::copy(publicKey.bytes.begin(), publicKey.bytes.end(), bytes.begin());
}

std::string Address::string() const {
    return Base58::bitcoin.encodeCheck(bytes);
}
