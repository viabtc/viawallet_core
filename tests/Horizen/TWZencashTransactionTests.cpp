
// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "../interface/TWTestUtilities.h"

#include "Bitcoin/OutPoint.h"
#include "HexCoding.h"
#include "PublicKey.h"
#include "Horizen/Script.h"
#include "Horizen/TransactionBuilder.h"
#include <TrustWalletCore/TWAnySigner.h>
#include <TrustWalletCore/TWBitcoinScript.h>
#include <BinaryCoding.h>
#include <gtest/gtest.h>

using namespace TW;

TEST(TWHorizenTransaction, lockScriptP2KH) {
    auto blockHeight = 142091;
    auto toAddress = "znkz4JE6Y4m8xWoo4ryTnpxwBT5F7vFDgNf";
    auto blockHashStr = "00000001cf4e27ce1dd8028408ed0a48edd445ba388170c9468ba0d42fff3052";
    auto lockingScriptTo = Horizen::Script::lockScriptForAddress(toAddress, blockHeight, blockHashStr);

    ASSERT_EQ(hex(lockingScriptTo.bytes),"76a914da46f44467949ac9321b16402c32bbeede5e3e5f88ac205230ff2fd4a08b46c9708138ba45d4ed480aed088402d81dce274ecf01000000030b2b02b4");
}

TEST(TWHorizenTransaction, lockScriptP2SH) {
    auto blockHeight = 142091;
    auto toAddress = "zt27CUh1tqguUvQrcBNpDHtd13adRauiqLX";
    auto blockHashStr = "00000001cf4e27ce1dd8028408ed0a48edd445ba388170c9468ba0d42fff3052";
    auto lockingScriptTo = Horizen::Script::lockScriptForAddress(toAddress, blockHeight, blockHashStr);

    ASSERT_EQ(hex(lockingScriptTo.bytes),"a914ed3f0f01c90f41ff665570d38f070c1ee8c075fe87205230ff2fd4a08b46c9708138ba45d4ed480aed088402d81dce274ecf01000000030b2b02b4");
}

TEST(TWHorizenTransaction, serializeTx) {

    std::string blockHash = "00000001cf4e27ce1dd8028408ed0a48edd445ba388170c9468ba0d42fff3052";
    auto blockHeight = 142091;

    auto input = Bitcoin::Proto::SigningInput();
    input.set_hash_type(TWBitcoinSigHashTypeAll);
    input.set_amount(100000);
    input.set_to_address("znkz4JE6Y4m8xWoo4ryTnpxwBT5F7vFDgNf");

    auto& plan = *input.mutable_plan();
    plan.set_amount(100000);
    plan.set_change(0);
    plan.set_block_hash(blockHash);
    plan.set_block_height(blockHeight);
    auto utxo0 = plan.add_utxos();

    auto hash0 = DATA("2704a392f88573cb26775e6cf394e4039b430a2375becac454e3e57c88aed59d");
    TWDataReverse(hash0.get());

    utxo0->mutable_out_point()->set_hash(TWDataBytes(hash0.get()), TWDataSize(hash0.get()));
    utxo0->mutable_out_point()->set_index(0);
    utxo0->mutable_out_point()->set_sequence(UINT32_MAX);

    Data data;
    auto transaction = Horizen::TransactionBuilder::build(plan, input.to_address(), input.change_address());
    transaction.encode(data, TW::Bitcoin::Transaction::SegwitFormatMode::NonSegwit);

    auto result = hex(data);

    ASSERT_EQ(result, "01000000019dd5ae887ce5e354c4cabe75230a439b03e494f36c5e7726cb7385f892a304270000000000ffffffff01a0860100000000003f76a914da46f44467949ac9321b16402c32bbeede5e3e5f88ac205230ff2fd4a08b46c9708138ba45d4ed480aed088402d81dce274ecf01000000030b2b02b400000000");
}

