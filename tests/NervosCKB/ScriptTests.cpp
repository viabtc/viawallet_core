// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "NervosCKB/Script.h"
#include "NervosCKB/Serializer.h"
#include <gtest/gtest.h>

using namespace TW;
using namespace TW::NervosCKB;

TEST(NervosCKBScript, Serialize) {
    H256 codeHash = parse_hex("0x68d5438ac952d2f584abf879527946a537e82c7f3c1cbf6d8ebf9767437d8e88");
    auto script = Script(codeHash, parse_hex("0x3954acece65096bfa81258983ddb83915fc56bd8"), SCRIPT_TYPE);
    ASSERT_EQ(hex(scriptSerialize(script)), "4900000010000000300000003100000068d5438ac952d2f584abf879527946a537e82c7f3c1cbf6d8ebf9767437d8e8801140000003954acece65096bfa81258983ddb83915fc56bd8");
}

TEST(NervosCKBScript, EmptyScriptHash) {
    auto script = Script();
    ASSERT_EQ(hex(script.hash()), "77c93b0632b5b6c3ef922c5b7cea208fb0a7c427a13d50e13d3fefad17e0c590");
}

TEST(NervosCKBScript, DataScriptHash) {
    H256 codeHash = parse_hex("0x28e83a1277d48add8e72fadaa9248559e1b632bab2bd60b27955ebc4c03800a5");
    auto script = Script(codeHash, Data(), SCRIPT_DATA);
    ASSERT_EQ(hex(script.hash()), "4ceaa32f692948413e213ce6f3a83337145bde6e11fd8cb94377ce2637dcc412");
}

TEST(NervosCKBScript, TypeScriptHash) {
    H256 codeHash = parse_hex("0x68d5438ac952d2f584abf879527946a537e82c7f3c1cbf6d8ebf9767437d8e88");
    auto script = Script(codeHash, parse_hex("0x3954acece65096bfa81258983ddb83915fc56bd8"), SCRIPT_TYPE);
    ASSERT_EQ(hex(script.hash()), "8a974f98096fd4b9049a787cee968d3869d3274a9b9baf382ad362e864d83798");
}

TEST(NervosCKBScript, ScriptHashWithZeroCodeHash) {
    H256 codeHash = parse_hex("0x0000000000000000000000000000000000000000000000000000000000000000");
    auto script = Script(codeHash, parse_hex("0x01"), SCRIPT_DATA);
    ASSERT_EQ(hex(script.hash()), "67951b34bce20cb71b7e235c1f8cda259628d99d94825bffe549c23b4dd2930f");
}

TEST(NervosCKBScript, LockScript) {
    auto script = Script::parseLockScript("ckb1qyqp8eqad7ffy42ezmchkjyz54rhcqf8q9pqrn323p");
    ASSERT_EQ(hex(script.hash()), "5f6761d98429e5dc4ac5eb2d6253bef761edce17123b82272f3c83cd8c8bd2e5");
}