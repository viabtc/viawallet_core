// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Coin.h"
#include "HexCoding.h"
#include "Base64.h"
#include "proto/Cosmos.pb.h"
#include "Cosmos/Address.h"
#include "Cosmos/Signer.h"
#include "Cosmos/ProtobufSerialization.h"
#include "uint256.h"
#include "../interface/TWTestUtilities.h"

#include <gtest/gtest.h>
#include <google/protobuf/util/json_util.h>

using namespace TW;
using namespace TW::Cosmos;


TEST(TerraSigner, SignSendTx) {
    auto input = Proto::SigningInput();
    input.set_signing_mode(Proto::JSON);
    input.set_account_number(1037);
    input.set_chain_id("phoenix-1");
    input.set_memo("");
    input.set_sequence(2);

    Address fromAddress;
    ASSERT_TRUE(Address::decode("terra1hsk6jryyqjfhp5dhc55tc9jtckygx0ep37hdd2", fromAddress));
    Address toAddress;
    ASSERT_TRUE(Address::decode("terra18wukp84dq227wu4mgh0jm6n9nlnj6rs82pp9wf", toAddress));

    auto msg = input.add_messages();
    auto& message = *msg->mutable_send_coins_message();
    message.set_from_address(fromAddress.string());
    message.set_to_address(toAddress.string());
    auto amountOfTx = message.add_amounts();
    amountOfTx->set_denom("luna");
    amountOfTx->set_amount("1000000");

    auto& fee = *input.mutable_fee();
    fee.set_gas(200000);
    auto amountOfFee = fee.add_amounts();
    amountOfFee->set_denom("luna");
    amountOfFee->set_amount("200");

    std::string json;
    google::protobuf::util::MessageToJsonString(input, &json);
    EXPECT_EQ(json, R"({"accountNumber":"1037","chainId":"phoenix-1","fee":{"amounts":[{"denom":"luna","amount":"200"}],"gas":"200000"},"sequence":"2","messages":[{"sendCoinsMessage":{"fromAddress":"terra1hsk6jryyqjfhp5dhc55tc9jtckygx0ep37hdd2","toAddress":"terra18wukp84dq227wu4mgh0jm6n9nlnj6rs82pp9wf","amounts":[{"denom":"luna","amount":"1000000"}]}}]})");

    auto privateKey = parse_hex("80e81ea269e66a0a05b11236df7919fb7fbeedba87452d667489d7403a02f005");
    input.set_private_key(privateKey.data(), privateKey.size());

    auto output = Signer::sign(input, TWCoinTypeTerra);

    assertJSONEqual(output.json(), R"(
        {
            "mode": "block",
            "tx": {
                "fee": {
                    "amount": [
                        {
                            "amount": "200",
                            "denom": "luna"
                        }
                    ],
                    "gas": "200000"
                },
                "memo": "",
                "msg": [
                    {
                        "type": "cosmos-sdk/MsgSend",
                        "value": {
                            "amount": [
                                {
                                    "amount": "1000000",
                                    "denom": "luna"
                                }
                            ],
                            "from_address": "terra1hsk6jryyqjfhp5dhc55tc9jtckygx0ep37hdd2",
                            "to_address": "terra18wukp84dq227wu4mgh0jm6n9nlnj6rs82pp9wf"
                        }
                    }
                ],
                "signatures": [
                    {
                        "pub_key": {
                            "type": "tendermint/PubKeySecp256k1",
                            "value": "AlcobsPzfTNVe7uqAAsndErJAjqplnyudaGB0f+R+p3F"
                        },
                        "signature": "ucrxGSY4UNalmI2ytf1EmkQTcLm6sq915dflIxwOFmJps/R5tEfa8aqxT2gowWIwmNlovAkW2Avj0/z7zdbppg=="
                    }
                ]
            }
        }
    )");
    EXPECT_EQ(hex(output.signature()), "b9caf119263850d6a5988db2b5fd449a441370b9bab2af75e5d7e5231c0e166269b3f479b447daf1aab14f6828c1623098d968bc0916d80be3d3fcfbcdd6e9a6");
    EXPECT_EQ(output.serialized(), "");
    EXPECT_EQ(output.error(), "");
}

