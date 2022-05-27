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


TEST(TWLBRYCreditsCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeLBRYCredits));
    auto txId = TWStringCreateWithUTF8Bytes("t123");
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeLBRYCredits, txId));
    auto accId = TWStringCreateWithUTF8Bytes("a12");
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeLBRYCredits, accId));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeLBRYCredits));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeLBRYCredits));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeLBRYCredits), 8);
    ASSERT_EQ(TWBlockchainBitcoin, TWCoinTypeBlockchain(TWCoinTypeLBRYCredits));
    ASSERT_EQ(0x7a, TWCoinTypeP2shPrefix(TWCoinTypeLBRYCredits));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeLBRYCredits));
    assertStringsEqual(symbol, "LBC");
    assertStringsEqual(txUrl, "https://explorer.lbry.com/tx/t123");
    assertStringsEqual(accUrl, "https://explorer.lbry.com/address/a12");
    assertStringsEqual(id, "lbry");
    assertStringsEqual(name, "LBRY Credits");
}
