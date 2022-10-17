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


TEST(TWAptosCoinType, TWCoinType) {
    const auto coin = TWCoinTypeAptos;
    const auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(coin));
    const auto id = WRAPS(TWCoinTypeConfigurationGetID(coin));
    const auto name = WRAPS(TWCoinTypeConfigurationGetName(coin));
    const auto txId = WRAPS(TWStringCreateWithUTF8Bytes("91424546"));
    const auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(coin, txId.get()));
    const auto accId = WRAPS(TWStringCreateWithUTF8Bytes("0x6af7d07b8a541913dfa87a9f99628faa255c70241ef9ebd9b82a7e715ee13108"));
    const auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(coin, accId.get()));

    assertStringsEqual(id, "aptos");
    assertStringsEqual(name, "Aptos");
    assertStringsEqual(symbol, "APT");
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(coin), 8);
    ASSERT_EQ(TWCoinTypeBlockchain(coin), TWBlockchainAptos);
    ASSERT_EQ(TWCoinTypeP2shPrefix(coin), 0x0);
    ASSERT_EQ(TWCoinTypeStaticPrefix(coin), 0x0);
    assertStringsEqual(txUrl, "https://explorer.aptoslabs.com/txn/91424546");
    assertStringsEqual(accUrl, "https://explorer.aptoslabs.com/account/0x6af7d07b8a541913dfa87a9f99628faa255c70241ef9ebd9b82a7e715ee13108");
}