TEST(TerraSigner, SignWasmTransferTxProtobuf_9FF3F0) {
    auto input = Proto::SigningInput();
    input.set_signing_mode(Proto::Protobuf);
    input.set_account_number(3407705);
    input.set_chain_id("phoenix-1");
    input.set_memo("");
    input.set_sequence(3);

    Address fromAddress;
    ASSERT_TRUE(Address::decode("terra18wukp84dq227wu4mgh0jm6n9nlnj6rs82pp9wf", fromAddress));
    Address toAddress;
    ASSERT_TRUE(Address::decode("terra1jlgaqy9nvn2hf5t2sra9ycz8s77wnf9l0kmgcp", toAddress));
    const auto tokenContractAddress = "terra14z56l0fp2lsf86zy3hty2z47ezkhnthtr9yq76"; // ANC

    auto msg = input.add_messages();
    auto& message = *msg->mutable_wasm_terra_execute_contract_transfer_message();
    message.set_sender_address(fromAddress.string());
    message.set_contract_address(tokenContractAddress);
    const auto amount = store(uint256_t(250000), 0);
    message.set_amount(amount.data(), amount.size());
    message.set_recipient_address(toAddress.string());

    auto& fee = *input.mutable_fee();
    fee.set_gas(200000);
    auto amountOfFee = fee.add_amounts();
    amountOfFee->set_denom("uluna");
    amountOfFee->set_amount("3000");

    std::string json;
    google::protobuf::util::MessageToJsonString(input, &json);
    assertJSONEqual(json, R"(
        {
            "signingMode": "Protobuf",
            "accountNumber": "3407705",
            "chainId": "phoenix-1",
            "fee": {
                "amounts": [
                    {
                        "denom": "uluna",
                        "amount": "3000"
                    }
                ],
                "gas": "200000"
            },
            "sequence": "3",
            "messages": [
                {
                    "wasmTerraExecuteContractTransferMessage": {
                        "senderAddress": "terra18wukp84dq227wu4mgh0jm6n9nlnj6rs82pp9wf",
                        "contractAddress": "terra14z56l0fp2lsf86zy3hty2z47ezkhnthtr9yq76",
                        "amount": "A9CQ",
                        "recipientAddress": "terra1jlgaqy9nvn2hf5t2sra9ycz8s77wnf9l0kmgcp"
                    }
                }
            ]
        }
    )");

    auto privateKey = parse_hex("cf08ee8493e6f6a53f9721b9045576e80f371c0e36d08fdaf78b27a7afd8e616");
    input.set_private_key(privateKey.data(), privateKey.size());

    auto output = Signer::sign(input, TWCoinTypeTerra);

    // https://finder.terra.money/mainnet/tx/9FF3F0A16879254C22EB90D8B4D6195467FE5014381FD36BD3C23CA6698FE94B
    // curl -H 'Content-Type: application/json' --data-binary '{"mode": "BROADCAST_MODE_BLOCK","tx_bytes": "CogCCo..wld8"})' https://<lcd-node-url>/cosmos/tx/v1beta1/txs
    assertJSONEqual(output.serialized(), R"(
        {
            "tx_bytes": "CucBCuQBCiYvdGVycmEud2FzbS52MWJldGExLk1zZ0V4ZWN1dGVDb250cmFjdBK5AQosdGVycmExOHd1a3A4NGRxMjI3d3U0bWdoMGptNm45bmxuajZyczgycHA5d2YSLHRlcnJhMTR6NTZsMGZwMmxzZjg2enkzaHR5Mno0N2V6a2hudGh0cjl5cTc2Glt7InRyYW5zZmVyIjp7ImFtb3VudCI6IjI1MDAwMCIsInJlY2lwaWVudCI6InRlcnJhMWpsZ2FxeTludm4yaGY1dDJzcmE5eWN6OHM3N3duZjlsMGttZ2NwIn19EmcKUApGCh8vY29zbW9zLmNyeXB0by5zZWNwMjU2azEuUHViS2V5EiMKIQNwZjrHsPmJKW/rXOWfukpQ1+lOHOJW3/IlFFnKLNmsABIECgIIARgDEhMKDQoFdWx1bmESBDMwMDAQwJoMGkB1m3Fnt983fsY8Lo6sio0Di7HU3OVTsRTURM4XDwQ4DjiENEnKCZ73NwN4qBR99Bup3C+iF7XZYac/ueUZY9IO",
            "mode": "BROADCAST_MODE_BLOCK"
        }
    )");
    EXPECT_EQ(hex(output.signature()), "759b7167b7df377ec63c2e8eac8a8d038bb1d4dce553b114d444ce170f04380e38843449ca099ef7370378a8147df41ba9dc2fa217b5d961a73fb9e51963d20e");
    EXPECT_EQ(output.json(), "");
    EXPECT_EQ(output.error(), "");
}

