// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Script.h"

namespace TW::NervosCKB {

    class CellOutput {

    public:

        /// The size of the cell (in shannons).
        Capacity capacity = 0;

        /// A Script that defines the ownership of the cell
        Script lock;

        /// A Script that defines the type of the cell.
        Script type;

        /// Initializes an empty cell output.
        CellOutput() = default;

        CellOutput(Capacity capacity, Script lock, Script type = Script())
                : capacity(capacity), lock(std::move(lock)), type(std::move(type)) {}
    };

} // namespace TW::NervosCKB

/// Wrapper for C interface.
struct TWNervosCKBCellOutput {
    TW::NervosCKB::CellOutput impl;
};
