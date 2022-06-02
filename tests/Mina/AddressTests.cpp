// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "Mina/Address.h"
#include "PrivateKey.h"
#include "PublicKey.h"
#include <HDWallet.h>
#include <gtest/gtest.h>
#include <vector>

using namespace TW;
using namespace TW::Mina;

TEST(MinaAddress, Valid) {
    ASSERT_TRUE(Address::isValid("B62qng4Q3NBfiwKRDctBrdQ6iAKTLFCEoXHz9wdTzG6kBh48p5Mf5EU"));
}

TEST(MinaAddress, Invalid) {
    ASSERT_FALSE(Address::isValid("B62qng4Q3NBfiwKRDctBrdQ6iAKTLFCEoXHz9wdTzG6kBh48p5Mf5EA"));
}

TEST(MinaAddress, FromPrivateKey) {
    auto privateKey = PrivateKey(parse_hex("1f8a33418070dce124003b3b287853969d5f21f869091c8d881e0cac8073064a"));
    auto address = Address(privateKey.getPublicKey(TWPublicKeyTypeMina));
    ASSERT_EQ(address.string(), "B62qng4Q3NBfiwKRDctBrdQ6iAKTLFCEoXHz9wdTzG6kBh48p5Mf5EU");
}

TEST(MinaAddress, FromPublicKey) {
    auto data = parse_hex("cb01017de6897948db6afdf6efba13ad694d329f33f6d6a54b7be3cd2571ffda68fa2f01");
    auto publicKey = PublicKey(data, TWPublicKeyTypeMina);
    auto address = Address(publicKey);
    ASSERT_EQ(address.string(), "B62qng4Q3NBfiwKRDctBrdQ6iAKTLFCEoXHz9wdTzG6kBh48p5Mf5EU");
}

TEST(MinaAddress, FromString) {
    auto address = Address("B62qng4Q3NBfiwKRDctBrdQ6iAKTLFCEoXHz9wdTzG6kBh48p5Mf5EU");
    ASSERT_EQ(address.string(), "B62qng4Q3NBfiwKRDctBrdQ6iAKTLFCEoXHz9wdTzG6kBh48p5Mf5EU");
}


TEST(MinaAddress, FromMnemonic) {
    const auto wallet = HDWallet("shoot island position soft burden budget tooth cruel issue economy destroy above", "");
    const auto privateKey = wallet.getKey(TWCoinTypeMina, DerivationPath("m/44'/12586'/0'/0/0"));
    auto address = Address(privateKey.getPublicKey(TWPublicKeyTypeMina));
    ASSERT_EQ(address.string(), "B62qkZY3vEc5TAgQf7PA38ra1ivTFE55oV1mePMBkdkTYwnFSF4DadQ");
}