TEST(TerraSigner, SignWasmTransferTxJson_078E90) {
    auto input = Proto::SigningInput();
    input.set_signing_mode(Proto::JSON);
    input.set_account_number(3407705);
    input.set_chain_id("phoenix-1");
    input.set_memo("");
    input.set_sequence(2);

    Address fromAddress;
    ASSERT_TRUE(Address::decode("terra18wukp84dq227wu4mgh0jm6n9nlnj6rs82pp9wf", fromAddress));
    Address toAddress;
    ASSERT_TRUE(Address::decode("terra1jlgaqy9nvn2hf5t2sra9ycz8s77wnf9l0kmgcp", toAddress));
    const auto tokenContractAddress = "terra14z56l0fp2lsf86zy3hty2z47ezkhnthtr9yq76"; // ANC

    auto msg = input.add_messages();
    auto& message = *msg->mutable_wasm_terra_execute_contract_transfer_message();
    message.set_sender_address(fromAddress.string());
    message.set_contract_address(tokenContractAddress);
    const auto amount = store(250000);
    message.set_amount(amount.data(), amount.size());
    message.set_recipient_address(toAddress.string());

    auto& fee = *input.mutable_fee();
    fee.set_gas(200000);
    auto amountOfFee = fee.add_amounts();
    amountOfFee->set_denom("uluna");
    amountOfFee->set_amount("3000");

    auto privateKey = parse_hex("cf08ee8493e6f6a53f9721b9045576e80f371c0e36d08fdaf78b27a7afd8e616");
    input.set_private_key(privateKey.data(), privateKey.size());

    auto output = Signer::sign(input, TWCoinTypeTerra);

    // https://finder.terra.money/mainnet/tx/078E90458061611F6FD8B708882B55FF5C1FFB3FCE61322107A0A0DE39FC0F3E
    // curl -H 'Content-Type: application/json' --data-binary '{"mode": "block","tx":{...}}' https://<lcd-node-url>/txs
    assertJSONEqual(output.json(), R"(
        {
            "mode": "block",
            "tx":
                {
                    "fee": {"amount":[{"amount": "3000","denom": "uluna"}],"gas": "200000"},
                    "memo": "",
                    "msg":
                        [
                            {
                                "type": "wasm/MsgExecuteContract",
                                "value":
                                    {
                                        "sender": "terra18wukp84dq227wu4mgh0jm6n9nlnj6rs82pp9wf",
                                        "contract": "terra14z56l0fp2lsf86zy3hty2z47ezkhnthtr9yq76",
                                        "execute_msg":
                                            {
                                                "transfer":
                                                    {
                                                        "amount": "250000",
                                                        "recipient": "terra1jlgaqy9nvn2hf5t2sra9ycz8s77wnf9l0kmgcp"
                                                    }
                                            },
                                        "coins": []
                                    }
                            }
                        ],
                    "signatures":
                        [
                            {
                                "pub_key":
                                    {
                                        "type": "tendermint/PubKeySecp256k1",
                                        "value": "A3BmOsew+Ykpb+tc5Z+6SlDX6U4c4lbf8iUUWcos2awA"
                                    },
                                "signature": "O97aLnylpxHXoeCcLtTfNFDQWdb6q8uq/klTh24qCupKd6B4qeO5o6l7ejXnAX1b1WiqipgzvYSHYOYA5EFHYw=="
                            }
                        ]
                }
        })");
    EXPECT_EQ(hex(output.signature()), "3bdeda2e7ca5a711d7a1e09c2ed4df3450d059d6faabcbaafe4953876e2a0aea4a77a078a9e3b9a3a97b7a35e7017d5bd568aa8a9833bd848760e600e4414763");
    EXPECT_EQ(output.serialized(), "");
    EXPECT_EQ(output.error(), "");
}

