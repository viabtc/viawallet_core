// Copyright © 2017-2023 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include <string>
#include "KaspaScriptPublicKey.h"

namespace TW::Kaspa {

class KaspaOutput {
public:
    uint64_t amount;
    KaspaScriptPublicKey scriptPublicKey;

    KaspaOutput(uint64_t amount, KaspaScriptPublicKey scriptPublicKey) :
        amount(amount),
        scriptPublicKey(scriptPublicKey) {}
};
} // namespace Kaspa

struct TWKaspaOutput {
    TW::Kaspa::KaspaOutput impl;
};
