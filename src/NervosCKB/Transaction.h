// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Type.h"
#include "CellDep.h"
#include "CellInput.h"
#include "CellOutput.h"
#include "WitnessArgs.h"

namespace TW::NervosCKB {

    class Transaction {
    public:
        Version version;

        std::vector<CellDep> cellDeps;

        std::vector<H256> headerDeps;

        std::vector<CellInput> inputs;

        std::vector<CellOutput> outputs;

        std::vector<Data> outputsData;

        std::vector<Data> witnesses;

        std::vector<WitnessArgs> unsignedWitnesses;

        [[nodiscard]] Data hash() const;

        [[nodiscard]] std::vector<Data> serializeWitnessArgs() const;

        [[nodiscard]] size_t serializedSizeInBlock() const;

        static Capacity fee(size_t txSize, int64_t rate);

        [[nodiscard]] Capacity fee(int64_t rate) const;

        [[nodiscard]] Data messageHash() const;
    };

} // namespace TW::NervosCKB

/// Wrapper for C interface.
struct TWNervosCKBTransaction {
    TW::NervosCKB::Transaction impl;
};
