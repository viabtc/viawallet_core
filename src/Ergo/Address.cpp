// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Address.h"
#include "Base58.h"
#include "HexCoding.h"

using namespace TW::Ergo;

bool Address::isValid(const std::string& string) {
    if (string.empty()) {
        return false;
    }

    std::string base58chars = std::string(Base58::bitcoin.digits.begin(), Base58::bitcoin.digits.end());
    for(auto ch: string) {
        if (std::string::npos == base58chars.find(ch)) {
            return false;
        }
    }

    const auto decoded = Base58::bitcoin.decode(string);
    const auto size = decoded.size();
    if (size < 4) {
        return false;
    }

    const auto script = TW::subData(decoded, 0, size - 4);
    const auto checksum = TW::subData(decoded, size - 4, 4);
    const auto calculatedChecksum = TW::subData(Hash::blake2b(script, 32), 0, 4);

    return hex(checksum) == hex(calculatedChecksum);
}

Address::Address(const std::string& string) {
    if (!isValid(string)) {
        throw std::invalid_argument("Invalid address string");
    }
    const auto decoded = Base58::bitcoin.decode(string);
    bytes.resize(decoded.size());
    std::copy(decoded.begin(), decoded.end(), bytes.begin());
}

Address::Address(const PublicKey& publicKey) {
    Data data;
    data.push_back({0x01});
    append(data, publicKey.bytes);
    auto checksum = Hash::blake2b(data, 32);
    append(data, checksum);

    if (data.size() < 38) {
        throw std::invalid_argument("Invalid address data");
    }
    bytes.resize(38);
    std::copy(data.begin(), data.begin() + 38, bytes.begin());

}

std::string Address::string() const {
    return Base58::bitcoin.encode(bytes);
}

TW::Data Address::ergoTree() {
    auto type = bytes[0] & 0xF;
    if (type == 1) { //P2PK
        Data data;
        append(data, 0x00);
        append(data, 0x08);
        append(data, 0xcd);
        auto publicKey = TW::subData(bytes, 1, 33);
        append(data, publicKey);
        return data;
    } else {
        return TW::subData(bytes, 1, bytes.size() - 5);
    }
}