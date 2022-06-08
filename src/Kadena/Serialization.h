// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../proto/Kadena.pb.h"
#include "Data.h"
#include <nlohmann/json.hpp>

namespace TW::Kadena {

    nlohmann::json transactionJSON(const Proto::SigningInput& input);
    nlohmann::json signedTransactionJSON(const std::string& cmd, const std::string& signature, const std::string& hash);

} // namespace
