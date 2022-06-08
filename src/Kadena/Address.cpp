// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Address.h"
#include "HexCoding.h"

using namespace TW::Kadena;

bool Address::isValid(const std::string& string) {
    if (string.empty()) {
        return false;
    }

    std::string prefix = "k:";
    if (string.substr(0, prefix.size()) == prefix) {
        auto substring = string.substr(prefix.size(), string.size());
        const auto data = parse_hex(substring);
        return data.size() == PublicKey::ed25519Size;
    }

    return false;
}

Address::Address(const std::string& string) {
    if (!isValid(string)) {
        throw std::invalid_argument("Invalid address string");
    }

    std::string prefix = "k:";
    if (string.substr(0, prefix.size()) == prefix) {
        auto substring = string.substr(prefix.size(), string.size());
        const auto data = parse_hex(substring);
        std::copy(std::begin(data), std::end(data), std::begin(bytes));
    } else {
        throw std::invalid_argument("Invalid address string");
    }
}

Address::Address(const PublicKey& publicKey) {
    auto data = publicKey.compressed().bytes;
    std::copy(std::begin(data), std::end(data), std::begin(bytes));
}

std::string Address::string() const {
    return "k:" + hex(bytes);
}
