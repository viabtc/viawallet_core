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


TEST(TWTerraClassicCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeTerraClassic));
    auto txId = WRAPS(TWStringCreateWithUTF8Bytes("D28D8AFC7CE89F2A22FA2DBF78D2C0A36E549BB830C4D9FA7459E3F723CA7182"));
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeTerraClassic, txId.get()));
    auto accId = WRAPS(TWStringCreateWithUTF8Bytes("terra16t3gx5rqvz6ru37yzn3shuu20erv4ngmfr59zf"));
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeTerraClassic, accId.get()));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeTerraClassic));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeTerraClassic));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeTerraClassic), 6);
    ASSERT_EQ(TWBlockchainCosmos, TWCoinTypeBlockchain(TWCoinTypeTerraClassic));
    ASSERT_EQ(0x0, TWCoinTypeP2shPrefix(TWCoinTypeTerraClassic));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeTerraClassic));
    assertStringsEqual(symbol, "LUNC");
    assertStringsEqual(txUrl, "https://finder.terra.money/tx/tx/D28D8AFC7CE89F2A22FA2DBF78D2C0A36E549BB830C4D9FA7459E3F723CA7182");
    assertStringsEqual(accUrl, "https://finder.terra.money/tx/address/terra16t3gx5rqvz6ru37yzn3shuu20erv4ngmfr59zf");
    assertStringsEqual(id, "terraclassic");
    assertStringsEqual(name, "Terra Classic");
}
