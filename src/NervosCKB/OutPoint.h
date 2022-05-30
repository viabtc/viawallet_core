// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Type.h"

namespace TW::NervosCKB {

    class OutPoint {

    public:
        /// The hash of the transaction that this cell belongs to.
        H256 txHash;

        /// The index of the cell in its transaction's output list.
        uint32_t index{};

        OutPoint() = default;

        OutPoint(H256 txHash, uint32_t index) : txHash(std::move(txHash)), index(index) {}

        static OutPoint secp256k1OutPoint();
    };

} // namespace TW::NervosCKB

/// Wrapper for C interface.
struct TWNervosCKBOutPoint {
    TW::NervosCKB::OutPoint impl;
};
