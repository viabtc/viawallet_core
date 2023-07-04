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


TEST(TWConfluxNetworkCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeConfluxNetwork));
    auto txId = TWStringCreateWithUTF8Bytes("0xc41edb83ab232aca7ef235f0e751957887f35bf8cd9126a95d2c8c721b0ec1cb");
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeConfluxNetwork, txId));
    auto accId = TWStringCreateWithUTF8Bytes("cfx:aatsut3me3yrg3h423afcnyvgrmhuzwyk6uk8g78rf");
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeConfluxNetwork, accId));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeConfluxNetwork));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeConfluxNetwork));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeConfluxNetwork), 18);
    ASSERT_EQ(TWBlockchainConflux, TWCoinTypeBlockchain(TWCoinTypeConfluxNetwork));
    ASSERT_EQ(0x0, TWCoinTypeP2shPrefix(TWCoinTypeConfluxNetwork));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeConfluxNetwork));
    assertStringsEqual(symbol, "CFX");
    assertStringsEqual(txUrl, "https://www.confluxscan.io/transaction/0xc41edb83ab232aca7ef235f0e751957887f35bf8cd9126a95d2c8c721b0ec1cb");
    assertStringsEqual(accUrl, "https://www.confluxscan.io/address/cfx:aatsut3me3yrg3h423afcnyvgrmhuzwyk6uk8g78rf");
    assertStringsEqual(id, "conflux");
    assertStringsEqual(name, "Conflux");
}
