// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "../src/HexCoding.h"
#include "PrivateKey.h"
#include "PublicKey.h"
#include "Horizen/Address.h"
#include <gtest/gtest.h>
#include <vector>
#include "HDWallet.h"

using namespace TW;
using namespace TW::Horizen;

TEST(HorizenAddress, FromPrivateKey) {
    auto privateKey = PrivateKey(parse_hex("2ff1cc7fa8ed5e711a53bca17574b8a4dac9011de4f14f5754e00723e534fc38"));
    auto address = Address(privateKey.getPublicKey(TWPublicKeyTypeSECP256k1));
    ASSERT_EQ(address.string(), "znk9bBKhf4YwqkNZu6QLcXyeSFqxfCFQLoK");
}

TEST(HorizenAddress, FromMnemonic) {
    const auto mnemonic = "hobby protect soda glow coconut make tip skate noodle venue crop check";
    const auto wallet = HDWallet(mnemonic, "");

    PrivateKey privKey0 = wallet.getKey(TWCoinTypeHorizen, DerivationPath("m/44'/121'/0'/0/0"));
    PublicKey pubKey0 = privKey0.getPublicKey(TWPublicKeyTypeSECP256k1);
    auto addr0 = Address(pubKey0);

    EXPECT_EQ("znk9bBKhf4YwqkNZu6QLcXyeSFqxfCFQLoK", addr0.string());
}