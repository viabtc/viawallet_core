// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Data.h"
#include "../PublicKey.h"
#include "Script.h"
#include "CKBConstant.h"

namespace TW::NervosCKB {

class Address {
public:
    /// Short Payload Format
    Data payload;

    /// Determines whether a string makes a valid address.
    static bool isValid(const std::string& string);

    /// Initializes a NervosCKB address with a string representation.
    explicit Address(const std::string& string);

    /// Initializes a NervosCKB address with a public key.
    explicit Address(const PublicKey& publicKey);

    /// Returns a string representation of the address.
    [[nodiscard]] std::string string() const;

    /// Returns public key hash
    [[nodiscard]] Data publicKeyHash() const {
        return subData(payload, 2, 20);
    }

    static std::string convertToBech32mFullAddress(const std::string& string);
};

inline bool operator==(const Address& lhs, const Address& rhs) {
    return lhs.payload == rhs.payload;
}

} // namespace TW::NervosCKB

/// Wrapper for C interface.
struct TWNervosCKBAddress {
    TW::NervosCKB::Address impl;
};
