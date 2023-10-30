// Copyright © 2017-2023 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include <string>
#include "BitcoinUnspentOutput.h"
#include "KaspaOutput.h"
#include "Data.h"
#include "KaspaInput.h"

namespace TW::Kaspa {

class TransactionData {
public:
    int version = 0;
    std::vector<KaspaInput> inputs;
    std::vector<KaspaOutput> outputs;
    int lockTime = 0;
    std::string subnetworkId = "0000000000000000000000000000000000000000";
};

} // namespace TW

struct TWTransactionData {
    TW::Kaspa::TransactionData impl;
};
