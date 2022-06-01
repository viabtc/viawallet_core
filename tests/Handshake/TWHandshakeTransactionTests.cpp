
// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "../interface/TWTestUtilities.h"

#include "Bitcoin/OutPoint.h"
#include "Handshake/Script.h"
#include "Handshake/Transaction.h"
#include "Handshake/TransactionOutput.h"
#include "HexCoding.h"
#include <TrustWalletCore/TWAnySigner.h>
#include <TrustWalletCore/TWBitcoinScript.h>
#include <BinaryCoding.h>
#include <PrivateKey.h>
#include <gtest/gtest.h>

using namespace TW;
using namespace TW::Handshake;

TEST(TWHandshakeTransaction, test00) {
    auto coin = TWCoinTypeHandshake;
    auto ownAddress = "hs1qp4q33c8mxg0ecnxk5q6a53v7j5vkleht934tur";
    auto ownPrivateKey = "a6bd2857bfefed5c3b8bd8a997337a50807d62ddac235cb194a153aa9a6a2fdc";
    auto toAddress0 = "hs1qsggs47m70f7qq7pefq2rsaz84dqc689d3ky4uv";
    auto utxo0Amount = 19972000;
    auto toAmount0 = 19958000;

    auto unsignedTx = Transaction();

    auto hash0 = parse_hex("68edbfb958908f0511a31173fa0327f38f8d5de8f0f20939829b5fdb5dd329a6");
    auto outpoint0 = TW::Bitcoin::OutPoint(hash0, 0);
    unsignedTx.inputs.emplace_back(outpoint0, Script(), UINT32_MAX);

    auto lockingScript0 = Script::lockScriptForAddress(toAddress0, coin);
    unsignedTx.outputs.push_back(TransactionOutput(toAmount0, lockingScript0));
    // change
//    auto lockingScript2 = Script::lockScriptForAddress(ownAddress, coin);
//    unsignedTx.outputs.push_back(
//    Bitcoin::TransactionOutput(utxo0Amount - toAmount0 - 172, lockingScript2));


    // add signature
    auto privkey = PrivateKey(parse_hex(ownPrivateKey));
    auto pubkey = PrivateKey(privkey).getPublicKey(TWPublicKeyTypeSECP256k1);
    EXPECT_EQ(hex(pubkey.bytes),
              "03db4ad989c60cc87211ef545b6b9c85eee789c335ef134a9499f0f3b8738067e6");

    auto utxo0Script = Script::lockScriptForAddress(ownAddress, coin); // buildPayToWitnessProgram()
    Data keyHashIn0;
    EXPECT_TRUE(utxo0Script.matchPayToWitnessPublicKeyHash(keyHashIn0));
    EXPECT_EQ(hex(keyHashIn0), "0d4118e0fb321f9c4cd6a035da459e95196fe6eb");

    auto redeemScript0 = Script::buildPayToPublicKeyHash(keyHashIn0);
    EXPECT_EQ(hex(redeemScript0.bytes), "76c0140d4118e0fb321f9c4cd6a035da459e95196fe6eb88ac");

    auto hashType = TWBitcoinSigHashType::TWBitcoinSigHashTypeAll;
    Data sighash = unsignedTx.getSignatureHash(
        redeemScript0, unsignedTx.inputs[0].previousOutput.index, hashType, utxo0Amount);

    auto sig = privkey.sign(sighash, TWCurveSECP256k1);

    // add witness stack
    unsignedTx.inputs[0].scriptWitness.push_back(sig);
    unsignedTx.inputs[0].scriptWitness.push_back(pubkey.bytes);

    Data unsignedData;
    unsignedTx.encode(unsignedData, Transaction::SegwitFormatMode::Segwit);
    EXPECT_EQ(hex(unsignedData), "000000000168edbfb958908f0511a31173fa0327f38f8d5de8f0f20939829b5fdb5dd329a600000000ffffffff01f088300100000000001482110afb7e7a7c0078394814387447ab418d1cad000000000000024174276738f240a53b307706d67bd816a7b8c0d0a086221469c79b8f717e88a2e81a14d8477a7ed971f96ce053bb5b2ef5f544883e9f8fd678d5915d2116f03d52012103db4ad989c60cc87211ef545b6b9c85eee789c335ef134a9499f0f3b8738067e6");
}


