// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here MAY BE LOST.
// Generated one-time (codegen/bin/cointests)
//

#include "../interface/TWTestUtilities.h"
#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <gtest/gtest.h>


TEST(HorizenCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeHorizen));
    auto txId = TWStringCreateWithUTF8Bytes("t123");
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeHorizen, txId));
    auto accId = TWStringCreateWithUTF8Bytes("a12");
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeHorizen, accId));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeHorizen));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeHorizen));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeHorizen), 8);
    ASSERT_EQ(TWBlockchainHorizen, TWCoinTypeBlockchain(TWCoinTypeHorizen));
    ASSERT_EQ(0x96, TWCoinTypeP2shPrefix(TWCoinTypeHorizen));
    ASSERT_EQ(0x20, TWCoinTypeStaticPrefix(TWCoinTypeHorizen));
    assertStringsEqual(symbol, "ZEN");
    assertStringsEqual(txUrl, "https://explorer.zensystem.io//tx/t123");
    assertStringsEqual(accUrl, "https://explorer.zensystem.io//address/a12");
    assertStringsEqual(id, "horizen");
    assertStringsEqual(name, "Horizen");
}
