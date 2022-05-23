// Copyright © 2017-2021 Trust Wallet.
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


TEST(TWFreecashCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeFreecash));
    auto txId = WRAPS(TWStringCreateWithUTF8Bytes("t123"));
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeFreecash, txId.get()));
    auto accId = WRAPS(TWStringCreateWithUTF8Bytes("a12"));
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeFreecash, accId.get()));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeFreecash));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeFreecash));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeFreecash), 8);
    ASSERT_EQ(TWBlockchainBitcoin, TWCoinTypeBlockchain(TWCoinTypeFreecash));
    ASSERT_EQ(0x0, TWCoinTypeP2shPrefix(TWCoinTypeFreecash));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeFreecash));
    assertStringsEqual(symbol, "FCH");
    assertStringsEqual(txUrl, "https://explorer.viawallet.com/fch/tx/t123");
    assertStringsEqual(accUrl, "https://explorer.viawallet.com/fch/address/a12");
    assertStringsEqual(id, "freecash");
    assertStringsEqual(name, "Freecash");
}
