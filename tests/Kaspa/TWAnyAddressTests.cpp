// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWAnyAddress.h>
#include "HexCoding.h"
#include "../interface/TWTestUtilities.h"
#include <gtest/gtest.h>

using namespace TW;

// TODO: Finalize tests

TEST(TWKaspa, Address) {
    auto string = STRING("kaspa:qypu7vn4dkvv4pzhwy9gp5r6n80ym3c6wdfgpum5zpg6de8gznl9xnghhscjnpt");
    auto addr = WRAP(TWAnyAddress, TWAnyAddressCreateWithString(string.get(), TWCoinTypeKaspa));
    auto string2 = WRAPS(TWAnyAddressDescription(addr.get()));
    EXPECT_TRUE(TWStringEqual(string.get(), string2.get()));
}
