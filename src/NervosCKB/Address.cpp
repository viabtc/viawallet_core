// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWHRP.h>
#include "../Bech32Address.h"
#include "../Bech32.h"
#include "Address.h"

using namespace TW::NervosCKB;

bool Address::isValid(const std::string& string) {
    auto dec = Bech32::decode(string);
    const std::string& hrp = HRP_NERVOSCKB;

    // check hrp prefix (if given)
    if (hrp.length() > 0 && std::get<0>(dec).compare(0, hrp.length(), hrp) != 0) {
        return false;
    }

    if (std::get<1>(dec).empty()) {
        return false;
    }

    Data payload;
    auto success = Bech32::convertBits<5, 8, false>(payload, std::get<1>(dec));
    if (!success || payload.size() < 2) {
        return false;
    }

    auto type = payload[0];

    if (type == TYPE_SHORT) {
        auto codeHashIndex = payload[1];
        auto args = TW::subData(payload, 2);

        if (codeHashIndex != CODE_HASH_IDX_ANYONE_CAN_PAY && args.size() != 20) {
            // "Short address args byte length must be equal to 20"
            return false;
        }

        if (codeHashIndex == CODE_HASH_IDX_BLAKE160
            || codeHashIndex == CODE_HASH_IDX_MULTISIG
            || codeHashIndex == CODE_HASH_IDX_ANYONE_CAN_PAY) {
            // "Short address code hash index must be 00, 01 or 02"
            return true;
        } else {
            return false;
        }
    }

    if (payload.size() < 33) {
        // "Invalid full address payload length"
        return false;
    }

    if (type == TYPE_FULL_DATA
        || type == TYPE_FULL_TYPE
        || type == TYPE_FULL_WITH_BECH32M) {
        // "Full address type must be 02 or 04"
        return true;
    }

    return false;
}

Address::Address(const std::string& string) {
    if (isValid(string)) {
        auto dec = Bech32::decode(string);
        Bech32::convertBits<5, 8, false>(payload, std::get<1>(dec));
    } else {
        throw std::invalid_argument("Invalid address string");
    }
}

Address::Address(const PublicKey& publicKey) {
    auto personal = TW::data("ckb-default-hash");
    auto blake2bHash = Hash::blake2b(publicKey.bytes, 32, personal);
    auto publicKeyHash = subData(blake2bHash, 0, 20);
    auto type = Data({0x01}); // short version for locks with popular code_hash
    auto codeHashIndex = Data({0x00});
    auto addressData = Data();
    append(addressData, type);
    append(addressData, codeHashIndex);
    append(addressData, publicKeyHash);
    payload = std::move(addressData);
}

std::string Address::string() const {
    auto address = Bech32Address(HRP_NERVOSCKB, payload);
    return address.string();
}

std::string Address::convertToBech32mFullAddress(const std::string& string) {
    // Payload: type(00) | code hash | hash type | args

    auto script = Script::parseLockScript(string);

    Data payload;
    TW::append(payload, TYPE_FULL_WITH_BECH32M);
    TW::append(payload, script.codeHash);
    TW::append(payload, script.hashType);
    TW::append(payload, script.args);

    Data enc;
    if (!Bech32::convertBits<8, 5, true>(enc, payload)) {
        return "";
    }

    return Bech32::encode(HRP_NERVOSCKB, enc, TW::Bech32::ChecksumVariant::Bech32M);
}
