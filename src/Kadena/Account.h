// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <string>

namespace TW::Kadena {

class Account {
  public:
    /// Determines whether a string makes a valid Kadena account id.
    static bool isValid(const std::string& string);
};
}
