// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Script.h"
#include "../BinaryCoding.h"

using namespace TW;
using namespace TW::SimpleLedger;

Script Script::buildSimpleLedgerTokenSend(const Data& tokenId, const std::vector<Bitcoin::Amount>& values) {
    assert(tokenId.size() == 32);
    Script script;
    script.bytes.push_back(OP_RETURN);
    script.bytes.push_back(0x04);   // length of lokad_id field (4 bytes)
    encode32BE(0x534c5000, script.bytes); // lokad id
    script.bytes.push_back(0x1); // length of token_type
    script.bytes.push_back(0x1); // token_type
    script.bytes.push_back(0x4); // number of bytes in transaction_type (4 bytes)
    encode32BE(0x53454e44, script.bytes); // 'SEND'
    script.bytes.push_back(0x20);
    script.bytes.insert(script.bytes.end(), tokenId.begin(), tokenId.end());
    for (auto& v : values) {
        script.bytes.push_back(0x08);
        encode64BE(v, script.bytes);
    }
    return script;
}