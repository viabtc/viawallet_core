// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Script.h"
#include "Address.h"
#include "Serializer.h"
#include "../Bech32.h"

using namespace TW;
using namespace TW::NervosCKB;

Data Script::hash() const {
    auto personal = data("ckb-default-hash");
    auto blake2bHash = Hash::blake2b(scriptSerialize(*this), 32, personal);
    return blake2bHash;
}

Script Script::secp256k1LockScript(const std::string &string) {
    auto address = Address(string);

    H256 codeHash = {0x9b, 0xd7, 0xe0, 0x6f,
                     0x3e, 0xcf, 0x4b, 0xe0,
                     0xf2, 0xfc, 0xd2, 0x18,
                     0x8b, 0x23, 0xf1, 0xb9,
                     0xfc, 0xc8, 0x8e, 0x5d,
                     0x4b, 0x65, 0xa8, 0x63,
                     0x7b, 0x17, 0x72, 0x3b,
                     0xbd, 0xa3, 0xcc, 0xe8};



    return Script(codeHash, address.publicKeyHash(), SCRIPT_TYPE);
}

Script Script::parseLockScript(const std::string &address) {

    if (!Address::isValid(address)) {
        throw std::invalid_argument("Invalid address for script: " + address);
    }

    auto dec = Bech32::decode(address);
    Data payload;
    Bech32::convertBits<5, 8, false>(payload, std::get<1>(dec));

    auto type = payload[0];

    if (TYPE_SHORT == type) {
        auto codeHashIndex = payload[1];
        auto args = TW::subData(payload, 2);

        switch (codeHashIndex) {
            case CODE_HASH_IDX_BLAKE160:
                return Script(SECP_BLAKE160_CODE_HASH, args, SCRIPT_TYPE);

            case CODE_HASH_IDX_MULTISIG:
                return Script(MULTISIG_CODE_HASH, args, SCRIPT_TYPE);

            case CODE_HASH_IDX_ANYONE_CAN_PAY:
                return Script(ACP_MAINNET_CODE_HASH, args, SCRIPT_TYPE);

            default:
                throw std::invalid_argument("Invalid address for script: " + address);
        }
    }


    if (TYPE_FULL_DATA == type) {
        auto codeHash = TW::subData(payload, 1, 32);
        auto args = TW::subData(payload, 33);
        return Script(codeHash, args, SCRIPT_DATA);

    } else if (TYPE_FULL_TYPE == type) {
        auto codeHash = TW::subData(payload, 1, 32);
        auto args = TW::subData(payload, 33);
        return Script(codeHash, args, SCRIPT_TYPE);
    }


    if (TYPE_FULL_WITH_BECH32M == type) {
        auto codeHash = TW::subData(payload, 1, 32);
        auto hashType = payload[33];
        auto args = TW::subData(payload, 34);

        return Script(codeHash, args, hashType);
    }

    throw std::invalid_argument("Invalid address for script: " + address);

}
