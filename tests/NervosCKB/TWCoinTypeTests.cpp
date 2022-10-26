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


TEST(TWNervosCKBCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeNervosCKB));
    auto txId = TWStringCreateWithUTF8Bytes("t123");
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeNervosCKB, txId));
    auto accId = TWStringCreateWithUTF8Bytes("a12");
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeNervosCKB, accId));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeNervosCKB));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeNervosCKB));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeNervosCKB), 8);
    ASSERT_EQ(TWBlockchainNervos, TWCoinTypeBlockchain(TWCoinTypeNervosCKB));
    ASSERT_EQ(0x0, TWCoinTypeP2shPrefix(TWCoinTypeNervosCKB));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeNervosCKB));
    assertStringsEqual(symbol, "CKB");
    assertStringsEqual(txUrl, "https://explorer.nervos.org/transaction/t123");
    assertStringsEqual(accUrl, "https://explorer.nervos.org/address/a12");
    assertStringsEqual(id, "nervosckb");
    assertStringsEqual(name, "Nervos CKB");
}
