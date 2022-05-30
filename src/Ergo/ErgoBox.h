// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "HexCoding.h"
#include "Address.h"
#include "../Data.h"
#include "../proto/Ergo.pb.h"
#include <array>
#include <cstring>
#include <utility>
#include <nlohmann/json.hpp>

namespace TW::Ergo {

/// ErgoBox class.
class ErgoBox {
  public:

    /// The boxId of the specific ErgoBox.
    std::string boxId = "";

    /// The value of the specific ErgoBox.
    uint64_t value;

    /// The creationHeight of the specific ErgoBox.
    uint32_t creationHeight;

    /// The address of the specific ErgoBox.
    std::string address = "";

    /// The ergoTree of the specific ErgoBox.
    std::string ergoTree = "";

    ErgoBox(const Proto::ErgoBox& other)
            : boxId(other.boxid())
            , value(other.value())
            , creationHeight(other.creationheight())
            , address(other.address()) {}

    ErgoBox(std::string  boxId, const uint64_t value, const uint32_t creationHeight, const std::string& address)
            : boxId(std::move(boxId))
            , value(value)
            , creationHeight(creationHeight)
            , address(address)
            , ergoTree(hex(Address(address).ergoTree())) {}

    /// Saves `this` as a JSON object.
    nlohmann::json toJson();
};

} // namespace TW::Ergo
