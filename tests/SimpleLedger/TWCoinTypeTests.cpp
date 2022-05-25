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


TEST(TWSimpleLedgerCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeSimpleLedger));
    auto txId = TWStringCreateWithUTF8Bytes("5053050dccd4a26deed73552012c16222fe0b1644c0a96eb0da375f4e2bee684");
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeSimpleLedger, txId));
    auto accId = TWStringCreateWithUTF8Bytes("simpleledger:qz3fzwpz6cszsujcd5pva3gcyrhr3dsr5vuu9qz558");
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeSimpleLedger, accId));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeSimpleLedger));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeSimpleLedger));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeSimpleLedger), 8);
    ASSERT_EQ(TWBlockchainBitcoin, TWCoinTypeBlockchain(TWCoinTypeSimpleLedger));
    ASSERT_EQ(0x5, TWCoinTypeP2shPrefix(TWCoinTypeSimpleLedger));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeSimpleLedger));
    assertStringsEqual(symbol, "SLP");
    assertStringsEqual(txUrl, "https://simpleledger.info/#tx/5053050dccd4a26deed73552012c16222fe0b1644c0a96eb0da375f4e2bee684");
    assertStringsEqual(accUrl, "https://simpleledger.info/#address/simpleledger:qz3fzwpz6cszsujcd5pva3gcyrhr3dsr5vuu9qz558");
    assertStringsEqual(id, "simpleledger");
    assertStringsEqual(name, "Simple Ledger");
}
