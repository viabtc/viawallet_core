// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "../interface/TWTestUtilities.h"
#include <TrustWalletCore/TWAnySigner.h>
#include "HexCoding.h"
#include "uint256.h"
#include "proto/ConfluxNetwork.pb.h"

#include <ConfluxNetwork/Address.h>
#include <gtest/gtest.h>

using namespace TW;
using namespace TW::ConfluxNetwork;


TEST(ConfluxNetworkSigner, Sign) {

    auto key = parse_hex("dbaa62128c638cda39bc8be5889a8666fb7fbb0355776d9f3ae5e4dc7c42de72");

    Proto::SigningInput input;
    auto chainId = store(uint256_t(1029));
    auto nonce = store(uint256_t(3));
    auto storageLimit = store(uint256_t(0));
    auto epochHeight = store(uint256_t(4482724));
    auto gasPrice = store(uint256_t(1));//1000000000
    auto gasLimit = store(uint256_t(21000));
    auto amount = store(uint256_t(1000000000000));

    input.set_to_address("cfx:aar4ekeaatt5s6808jmb8p0bmzrtevxazas5rhn083");
    input.set_chain_id(chainId.data(), chainId.size());
    input.set_nonce(nonce.data(), nonce.size());
    input.set_gas_price(gasPrice.data(), gasPrice.size());
    input.set_gas_limit(gasLimit.data(), gasLimit.size());
    input.set_amount(amount.data(), amount.size());
    input.set_storage_limit(storageLimit.data(), storageLimit.size());
    input.set_epoch_height(epochHeight.data(), epochHeight.size());
    input.set_private_key(key.data(), key.size());
    input.set_payload("");

    std::string expected = "0xf86de90301825208941ba2248003dfb773d6f2141f32c1555af24660a885e8d4a5100080834466a48204058001a04f09e2ce56b39f1ed552f288369835f6fa1c39e9167100d1f6ebb4f7c578a158a0521faffa0164f630bebc2a2e15d2583984b1ead45976d1171f74cc06aa4da644";

    Proto::SigningOutput output;
    ANY_SIGN(input, TWCoinTypeConfluxNetwork);

    std::string result = "0x" + hex(output.encoded());
    ASSERT_EQ(result, expected);

}