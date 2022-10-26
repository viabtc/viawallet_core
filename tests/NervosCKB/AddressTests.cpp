// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "NervosCKB/Address.h"
#include "PublicKey.h"
#include "PrivateKey.h"
#include <gtest/gtest.h>

using namespace TW;
using namespace TW::NervosCKB;

TEST(NervosCKBAddress, Valid) {
    ASSERT_TRUE(Address::isValid("ckb1qyqp8eqad7ffy42ezmchkjyz54rhcqf8q9pqrn323p"));
}

TEST(NervosCKBAddress, Invalid) {
    ASSERT_FALSE(Address::isValid("ckb1qyqp8eqad7ffy42ezmchkjyz54rhcqf8q9pqrn3231"));
}

TEST(NervosCKBAddress, FromPrivateKey) {
    auto privateKey = PrivateKey(parse_hex("abe74a98f6c7eabee0428f53798f0ab8aa1bd37873999041703c742f15ac7e1e"));
    auto address = Address(privateKey.getPublicKey(TWPublicKeyTypeSECP256k1));
    ASSERT_EQ(address.string(), "ckb1qyqwhkr8v4n2ydfyl3kse5e93mhwvd67wnzs3g2psu");
}

TEST(NervosCKBAddress, FromPublicKey) {
    auto publicKey = PublicKey(parse_hex("0x024a501efd328e062c8675f2365970728c859c592beeefd6be8ead3d901330bc01"), TWPublicKeyTypeSECP256k1);
    auto address = Address(publicKey);
    ASSERT_EQ(address.string(), "ckb1qyqrdsefa43s6m882pcj53m4gdnj4k440axqdt9rtd");
}

TEST(NervosCKBAddress, FromString) {
    auto address = Address("ckb1qyqlqn8vsj7r0a5rvya76tey9jd2rdnca8lq2sg8su");
    ASSERT_EQ(address.string(), "ckb1qyqlqn8vsj7r0a5rvya76tey9jd2rdnca8lq2sg8su");
}

TEST(NervosCKBAddress, PublicKeyHash) {
    auto publicKey = PublicKey(parse_hex("0x024a501efd328e062c8675f2365970728c859c592beeefd6be8ead3d901330bc01"), TWPublicKeyTypeSECP256k1);
    auto address = Address(publicKey);
    ASSERT_EQ(hex(address.payload), "010036c329ed630d6ce750712a477543672adab57f4c");
}

TEST(NervosCKBAddress, ConvertToBech32mFullAddress) {
    const std::string& fullAddress =
        Address::convertToBech32mFullAddress("ckb1qyqrdsefa43s6m882pcj53m4gdnj4k440axqdt9rtd");
    ASSERT_EQ(fullAddress, "ckb1qzda0cr08m85hc8jlnfp3zer7xulejywt49kt2rr0vthywaa50xwsqfkcv576ccddnn4quf2ga65xee2m26h7nqmzxl9m");
}

TEST(NervosCKBAddress, Payload) {
    auto address = Address("ckb1qyqrdsefa43s6m882pcj53m4gdnj4k440axqdt9rtd");
    ASSERT_EQ(hex(address.payload), "010036c329ed630d6ce750712a477543672adab57f4c");
}