TEST(TWHorizenTransaction, Signing1) {

    auto blockHash = "0000000001152fd77a60ecc7c62d08511d79edf08c27f1462a6a2262136bf23c";
    auto blockHeight = 871320;

    auto input = Bitcoin::Proto::SigningInput();
    input.set_hash_type(TWBitcoinSigHashTypeAll);
    input.set_amount(1000000);
    input.set_to_address("znaq4LQzZAFeNw7vot7yca3428XB4xgh13Y");
    input.set_change_address("znaykdphJqVASVR7cqGiL5u2civyo6xjaDQ");
    input.set_coin_type(TWCoinTypeHorizen);

    auto hash0 = DATA("ec6afbcfdb545f942f8710ba5381dff46fd2a0cb6e1c7974538bb1219b569980");
    TWDataReverse(hash0.get());

    auto utxo0 = input.add_utxo();
    utxo0->mutable_out_point()->set_hash(TWDataBytes(hash0.get()), TWDataSize(hash0.get()));
    utxo0->mutable_out_point()->set_index(0);
    utxo0->mutable_out_point()->set_sequence(UINT32_MAX);
    auto script0 = parse_hex("76a914d11c59a58b2dc69e9cf84ca4c7de8310ed9ff7f788ac207f52873e5884cf479568ad17b9237b70a9be488458dfd01a81068e010000000003ba3d0db4");
    utxo0->set_script(script0.data(), script0.size());

    auto utxoKey0 = DATA("2ff1cc7fa8ed5e711a53bca17574b8a4dac9011de4f14f5754e00723e534fc38");
    input.add_private_key(TWDataBytes(utxoKey0.get()), TWDataSize(utxoKey0.get()));

    auto& plan = *input.mutable_plan();
    plan.set_amount(1000000);
    plan.set_change(48990000);
    plan.set_block_hash(blockHash);
    plan.set_block_height(blockHeight);

    auto& planUtxo = *plan.add_utxos();
    planUtxo = input.utxo(0);

    Bitcoin::Proto::SigningOutput output;

    ANY_SIGN(input, TWCoinTypeHorizen);

    ASSERT_EQ(hex(output.encoded()), "01000000018099569b21b18b5374791c6ecba0d26ff4df8153ba10872f945f54dbcffb6aec000000006b4830450221008295105d76aafbf63561c62f2f1d41bca82f5bc214c5a5f2e313d5500d3689dc02200e9661a5695189bae02c8975bf5ba649678938455f2b5b988556e176285faefb0121036d81bf37b184a34cc4adb11c47d782d682bb25c974d607ac5dd6bb52c0782bfcffffffff0240420f00000000003f76a9146ae1fbf2261e006f73f256d64eea1f01997e800788ac203cf26b1362226a2a46f1278cf0ed791d51082dc6c7ec607ad72f15010000000003984b0db43087eb02000000003f76a9146c86f3e604bd59f335adfadfcb5732516f7f352188ac203cf26b1362226a2a46f1278cf0ed791d51082dc6c7ec607ad72f15010000000003984b0db400000000");
}

