// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWAnySigner.h>
#include <uint1024.h>
#include <gtest/gtest.h>
#include "../interface/TWTestUtilities.h"
#include "HexCoding.h"
#include "proto/Mina.pb.h"

using namespace TW;

TEST(TWAnySignerMina, Sign) {
    auto privateKey = parse_hex("1f8a33418070dce124003b3b287853969d5f21f869091c8d881e0cac8073064a");
    auto from = "B62qng4Q3NBfiwKRDctBrdQ6iAKTLFCEoXHz9wdTzG6kBh48p5Mf5EU";
    auto to = "B62qng4Q3NBfiwKRDctBrdQ6iAKTLFCEoXHz9wdTzG6kBh48p5Mf5EU";
    auto amount = 10000000;
    auto fee = 20000000;
    auto nonce = 1;
    uint32_t validUntil = 4294967295;
    auto memo = "";
    auto delegation = false;

    Mina::Proto::SigningInput input;
    input.set_private_key(privateKey.data(), privateKey.size());
    input.set_to(to);
    input.set_from(from);
    input.set_amount(amount);
    input.set_fee(fee);
    input.set_nonce(nonce);
    input.set_valid_until(validUntil);
    input.set_memo(memo);
    input.set_delegation(delegation);

    Mina::Proto::SigningOutput output;
    ANY_SIGN(input, TWCoinTypeMina);

    ASSERT_EQ(output.signature(), "3d6ea210c8b93eca7fe9fe2040b2c0dab31b230aee424c2deb8b17be7c5096970f1e630d1a47f3a1a3c6754d47f0b04916c36d1aa5cf0cf8f73cfd5901232b8e");
}