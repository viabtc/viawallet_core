// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Base58Address.h"
#include "../PublicKey.h"

#include <array>
#include <cstdint>
#include <string>

namespace TW::Horizen {

class Address : public TW::Base58Address<22> {
  public:
    static const byte staticPrefix = 0x20;
    static const byte p2pkh = 0x89;
    static const byte p2sh = 0x96;

    /// Determines whether a string makes a valid ZCash address.
    static bool isValid(const std::string& string) {
        return TW::Base58Address<size>::isValid(string, {{staticPrefix, p2pkh}, {staticPrefix, p2sh}});
    }

    /// Determines whether a string makes a valid ZCash address, with possible prefixes.
    static bool isValid(const std::string& string, const std::vector<Data>& validPrefixes) {
        return TW::Base58Address<size>::isValid(string, validPrefixes);
    }

    /// Initializes a  address with a string representation.
    explicit Address(const std::string& string) : TW::Base58Address<size>(string) {}

    /// Initializes a  address with a collection of bytes.
    explicit Address(const Data& data) : TW::Base58Address<size>(data) {}

    /// Initializes a  address with a public key and a prefix (2nd byte).
    Address(const PublicKey& publicKey, uint8_t prefix = p2pkh) : TW::Base58Address<size>(publicKey, {staticPrefix, prefix}) {}

  private:
    Address() = default;
};

} // namespace TW::Horizen

struct TWHorizenAddress {
    TW::Horizen::Address impl;
};
