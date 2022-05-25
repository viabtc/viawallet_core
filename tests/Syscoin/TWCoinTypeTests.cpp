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


TEST(TWSyscoinCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeSyscoin));
    auto txId = TWStringCreateWithUTF8Bytes("t123");
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeSyscoin, txId));
    auto accId = TWStringCreateWithUTF8Bytes("a12");
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeSyscoin, accId));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeSyscoin));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeSyscoin));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeSyscoin), 8);
    ASSERT_EQ(TWBlockchainBitcoin, TWCoinTypeBlockchain(TWCoinTypeSyscoin));
    ASSERT_EQ(0x5, TWCoinTypeP2shPrefix(TWCoinTypeSyscoin));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeSyscoin));
    assertStringsEqual(symbol, "SYS");
    assertStringsEqual(txUrl, "https://sys1.bcfn.ca//tx/t123");
    assertStringsEqual(accUrl, "https://sys1.bcfn.ca//address/a12");
    assertStringsEqual(id, "syscoin");
    assertStringsEqual(name, "Syscoin");
}
