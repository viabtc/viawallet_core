// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "Kaspa/Address.h"
#include "PublicKey.h"
#include "PrivateKey.h"
#include <gtest/gtest.h>
#include <vector>

namespace TW::Kaspa::tests {

TEST(KaspaAddress, Valid) {
    ASSERT_TRUE(Address::isValid("kaspa:qpsqw2aamda868dlgqczeczd28d5nc3rlrj3t87vu9q58l2tugpjs2psdm4fv"));
}

TEST(KaspaAddress, Invalid) {
    ASSERT_FALSE(Address::isValid("qypu7vn4dkvv4pzhwy9gp5r6n80ym3c6wdfgpum5zpg6de8gznl9xnghhscjnpt"));
}

TEST(KaspaAddress, FromPrivateKey) {
    auto privateKey = PrivateKey(parse_hex("4a08d405f8db0f11010c41b7a51debb2baacb62b1ee0bdf23e0ec35973559de9"));
    auto address = Address(privateKey.getPublicKey(TWPublicKeyTypeSECP256k1));
    ASSERT_EQ(address.string(), "kaspa:qypu7vn4dkvv4pzhwy9gp5r6n80ym3c6wdfgpum5zpg6de8gznl9xnghhscjnpt");
}

TEST(KaspaAddress, FromPublicKey) {
    const auto publicKey =
        PublicKey(parse_hex("03cf32756d98ca8457710a80d07a99de4dc71a735280f3741051a6e4e814fe534d"),
                  TWPublicKeyTypeSECP256k1);
    auto address = Address(publicKey);
    ASSERT_EQ(address.string(), "kaspa:qypu7vn4dkvv4pzhwy9gp5r6n80ym3c6wdfgpum5zpg6de8gznl9xnghhscjnpt");
}

TEST(KaspaAddress, FromString) {
    auto address = Address("kaspa:qze6wl9gvt2gzkc24l78fl9vey27tw282utfr4rkafw6p3ps3wly7dnl38xq9");
    ASSERT_EQ(address.string(), "kaspa:qze6wl9gvt2gzkc24l78fl9vey27tw282utfr4rkafw6p3ps3wly7dnl38xq9");
}

} // namespace TW::Kaspa::tests
