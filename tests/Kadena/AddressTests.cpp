// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "Kadena/Address.h"
#include "Kadena/Account.h"
#include "PublicKey.h"
#include "PrivateKey.h"
#include "HDWallet.h"
#include <gtest/gtest.h>
#include <vector>
#include <TrezorCrypto/kadena/kadena_encrypted_sign.h>

using namespace TW;
using namespace TW::Kadena;

TEST(KadenaAddress, Valid) {

    ASSERT_TRUE(Address::isValid("k:11cde3a2ca5ca752318158e267c1eedb9b001914906cc0bb2ca4c72604ea1e80"));

    ASSERT_TRUE(Account::isValid("alice"));
}

TEST(KadenaAddress, Invalid) {

    ASSERT_FALSE(Address::isValid("11cde3a2ca5ca752318158e267c1eedb9b001914906cc0bb2ca4c72604ea1e80"));

    ASSERT_FALSE(Address::isValid("al"));
}

TEST(KadenaAddress, FromPrivateKey) {

    auto privateKey = PrivateKey(parse_hex("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));

    auto publicKey = privateKey.getPublicKey(TWPublicKeyTypeED25519);

    auto address = Address(publicKey);

    ASSERT_EQ(address.string(), "k:e734ea6c2b6257de72355e472aa05a4c487e6b463c029ed306df2f01b5636b58");
}

TEST(KadenaAddress, FromPublicKey) {

    auto publicKey = PublicKey(parse_hex("e734ea6c2b6257de72355e472aa05a4c487e6b463c029ed306df2f01b5636b58"), TWPublicKeyTypeED25519);
    auto address = Address(publicKey);
    ASSERT_EQ(address.string(), "k:e734ea6c2b6257de72355e472aa05a4c487e6b463c029ed306df2f01b5636b58");
}

TEST(KadenaAddress, FromString) {

    auto address = Address("k:11cde3a2ca5ca752318158e267c1eedb9b001914906cc0bb2ca4c72604ea1e80");

    ASSERT_EQ(address.string(), "k:11cde3a2ca5ca752318158e267c1eedb9b001914906cc0bb2ca4c72604ea1e80");
}
