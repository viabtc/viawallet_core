// Copyright © 2017-2023 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Address.h"
#include <TrustWalletCore/TWHRP.h>
#include "KaspaBech32.h"
#include <array>
#include <cassert>
#include <utility>
#include <string>

namespace TW::Kaspa {

bool Address::isValid(const std::string& string) {
    auto dec = KaspaBech32::decode(string);
    const std::string& hrp = HRP_KASPA;

    // check hrp prefix (if given)
    if (hrp.length() > 0 && std::get<0>(dec).compare(0, hrp.length(), hrp) != 0) {
        return false;
    }

    if (std::get<1>(dec).empty()) {
        return false;
    }

    Data payload;
    auto success = KaspaBech32::convertBits<5, 8, false>(payload, std::get<1>(dec));
    if (!success || payload.size() < 2) {
        return false;
    }

    auto type = payload[0];
    if (type == AddressType::ecdsa
        || type == AddressType::schnorr
        || type == AddressType::p2sh) {
        return true;
    }
    return false;
}

Address::Address(const std::string& string) {
    if (isValid(string)) {
        auto dec = KaspaBech32::decode(string);
        KaspaBech32::convertBits<5, 8, false>(payload, std::get<1>(dec));
    } else {
        throw std::invalid_argument("Invalid address string");
    }
}

Address::Address(const PublicKey& publicKey) {
    auto publicKeyHash = publicKey.compressed().bytes;
    //version: ECDSA
    byte type = AddressType::ecdsa;
    auto version = Data({type});
    auto addressData = Data();
    append(addressData, version);
    append(addressData, publicKeyHash);
    payload = std::move(addressData);
}

std::string Address::string() const {
    Data enc;
    if (!KaspaBech32::convertBits<8, 5, true>(enc, payload)) {
        return "";
    }

    auto address = KaspaBech32::encode(HRP_KASPA, enc, KaspaBech32::Bech32);
    return address;
}

Address::AddressComponents Address::parse(const std::string& string) {
    if (Address::isValid(string)) {
        auto dec = KaspaBech32::decode(string);
        const std::string& hrp = HRP_KASPA;
        Data payload;
        auto success = KaspaBech32::convertBits<5, 8, false>(payload, std::get<1>(dec));
        if (!success || payload.size() < 2) {
            throw std::invalid_argument("Invalid address string");
        }
        auto type = payload[0];

        Data hashData;
        hashData.resize(0);
        for (long index = 1; index < payload.size(); index ++) {
            auto hash = payload[index];
            hashData.push_back(hash);
        }

        if (type == Address::ecdsa) {
            Address::AddressComponents component;
            component.hash = hashData;
            component.type = Address::AddressType::ecdsa;
            component.prefix = hrp;
            return component;
        } else if (type == Address::schnorr) {
            Address::AddressComponents component;
            component.hash = hashData;
            component.type = Address::AddressType::schnorr;
            component.prefix = hrp;
            return component;
        } else {
            Address::AddressComponents component;
            component.hash = hashData;
            component.type = Address::AddressType::p2sh;
            component.prefix = hrp;
            return component;
        }
    } else {
        throw std::invalid_argument("Invalid address string");
    }
}

} // namespace TW::Kaspa
