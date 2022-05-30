// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../proto/Ergo.pb.h"
#include <cstring>
#include <utility>
#include <nlohmann/json.hpp>

namespace TW::Ergo {

/// SpendingProof class.
class SpendingProof {
  public:

    /// The proof bytes.
    std::string proofBytes = "";

    SpendingProof() {}

    SpendingProof(std::string& proofBytes)
            : proofBytes(proofBytes) {}

    /// Saves `this` as a JSON object.
    nlohmann::json toJson();

};
} // namespace TW::Ergo
