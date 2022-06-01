// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.


#pragma once

#include "Bitcoin/Script.h"

namespace TW::Horizen {

class Script: public Bitcoin::Script {
  public:
    /// Initializes an empty script.
    Script() = default;

    /// Initializes a script with a collection of raw bytes.
    template <typename It>
    Script(It begin, It end) : Bitcoin::Script(begin, end) {}

    /// Initializaes a script with a collection of raw bytes by moving.
    explicit Script(const Data& bytes) : Bitcoin::Script(bytes) {}

  public:
    /// Builds a appropriate lock script for the given zen address.
    static Script lockScriptForAddress(const std::string& address, uint32_t block_height, const std::string& block_hash);

    /// Builds a pay-to-public-key-hash script from a public key hash.
    static Script buildPublicKeyHash(const Data& data, const Data& block_height, const Data& block_hash);

    /// Builds a pay-to-script-hash script from a script hash.
    static Script buildScriptHash(const Data& data, const Data& block_height, const Data& block_hash);

    /// Matches the script to a pay-to-public-key-hash (P2PKH).
    bool matchPayToPublicKeyHash(Data& result);
};
}
