// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "ConfluxNetwork/Address.h"
#include "HDWallet.h"
#include "HexCoding.h"
#include "PrivateKey.h"
#include "PublicKey.h"
#include <Coin.h>
#include <gtest/gtest.h>
#include <vector>

using namespace TW;
using namespace TW::ConfluxNetwork;

TEST(ConfluxNetworkAddress, Valid) {
    ASSERT_TRUE(Address::isValid("cfx:aar4ekeaatt5s6808jmb8p0bmzrtevxazas5rhn083"));
    ASSERT_TRUE(Address::isValid("0x1ba2248003dfb773d6f2141f32c1555af24660a8"));
}

TEST(ConfluxNetworkAddress, Invalid) {
    ASSERT_FALSE(Address::isValid("cfx:aar4ekeaatt5s6808jmb8p0bmzrtevxazas5rhn08"));
    ASSERT_FALSE(Address::isValid("cfx:aar4ekeaatt5s6808jmb8p0bmzrtevxazas5rhn084"));
}

TEST(ConfluxNetworkAddress, FromPrivateKey) {
    const auto derivationPath = TW::derivationPath(TWCoinTypeConfluxNetwork);
    const auto wallet = HDWallet("hobby protect soda glow coconut make tip skate noodle venue crop check", "");
    const auto privateKey = wallet.getKey(TWCoinTypeConfluxNetwork, derivationPath);
    auto address = Address(privateKey.getPublicKey(TWPublicKeyTypeSECP256k1Extended));
    ASSERT_EQ(address.string(), "cfx:aar4ekeaatt5s6808jmb8p0bmzrtevxazas5rhn083");
}

TEST(ConfluxNetworkAddress, testEncode) {
    auto string = Address::encode("0x1ba2248003dfb773d6f2141f32c1555af24660a8");
    ASSERT_EQ(string, "cfx:aar4ekeaatt5s6808jmb8p0bmzrtevxazas5rhn083");
}

TEST(ConfluxNetworkAddress, testDecode) {
    auto decodeStr = Address::decode("cfx:aar4ekeaatt5s6808jmb8p0bmzrtevxazas5rhn083");
    ASSERT_EQ(decodeStr, "0x1ba2248003dfb773d6f2141f32c1555af24660a8");
}

