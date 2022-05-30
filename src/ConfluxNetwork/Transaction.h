// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Address.h"
#include "../uint256.h"

namespace TW::ConfluxNetwork {

class Transaction {
  public:
    uint256_t nonce;
    uint256_t gasPrice;
    uint256_t gasLimit;
    // Public key hash (Address.bytes)
    Data to;
    uint256_t amount;
    uint256_t storageLimit;
    uint256_t epochHeight;
    uint256_t chainId;
    Data payload;

    // Signature values
    uint256_t v = uint256_t();
    uint256_t r = uint256_t();
    uint256_t s = uint256_t();

    Transaction(uint256_t nonce, uint256_t gasPrice, uint256_t gasLimit, const Data& to,
                uint256_t amount, uint256_t storageLimit, uint256_t epochHeight, uint256_t chainId, Data payload)
        : nonce(std::move(nonce))
        , gasPrice(std::move(gasPrice))
        , gasLimit(std::move(gasLimit))
        , to(std::move(to))
        , amount(std::move(amount))
        , storageLimit(std::move(storageLimit))
        , epochHeight(std::move(epochHeight))
        , chainId(std::move(chainId))
        , payload(std::move(payload)) {}
};

} // namespace TW::ConfluxNetwork
