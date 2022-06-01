// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Bitcoin/Amount.h"
#include "Script.h"

#include <memory>

namespace TW::Handshake {

/// Bitcoin transaction output.
struct TransactionOutput {
    /// Transaction amount.
    Bitcoin::Amount value;

    /// Usually contains the public key as a Bitcoin script setting up
    /// conditions to claim this output.
    Script script;

    /// Initializes an empty transaction output.
    TransactionOutput() = default;

    /// Initializes a transaction output with a value and a script.
    TransactionOutput(Bitcoin::Amount value, Script script) : value(value), script(std::move(script)) {}

    /// Encodes the output into the provided buffer.
    void encode(std::vector<uint8_t>& data) const;
};

} // namespace TW::Handshake

/// Wrapper for C interface.
struct TWHandshakeTransactionOutput {
    TW::Handshake::TransactionOutput impl;
};
