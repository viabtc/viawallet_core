// Copyright © 2017-2023 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Data.h"
#include "../PublicKey.h"

#include <string>

namespace TW::Kaspa {

class Address {
  public:
      enum AddressType: byte {
          schnorr = 0x0,
          ecdsa = 0x01,
          p2sh = 0x08
      };

      struct AddressComponents {
          AddressType type;
          Data hash;
          std::string prefix;
      };

      Data payload;
      /// Determines whether a string makes a valid address.
      static bool isValid(const std::string& string);
      /// Initializes a Kaspa address with a string representation.
      explicit Address(const std::string& string);
      /// Initializes a Kaspa address with a public key.
      explicit Address(const PublicKey& publicKey);
      /// Returns a string representation of the address.
      std::string string() const;
      /// parse AddressType
      static AddressComponents parse(const std::string& string);
};

inline bool operator==(const Address& lhs, const Address& rhs) {
    return lhs.payload == rhs.payload;
}

} // namespace TW::Kaspa
