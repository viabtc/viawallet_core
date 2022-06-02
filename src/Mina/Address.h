// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Data.h"
#include "../PublicKey.h"

#include <string>

namespace TW::Mina {

class Address {
  public:

    /// Number of bytes in Mina address
    static const size_t size = PublicKey::minaSize;;

    /// Address data
    std::array<byte, size> bytes;

    /// Determines whether a string makes a valid address.
    static bool isValid(const std::string& string);

    /// Initializes a Mina address with a string representation.
    explicit Address(const std::string& string);

    /// Initializes a Mina address with a public key.
    explicit Address(const PublicKey& publicKey);

    /// Returns a string representation of the address.
    std::string string() const;
};

inline bool operator==(const Address& lhs, const Address& rhs) {
    return lhs.bytes == rhs.bytes;
}

} // namespace TW::Mina

/// Wrapper for C interface.
struct TWMinaAddress {
    TW::Mina::Address impl;
};
