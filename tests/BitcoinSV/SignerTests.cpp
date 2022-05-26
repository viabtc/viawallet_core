// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "PrivateKey.h"
#include "PublicKey.h"
#include "proto/Bitcoin.pb.h"
#include "../interface/TWTestUtilities.h"

#include <TrustWalletCore/TWBitcoinSigHashType.h>
#include <TrustWalletCore/TWAnySigner.h>
#include <gtest/gtest.h>

using namespace TW;
using namespace TW::Bitcoin;

TEST(BitcoinSVSigner, Sign) {

    const int64_t amount = 600;

    auto input = Proto::SigningInput();
    input.set_hash_type(TWBitcoinSigHashTypeAll | TWBitcoinSigHashTypeFork);
    input.set_amount(amount);
    input.set_byte_fee(1);
    input.set_to_address("1LzTnrmZcT8dQnmSghZyA6gvq9YPsD711Q");
    input.set_change_address("1N3sZKqYXewdLrCNT3wh88x66Np7MRLMgQ");

    auto hash0 = DATA("1f6e554b9bb2830b820402f4e3969fcf03ab662b70395152fad3d41dc84cd65f");
    auto script0 = parse_hex("76a914e6e5ad2fd9fe6bff9cd622c36df5666efaa6d35488ac");
    auto utxo0 = input.add_utxo();
    utxo0->set_amount(134600);
    utxo0->set_script(script0.data(), script0.size());
    utxo0->mutable_out_point()->set_hash(TWDataBytes(hash0.get()), TWDataSize(hash0.get()));
    utxo0->mutable_out_point()->set_index(1);
    utxo0->mutable_out_point()->set_sequence(UINT32_MAX);

    auto utxoKey0 = DATA("57264bb5c5dfaa02b28b9b8e9c99ed4cbeb490cf6b4458f78b826dfa56d0de72");
    input.add_private_key(TWDataBytes(utxoKey0.get()), TWDataSize(utxoKey0.get()));

    Proto::SigningOutput output;
    ANY_SIGN(input, TWCoinTypeBitcoinSV);

    EXPECT_EQ(output.transaction().outputs_size(), 2);
    EXPECT_EQ(output.transaction().outputs(0).value(), amount);
    EXPECT_EQ(output.transaction().outputs(1).value(), 133774);
    EXPECT_EQ(output.encoded().length(), 226);
    ASSERT_EQ(hex(output.encoded()),
              "01000000011f6e554b9bb2830b820402f4e3969fcf03ab662b70395152fad3d41dc84cd65f010000006b483045022100cdab40211c1b76bb91bd4a9471dfd3698b596f7059c2cbb5e2ae5d5dbf96049c022003b4d58f7df51271dd1afe9e73506cbde44e09f21e14f5f92e5fdcb5eca826d8412103e005ad98f6b0267b48e75675ccc7b1a6231c3157fd7e396a3515a22676cc75a5ffffffff0258020000000000001976a914db4876a32ffd9822fb9b0bf4914cb28529262d4088ac8e0a0200000000001976a914e6e5ad2fd9fe6bff9cd622c36df5666efaa6d35488ac00000000");

}
