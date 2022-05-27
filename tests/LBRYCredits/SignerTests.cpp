// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWAnyAddress.h>
#include <TrustWalletCore/TWAnySigner.h>
#include <TrustWalletCore/TWBitcoinSigHashType.h>
#include <gtest/gtest.h>
#include "HexCoding.h"
#include "proto/Bitcoin.pb.h"
#include "../interface/TWTestUtilities.h"

using namespace TW;
using namespace TW::Bitcoin;


TEST(LBRYCreditsSigner, Sign) {
    // Transaction on LBRY Mainnet
    // https://explorer.lbry.com/tx/d7cc0005bdaae7e7d9121aabe7ebf21cbe45de196ee829858c5129c6a8ae6268

    auto input = Proto::SigningInput();
    input.set_coin_type(TWCoinTypeLBRYCredits);
    input.set_hash_type(TWBitcoinSigHashTypeAll);
    input.set_amount(600);
    input.set_byte_fee(1);
    input.set_to_address("bLTP2Y1sJDYBmHi69TN4uiyXQJJh5aTT37");
    input.set_change_address("bD1bbhMXEqzttWcjLxTAGDyfw779jRaUL5");

    auto hash0 = DATA("d9b93d3e921a217c618f3012ef6f5c82b38763849f27bf818e038ef52eef089a");//9a08ef2ef58e038e81bf279f846387b3825c6fef12308f617c211a923e3db9d9

    auto utxo0 = input.add_utxo();
    utxo0->mutable_out_point()->set_hash(TWDataBytes(hash0.get()), TWDataSize(hash0.get()));
    utxo0->mutable_out_point()->set_index(0);
    utxo0->mutable_out_point()->set_sequence(4294967295);
    utxo0->set_amount(5077022632);
    auto script0 = parse_hex("76a91403166fa6de26adb91ac127a8a5fcd519049c422c88ac");
    utxo0->set_script(script0.data(), script0.size());

    auto utxoKey0 = parse_hex("c0b0a4a59dae3d4095bb474da4d5819058af8389a1b8b3e78dc123a0a92ae7a0");
    input.add_private_key(utxoKey0.data(), utxoKey0.size());

    // Sign
    Proto::SigningOutput output;
    ANY_SIGN(input, TWCoinTypeLBRYCredits);
    auto result = hex(output.encoded());

    ASSERT_EQ(result, "0100000001d9b93d3e921a217c618f3012ef6f5c82b38763849f27bf818e038ef52eef089a000000006b483045022100e13f04486e84daad1e5610d09ccae1d50f37f9eb68d0939b30b5aa72e55ef1d102206d210b74d4c959645a7f70bd0c30c58bb9938a22bbcab372156e0c25ed97b1cc0121034a3336eb5d29ba3e9abd5a6e4f44b9c45e7bc95fa51a3fe26a58857bd9a4be3cffffffff0258020000000000001976a91454bfa324396b0034177ba500200311f665532e3488ac6e349d2e010000001976a91403166fa6de26adb91ac127a8a5fcd519049c422c88ac00000000");
}
