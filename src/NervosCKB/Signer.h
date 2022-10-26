// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Data.h"
#include "../PrivateKey.h"
#include "../proto/NervosCKB.pb.h"

namespace TW::NervosCKB {

    /// Helper class that performs NervosCKB transaction signing.
    class Signer {
    public:
        /// Hide default constructor
        Signer() = delete;

        /// Returns a transaction plan (cell selection, fee estimation)
        static Proto::TransactionPlan plan(const Proto::SigningInput &input) noexcept;

        /// Signs a Proto::SigningInput transaction
        static Proto::SigningOutput sign(const Proto::SigningInput &input) noexcept;
    };

} // namespace TW::NervosCKB

/// Wrapper for C interface.
struct TWNervosCKBSigner {
    TW::NervosCKB::Signer impl;
};
