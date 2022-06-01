// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "PrivateKey.h"
#include "PublicKey.h"
#include "Handshake/Script.h"
#include <Bitcoin/SegwitAddress.h>
#include <Coin.h>
#include <HDWallet.h>
#include <gtest/gtest.h>
#include <vector>
#include <TrezorCrypto/ecdsa.h>

using namespace TW;

TEST(HandshakeAddress, FromMnemonic) {

    auto mnemonic = "hobby protect soda glow coconut make tip skate noodle venue crop check";
    auto wallet = HDWallet(mnemonic, "");

    PrivateKey privKey0 = wallet.getKey(TWCoinTypeHandshake, DerivationPath("m/44'/5353'/0'/0/0"));
    PublicKey pubKey0 = privKey0.getPublicKey(TWPublicKeyTypeSECP256k1);
    auto addr0 = Bitcoin::SegwitAddress(pubKey0, 0, "hs", HasherType::HASHER_BLAKE2B);

    EXPECT_EQ("hs1qucnsnmnhp6el5js76vhcvfm8ukfkrazgnf97wv", addr0.string());
}

TEST(HandshakeAddress, FromMnemonic1) {

    auto coin = TWCoinTypeHandshake;
    auto ownAddress = "hs1qucnsnmnhp6el5js76vhcvfm8ukfkrazgnf97wv";

    auto utxo0Script = Handshake::Script::lockScriptForAddress(ownAddress, coin);

    auto addr0 = Bitcoin::SegwitAddress("hs", 0, utxo0Script.hash());

    EXPECT_EQ("hs1q96ltgtm850qge6k2yjwaqz438jr2cjtp8tu6drlgx3ftyeg78whqps2xap", addr0.string());
}

TEST(HandshakeAddress, ValidateAddress0) {
    bool valid = Bitcoin::SegwitAddress::isValid("hs1qucnsnmnhp6el5js76vhcvfm8ukfkrazgnf97wv");
    EXPECT_EQ(true, valid);
}

TEST(HandshakeAddress, ValidateAddress1) {
    bool valid = TW::validateAddress(TWCoinTypeHandshake, "hs1qleh3ynkuvlpqwq4dltcj2lsgqenyrhhzf7uvrk");
    EXPECT_EQ(true, valid);
}

TEST(HandshakeAddress, ValidateAddress2) {
    bool valid = TW::validateAddress(TWCoinTypeHandshake, "hs1q6htdfahajgexq34ga5hh9kurc8f5amkp3t2x55pc5v6qsq2t20vs7et84l");
    EXPECT_EQ(true, valid);
}
