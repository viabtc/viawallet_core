// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "TransactionOutput.h"

#include "../BinaryCoding.h"

using namespace TW::Handshake;

void TransactionOutput::encode(std::vector<uint8_t>& data) const {
    encode64LE(value, data);
    script.encode(data);

    //covenant
    data.push_back(OP_0);
    encodeVarInt(0, data);
}
