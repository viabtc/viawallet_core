// Copyright © 2017-2023 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include <string>

namespace TW::Kaspa {

class KaspaScriptPublicKey {
public:
    uint16_t version = 0;
    std::string scriptPublicKey;

    KaspaScriptPublicKey(std::string scriptPublicKey) :
        scriptPublicKey(scriptPublicKey) {}
};

} // namespace TW

struct TWKaspaScriptPublicKey {
    TW::Kaspa::KaspaScriptPublicKey impl;
};
