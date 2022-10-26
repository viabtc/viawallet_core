// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "NervosCKB/Serializer.h"
#include "NervosCKB/WitnessArgs.h"
#include "NervosCKB/CellDep.h"
#include "NervosCKB/CellInput.h"
#include "NervosCKB/Script.h"
#include "NervosCKB/CellOutput.h"
#include "NervosCKB/CKBConstant.h"
#include <gtest/gtest.h>

using namespace TW;
using namespace TW::NervosCKB;

const auto txHash1 = parse_hex("0xbffab7ee0a050e2cb882de066d3dbf3afdd8932d6a26eda44f06e4b23f0f4b5a");
const auto outPoint1 = OutPoint(txHash1, 0);
const auto cellDep1 = CellDep(outPoint1, CellDep::DepType::CODE);

const auto txHash2 = parse_hex("0x29f94532fb6c7a17f13bcde5adb6e2921776ee6f357adf645e5393bd13442141");
const auto outPoint2 = OutPoint(txHash2, 0);
const auto cellDep2 = CellDep(outPoint2, CellDep::DepType::CODE);

const auto txHash3 = parse_hex("0x5ba156200c6310bf140fbbd3bfe7e8f03d4d5f82b612c1a8ec2501826eaabc17");
const auto outPoint3 = OutPoint(txHash3, 0);
const auto cellInput1 = CellInput(outPoint3, 0);
const auto cellInput2 = CellInput(outPoint3, 1);

