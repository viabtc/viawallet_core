// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "Ergo/Address.h"
#include "PublicKey.h"
#include "PrivateKey.h"
#include <gtest/gtest.h>
#include <vector>

using namespace TW;
using namespace TW::Ergo;

TEST(ErgoAddress, Valid) {
    ASSERT_TRUE(Address::isValid("9heVCt2LBsXoBsfSoxK4FNAATzwGdATPERtdA79HiQUFf8HT1fU"));
    ASSERT_TRUE(Address::isValid("88dhgzEuTXaSBHLJTHU5FZrsrhjPe2smA1HnnDbBDiAMjuQHw2A4JoRWQ68nJeK7dAFPUbYaFXStXWcE"));
    ASSERT_TRUE(Address::isValid("2Z4YBkDsDvQj8BX7xiySFewjitqp2ge9c99jfes2whbtKitZTxdBYqbrVZUvZvKv6aqn9by4kp3LE1c26LCyosFnVnm6b6U1JYvWpYmL2ZnixJbXLjWAWuBThV1D6dLpqZJYQHYDznJCk49g5TUiS4q8khpag2aNmHwREV7JSsypHdHLgJT7MGaw51aJfNubyzSKxZ4AJXFS27EfXwyCLzW1K6GVqwkJtCoPvrcLqmqwacAWJPkmh78nke9H4oT88XmSbRt2n9aWZjosiZCafZ4osUDxmZcc5QVEeTWn8drSraY3eFKe8Mu9MSCcVU"));
}

TEST(ErgoAddress, Invalid) {
    ASSERT_FALSE(Address::isValid("1FGRdbPWNzFuwEQ9o1gVXqU4b1Hp6adpZM"));
    ASSERT_FALSE(Address::isValid(""));
    ASSERT_FALSE(Address::isValid("fasfDFSFDSFd"));
    ASSERT_FALSE(Address::isValid(","));
    ASSERT_FALSE(Address::isValid("雍"));
}

TEST(ErgoAddress, FromPrivateKey) {
    const auto privateKey = PrivateKey(parse_hex("39fdd21cf21d02457fa1237355cd4213888f4e339d9b6e37c0b77b2cbf013d4b"));
    const auto publicKey = privateKey.getPublicKey(TWPublicKeyTypeSECP256k1);
    auto address = Address(publicKey);
    ASSERT_EQ(address.string(), "9heVCt2LBsXoBsfSoxK4FNAATzwGdATPERtdA79HiQUFf8HT1fU");
}

TEST(ErgoAddress, FromPublicKey) {
    auto publicKey = PublicKey(parse_hex("039bf301d5e564bf16ea65e6d6780978e3706787e316c4b8d2054d3979f25c4a7d"), TWPublicKeyTypeSECP256k1);
    auto address = Address(publicKey);
    ASSERT_EQ(address.string(), "9heVCt2LBsXoBsfSoxK4FNAATzwGdATPERtdA79HiQUFf8HT1fU");
}

TEST(ErgoAddress, FromString) {
    auto address = Address("9heVCt2LBsXoBsfSoxK4FNAATzwGdATPERtdA79HiQUFf8HT1fU");
    ASSERT_EQ(address.string(), "9heVCt2LBsXoBsfSoxK4FNAATzwGdATPERtdA79HiQUFf8HT1fU");
}
