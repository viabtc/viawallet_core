// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWAnySigner.h>
#include "HexCoding.h"
#include "HDWallet.h"
#include "proto/NervosCKB.pb.h"
#include "Coin.h"

#include "../interface/TWTestUtilities.h"
#include <gtest/gtest.h>

using namespace TW;

TEST(TWAnySignerNervosCKB, Sign) {
    const auto mnemonic = "hobby protect soda glow coconut make tip skate noodle venue crop check";
    const auto wallet = HDWallet(mnemonic, "");
    const auto path = derivationPath(TWCoinTypeNervosCKB);
    const auto privateKey = wallet.getKey(TWCoinTypeNervosCKB, path);

    auto input = NervosCKB::Proto::SigningInput();
    auto transfer = input.mutable_transfer();
    transfer->set_amount(6200000000);
    transfer->set_fee_rate(1000);
    transfer->set_to("ckb1qyq2tatnjz8585dr4j94any9gymm03w2uprsq23unj");
    transfer->set_use_max_amount(false);
    transfer->set_private_key(privateKey.bytes.data(), privateKey.bytes.size());
    auto cell = transfer->add_cells();
    cell->set_since(0);
    cell->set_capacity(19000000000);
    auto previous_output = cell->mutable_previous_output();
    auto txHash = parse_hex("0x14dead518c172b8f90d36ea45d6712dc833c04044179f39704119d31c1cbfee6");
    previous_output->set_txhash(txHash.data(), txHash.size());
    previous_output->set_index(0);
    NervosCKB::Proto::SigningOutput output;
    ANY_SIGN(input, TWCoinTypeNervosCKB);
    ASSERT_EQ(output.json(), "{\"cell_deps\":[{\"dep_type\":\"dep_group\",\"out_point\":{\"index\":\"0x0\",\"tx_hash\":\"0x71a7ba8fc96349fea0ed3a5c47992e3b4084b031a42264a018e0072e8172e46c\"}}],\"header_deps\":[],\"inputs\":[{\"previous_output\":{\"index\":\"0x0\",\"tx_hash\":\"0x14dead518c172b8f90d36ea45d6712dc833c04044179f39704119d31c1cbfee6\"},\"since\":\"0x0\"}],\"outputs\":[{\"capacity\":\"0x1718c7e00\",\"lock\":{\"args\":\"0xa5f573908f43d1a3ac8b5ecc854137b7c5cae047\",\"code_hash\":\"0x9bd7e06f3ecf4be0f2fcd2188b23f1b9fcc88e5d4b65a8637b17723bbda3cce8\",\"hash_type\":\"type\"},\"type\":null},{\"capacity\":\"0x2faf07e30\",\"lock\":{\"args\":\"0xf130dc01daf29985c1b607cb0a1533e0b3dfc10f\",\"code_hash\":\"0x9bd7e06f3ecf4be0f2fcd2188b23f1b9fcc88e5d4b65a8637b17723bbda3cce8\",\"hash_type\":\"type\"},\"type\":null}],\"outputs_data\":[\"0x\",\"0x\"],\"version\":\"0x0\",\"witnesses\":[\"0x55000000100000005500000055000000410000002194b89bb157e8edd597a2e1793c0791e8b675fbe7258db87b23ba18bfe9ca7f7b14f88219582b41653e51a4ff8d5ac9be45342902d12ecdc240e77b29459a6000\"]}");

}
