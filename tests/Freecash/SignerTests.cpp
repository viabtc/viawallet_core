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

TEST(FreecashSigner, Sign) {

    const int64_t amount = 600;

    auto input = Proto::SigningInput();
    input.set_hash_type(TWBitcoinSigHashTypeAll | TWBitcoinSigHashTypeFork);
    input.set_amount(amount);
    input.set_byte_fee(1);
    input.set_to_address("FERr6havEuXVgUBen7oiQ6uGBbCmF3TCYm");
    input.set_change_address("FJTxTFxRTP6Dv3M4AgAefRhjtFo364CGEP");
    input.set_coin_type(TWCoinTypeFreecash);

    auto hash0 = DATA("f039f10e0eeadb3e5f164beebfb1135c61a4d58c466960c673589f214ed9b6eb");
    auto script0 = parse_hex("76a9148a99611dacbf609c54460b4a8ff477599652841688ac");
    auto utxo0 = input.add_utxo();
    utxo0->set_amount(936894);
    utxo0->set_script(script0.data(), script0.size());
    utxo0->mutable_out_point()->set_hash(TWDataBytes(hash0.get()), TWDataSize(hash0.get()));
    utxo0->mutable_out_point()->set_index(1);
    utxo0->mutable_out_point()->set_sequence(UINT32_MAX);

    auto utxoKey0 = DATA("b0e20b063d3f0aeb66d5f6bf0fbac8dcb2fafccfe7aaccbd7cd28d33075e2b4b");
    input.add_private_key(TWDataBytes(utxoKey0.get()), TWDataSize(utxoKey0.get()));

    Proto::SigningOutput output;
    ANY_SIGN(input, TWCoinTypeFreecash);

    EXPECT_EQ(output.transaction().outputs_size(), 2);
    EXPECT_EQ(output.transaction().outputs(0).value(), amount);
    EXPECT_EQ(output.transaction().outputs(1).value(), 936068);
    EXPECT_EQ(output.encoded().length(), 219);
    ASSERT_EQ(hex(output.encoded()),
              "0100000001f039f10e0eeadb3e5f164beebfb1135c61a4d58c466960c673589f214ed9b6eb01000000644158d5cad68a9c9e748ae829c4745f3e81def3f54c66a036f2e3ecff6253c41c2807bc4d7cccc4a45233b303c9049adb1bef31b10cec3c3c9e944f35435eb38ee841210316d04954e8e33f02e2ff6e1c3ea8b54e65be907ac732fc804565919f8ef0722fffffffff0258020000000000001976a9145e52bd6846fb52ae94b06c62cc9d87fb42de7f9888ac84480e00000000001976a9148a99611dacbf609c54460b4a8ff477599652841688ac00000000");

}

TEST(FreecashSigner, SignSchnorr) {

    auto key = TW::parse_hex("040564c844e6aeb1915a27669b0e9e7e4e794bbc557b95f692403bc62875cab1");
    auto data = TW::parse_hex("9938428ed6df944a2182a32cac7b3be849ca6f3f3e6d627a860d5a023742e1df");

    auto privateKey = PrivateKey(key);
    auto publicKey = privateKey.getPublicKey(TWPublicKeyTypeSECP256k1);

    auto signature = privateKey.signBCHSchnorr(data);

    auto expected = TW::parse_hex("1229813c55664e4a6802cc41131fb4fd84305f19d39343568fac580c5436d84da13a6f954b8bcd9b1d60f0aa0c9a47819d35b4ad5c67153837b6b8ec5f5ed008");
    for (auto i = 0; i < sizeof(expected); i += 1) {
        ASSERT_EQ(signature[i], expected[i]);
    }

    ASSERT_TRUE(publicKey.verifyBCHSchnorr(signature, data));
}
