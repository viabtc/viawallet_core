// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Ergo/Signer.h"
#include "Ergo/Address.h"
#include "HexCoding.h"
#include <gtest/gtest.h>
#include "proto/Ergo.pb.h"

using namespace TW;
using namespace TW::Ergo;

TEST(ErgoSigner, Sign) {

    TW::Ergo::Proto::SigningInput input;

    auto privateKey0 = parse_hex("39fdd21cf21d02457fa1237355cd4213888f4e339d9b6e37c0b77b2cbf013d4b");
    input.add_private_key(privateKey0.data(), privateKey0.size());

    auto privateKey1 = parse_hex("ca792a1815e34ce9c2f4258f02da149a3af551b4f0b8e0e15eb66369100e63e4");
    input.add_private_key(privateKey1.data(), privateKey1.size());

    input.set_creation_height(556284);
    input.set_fee(1100000);
    input.set_fee_address("2iHkR7CWvD1R4j1yZg5bkeDRQavjAaVPeTDFGGLZduHyfWMuYpmhHocX8GJoaieTx78FntzJbCBVL6rf96ocJoZdmWBL2fci7NqWgAirppPQmZ7fN9V6z13Ay6brPriBKYqLp1bT2Fk4FkFLCfdPpe");
    input.set_value(97000000);
    input.set_to_address("9htc5VcSkgrKATjj663sENhLzsEGVoKXnGhfA2XHVoxHesn3wX6");
    input.set_change_address("9hAfihPpKYpJtEYvsGQMRm5fatobkuWv2mG4FZAPiFM2S23EfRd");

    auto utxo0 = input.add_unspentoutput();
    utxo0->set_boxid("9ff7f5d5e6f72b6be355299f1b54b0caa1b396811bbd9327783525a3278bed97");
    utxo0->set_value(1200000);

    auto utxo1 = input.add_unspentoutput();
    utxo1->set_boxid("33a791b477a96da7403c953b93794a863431f6c42fc52353d72eb39d7b88d297");
    utxo1->set_value(97700000);

    auto signOutput = Signer::sign(input);

}