TEST(TWHandshakeTransaction, test01) {
    auto coin = TWCoinTypeHandshake;
    auto ownAddress = "hs1qp4q33c8mxg0ecnxk5q6a53v7j5vkleht934tur";
    auto ownPrivateKey = "a6bd2857bfefed5c3b8bd8a997337a50807d62ddac235cb194a153aa9a6a2fdc";
    auto toAddress0 = "hs1qsggs47m70f7qq7pefq2rsaz84dqc689d3ky4uv";
    auto utxo0Amount = 19972000;
    auto toAmount0 = 19958000;

    auto unsignedTx = Transaction();

    auto hash0 = parse_hex("68edbfb958908f0511a31173fa0327f38f8d5de8f0f20939829b5fdb5dd329a6");
    auto outpoint0 = TW::Bitcoin::OutPoint(hash0, 0);
    unsignedTx.inputs.emplace_back(outpoint0, Script(), UINT32_MAX);

    auto lockingScript0 = Script::lockScriptForAddress(toAddress0, coin);
    unsignedTx.outputs.push_back(TransactionOutput(toAmount0, lockingScript0));
    // change
//    auto lockingScript2 = Script::lockScriptForAddress(ownAddress, coin);
//    unsignedTx.outputs.push_back(
//        Bitcoin::TransactionOutput(utxo0Amount - toAmount0 - 172, lockingScript2));


    Data unsignedData;
    unsignedTx.encode(unsignedData, Transaction::SegwitFormatMode::NonSegwit);


    // add signature
    auto privkey = PrivateKey(parse_hex(ownPrivateKey));
    auto pubkey = PrivateKey(privkey).getPublicKey(TWPublicKeyTypeSECP256k1);
    EXPECT_EQ(hex(pubkey.bytes),
              "03db4ad989c60cc87211ef545b6b9c85eee789c335ef134a9499f0f3b8738067e6");

    auto utxo0Script = Script::lockScriptForAddress(ownAddress, coin); // buildPayToWitnessProgram()
    EXPECT_EQ(hex(utxo0Script.bytes), "00140d4118e0fb321f9c4cd6a035da459e95196fe6eb");
    Data keyHashIn0;
    EXPECT_TRUE(utxo0Script.matchPayToWitnessPublicKeyHash(keyHashIn0));
    EXPECT_EQ(hex(keyHashIn0), "0d4118e0fb321f9c4cd6a035da459e95196fe6eb");

    auto redeemScript0 = Script::buildPayToPublicKeyHash(keyHashIn0);
    EXPECT_EQ(hex(redeemScript0.bytes), "76c0140d4118e0fb321f9c4cd6a035da459e95196fe6eb88ac");

    auto hashType = TWBitcoinSigHashType::TWBitcoinSigHashTypeAll;
    Data sighash = unsignedTx.getSignatureHash(
        redeemScript0, unsignedTx.inputs[0].previousOutput.index, hashType, utxo0Amount);

    auto sig = privkey.sign(sighash, TWCurveSECP256k1);

    // add witness stack
    unsignedTx.inputs[0].scriptWitness.push_back(sig);
    unsignedTx.inputs[0].scriptWitness.push_back(pubkey.bytes);

    unsignedData.clear();
    unsignedTx.encode(unsignedData, Transaction::SegwitFormatMode::Segwit);
    EXPECT_EQ(hex(unsignedData), "000000000168edbfb958908f0511a31173fa0327f38f8d5de8f0f20939829b5fdb5dd329a600000000ffffffff01f088300100000000001482110afb7e7a7c0078394814387447ab418d1cad000000000000024174276738f240a53b307706d67bd816a7b8c0d0a086221469c79b8f717e88a2e81a14d8477a7ed971f96ce053bb5b2ef5f544883e9f8fd678d5915d2116f03d52012103db4ad989c60cc87211ef545b6b9c85eee789c335ef134a9499f0f3b8738067e6");
}

