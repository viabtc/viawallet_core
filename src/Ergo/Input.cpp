// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Input.h"

using namespace TW::Ergo;

nlohmann::json Input::toJson() {
    auto json = nlohmann::json();
    json["spendingProof"] = spendingProof.toJson();
    json["boxId"] = boxId;
    return json;
}
