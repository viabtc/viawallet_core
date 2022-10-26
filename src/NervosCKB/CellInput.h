// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "OutPoint.h"

namespace TW::NervosCKB {

    class CellInput {

    public:
        /// A cell outpoint that point to the cells used as inputs.
        OutPoint previousOutput;

        /// Since value guarding current referenced inputs.
        uint64_t since{};

        Capacity capacity{};

        CellInput() = default;

        CellInput(OutPoint previousOutput, std::uint64_t since, Capacity capacity = 0) :
                previousOutput(std::move(previousOutput)),
                since(since),
                capacity(capacity) {}
    };

} // namespace TW::NervosCKB

/// Wrapper for C interface.
struct TWNervosCKBCellInput {
    TW::NervosCKB::CellInput impl;
};
