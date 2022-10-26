// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "OutPoint.h"

namespace TW::NervosCKB {

    class CellDep {

    public:

        enum class DepType : byte {
            CODE,
            DEP_GROUP
        };

        OutPoint outPoint;

        DepType depType = DepType::CODE;

        CellDep() = default;

        CellDep(OutPoint outPoint, DepType depType) : outPoint(std::move(outPoint)), depType(depType) {}

        static CellDep secp256k1CellDep();
    };

} // namespace TW::NervosCKB

/// Wrapper for C interface.
struct TWNervosCKBCellDep {
    TW::NervosCKB::CellDep impl;
};
