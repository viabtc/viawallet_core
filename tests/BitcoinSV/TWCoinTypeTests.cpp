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


TEST(TWBitcoinSVCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeBitcoinSV));
    auto txId = TWStringCreateWithUTF8Bytes("bfd9e5632b9d217d989a2dd5d767b88669fcec3f422786b61c7998e1892a032e");
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeBitcoinSV, txId));
    auto accId = TWStringCreateWithUTF8Bytes("17zM8LzRqxHkMd7iB8UQFw5mTL78qWbG4X");
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeBitcoinSV, accId));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeBitcoinSV));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeBitcoinSV));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeBitcoinSV), 8);
    ASSERT_EQ(TWBlockchainBitcoin, TWCoinTypeBlockchain(TWCoinTypeBitcoinSV));
    ASSERT_EQ(0x5, TWCoinTypeP2shPrefix(TWCoinTypeBitcoinSV));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeBitcoinSV));
    assertStringsEqual(symbol, "BSV");
    assertStringsEqual(txUrl, "https://explorer.viawallet.com/bsv/tx/bfd9e5632b9d217d989a2dd5d767b88669fcec3f422786b61c7998e1892a032e");
    assertStringsEqual(accUrl, "https://explorer.viawallet.com/bsv/address/17zM8LzRqxHkMd7iB8UQFw5mTL78qWbG4X");
    assertStringsEqual(id, "bitcoinsv");
    assertStringsEqual(name, "Bitcoin SV");
}
