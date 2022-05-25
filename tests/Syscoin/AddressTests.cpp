// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HDWallet.h"
#include "HexCoding.h"
#include "PrivateKey.h"
#include "PublicKey.h"
#include <Coin.h>
#include <gtest/gtest.h>
#include <vector>

#include "Bitcoin/Address.h"
#include "Bitcoin/SegwitAddress.h"

using namespace TW;
using namespace TW::Bitcoin;


TEST(SyscoinAddress, FromPrivateKey) {
    const auto derivationPath = TW::derivationPath(TWCoinTypeSyscoin);
    const auto wallet = HDWallet("hobby protect soda glow coconut make tip skate noodle venue crop check", "");
    const auto privateKey = wallet.getKey(TWCoinTypeSyscoin, derivationPath);
    const auto publicKey = privateKey.getPublicKey(TWPublicKeyTypeSECP256k1);

    auto address = Bitcoin::Address(PublicKey(publicKey), p2pkhPrefix(TWCoinTypeSyscoin));
    ASSERT_EQ(address.string(), "SUjs9R9TR3q6QrgwaaP8CwJWWbPMJGJqCF");
}

TEST(SyscoinAddress, ValidateAddress) {
    EXPECT_EQ(true, Bitcoin::SegwitAddress::isValid("sys1q2yg8dcl8vtw6vw94ylgds4kt239q4xmzw9yn60"));
}