TEST(TerraSigner, SignWasmGeneric_EC4F85) {
    auto input = Proto::SigningInput();
    input.set_signing_mode(Proto::Protobuf);
    input.set_account_number(3407705);
    input.set_chain_id("phoenix-1");
    input.set_memo("");
    input.set_sequence(7);

    Address fromAddress;
    ASSERT_TRUE(Address::decode("terra18wukp84dq227wu4mgh0jm6n9nlnj6rs82pp9wf", fromAddress));
    Address toAddress;
    ASSERT_TRUE(Address::decode("terra1jlgaqy9nvn2hf5t2sra9ycz8s77wnf9l0kmgcp", toAddress));
    const auto tokenContractAddress = "terra14z56l0fp2lsf86zy3hty2z47ezkhnthtr9yq76"; // ANC
    const auto txMessage = R"({"transfer": { "amount": "250000", "recipient": "terra1d7048csap4wzcv5zm7z6tdqem2agyp9647vdyj" } })";

    auto msg = input.add_messages();
    auto& message = *msg->mutable_wasm_terra_execute_contract_generic();
    message.set_sender_address(fromAddress.string());
    message.set_contract_address(tokenContractAddress);
    message.set_execute_msg(txMessage);

    auto& fee = *input.mutable_fee();
    fee.set_gas(200000);
    auto amountOfFee = fee.add_amounts();
    amountOfFee->set_denom("uluna");
    amountOfFee->set_amount("3000");

    auto privateKey = parse_hex("cf08ee8493e6f6a53f9721b9045576e80f371c0e36d08fdaf78b27a7afd8e616");
    input.set_private_key(privateKey.data(), privateKey.size());

    auto output = Signer::sign(input, TWCoinTypeTerra);

    // https://finder.terra.money/mainnet/tx/EC4F8532847E4D6AF016E6F6D3F027AE7FB6FF0B533C5132B01382D83B214A6F
    // curl -H 'Content-Type: application/json' --data-binary '{"mode": "BROADCAST_MODE_BLOCK","tx_bytes": "Cu4BC...iVt"})' https://<lcd-node-url>/cosmos/tx/v1beta1/txs
    assertJSONEqual(output.serialized(), R"(
        {
            "tx_bytes": "Cu4BCusBCiYvdGVycmEud2FzbS52MWJldGExLk1zZ0V4ZWN1dGVDb250cmFjdBLAAQosdGVycmExOHd1a3A4NGRxMjI3d3U0bWdoMGptNm45bmxuajZyczgycHA5d2YSLHRlcnJhMTR6NTZsMGZwMmxzZjg2enkzaHR5Mno0N2V6a2hudGh0cjl5cTc2GmJ7InRyYW5zZmVyIjogeyAiYW1vdW50IjogIjI1MDAwMCIsICJyZWNpcGllbnQiOiAidGVycmExZDcwNDhjc2FwNHd6Y3Y1em03ejZ0ZHFlbTJhZ3lwOTY0N3ZkeWoiIH0gfRJnClAKRgofL2Nvc21vcy5jcnlwdG8uc2VjcDI1NmsxLlB1YktleRIjCiEDcGY6x7D5iSlv61zln7pKUNfpThziVt/yJRRZyizZrAASBAoCCAEYBxITCg0KBXVsdW5hEgQzMDAwEMCaDBpAMqiyuTNZUrFOMYa/RmbmyyyaY8RL3Y2bMBEvsdH25xEYkroSvnOzcVVbkbWS1RD+FJlGtVdL8W6h1YkgUyWOPA==",
            "mode": "BROADCAST_MODE_BLOCK"
        }
    )");

    EXPECT_EQ(hex(output.signature()), "32a8b2b9335952b14e3186bf4666e6cb2c9a63c44bdd8d9b30112fb1d1f6e7111892ba12be73b371555b91b592d510fe149946b5574bf16ea1d5892053258e3c");
    EXPECT_EQ(output.json(), "");
    EXPECT_EQ(output.error(), "");
}


