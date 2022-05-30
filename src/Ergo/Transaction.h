// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Data.h"
#include <utility>
#include <vector>
#include "Input.h"
#include "ErgoBox.h"
#include <nlohmann/json.hpp>

namespace TW::Ergo {

struct Transaction {
public:

    /// A list of transaction inputs
    std::vector<Input> inputs;

    /// A list of transaction outputs
    std::vector<ErgoBox> outputs;

    /// A list of dataInputs
    std::vector<Input> dataInputs;

public:
    Transaction() = default;

    Transaction(std::vector<Input>& inputs, std::vector<ErgoBox>& outputs, std::vector<Input>& dataInputs)
        :  inputs(inputs), outputs(outputs), dataInputs(dataInputs) {}

    /// Variable-length quantity
    uint8_t encodeVarInt(uint64_t num, Data& data);

    /// Serialize `this` as Data.
    Data serialize();

    /// Saves `this` as a JSON object.
    nlohmann::json toJson();

};

} // namespace TW::Ergo