TEST(TWHorizenTransaction, Signing2) {

    auto blockHash = "0000000002ac2b5d86e3cd3180fd473ade330778d60d68390e2f1acbc7a8b380";
    auto blockHeight = 891687;

    auto input = Bitcoin::Proto::SigningInput();
    input.set_hash_type(TWBitcoinSigHashTypeAll);
    input.set_amount(1000000);
    input.set_to_address("znb1Yg84fdvuTbEK4ZgNL9ZuAKyHDzQNMPV");
    input.set_change_address("znZ8rUJqm6zECUYHTJiDfzGQCvLMx8GwYBm");
    input.set_coin_type(TWCoinTypeHorizen);

    auto hash0 = DATA("60f7ec088f114386bf006109ca4c83082b4c006b1800bb4915f33abbe7f39775");
    TWDataReverse(hash0.get());

    auto utxo0 = input.add_utxo();
    utxo0->mutable_out_point()->set_hash(TWDataBytes(hash0.get()), TWDataSize(hash0.get()));
    utxo0->mutable_out_point()->set_index(1);
    utxo0->mutable_out_point()->set_sequence(UINT32_MAX);
    auto script0 = parse_hex("76a914177bf500f9048db835f22c562cdf71e9f98fdde488ac202ef1c67a483e66e04dd82e34f7f573726e96c9db656f919571e6710100000000034c970db4");
    utxo0->set_script(script0.data(), script0.size());

    auto utxoKey0 = DATA("3b1cc28ae3a971dd26a6b4234454b3fc176a7b3afa48d06881fe0bb35c2c8846");
    input.add_private_key(TWDataBytes(utxoKey0.get()), TWDataSize(utxoKey0.get()));

    auto& plan = *input.mutable_plan();
    plan.set_amount(1000000);
    plan.set_change(37908644);
    plan.set_block_hash(blockHash);
    plan.set_block_height(blockHeight);

    auto& planUtxo = *plan.add_utxos();
    planUtxo = input.utxo(0);

    Bitcoin::Proto::SigningOutput output;

    ANY_SIGN(input, TWCoinTypeHorizen);

    ASSERT_EQ(hex(output.encoded()), "01000000017597f3e7bb3af31549bb00186b004c2b08834cca096100bf8643118f08ecf760010000006a47304402201a007623d2e6f1fd98f53e911466b838505be966f9dbc673f8363f35b7d215f7022071e3e62fff8c816c31f7fd94f8607e821b7f0502bbd69d3462584cda272a54ee01210293056e7e2c8c429bb7c9d9ad43ef1dfe7df4de09c86553437e78b095081fed58ffffffff0240420f00000000003f76a9146cddccf779d5aac340bab4026ed83861126af2b088ac2080b3a8c7cb1a2f0e39680dd6780733de3a47fd8031cde3865d2bac020000000003279b0db4a4704202000000003f76a914584f51013f8af2e7cc502efebbb77c486b88273b88ac2080b3a8c7cb1a2f0e39680dd6780733de3a47fd8031cde3865d2bac020000000003279b0db400000000");
}

