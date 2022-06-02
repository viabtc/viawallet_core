// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.


#pragma once

#include <nlohmann/json.hpp>
#include "../Data.h"
#include "../PrivateKey.h"
#include "../proto/Mina.pb.h"

namespace TW::Mina {

/// Helper class that performs Mina transaction signing.
class Signer {
public:
    /// Hide default constructor
    Signer() = delete;

    /// Signs a Proto::SigningInput transaction
    static Proto::SigningOutput sign(const Proto::SigningInput& input) noexcept;


    static nlohmann::json transactionJSON(
                         const std::string& field,
                         const std::string& scalar,
                         const std::string& to,
                         const std::string& from,
                         uint64_t fee,
                         uint64_t amount,
                         uint32_t nonce,
                         const std::string& memo,
                         uint64_t validUntil);

};

} // namespace TW::Mina

/// Wrapper for C interface.
struct TWMinaSigner {
    TW::Mina::Signer impl;
};
