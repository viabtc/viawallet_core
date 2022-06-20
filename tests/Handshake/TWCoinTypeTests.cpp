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


TEST(TWHandshakeCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeHandshake));
    auto txId = TWStringCreateWithUTF8Bytes("t123");
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeHandshake, txId));
    auto accId = TWStringCreateWithUTF8Bytes("a12");
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeHandshake, accId));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeHandshake));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeHandshake));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeHandshake), 6);
    ASSERT_EQ(TWBlockchainHandshake, TWCoinTypeBlockchain(TWCoinTypeHandshake));
    ASSERT_EQ(0x0, TWCoinTypeP2shPrefix(TWCoinTypeHandshake));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeHandshake));
    assertStringsEqual(symbol, "HNS");
    assertStringsEqual(txUrl, "https://hnscan.com/tx/t123");
    assertStringsEqual(accUrl, "https://hnscan.com/address/a12");
    assertStringsEqual(id, "handshake");
    assertStringsEqual(name, "Handshake");
}
