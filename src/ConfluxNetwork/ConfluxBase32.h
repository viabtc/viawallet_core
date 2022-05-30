// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <string>
#include "Data.h"

namespace TW::ConfluxNetwork {

/// Entry point for implementation of ConfluxNetwork coin.
/// Note: do not put the implementation here (no matter how simple), to avoid having coin-specific includes in this file
class ConfluxBase32 {
public:
    static std::string encode(const Data& buffer);

    static Data decode(const std::string& base32Str);

    static bool isValid(const std::string& base32Str);

    static std::string createCheckSum(const std::string& chainPrefix, const std::string& payload);
};

} // namespace TW::ConfluxNetwork