const auto txHash4 = parse_hex("0x68d5438ac952d2f584abf879527946a537e82c7f3c1cbf6d8ebf9767437d8e88");
const auto txHash5 = parse_hex("0xece45e0979030e2f8909f76258631c42333b1e906fd9701ec3600a464a90b8f6");
const auto txHash6 = parse_hex("0x68d5438ac952d2f584abf879527946a537e82c7f3c1cbf6d8ebf9767437d8e88");
const auto script1 = Script(txHash4, parse_hex("0x59a27ef3ba84f061517d13f42cf44ed020610061"), SCRIPT_TYPE);
const auto script2 = Script(txHash5, Data(), SCRIPT_DATA);
const auto script3 = Script(txHash6, parse_hex("0x59a27ef3ba84f061517d13f42cf44ed020610061"), SCRIPT_TYPE);
const auto cellOutput1 = CellOutput(100'000'000'000, script1, script2);
const auto cellOutput2 = CellOutput(98'824'000'000'000, script3);

const auto cellOutput3 = CellOutput(
        100000000000,
        Script(
            parse_hex("0x9e3b3557f11b2b3532ce352bfe8017e9fd11d154c4c7f9b7aaaa1e621b539a08"),
                parse_hex("0xe2193df51d78411601796b35b17b4f8f2cd85bd0"),
                    SCRIPT_DATA
        )
);
const auto cellOutput4 = CellOutput(
        4900000000000,
        Script(
            parse_hex("0x9e3b3557f11b2b3532ce352bfe8017e9fd11d154c4c7f9b7aaaa1e621b539a08"),
                parse_hex("0x36c329ed630d6ce750712a477543672adab57f4c"),
                    SCRIPT_DATA
        )
);


TEST(NervosCKBSerializer, UInt32Serializer) {
    auto string = hex(uint32Serialize(uint32_t(16909060)));
    ASSERT_EQ(string, "04030201");
}

TEST(NervosCKBSerializer, UInt64Serializer) {
    auto string = hex(uint64Serialize(uint64_t(0xffffffffffffffff)));
    ASSERT_EQ(string, "ffffffffffffffff");
}

TEST(NervosCKBSerializer, OutPoint) {
    ASSERT_EQ(hex(outPointSerialize(outPoint1)), "bffab7ee0a050e2cb882de066d3dbf3afdd8932d6a26eda44f06e4b23f0f4b5a00000000");
    ASSERT_EQ(hex(outPointSerialize(outPoint2)), "29f94532fb6c7a17f13bcde5adb6e2921776ee6f357adf645e5393bd1344214100000000");
}

TEST(NervosCKBSerializer, CellDep) {
    ASSERT_EQ(hex(cellDepSerialize(cellDep1)), "bffab7ee0a050e2cb882de066d3dbf3afdd8932d6a26eda44f06e4b23f0f4b5a0000000000");
    ASSERT_EQ(hex(cellDepSerialize(cellDep2)), "29f94532fb6c7a17f13bcde5adb6e2921776ee6f357adf645e5393bd134421410000000000");
}

TEST(NervosCKBSerializer, CellInput) {
    ASSERT_EQ(hex(cellInputSerialize(cellInput1)),
              "00000000000000005ba156200c6310bf140fbbd3bfe7e8f03d4d5f82b612c1a8ec2501826eaabc1700000000");
    ASSERT_EQ(hex(cellInputSerialize(cellInput2)),
              "01000000000000005ba156200c6310bf140fbbd3bfe7e8f03d4d5f82b612c1a8ec2501826eaabc1700000000");
}

TEST(NervosCKBSerializer, CellOutput) {
    ASSERT_EQ(hex(cellOutputSerialize(cellOutput1)),
              "9600000010000000180000006100000000e87648170000004900000010000000300000003100000068d5438ac952d2f584abf879527946a537e82c7f3c1cbf6d8ebf9767437d8e88011400000059a27ef3ba84f061517d13f42cf44ed02061006135000000100000003000000031000000ece45e0979030e2f8909f76258631c42333b1e906fd9701ec3600a464a90b8f60000000000");
    ASSERT_EQ(hex(cellOutputSerialize(cellOutput2)),
              "6100000010000000180000006100000000506a41e15900004900000010000000300000003100000068d5438ac952d2f584abf879527946a537e82c7f3c1cbf6d8ebf9767437d8e88011400000059a27ef3ba84f061517d13f42cf44ed020610061");
}

TEST(NervosCKBSerializer, FixVecSerializer) {
    std::vector<Data> value1;
    value1.push_back(cellDepSerialize(cellDep1));
    auto string1 = hex(fixVecSerialize(value1));
    ASSERT_EQ(string1, "01000000bffab7ee0a050e2cb882de066d3dbf3afdd8932d6a26eda44f06e4b23f0f4b5a0000000000");

    std::vector<Data> value2;
    value2.push_back(cellDepSerialize(cellDep2));
    auto string2 = hex(fixVecSerialize(value2));
    ASSERT_EQ(string2, "0100000029f94532fb6c7a17f13bcde5adb6e2921776ee6f357adf645e5393bd134421410000000000");

    std::vector<Data> value3;
    value3.push_back(parse_hex("0x8033e126475d197f2366bbc2f30b907d15af85c9d9533253c6f0787dcbbb509e"));
    ASSERT_EQ(hex(fixVecSerialize(value3)),
              "010000008033e126475d197f2366bbc2f30b907d15af85c9d9533253c6f0787dcbbb509e");

    std::vector<Data> value4;
    value4.push_back(cellInputSerialize(cellInput1));
    value4.push_back(cellInputSerialize(cellInput2));
    ASSERT_EQ(hex(fixVecSerialize(value4)),
              "0200000000000000000000005ba156200c6310bf140fbbd3bfe7e8f03d4d5f82b612c1a8ec2501826eaabc170000000001000000000000005ba156200c6310bf140fbbd3bfe7e8f03d4d5f82b612c1a8ec2501826eaabc1700000000");
}

TEST(NervosCKBSerializer, DynVecSerializer) {
    std::vector<Data> value;
    ASSERT_EQ(hex(dynVecSerialize(value)), "04000000");

    std::vector<Data> value1;
    value1.push_back(bytesSerialize({0x12, 0x34}));
    ASSERT_EQ(hex(dynVecSerialize(value1)), "0e00000008000000020000001234");

    std::vector<Data> value2;
    value2.push_back(bytesSerialize({0x12, 0x34}));
    value2.push_back(bytesSerialize({}));
    value2.push_back(bytesSerialize({0x05, 0x67}));
    value2.push_back(bytesSerialize({0x89}));
    value2.push_back(bytesSerialize({0xab, 0xcd, 0xef}));
    ASSERT_EQ(hex(dynVecSerialize(value2)), "34000000180000001e00000022000000280000002d00000002000000123400000000020000000567010000008903000000abcdef");

    std::vector<Data> value3;
    value3.push_back(cellOutputSerialize(cellOutput1));
    value3.push_back(cellOutputSerialize(cellOutput2));
    ASSERT_EQ(hex(dynVecSerialize(value3)),
              "030100000c000000a20000009600000010000000180000006100000000e87648170000004900000010000000300000003100000068d5438ac952d2f584abf879527946a537e82c7f3c1cbf6d8ebf9767437d8e88011400000059a27ef3ba84f061517d13f42cf44ed02061006135000000100000003000000031000000ece45e0979030e2f8909f76258631c42333b1e906fd9701ec3600a464a90b8f600000000006100000010000000180000006100000000506a41e15900004900000010000000300000003100000068d5438ac952d2f584abf879527946a537e82c7f3c1cbf6d8ebf9767437d8e88011400000059a27ef3ba84f061517d13f42cf44ed020610061");

}

TEST(NervosCKBSerializer, WitnessArgsOptionValueSerialization) {
    Data data = witnessArgsSerialize(WitnessArgs(Data(), Data(), Data()));
    auto string = hex(data);
    ASSERT_EQ(string, "10000000100000001000000010000000");
}

TEST(NervosCKBSerializer, WitnessArgsEmptyLock) {
    Data data = witnessArgsSerialize(WitnessArgs(std::vector<byte>(65, 0), Data(), Data()));
    auto string = hex(data);
    ASSERT_EQ(string,
              "55000000100000005500000055000000410000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
}