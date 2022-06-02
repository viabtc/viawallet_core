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


TEST(TWMinaCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeMina));
    auto txId = TWStringCreateWithUTF8Bytes("CkpZo3tZsNBDyvT3TQbsM6UsYbz4Te9V5NbPbw7fe6chENzNhx77v");
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeMina, txId));
    auto accId = TWStringCreateWithUTF8Bytes("B62qkNm8jmhLKWhP5Qr5LL1RtzRz54rhZjdLxCX1nxcgzs6EB21jrdV");
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeMina, accId));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeMina));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeMina));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeMina), 9);
    ASSERT_EQ(TWBlockchainMina, TWCoinTypeBlockchain(TWCoinTypeMina));
    ASSERT_EQ(0x5, TWCoinTypeP2shPrefix(TWCoinTypeMina));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeMina));
    assertStringsEqual(symbol, "MINA");
    assertStringsEqual(txUrl, "https://minaexplorer.com/transaction/CkpZo3tZsNBDyvT3TQbsM6UsYbz4Te9V5NbPbw7fe6chENzNhx77v");
    assertStringsEqual(accUrl, "https://minaexplorer.com/wallet/B62qkNm8jmhLKWhP5Qr5LL1RtzRz54rhZjdLxCX1nxcgzs6EB21jrdV");
    assertStringsEqual(id, "mina");
    assertStringsEqual(name, "Mina");
}
