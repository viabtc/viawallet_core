// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Script.h"
#include "Address.h"
#include "../HexCoding.h"
#include "../BinaryCoding.h"
#include "../Coin.h"

using namespace TW;
using namespace TW::Horizen;

Script Script::lockScriptForAddress(const std::string& address, const uint32_t block_height,
                                    const std::string& block_hash) {
    if (Horizen::Address::isValid(address)) {
        auto zenAddress = Horizen::Address(address);
        auto data = Data();
        data.reserve(Address::size - 2);
        std::copy(zenAddress.bytes.begin() + 2, zenAddress.bytes.end(), std::back_inserter(data));

        Data blockHeightBuffer;
        encode32LE(static_cast<uint32_t>(block_height), blockHeightBuffer);
        if (blockHeightBuffer.size() == 4 && blockHeightBuffer[3] == 0x00) {
            blockHeightBuffer.pop_back();
        }

        auto blockHash = parse_hex(block_hash);
        std::reverse(blockHash.begin(), blockHash.end());

        if (zenAddress.bytes[1] == TW::p2pkhPrefix(TWCoinTypeHorizen)) {
            return buildPublicKeyHash(data, blockHeightBuffer, blockHash);
        } else if (zenAddress.bytes[1] == TW::p2shPrefix(TWCoinTypeHorizen)) {
            return buildScriptHash(data, blockHeightBuffer, blockHash);
        }
    }
    return {};
}

Script Script::buildPublicKeyHash(const Data& data, const Data& block_height,
                                        const Data& block_hash) {
    assert(data.size() == 20);
    Script script;
    script.bytes.push_back(OP_DUP);
    script.bytes.push_back(OP_HASH160);
    script.bytes.push_back(20);
    script.bytes.insert(script.bytes.end(), data.begin(), data.end());
    script.bytes.push_back(OP_EQUALVERIFY);
    script.bytes.push_back(OP_CHECKSIG);

    Data blockHashSize;
    encodeVarInt(block_hash.size(), blockHashSize);
    script.bytes.insert(script.bytes.end(), blockHashSize.begin(), blockHashSize.end());
    script.bytes.insert(script.bytes.end(), block_hash.begin(), block_hash.end());

    Data blockHeightSize;
    encodeVarInt(block_height.size(), blockHeightSize);
    script.bytes.insert(script.bytes.end(), blockHeightSize.begin(), blockHeightSize.end());
    script.bytes.insert(script.bytes.end(), block_height.begin(), block_height.end());
    script.bytes.push_back(OP_CHECKBLOCKATHEIGHT);
    return script;
}

Script Script::buildScriptHash(const Data& data, const Data& block_height,
                                     const Data& block_hash) {
    assert(data.size() == 20);
    Script script;
    script.bytes.push_back(OP_HASH160);
    script.bytes.push_back(20);
    script.bytes.insert(script.bytes.end(), data.begin(), data.end());
    script.bytes.push_back(OP_EQUAL);

    Data blockHashSize;
    encodeVarInt(block_hash.size(), blockHashSize);
    script.bytes.insert(script.bytes.end(), blockHashSize.begin(), blockHashSize.end());
    script.bytes.insert(script.bytes.end(), block_hash.begin(), block_hash.end());

    Data blockHeightSize;
    encodeVarInt(block_height.size(), blockHeightSize);
    script.bytes.insert(script.bytes.end(), blockHeightSize.begin(), blockHeightSize.end());
    script.bytes.insert(script.bytes.end(), block_height.begin(), block_height.end());
    script.bytes.push_back(OP_CHECKBLOCKATHEIGHT);
    return script;
}

bool Script::matchPayToPublicKeyHash(Data& result) {
    if (bytes[0] == OP_DUP && bytes[1] == OP_HASH160 && bytes[2] == 20 &&
        bytes[23] == OP_EQUALVERIFY && bytes[24] == OP_CHECKSIG) {
        result.clear();
        std::copy(std::begin(bytes) + 3, std::begin(bytes) + 3 + 20, std::back_inserter(result));
        return true;
    }
    return false;
}