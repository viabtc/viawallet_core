// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Data.h"
#include "../PrivateKey.h"
#include "../proto/Ergo.pb.h"

namespace TW::Ergo {

/// Helper class that performs Ergo transaction signing.
class Signer {
public:
    /// Hide default constructor
    Signer() = delete;

    /// Signs a Proto::SigningInput transaction
    static Proto::SigningOutput sign(const Proto::SigningInput& input) noexcept;

    /// Sign serialize transaction
    static Data sign(const Data& msg, const Data& key) noexcept;

    /// Generate commitment
    static Data genCommitment(const Data& pk, const Data& w) noexcept;

};

} // namespace TW::Ergo
