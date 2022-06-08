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


TEST(TWKadenaCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeKadena));
    auto txId = TWStringCreateWithUTF8Bytes("t123");
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeKadena, txId));
    auto accId = TWStringCreateWithUTF8Bytes("a12");
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeKadena, accId));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeKadena));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeKadena));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeKadena), 12);
    ASSERT_EQ(TWBlockchainKadena, TWCoinTypeBlockchain(TWCoinTypeKadena));
    ASSERT_EQ(0x0, TWCoinTypeP2shPrefix(TWCoinTypeKadena));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeKadena));
    assertStringsEqual(symbol, "KDA");
    assertStringsEqual(txUrl, "https://explorer.chainweb.com/mainnet/tx/t123");
    assertStringsEqual(accUrl, "https://explorer.chainweb.com/mainneta12");
    assertStringsEqual(id, "kadena");
    assertStringsEqual(name, "Kadena");
}
