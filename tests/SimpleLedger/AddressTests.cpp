// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "SimpleLedger/Address.h"
#include "PrivateKey.h"
#include <gtest/gtest.h>
#include <vector>

using namespace std;
using namespace TW;
using namespace TW::SimpleLedger;

TEST(SimpleLedgerAddress, Valid) {
    string address = "simpleledger:qr2m5chhu3mr8d5exphs5jzcldm2295dag5m0cmgku";
    ASSERT_TRUE(Address::isValid(address));
}

TEST(SimpleLedgerAddress, Invalid) {
    string address = "1Az8FtHoKDC18jas7UDVL9qZMVHJUjSzQc";
    ASSERT_FALSE(Address::isValid(address));
}

TEST(SimpleLedgerAddress, FromPrivateKey) {
    auto privateKey = PrivateKey(parse_hex("28071bf4e2b0340db41b807ed8a5514139e5d6427ff9d58dbd22b7ed187103a4"));
    auto address = Address(privateKey.getPublicKey(TWPublicKeyTypeSECP256k1));
    ASSERT_EQ(address.string(), "simpleledger:qruxj7zq6yzpdx8dld0e9hfvt7u47zrw9g9clv30jf");
}

TEST(SimpleLedgerAddress, FromString) {
    auto address = Address("simpleledger:qruxj7zq6yzpdx8dld0e9hfvt7u47zrw9g9clv30jf");
    ASSERT_EQ(address.string(), "simpleledger:qruxj7zq6yzpdx8dld0e9hfvt7u47zrw9g9clv30jf");
}
