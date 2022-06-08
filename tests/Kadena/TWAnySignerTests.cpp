// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWAnySigner.h>
#include <gtest/gtest.h>
#include "HexCoding.h"
#include "Hash.h"
#include "proto/Kadena.pb.h"
#include "../interface/TWTestUtilities.h"

using namespace TW;

TEST(TWAnySignerKadena, SignTransfer) {
    auto privateKey = parse_hex("c85ea674ed7f6c0750fe44261af4c05f2a153e27fd167148aef28959a7bddc59cdcfcdfb82e4377e518856781a9d9e5193715181f6db3855655e1a127f4ed9ccb0b3c439740e93ebc1f91517a1d6bd65e3e2f2d0d8896bc857a7ef198e0b9daa");

    Kadena::Proto::SigningInput input;
    input.set_privatekey(privateKey.data(), privateKey.size());
    input.set_networkid("mainnet01");
    input.set_sender("k:3e6f46372e6dc6a9faf4436f7536bf467a87517d32734db3c94b24034482924a");
    input.set_receiver("k:3e6f46372e6dc6a9faf4436f7536bf467a87517d32734db3c94b24034482924a");
    input.set_amount("0.0001");
    input.set_gasprice("0.00001");
    input.set_gaslimit(600);
    input.set_nonce("2022-01-27T11:34:25.050Z");
    input.set_creationtime(1643254410);
    input.set_ttl(3000);
    input.set_chainid("0");
    input.set_targetchainid("1");

    input.add_receiverpubkeys("3e6f46372e6dc6a9faf4436f7536bf467a87517d32734db3c94b24034482924a");
    input.set_pred("keys-all");

    Kadena::Proto::SigningOutput output;
    ANY_SIGN(input, TWCoinTypeKadena);

    auto jsonStr = output.json();
    auto hash = output.hash();

    ASSERT_EQ(hash, "ArL4GzBnBlzJJeb7P8FvupYKUsPQOrAi6Fy3Wjl2D8k");
}