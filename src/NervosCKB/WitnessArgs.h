// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <utility>

#include "../Data.h"

namespace TW::NervosCKB {

    class WitnessArgs {
    public:
        enum class Type {
            DATA,
            PARSED
        };

        static const Data emptyLockHash;

        static const WitnessArgs emptyLock;

        static std::vector<WitnessArgs> witnessArgs(size_t size);

        Type type = Type::DATA;

        Data data;

        Data lock;

        Data inputType;

        Data outputType;

        WitnessArgs() = default;

        explicit WitnessArgs(Data data) : data(std::move(data)) {}

        WitnessArgs(Data lock, Data inputType, Data outputType) :
                type(Type::PARSED),
                lock(std::move(lock)),
                inputType(std::move(inputType)),
                outputType(std::move(outputType)) {}
    };

} // namespace TW::NervosCKB

/// Wrapper for C interface.
struct TWNervosCKBWitnessArgs {
    TW::NervosCKB::WitnessArgs impl;
};
