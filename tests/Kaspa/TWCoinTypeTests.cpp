// Copyright © 2017-2022 Trust Wallet.
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


TEST(TWKaspaCoinType, TWCoinType) {
    const auto coin = TWCoinTypeKaspa;
    const auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(coin));
    const auto id = WRAPS(TWCoinTypeConfigurationGetID(coin));
    const auto name = WRAPS(TWCoinTypeConfigurationGetName(coin));
    const auto txId = WRAPS(TWStringCreateWithUTF8Bytes("t123"));
    const auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(coin, txId.get()));
    const auto accId = WRAPS(TWStringCreateWithUTF8Bytes("a12"));
    const auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(coin, accId.get()));

    assertStringsEqual(id, "kaspa");
    assertStringsEqual(name, "Kaspa");
    assertStringsEqual(symbol, "KAS");
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(coin), 8);
    ASSERT_EQ(TWCoinTypeBlockchain(coin), TWBlockchainKaspa);
    ASSERT_EQ(TWCoinTypeP2shPrefix(coin), 0x0);
    ASSERT_EQ(TWCoinTypeStaticPrefix(coin), 0x0);
    assertStringsEqual(txUrl, "https://explorer.kaspa.org//txs/t123");
    assertStringsEqual(accUrl, "https://explorer.kaspa.org//address/a12");
}
