// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Bitcoin/Address.h"
#include "PrivateKey.h"
#include "PublicKey.h"
#include "HexCoding.h"
#include "Coin.h"
#include <gtest/gtest.h>
#include <TrustWalletCore/TWAnyAddress.h>

using namespace TW;

TEST(LBRYCreditsAddress, Valid) {
    ASSERT_TRUE(Bitcoin::Address::isValid(std::string("bGWjnk8zwTuvs4giWfW5V7NnbWtPwxpxuJ")));
    ASSERT_TRUE(Bitcoin::Address::isValid(std::string("bLTP2Y1sJDYBmHi69TN4uiyXQJJh5aTT37")));
    ASSERT_TRUE(Bitcoin::Address::isValid(std::string("bHaZvWkpiUm9V5reC8ZQqvdFTgAD4caLUu")));
}

TEST(LBRYCreditsAddress, Invalid) {
    ASSERT_FALSE(Bitcoin::Address::isValid(std::string("gbGWjnk8zwTuvs4giWfW5V7NnbWtPwxpxuJ")));
}

TEST(LBRYCreditsAddress, FromPrivateKey) {
    auto privateKey = PrivateKey(parse_hex("4F05FE1EE7166229BC2567DE0FBDE73E73236E81B3BEA31E5C5C1CFFA80950A5"));
    const auto publicKey = privateKey.getPublicKey(TWPublicKeyTypeSECP256k1);
    auto address = Bitcoin::Address(PublicKey(publicKey), p2pkhPrefix(TWCoinTypeLBRYCredits));
    ASSERT_EQ(address.string(), "bFcmTueazsFZrkj1V8LqCF4MjUZnDGvdrV");
}


TEST(LBRYCreditsAddress, FromPublicKey) {
    auto publicKey = PublicKey(parse_hex("0214CF9D9444D886C3D9379027CAE6BF81D1BD4143683F5B3BFD22B57C7612572E"), TWPublicKeyTypeSECP256k1);
    auto address = Bitcoin::Address(PublicKey(publicKey), p2pkhPrefix(TWCoinTypeLBRYCredits));
    ASSERT_EQ(address.string(), "bFcmTueazsFZrkj1V8LqCF4MjUZnDGvdrV");
}

TEST(LBRYCreditsAddress, FromString) {
    auto address = Bitcoin::Address("bFcmTueazsFZrkj1V8LqCF4MjUZnDGvdrV");
    ASSERT_EQ(address.string(), "bFcmTueazsFZrkj1V8LqCF4MjUZnDGvdrV");
}
