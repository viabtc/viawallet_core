// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWAnyAddress.h>
#include "HexCoding.h"

#include "../interface/TWTestUtilities.h"
#include <gtest/gtest.h>

using namespace TW;

TEST(TWNervosCKB, Address) {
    auto string = STRING("ckb1qyqrdsefa43s6m882pcj53m4gdnj4k440axqdt9rtd");
    auto addr = WRAP(TWAnyAddress, TWAnyAddressCreateWithString(string.get(), TWCoinTypeNervosCKB));
    auto keyHash = WRAPD(TWAnyAddressData(addr.get()));
    assertHexEqual(keyHash, "010036c329ed630d6ce750712a477543672adab57f4c");
}