TEST(TerraSigner, SignWasmGenericWithCoins_6651FC) {
    auto input = Proto::SigningInput();
    input.set_signing_mode(Proto::Protobuf);
    input.set_account_number(3407705);
    input.set_chain_id("phoenix-1");
    input.set_memo("");
    input.set_sequence(9);

    Address fromAddress;
    ASSERT_TRUE(Address::decode("terra18wukp84dq227wu4mgh0jm6n9nlnj6rs82pp9wf", fromAddress));
    Address toAddress;
    ASSERT_TRUE(Address::decode("terra1jlgaqy9nvn2hf5t2sra9ycz8s77wnf9l0kmgcp", toAddress));
    const auto tokenContractAddress = "terra1sepfj7s0aeg5967uxnfk4thzlerrsktkpelm5s"; // ANC Market
    const auto txMessage = R"({ "deposit_stable": {} })";

    auto msg = input.add_messages();
    auto& message = *msg->mutable_wasm_terra_execute_contract_generic();
    message.set_sender_address(fromAddress.string());
    message.set_contract_address(tokenContractAddress);
    message.set_execute_msg(txMessage);

    auto amount = message.add_coins();
    amount->set_denom("uusd");
    amount->set_amount("1000");

    auto& fee = *input.mutable_fee();
    fee.set_gas(600000);
    auto amountOfFee = fee.add_amounts();
    amountOfFee->set_denom("uluna");
    amountOfFee->set_amount("7000");

    auto privateKey = parse_hex("cf08ee8493e6f6a53f9721b9045576e80f371c0e36d08fdaf78b27a7afd8e616");
    input.set_private_key(privateKey.data(), privateKey.size());

    auto output = Signer::sign(input, TWCoinTypeTerra);

    // https://finder.terra.money/mainnet/tx/6651FCE0EE5C6D6ACB655CC49A6FD5E939FB082862854616EA0642475BCDD0C9
    // curl -H 'Content-Type: application/json' --data-binary '{"mode": "BROADCAST_MODE_BLOCK","tx_bytes": "CrIBCq8B.....0NWg=="})' https://<lcd-node-url>/cosmos/tx/v1beta1/txs
    assertJSONEqual(output.serialized(), R"(
        {
            "tx_bytes": "CrIBCq8BCiYvdGVycmEud2FzbS52MWJldGExLk1zZ0V4ZWN1dGVDb250cmFjdBKEAQosdGVycmExOHd1a3A4NGRxMjI3d3U0bWdoMGptNm45bmxuajZyczgycHA5d2YSLHRlcnJhMXNlcGZqN3MwYWVnNTk2N3V4bmZrNHRoemxlcnJza3RrcGVsbTVzGhh7ICJkZXBvc2l0X3N0YWJsZSI6IHt9IH0qDAoEdXVzZBIEMTAwMBJnClAKRgofL2Nvc21vcy5jcnlwdG8uc2VjcDI1NmsxLlB1YktleRIjCiEDcGY6x7D5iSlv61zln7pKUNfpThziVt/yJRRZyizZrAASBAoCCAEYCRITCg0KBXVsdW5hEgQ3MDAwEMDPJBpAweKp9RwZEfKzsKCUoC9zjC1dB8n5S5VFGWGfrBf7QCp+De6rT8jXP4g8h3uKmyK5QPUcOjU81wktKPIBrjMRAg==",
            "mode": "BROADCAST_MODE_BLOCK"
        }
    )");

    EXPECT_EQ(hex(output.signature()), "c1e2a9f51c1911f2b3b0a094a02f738c2d5d07c9f94b954519619fac17fb402a7e0deeab4fc8d73f883c877b8a9b22b940f51c3a353cd7092d28f201ae331102");
    EXPECT_EQ(output.json(), "");
    EXPECT_EQ(output.error(), "");
}

