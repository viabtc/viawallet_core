// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWAnySigner.h>
#include "HexCoding.h"
#include "HDWallet.h"
#include "../interface/TWTestUtilities.h"
#include <gtest/gtest.h>
#include "Coin.h"
#include "proto/kaspa.pb.h"

using namespace TW;

// TODO: Finalize tests

TEST(TWAnySignerKaspa, Sign) {
    auto key1 = PrivateKey(parse_hex("0ddc6c6b255c89add0b05926d82e29494336467fb757ccf1dac4c34acfb5e689"));
    auto key2 = PrivateKey(parse_hex("4a08d405f8db0f11010c41b7a51debb2baacb62b1ee0bdf23e0ec35973559de9"));

    Kaspa::Proto::SigningInput input;
    auto transfer = input.mutable_transfer();
    transfer->set_amount(800000);
    transfer->set_fee(30000);
    transfer->set_to("kaspa:qypu7vn4dkvv4pzhwy9gp5r6n80ym3c6wdfgpum5zpg6de8gznl9xnghhscjnpt");
    transfer->set_changeaddress("kaspa:qyp6vqamd8gyy0v570wzfk9p5lvhysvt0w9zxg0ypgarrmmv6cx4llgnngkk9s6");
    transfer->add_private_key(key1.bytes.data(), key1.bytes.size());
    transfer->add_private_key(key2.bytes.data(), key2.bytes.size());

    auto utxo1 = transfer->add_unspentoutput();
    utxo1->set_amount(599110000);
    utxo1->set_outputindex(1);
    utxo1->set_outputscript("21024987f8e0ff31bd9d53ba1f11c0998b9af6cbcef12579beaa9d6061fc211d9556ab");
    utxo1->set_transactionhash("cf2d5c06becedd51488b812766c03e332f890ae140791a67ad5d51aae3953f23");
    utxo1->set_address("kaspa:qypynplcurlnr0va2wap7ywqnx9e4aktemcj27d742wkqc0uyywe24sngvn9ly6");

    auto utxo2 = transfer->add_unspentoutput();
    utxo2->set_amount(800000);
    utxo2->set_outputindex(0);
    utxo2->set_outputscript("2103cf32756d98ca8457710a80d07a99de4dc71a735280f3741051a6e4e814fe534dab");
    utxo2->set_transactionhash("cf2d5c06becedd51488b812766c03e332f890ae140791a67ad5d51aae3953f23");
    utxo2->set_address("kaspa:qypu7vn4dkvv4pzhwy9gp5r6n80ym3c6wdfgpum5zpg6de8gznl9xnghhscjnpt");

    Kaspa::Proto::SigningOutput output;
    ANY_SIGN(input, TWCoinTypeKaspa);
    ASSERT_EQ(output.json(), "{\"inputs\":[{\"previousOutpoint\":{\"index\":1,\"transactionId\":\"cf2d5c06becedd51488b812766c03e332f890ae140791a67ad5d51aae3953f23\"},\"sequence\":0,\"sigOpCount\":1,\"signatureScript\":\"4120e46b159511efb9caf60f06e5f3a4e45f03665ab1ce12126b0b7691561740bf6061ee258404b489fc0fba3ec3548da11b1f4983932e325ea047132693b54b2f01\"},{\"previousOutpoint\":{\"index\":0,\"transactionId\":\"cf2d5c06becedd51488b812766c03e332f890ae140791a67ad5d51aae3953f23\"},\"sequence\":0,\"sigOpCount\":1,\"signatureScript\":\"41edda5ab14f448be142334375800bd8cb5374ce08f78d65bc6bfffba32d8de9bb0314c4109e71e03952dfaf4ccb53061e00170c5934289016898e264c04fb47e901\"}],\"lockTime\":0,\"outputs\":[{\"amount\":800000,\"scriptPublicKey\":{\"script\":\"2103cf32756d98ca8457710a80d07a99de4dc71a735280f3741051a6e4e814fe534dab\",\"version\":0}},{\"amount\":599080000,\"scriptPublicKey\":{\"script\":\"2103a603bb69d0423d94f3dc24d8a1a7d972418b7b8a2321e40a3a31ef6cd60d5ffdab\",\"version\":0}}],\"subnetworkId\":\"0000000000000000000000000000000000000000\",\"version\":0}");
}