TEST(TWHandshakeTransaction, test02) {
    auto coin = TWCoinTypeHandshake;
//    auto ownAddress = "hs1qp4q33c8mxg0ecnxk5q6a53v7j5vkleht934tur";
    auto ownPrivateKey = "a6bd2857bfefed5c3b8bd8a997337a50807d62ddac235cb194a153aa9a6a2fdc";
    auto toAddress0 = "hs1qsggs47m70f7qq7pefq2rsaz84dqc689d3ky4uv";
    auto utxo0Amount = 19972000;
    auto toAmount0 = 19958000;


    auto input = Bitcoin::Proto::SigningInput();
    input.set_hash_type(TWBitcoinSigHashTypeAll);
    input.set_amount(toAmount0);
    input.set_to_address(toAddress0);

    auto hash0 = DATA("68edbfb958908f0511a31173fa0327f38f8d5de8f0f20939829b5fdb5dd329a6");

    auto utxo0 = input.add_utxo();
    utxo0->mutable_out_point()->set_hash(TWDataBytes(hash0.get()), TWDataSize(hash0.get()));
    utxo0->mutable_out_point()->set_index(0);
    utxo0->mutable_out_point()->set_sequence(UINT32_MAX);
    auto script0 = parse_hex("00140d4118e0fb321f9c4cd6a035da459e95196fe6eb");
    utxo0->set_script(script0.data(), script0.size());
    utxo0->set_amount(utxo0Amount);

    auto utxoKey0 = DATA(ownPrivateKey);
    input.add_private_key(TWDataBytes(utxoKey0.get()), TWDataSize(utxoKey0.get()));

    auto& plan = *input.mutable_plan();
    plan.set_amount(toAmount0);
    plan.set_change(0);

    auto& planUtxo = *plan.add_utxos();
    planUtxo = input.utxo(0);

    Bitcoin::Proto::SigningOutput output;

    ANY_SIGN(input, coin);

    ASSERT_EQ(hex(output.encoded()), "000000000168edbfb958908f0511a31173fa0327f38f8d5de8f0f20939829b5fdb5dd329a600000000ffffffff01f088300100000000001482110afb7e7a7c0078394814387447ab418d1cad000000000000024174276738f240a53b307706d67bd816a7b8c0d0a086221469c79b8f717e88a2e81a14d8477a7ed971f96ce053bb5b2ef5f544883e9f8fd678d5915d2116f03d52012103db4ad989c60cc87211ef545b6b9c85eee789c335ef134a9499f0f3b8738067e6");
}

TEST(TWHandshakeTransaction, test03) {
    auto coin = TWCoinTypeHandshake;
//    auto ownAddress = "hs1qsggs47m70f7qq7pefq2rsaz84dqc689d3ky4uv";
    auto ownPrivateKey = "cbbdccb987e00ae7a6e08804d3011e9e80c723bd180768134c13dc534026c119";
    auto toAddress0 = "hs1qju8fvkh7993mts6pfnkmd9xdy293f2s9eaf84w";
    auto utxo0Amount = 19958000;
    auto toAmount0 = 19948000;


    auto input = Bitcoin::Proto::SigningInput();
    input.set_hash_type(TWBitcoinSigHashTypeAll);
    input.set_amount(toAmount0);
    input.set_to_address(toAddress0);

    auto hash0 = DATA("40843352fa723cdc8e8974e3945126135429e10ee394a2266e5caab768ab8fe9");

    auto utxo0 = input.add_utxo();
    utxo0->mutable_out_point()->set_hash(TWDataBytes(hash0.get()), TWDataSize(hash0.get()));
    utxo0->mutable_out_point()->set_index(0);
    utxo0->mutable_out_point()->set_sequence(UINT32_MAX);
    auto script0 = parse_hex("001482110afb7e7a7c0078394814387447ab418d1cad");
    utxo0->set_script(script0.data(), script0.size());
    utxo0->set_amount(utxo0Amount);

    auto utxoKey0 = DATA(ownPrivateKey);
    input.add_private_key(TWDataBytes(utxoKey0.get()), TWDataSize(utxoKey0.get()));

    auto& plan = *input.mutable_plan();
    plan.set_amount(toAmount0);
    plan.set_change(0);

    auto& planUtxo = *plan.add_utxos();
    planUtxo = input.utxo(0);

    Bitcoin::Proto::SigningOutput output;

    ANY_SIGN(input, coin);

    ASSERT_EQ(hex(output.encoded()), "000000000140843352fa723cdc8e8974e3945126135429e10ee394a2266e5caab768ab8fe900000000ffffffff01e0613001000000000014970e965afe2963b5c3414cedb694cd228b14aa0500000000000002413b207915ac128d707f11c7a308767e81e8a892ef0f22ee3f39deb4e92999c173191f500a640be2632c9e469b7c8c0e3c482c27e0b7929ee288d1cf6173fdf39c012102a03e93a51c2dd06dcca2e665ad1f2129c8d134177c8aa8c7524da09f29f43d25");
}