TEST(TerraSigner, SignWasmSendTxProtobuf) {
    auto input = Proto::SigningInput();
    input.set_signing_mode(Proto::Protobuf);
    input.set_account_number(3407705);
    input.set_chain_id("phoenix-1");
    input.set_memo("");
    input.set_sequence(4);

    Address fromAddress;
    ASSERT_TRUE(Address::decode("terra18wukp84dq227wu4mgh0jm6n9nlnj6rs82pp9wf", fromAddress));
    Address toAddress;
    ASSERT_TRUE(Address::decode("terra1jlgaqy9nvn2hf5t2sra9ycz8s77wnf9l0kmgcp", toAddress));
    const auto tokenContractAddress = "terra14z56l0fp2lsf86zy3hty2z47ezkhnthtr9yq76"; // ANC

    auto msg = input.add_messages();
    auto& message = *msg->mutable_wasm_terra_execute_contract_send_message();
    message.set_sender_address(fromAddress.string());
    message.set_contract_address(tokenContractAddress);
    const auto amount = store(uint256_t(250000), 0);
    message.set_amount(amount.data(), amount.size());
    message.set_recipient_contract_address(toAddress.string());
    const auto msgMsg = Base64::encode(data(std::string(R"({"some_message":{}})")));
    EXPECT_EQ(msgMsg, "eyJzb21lX21lc3NhZ2UiOnt9fQ==");
    message.set_msg(msgMsg);

    auto& fee = *input.mutable_fee();
    fee.set_gas(200000);
    auto amountOfFee = fee.add_amounts();
    amountOfFee->set_denom("uluna");
    amountOfFee->set_amount("3000");

    std::string json;
    google::protobuf::util::MessageToJsonString(input, &json);
    assertJSONEqual(json, R"(
        {
            "signingMode": "Protobuf",
            "accountNumber": "3407705",
            "chainId": "phoenix-1",
            "fee": {
                "amounts": [
                    {
                        "denom": "uluna",
                        "amount": "3000"
                    }
                ],
                "gas": "200000"
            },
            "sequence": "4",
            "messages": [
                {
                    "wasmTerraExecuteContractSendMessage": {
                        "senderAddress": "terra18wukp84dq227wu4mgh0jm6n9nlnj6rs82pp9wf",
                        "contractAddress": "terra14z56l0fp2lsf86zy3hty2z47ezkhnthtr9yq76",
                        "amount": "A9CQ",
                        "recipientContractAddress": "terra1jlgaqy9nvn2hf5t2sra9ycz8s77wnf9l0kmgcp",
                        "msg": "eyJzb21lX21lc3NhZ2UiOnt9fQ=="
                    }
                }
            ]
        }
    )");

    auto privateKey = parse_hex("cf08ee8493e6f6a53f9721b9045576e80f371c0e36d08fdaf78b27a7afd8e616");
    input.set_private_key(privateKey.data(), privateKey.size());

    auto output = Signer::sign(input, TWCoinTypeTerra);

    // https://finder.terra.money/mainnet/tx/9FF3F0A16879254C22EB90D8B4D6195467FE5014381FD36BD3C23CA6698FE94B
    // curl -H 'Content-Type: application/json' --data-binary '{"mode": "BROADCAST_MODE_BLOCK","tx_bytes": "CogCCo..wld8"})' https://<lcd-node-url>/cosmos/tx/v1beta1/txs
    assertJSONEqual(output.serialized(), R"(
        {
            "tx_bytes": "CocCCoQCCiYvdGVycmEud2FzbS52MWJldGExLk1zZ0V4ZWN1dGVDb250cmFjdBLZAQosdGVycmExOHd1a3A4NGRxMjI3d3U0bWdoMGptNm45bmxuajZyczgycHA5d2YSLHRlcnJhMTR6NTZsMGZwMmxzZjg2enkzaHR5Mno0N2V6a2hudGh0cjl5cTc2Gnt7InNlbmQiOnsiYW1vdW50IjoiMjUwMDAwIiwiY29udHJhY3QiOiJ0ZXJyYTFqbGdhcXk5bnZuMmhmNXQyc3JhOXljejhzNzd3bmY5bDBrbWdjcCIsIm1zZyI6ImV5SnpiMjFsWDIxbGMzTmhaMlVpT250OWZRPT0ifX0SZwpQCkYKHy9jb3Ntb3MuY3J5cHRvLnNlY3AyNTZrMS5QdWJLZXkSIwohA3BmOsew+Ykpb+tc5Z+6SlDX6U4c4lbf8iUUWcos2awAEgQKAggBGAQSEwoNCgV1bHVuYRIEMzAwMBDAmgwaQMGVYiu+evsra9ETnF+OCX6t9OvhYu4Sdqo3Lw1noJ3/CwGH2ycnuLPfrvd7FAKc9Eh//qTSAXHdtRM2wP8+YSo=",
            "mode": "BROADCAST_MODE_BLOCK"
        }
    )");
    EXPECT_EQ(hex(output.signature()), "c195622bbe7afb2b6bd1139c5f8e097eadf4ebe162ee1276aa372f0d67a09dff0b0187db2727b8b3dfaef77b14029cf4487ffea4d20171ddb51336c0ff3e612a");
    EXPECT_EQ(output.json(), "");
    EXPECT_EQ(output.error(), "");
}

TEST(TerraSigner, SignWasmTerraTransferPayload) {
    auto proto = Proto::Message_WasmTerraExecuteContractTransfer();
    proto.set_recipient_address("recipient=address");
    const auto amount = store(uint256_t(250000), 0);
    proto.set_amount(amount.data(), amount.size());

    const auto payload = wasmTerraExecuteTransferPayload(proto);

    assertJSONEqual(payload.dump(), R"(
        {
            "transfer":
                {
                    "amount": "250000",
                    "recipient": "recipient=address"
                }
        }
    )");
}
