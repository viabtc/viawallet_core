// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../proto/Ergo.pb.h"
#include "SpendingProof.h"
#include <cstring>
#include <utility>
#include <nlohmann/json.hpp>

namespace TW::Ergo {

/// Input class.
class Input {
  public:
    /// The boxId of the specific Input.
    std::string boxId = "";

    /// The spendingProof the specific Input.
    SpendingProof spendingProof;

    Input(std::string boxId)
    : boxId(std::move(boxId)){}

    Input(std::string boxId, SpendingProof& spendingProof)
    : boxId(std::move(boxId))
    , spendingProof(spendingProof) {}

    /// Saves `this` as a JSON object.
    nlohmann::json toJson();
};

} // namespace TW::Ergo
