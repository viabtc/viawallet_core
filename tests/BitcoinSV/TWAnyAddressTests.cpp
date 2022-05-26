// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWAnyAddress.h>
#include "Bitcoin/Address.h"
#include "HexCoding.h"
#include "PrivateKey.h"
#include "Coin.h"

#include "../interface/TWTestUtilities.h"
#include <gtest/gtest.h>

using namespace TW;

TEST(TWBitcoinSV, Valid) {
    auto address = "1BvBMSEYstWetqTFn5Au4m4GFg7xJaNVN2";
    auto fakeAddress = "qq07l6rr5lsdm3m80qxw80ku2ex0tj76vvsxpvmgme";
    ASSERT_TRUE(Bitcoin::Address::isValid(std::string(address)));
    ASSERT_FALSE(Bitcoin::Address::isValid(std::string(fakeAddress)));
    ASSERT_TRUE(TWAnyAddressIsValid(STRING(address).get(), TWCoinTypeBitcoinSV));
}

TEST(TWBitcoinSV, PubkeyToAddress) {
    auto address = "19RZZgV1uLsC7LVFZBW3x3mN1ABCV3qgGu";
    auto key = "CA6D1402199530A5D610A01A53505B6A344CF61B0CCB2902D5AEFBEA63C274BB";
    const auto privateKey = PrivateKey(parse_hex(key));
    const auto publicKey = privateKey.getPublicKey(TWPublicKeyTypeSECP256k1);

    /// construct with public key
    auto result = Bitcoin::Address(PublicKey(publicKey), p2pkhPrefix(TWCoinTypeBitcoinSV));
    ASSERT_EQ(result.string(), address);
}

TEST(TWBitcoinSV, AnyAddress) {

    auto privateKey = WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(DATA("ba0828d5734b65e3bcc2c51c93dfc26dd71bd666cc0273adee77d73d9a322035").get()));
    ASSERT_NE(nullptr, privateKey.get());
    auto publicKey = TWPrivateKeyGetPublicKeySecp256k1(privateKey.get(), true);
    ASSERT_NE(nullptr, publicKey);
    ASSERT_EQ(33, publicKey->impl.bytes.size());
    auto address = WRAP(TWAnyAddress, TWAnyAddressCreateWithPublicKey(publicKey, TWCoinTypeBitcoinSV));
    auto addressString = WRAPS(TWAnyAddressDescription(address.get()));
    assertStringsEqual(addressString, "193vV6Mdk2r5ieB7nSSpzWuoxjWrXNpVkJ");
}