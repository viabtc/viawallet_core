// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Bitcoin/Script.h"
#include "Bitcoin/Amount.h"

namespace TW::SimpleLedger {

    class Script: public Bitcoin::Script {
    public:
        /// Builds a simple ledger token script from a script hash.
        static Script buildSimpleLedgerTokenSend(const Data& tokenId, const std::vector<Bitcoin::Amount>& values);
    };
}