TEST(TWHorizenTransaction, Signing3) {

    auto blockHash = "0000000000c4b775a95c58223c5225726c5dd2e04e97122a08b01ebb0e97c30e";
    auto blockHeight = 892407;

    auto input = Bitcoin::Proto::SigningInput();
    input.set_hash_type(TWBitcoinSigHashTypeAll);
    input.set_amount(35982188);
    input.set_to_address("znk9bBKhf4YwqkNZu6QLcXyeSFqxfCFQLoK");
    input.set_change_address("zndMCaCtjKdBs2meDjAboQq6UvNhqiG3NGn");
    input.set_coin_type(TWCoinTypeHorizen);
    input.set_byte_fee(2);

    auto hash0 = DATA("7bb9dada01f23e95a14dab1512ab8e97318c5e83ce01b2046b8dfc1c9685a461");
    TWDataReverse(hash0.get());
    auto utxo0 = input.add_utxo();
    utxo0->mutable_out_point()->set_hash(TWDataBytes(hash0.get()), TWDataSize(hash0.get()));
    utxo0->mutable_out_point()->set_index(1);
    utxo0->mutable_out_point()->set_sequence(UINT32_MAX);
    auto script0 = parse_hex("76a9140753f5839a5793c51b51ac6f2e0bfc5c1821911c88ac2055c41f7f2901e3e8d6519dddb0929f14d5d59c84eb4874ab4d4e9e010000000003529d0db4");
    utxo0->set_script(script0.data(), script0.size());
    auto utxoKey0 = DATA("b0b8849f1660db579e984137f4cdb1d581e9c1e46e9ce032977ac3f402e8c7a7");
    input.add_private_key(TWDataBytes(utxoKey0.get()), TWDataSize(utxoKey0.get()));

    auto hash1 = DATA("4dc6fc7748b4c82d42e604993657d7d8f9393200cef5c9cf74700863c9717f78");
    TWDataReverse(hash1.get());
    auto utxo1 = input.add_utxo();
    utxo1->mutable_out_point()->set_hash(TWDataBytes(hash1.get()), TWDataSize(hash1.get()));
    utxo1->mutable_out_point()->set_index(0);
    utxo1->mutable_out_point()->set_sequence(UINT32_MAX);
    auto script1 = parse_hex("76a914eeeb5bf74c7de9acf34424c981ff7e251a3f45ec88ac20ee6023b85067c29d171a82d21fbaac186cfe40ce50e1fbcd42271f020000000003439d0db4");
    utxo1->set_script(script1.data(), script1.size());
    auto utxoKey1 = DATA("13319d19b8824075dd56fc8d10593bf4b1660c5cd810698c4152ac0c0b476450");
    input.add_private_key(TWDataBytes(utxoKey1.get()), TWDataSize(utxoKey1.get()));


    auto hash2 = DATA("5df913a8b6343aaf040e2b087cdf88fde417ec0cb56cb5470ea396be7a453126");
    TWDataReverse(hash2.get());
    auto utxo2 = input.add_utxo();
    utxo2->mutable_out_point()->set_hash(TWDataBytes(hash2.get()), TWDataSize(hash2.get()));
    utxo2->mutable_out_point()->set_index(0);
    utxo2->mutable_out_point()->set_sequence(UINT32_MAX);
    auto script2 = parse_hex("76a91461d8189ef451fe42ca79b00b0caa30cf1f152cfa88ac203b99bef485b43c198be402188a7ee082a7cb8535972383a5e02adf020000000003409d0db4");
    utxo2->set_script(script2.data(), script2.size());
    auto utxoKey2 = DATA("9dac20fe589599eeb0849729d2cf3db51fea09e8986394983a3ee68cfc5c00f0");
    input.add_private_key(TWDataBytes(utxoKey2.get()), TWDataSize(utxoKey2.get()));

    auto hash3 = DATA("17a8f02c5e2d9686c5fadec10ab8d2c4452a900bfc35950bf671888566ed57c4");
    TWDataReverse(hash3.get());
    auto utxo3 = input.add_utxo();
    utxo3->mutable_out_point()->set_hash(TWDataBytes(hash3.get()), TWDataSize(hash3.get()));
    utxo3->mutable_out_point()->set_index(0);
    utxo3->mutable_out_point()->set_sequence(UINT32_MAX);
    auto script3 = parse_hex("76a91461d8189ef451fe42ca79b00b0caa30cf1f152cfa88ac208ecd363304b0e8f9d75f34522f372c1cbfa541b3a7a06150e662cb0100000000033e9d0db4");
    utxo3->set_script(script3.data(), script3.size());
    auto utxoKey3 = DATA("9dac20fe589599eeb0849729d2cf3db51fea09e8986394983a3ee68cfc5c00f0");
    input.add_private_key(TWDataBytes(utxoKey3.get()), TWDataSize(utxoKey3.get()));


    auto hash4 = DATA("c01109f41ca308a416471ec779f73144107d62016ad610d3da765d17dadab97c");
    TWDataReverse(hash4.get());
    auto utxo4 = input.add_utxo();
    utxo4->mutable_out_point()->set_hash(TWDataBytes(hash4.get()), TWDataSize(hash4.get()));
    utxo4->mutable_out_point()->set_index(0);
    utxo4->mutable_out_point()->set_sequence(UINT32_MAX);
    auto script4 = parse_hex("76a91461d8189ef451fe42ca79b00b0caa30cf1f152cfa88ac20d611a6335849668290806053644fe4ff6e8b9f5475e27358c3600c0000000000035b970db4");
    utxo4->set_script(script4.data(), script4.size());
    auto utxoKey4 = DATA("9dac20fe589599eeb0849729d2cf3db51fea09e8986394983a3ee68cfc5c00f0");
    input.add_private_key(TWDataBytes(utxoKey4.get()), TWDataSize(utxoKey4.get()));


    auto hash5 = DATA("0ab701951db8d90e92d9bb903d650b3c1e704bea2e54d8c0612b60d09f914506");
    TWDataReverse(hash5.get());
    auto utxo5 = input.add_utxo();
    utxo5->mutable_out_point()->set_hash(TWDataBytes(hash5.get()), TWDataSize(hash5.get()));
    utxo5->mutable_out_point()->set_index(0);
    utxo5->mutable_out_point()->set_sequence(UINT32_MAX);
    auto script5 = parse_hex("76a914d11c59a58b2dc69e9cf84ca4c7de8310ed9ff7f788ac20d1bbbada1d3abdd72722fa8cee954445167271ddc3b5d098bf0bff01000000000343970db4");
    utxo5->set_script(script5.data(), script5.size());
    auto utxoKey5 = DATA("2ff1cc7fa8ed5e711a53bca17574b8a4dac9011de4f14f5754e00723e534fc38");
    input.add_private_key(TWDataBytes(utxoKey5.get()), TWDataSize(utxoKey5.get()));


    auto hash6 = DATA("a382fbae66808ff36746f4e29e0e4466f316ebb3487e4a33d6d578d5752e8fab");
    TWDataReverse(hash6.get());
    auto utxo6 = input.add_utxo();
    utxo6->mutable_out_point()->set_hash(TWDataBytes(hash6.get()), TWDataSize(hash6.get()));
    utxo6->mutable_out_point()->set_index(0);
    utxo6->mutable_out_point()->set_sequence(UINT32_MAX);
    auto script6 = parse_hex("76a914d11c59a58b2dc69e9cf84ca4c7de8310ed9ff7f788ac2060482bbc73e2aa837e8cdc060f6053ea2cc71108d227d8a0921142000000000003f69d0db4");
    utxo6->set_script(script6.data(), script6.size());
    auto utxoKey6 = DATA("2ff1cc7fa8ed5e711a53bca17574b8a4dac9011de4f14f5754e00723e534fc38");
    input.add_private_key(TWDataBytes(utxoKey6.get()), TWDataSize(utxoKey6.get()));


    auto hash7 = DATA("a382fbae66808ff36746f4e29e0e4466f316ebb3487e4a33d6d578d5752e8fab");
    TWDataReverse(hash7.get());
    auto utxo7 = input.add_utxo();
    utxo7->mutable_out_point()->set_hash(TWDataBytes(hash7.get()), TWDataSize(hash7.get()));
    utxo7->mutable_out_point()->set_index(1);
    utxo7->mutable_out_point()->set_sequence(UINT32_MAX);
    auto script7 = parse_hex("76a914b1c8cd363fccb79adfa1627bbc192c08fa5c830f88ac2060482bbc73e2aa837e8cdc060f6053ea2cc71108d227d8a0921142000000000003f69d0db4");
    utxo7->set_script(script7.data(), script7.size());
    auto utxoKey7 = DATA("d723490957b754d9c1caf1d65106acef0a53a73911fc39ecb51a08cec2db2fda");
    input.add_private_key(TWDataBytes(utxoKey7.get()), TWDataSize(utxoKey7.get()));


    auto& plan = *input.mutable_plan();
    plan.set_amount(35982188);
    plan.set_change(0);
    plan.set_block_hash(blockHash);
    plan.set_block_height(blockHeight);

    auto& planUtxo0 = *plan.add_utxos();
    planUtxo0 = input.utxo(0);

    auto& planUtxo1 = *plan.add_utxos();
    planUtxo1 = input.utxo(1);

    auto& planUtxo2 = *plan.add_utxos();
    planUtxo2 = input.utxo(2);

    auto& planUtxo3 = *plan.add_utxos();
    planUtxo3 = input.utxo(3);

    auto& planUtxo4 = *plan.add_utxos();
    planUtxo4 = input.utxo(4);

    auto& planUtxo5 = *plan.add_utxos();
    planUtxo5 = input.utxo(5);

    auto& planUtxo6 = *plan.add_utxos();
    planUtxo6 = input.utxo(6);

    auto& planUtxo7 = *plan.add_utxos();
    planUtxo7 = input.utxo(7);

    Bitcoin::Proto::SigningOutput output;

    ANY_SIGN(input, TWCoinTypeHorizen);

    ASSERT_EQ(hex(output.encoded()), "010000000861a485961cfc8d6b04b201ce835e8c31978eab1215ab4da1953ef201dadab97b010000006a473044022069077a3517f81dd78cb550f8d167aa244c7b9cdefdeba5c99c803c4d9a916ff202200783bc366bd4f3edf8ef0b618ee549c1e76ae576f62c9194e8c8a1b78e465fa70121025719853af8c3d54aa20ce8ece7c4671b566eca8dc9ac480019846b0ad77a1bcdffffffff787f71c963087074cfc9f5ce003239f9d8d757369904e6422dc8b44877fcc64d000000006a473044022035f0707645747d1ac507be7de8dfd9f59c627f7f021fec6d5b5aeb9f7152e99e0220349d66b72f8e809723048fb8421f8c84cca53ba1eb3118b136589983d4cef440012102860ea3716546df04f84587709f7a44b8442fe33ef719c15af69ab7be85842ffaffffffff2631457abe96a30e47b56cb50cec17e4fd88df7c082b0e04af3a34b6a813f95d000000006b483045022100d5754729cb4530b700233bbb21033938910ae2996dc61395073758decad4c3da02203264538656ec07a75de1d40fbfb2129f57780c96ca49cd46588817869fd9354e01210294ffe13445fde584a91b59db05783e4d8cad25e169edb1fd0e118688d88e44b0ffffffffc457ed66858871f60b9535fc0b902a45c4d2b80ac1defac586962d5e2cf0a817000000006a4730440220129f42e641d9d60518ee605cbdfd0d92a2e704316f100e3fdf896de9b526aec0022009067bfd8b051f0ae8027baae637a6f2ef79b27d89dd2dbff5c687365d17835f01210294ffe13445fde584a91b59db05783e4d8cad25e169edb1fd0e118688d88e44b0ffffffff7cb9dada175d76dad310d66a01627d104431f779c71e4716a408a31cf40911c0000000006a47304402206697d5f42e7e26c79c73e04a5ce5cb5b9f74710141c7abad8734b9406d42a99d0220678bf1d1283b7d18eb07de9ea87842b2ea602881313a22aee774d0ccb563af9001210294ffe13445fde584a91b59db05783e4d8cad25e169edb1fd0e118688d88e44b0ffffffff0645919fd0602b61c0d8542eea4b701e3c0b653d90bbd9920ed9b81d9501b70a000000006a47304402206391e142860f09d7e3a3729ef05090a36c89ed38002d25625a40d66a616431d802205a167ee11f2949fa94bc31451efb4cf30b2956fc780facbd51bbe67fa71a72840121036d81bf37b184a34cc4adb11c47d782d682bb25c974d607ac5dd6bb52c0782bfcffffffffab8f2e75d578d5d6334a7e48b3eb16f366440e9ee2f44667f38f8066aefb82a3000000006a4730440220062ad6f63b7c794960139ab8bb37db3a1ad190fc68e2536d9e26b2ac1ed1f999022019ea6f822267dca00630baf6f5d5a11975231ec0c653f9d0a31b4734a34b83ff0121036d81bf37b184a34cc4adb11c47d782d682bb25c974d607ac5dd6bb52c0782bfcffffffffab8f2e75d578d5d6334a7e48b3eb16f366440e9ee2f44667f38f8066aefb82a3010000006a473044022068775682d0640de485c9a007add1618e5408307cbcbe62a95019b8a35f04e234022049682dbcf30c7c7e746199233c9aa08496dbc6a7eb6e8249ff96444e921788ec012103909e79cc0820a4c3daa304fa34f69f39dbb98d0f76363f87e304adc701a1a053ffffffff016c0b2502000000003f76a914d11c59a58b2dc69e9cf84ca4c7de8310ed9ff7f788ac200ec3970ebb1eb0082a12974ee0d25d6c7225523c22585ca975b7c4000000000003f79d0db400000000");

}
