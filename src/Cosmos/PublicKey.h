// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <string>
#include "../Data.h"

namespace TW::Cosmos {

    class PublicKey {

        public:

            /// Human-readable part.
            std::string hrp;

            /// Public key data.
            Data data;

            /// Initializes an public key with human-readable part and data.
            PublicKey(std::string hrp, Data data) : hrp(std::move(hrp)), data(std::move(data)) {}

            /// Decodes an public key.
            ///
            /// \returns a pair with the public key and a success flag.
            static std::pair<PublicKey, bool> decode(const std::string& publicKey);

            /// Encodes the public key.
            ///
            /// \returns encoded public key string, or empty string on failure.
            std::string string() const;

            bool operator==(const PublicKey& rhs) const { return hrp == rhs.hrp && data == rhs.data; }
    };

} // namespace TW::Cosmos

/// Wrapper for C interface.
struct TWCosmosPublicKey {
    TW::Cosmos::PublicKey impl;
};