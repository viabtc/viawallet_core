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


TEST(TWErgoCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeErgo));
    auto txId = TWStringCreateWithUTF8Bytes("t123");
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeErgo, txId));
    auto accId = TWStringCreateWithUTF8Bytes("a12");
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeErgo, accId));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeErgo));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeErgo));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeErgo), 9);
    ASSERT_EQ(TWBlockchainErgo, TWCoinTypeBlockchain(TWCoinTypeErgo));
    ASSERT_EQ(TWCoinTypeErgo, TWCoinType(TWCoinTypeErgo));
    assertStringsEqual(symbol, "ERG");
    assertStringsEqual(txUrl, "https://explorer.ergoplatform.com/en//transactionst123");
    assertStringsEqual(accUrl, "https://explorer.ergoplatform.com/en//addresses/a12");
    assertStringsEqual(id, "ergo");
    assertStringsEqual(name, "Ergo");
}
