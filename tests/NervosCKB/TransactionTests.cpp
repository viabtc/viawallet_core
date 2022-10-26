// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "NervosCKB/Serializer.h"
#include "NervosCKB/CKBConstant.h"
#include "PrivateKey.h"
#include <gtest/gtest.h>

using namespace TW;
using namespace TW::NervosCKB;

TEST(NervosCKBTransaction, Transaction) {
    auto tx1 = Transaction();
    tx1.version = 0;
    tx1.cellDeps = {
            CellDep(
                    OutPoint(parse_hex("0xbffab7ee0a050e2cb882de066d3dbf3afdd8932d6a26eda44f06e4b23f0f4b5a"), 0),
                    CellDep::DepType::CODE
                    )
    };
    tx1.outputs = {
            CellOutput(
                    100000000000,
                    Script(
                            parse_hex("0x9e3b3557f11b2b3532ce352bfe8017e9fd11d154c4c7f9b7aaaa1e621b539a08"),
                            parse_hex("0xe2193df51d78411601796b35b17b4f8f2cd85bd0"),
                            SCRIPT_DATA
                            )
                    ),
            CellOutput(
                    4900000000000,
                    Script(
                            parse_hex("0x9e3b3557f11b2b3532ce352bfe8017e9fd11d154c4c7f9b7aaaa1e621b539a08"),
                            parse_hex("0x36c329ed630d6ce750712a477543672adab57f4c"),
                            SCRIPT_DATA
                    )
            )
    };
    tx1.outputsData = {Data(), Data()};
    tx1.witnesses = {Data()};
    ASSERT_EQ(hex(transactionSerialize(tx1)), "330100001c00000020000000490000004d000000510000001f0100000000000001000000bffab7ee0a050e2cb882de066d3dbf3afdd8932d6a26eda44f06e4b23f0f4b5a00000000000000000000000000ce0000000c0000006d0000006100000010000000180000006100000000e8764817000000490000001000000030000000310000009e3b3557f11b2b3532ce352bfe8017e9fd11d154c4c7f9b7aaaa1e621b539a080014000000e2193df51d78411601796b35b17b4f8f2cd85bd0610000001000000018000000610000000068c2de74040000490000001000000030000000310000009e3b3557f11b2b3532ce352bfe8017e9fd11d154c4c7f9b7aaaa1e621b539a08001400000036c329ed630d6ce750712a477543672adab57f4c140000000c000000100000000000000000000000");
    ASSERT_EQ(hex(tx1.hash()), "4c02905db773301f73bbc6cd5a400c928caf410bbb13136f6f48bec0a79c22e4");

    auto tx2 = Transaction();
    tx2.cellDeps = {
            CellDep(
                    OutPoint(parse_hex("0x29f94532fb6c7a17f13bcde5adb6e2921776ee6f357adf645e5393bd13442141"), 0),
                    CellDep::DepType::CODE
                    )
    };
    tx2.headerDeps = {parse_hex("0x8033e126475d197f2366bbc2f30b907d15af85c9d9533253c6f0787dcbbb509e")};
    tx2.inputs = {
            CellInput(
                    OutPoint(parse_hex("0x5ba156200c6310bf140fbbd3bfe7e8f03d4d5f82b612c1a8ec2501826eaabc17"), 0),
                    0
                    )
    };
    tx2.outputs = {
            CellOutput(
                    100000000000,
                    Script(
                            parse_hex("0x28e83a1277d48add8e72fadaa9248559e1b632bab2bd60b27955ebc4c03800a5"),
                            Data(),
                            SCRIPT_DATA
                    )
            )
    };
    tx2.outputsData = {Data()};
    ASSERT_EQ(hex(tx2.hash()), "6f6b16079884d8127490aac5e0f87274e81f15ea1fd6c9672a5b0326bd8ce76d");

    auto tx3 = Transaction();
    tx3.cellDeps = {
            CellDep(
                    OutPoint(parse_hex("0x29f94532fb6c7a17f13bcde5adb6e2921776ee6f357adf645e5393bd13442141"), 0),
                    CellDep::DepType::CODE
            )
    };
    tx3.headerDeps = {
            parse_hex("0x8033e126475d197f2366bbc2f30b907d15af85c9d9533253c6f0787dcbbb509e")
    };
    tx3.inputs = {
            CellInput(
                    OutPoint(parse_hex("0x5ba156200c6310bf140fbbd3bfe7e8f03d4d5f82b612c1a8ec2501826eaabc17"), 0),
                    0
            ),
            CellInput(
                    OutPoint(parse_hex("0x5ba156200c6310bf140fbbd3bfe7e8f03d4d5f82b612c1a8ec2501826eaabc17"), 0),
                    1
            )
    };
    tx3.outputsData = {Data()};
    tx3.witnesses = {
            parse_hex("0x4107bd23eedb9f2a2a749108f6bb9720d745d50f044cc4814bafe189a01fe6fb"),
            parse_hex("0x4107bd23eedb9f2a2a749108f6bb9720d745d50f044cc4814bafe189a01fe6fb")
    };
    ASSERT_EQ(hex(tx3.hash()), "e37f68d4d81e0f790ca98c5abbd763764f826170867a0b96137f68df908e5641");
}

TEST(NervosCKBTransaction, SizeInBlock) {
    auto tx = Transaction();
    tx.cellDeps = {
            CellDep(
                    OutPoint(parse_hex("0xc12386705b5cbb312b693874f3edf45c43a274482e27b8df0fd80c8d3f5feb8b"), 0),
                    CellDep::DepType::DEP_GROUP
                    ),
            CellDep(
                    OutPoint(parse_hex("0x0fb4945d52baf91e0dee2a686cdd9d84cad95b566a1d7409b970ee0a0f364f60"), 2),
                    CellDep::DepType::DEP_GROUP
                    )
    };
    tx.inputs = {
            CellInput(OutPoint(parse_hex("0x31f695263423a4b05045dd25ce6692bb55d7bba2965d8be16b036e138e72cc65"), 1), 0)
    };
    tx.outputs = {
            CellOutput(
                    100000000000,
                    Script(parse_hex("0x68d5438ac952d2f584abf879527946a537e82c7f3c1cbf6d8ebf9767437d8e88"), parse_hex("0x59a27ef3ba84f061517d13f42cf44ed020610061"), SCRIPT_TYPE),
                    Script(parse_hex("0xece45e0979030e2f8909f76258631c42333b1e906fd9701ec3600a464a90b8f6"), Data(), SCRIPT_DATA)
                    ),
            CellOutput(
                    98824000000000,
                    Script(parse_hex("0x68d5438ac952d2f584abf879527946a537e82c7f3c1cbf6d8ebf9767437d8e88"), parse_hex("0x59a27ef3ba84f061517d13f42cf44ed020610061"), SCRIPT_TYPE)
                    )
    };
    tx.outputsData = {Data({0x12, 0x34}), Data()};
    tx.witnesses = {
        parse_hex("0x82df73581bcd08cb9aa270128d15e79996229ce8ea9e4f985b49fbf36762c5c37936caf3ea3784ee326f60b8992924fcf496f9503c907982525a3436f01ab32900")
    };
    ASSERT_EQ(hex(tx.hash()), "c918beb46c8343d4cf063a053809478304cf7548ffd5e3d3d6eefa2ce8f925bf");

    auto txData = transactionPlusWitnessesSerialize(tx);
    ASSERT_EQ(hex(txData), "140200000c000000c7010000bb0100001c000000200000006e00000072000000a2000000a50100000000000002000000c12386705b5cbb312b693874f3edf45c43a274482e27b8df0fd80c8d3f5feb8b00000000010fb4945d52baf91e0dee2a686cdd9d84cad95b566a1d7409b970ee0a0f364f6002000000010000000001000000000000000000000031f695263423a4b05045dd25ce6692bb55d7bba2965d8be16b036e138e72cc6501000000030100000c000000a20000009600000010000000180000006100000000e87648170000004900000010000000300000003100000068d5438ac952d2f584abf879527946a537e82c7f3c1cbf6d8ebf9767437d8e88011400000059a27ef3ba84f061517d13f42cf44ed02061006135000000100000003000000031000000ece45e0979030e2f8909f76258631c42333b1e906fd9701ec3600a464a90b8f600000000006100000010000000180000006100000000506a41e15900004900000010000000300000003100000068d5438ac952d2f584abf879527946a537e82c7f3c1cbf6d8ebf9767437d8e88011400000059a27ef3ba84f061517d13f42cf44ed020610061160000000c00000012000000020000001234000000004d000000080000004100000082df73581bcd08cb9aa270128d15e79996229ce8ea9e4f985b49fbf36762c5c37936caf3ea3784ee326f60b8992924fcf496f9503c907982525a3436f01ab32900");

    auto size = tx.serializedSizeInBlock();
    EXPECT_EQ(size, 536);

    EXPECT_EQ(tx.fee(1000), 536);
}

TEST(NervosCKBTransaction, FeeForSizeAndRate) {
    EXPECT_EQ(Transaction::fee(1035, 900), 932);
    EXPECT_EQ(Transaction::fee(1035, 1000), 1035);
    EXPECT_EQ(Transaction::fee(1038, 1002), 1041);
}

TEST(NervosCKBTransaction, Sign) {
    auto tx = Transaction();
    tx.cellDeps = {
            CellDep(OutPoint(parse_hex("0xa76801d09a0eabbfa545f1577084b6f3bafb0b6250e7f5c89efcfd4e3499fb55"), 1), CellDep::DepType::CODE)
    };
    tx.inputs = {
            CellInput(OutPoint(parse_hex("0xa80a8e01d45b10e1cbc8a2557c62ba40edbdc36cd63a31fc717006ca7b157b50"), 0), 0)
    };
    tx.outputs = {
            CellOutput(
                    100000000000,
                    Script(parse_hex("0x9e3b3557f11b2b3532ce352bfe8017e9fd11d154c4c7f9b7aaaa1e621b539a08"), parse_hex("0xe2193df51d78411601796b35b17b4f8f2cd85bd0"), SCRIPT_DATA)
            ),
            CellOutput(
                    4900000000000,
                    Script(parse_hex("0x9e3b3557f11b2b3532ce352bfe8017e9fd11d154c4c7f9b7aaaa1e621b539a08"), parse_hex("0x36c329ed630d6ce750712a477543672adab57f4c"), SCRIPT_DATA)
            )
    };
    tx.outputsData = {Data(), Data()};
    tx.unsignedWitnesses = {WitnessArgs(std::vector<byte>(65, 0), Data(), Data())};
    auto hash = tx.messageHash();
    auto key = PrivateKey(parse_hex("0xe79f3207ea4980b7fed79956d5934249ceac4751a4fae01a0f7c4a96884bc4e3"));
    auto signature = key.sign(hash, TWCurveSECP256k1);
    ASSERT_EQ(hex(signature), "7a360306c20f1f0081d27feff5c59fb9b4307b25876543848010614fb78ea21d165f48f67ae3357eeafbad2033b1e53cd737d4e670de60e1081d514b1e05cf5100");
}

TEST(NervosCKBTransaction, MultipleInputsSign) {
    auto tx = Transaction();
    tx.cellDeps = {
            CellDep(OutPoint(parse_hex("0xa76801d09a0eabbfa545f1577084b6f3bafb0b6250e7f5c89efcfd4e3499fb55"), 1), CellDep::DepType::CODE)
    };
    tx.inputs = {
            CellInput(OutPoint(parse_hex("0x91fcfd61f420c1090aeded6b6d91d5920a279fe53ec34353afccc59264eeddd4"), 0), 113),
            CellInput(OutPoint(parse_hex("0x00000000000000000000000000004e4552564f5344414f494e50555430303031"), 0), 0)
    };
    tx.outputs = {
            CellOutput(
                    10000009045634,
                    Script(parse_hex("0xf1951123466e4479842387a66fabfd6b65fc87fd84ae8e6cd3053edb27fff2fd"), parse_hex("0x36c329ed630d6ce750712a477543672adab57f4c"), SCRIPT_DATA)
            )
    };
    tx.outputsData = {Data()};
    tx.unsignedWitnesses = {
            WitnessArgs(parse_hex("0x4107bd23eedb9f2a2a749108f6bb9720d745d50f044cc4814bafe189a01fe6fb"), parse_hex("0x99caa8d7efdaab11c2bb7e45f4f385d0405f0fa2e8d3ba48496c28a2443e607d"), parse_hex("0xa6d5e23a77f4d7940aeb88764eebf8146185138641ac43b233e1c9b3daa170fa")),
            WitnessArgs(Data())
    };
    auto hash = tx.messageHash();
    auto key = PrivateKey(parse_hex("0xe79f3207ea4980b7fed79956d5934249ceac4751a4fae01a0f7c4a96884bc4e3"));
    auto signature = key.sign(hash, TWCurveSECP256k1);
    ASSERT_EQ(hex(signature), "d896d67ddda97ab2d15cd13098b40e4a2b6d6c66ad465d987df9a28b0a038f4a18dbebbc702a1a0b2056aa9e4290a3640a4d73dd1f6483e6f8e0cd2784b4a78b00");
}

TEST(NervosCKBTransaction, MultipleInputsSign2) {
    auto tx = Transaction();
    tx.cellDeps = {
            CellDep(OutPoint(parse_hex("0xe7d5ddd093bcc5909a6f441882e58906062eaf66a6ac1bcf7d7411931bc9ab72"), 0), CellDep::DepType::DEP_GROUP)
    };
    tx.inputs = {
            CellInput(OutPoint(parse_hex("0xa31b9b8d105c62d69b7fbfc09bd700f3a1d6659232ffcfaa12a048ee5d7b7f2d"), 0), 0),
            CellInput(OutPoint(parse_hex("0xec5e63e19ec0161092ba78a841e9ead5deb30e56c2d98752ed974f2f2b4aeff2"), 0), 0),
            CellInput(OutPoint(parse_hex("0x5ad2600cb884572f9d8f568822c0447f6f49eb63b53257c20d0d8559276bf4e2"), 0), 0),
            CellInput(OutPoint(parse_hex("0xf21e34224e90c1ab47f42e2977ea455445d22ba3aaeb4bd2fcb2075704f330ff"), 0), 0),
            CellInput(OutPoint(parse_hex("0xc8212696d516c63bced000d3008c4a8c27c72c03f4becb40f0bf24a31063271f"), 0), 0)
    };
    tx.outputs = {
            CellOutput(
                    1000000000000,
                    Script(parse_hex("0x9bd7e06f3ecf4be0f2fcd2188b23f1b9fcc88e5d4b65a8637b17723bbda3cce8"), parse_hex("0x59a27ef3ba84f061517d13f42cf44ed020610061"), SCRIPT_TYPE)
            ),
            CellOutput(
                    19113828003,
            Script(parse_hex("0x9bd7e06f3ecf4be0f2fcd2188b23f1b9fcc88e5d4b65a8637b17723bbda3cce8"), parse_hex("0x3954acece65096bfa81258983ddb83915fc56bd8"), SCRIPT_TYPE)
            )
    };
    tx.outputsData = {Data(), Data()};
    tx.unsignedWitnesses = {
            WitnessArgs(Data(), Data(), Data()),
            WitnessArgs(Data()),
            WitnessArgs(Data()),
            WitnessArgs(Data()),
            WitnessArgs(Data()),
    };
    auto hash = tx.messageHash();
    auto key = PrivateKey(parse_hex("0x845b781a1a094057b972714a2b09b85de4fc2eb205351c3e5179aabd264f3805"));
    auto signature = key.sign(hash, TWCurveSECP256k1);
    ASSERT_EQ(hex(signature), "90cdaca0b898586ef68c02e8514087e620d3b19767137baf2fbc8dee28c83ac047be76c76d7f5098a759f3d417c1daedf534a3772aa29159d807d948ed1f8c3a00");
}

TEST(NervosCKBTransaction, ThrowErrorWhenWitnessesUnsatisfied) {
    auto tx = Transaction();
    tx.cellDeps = {
            CellDep(OutPoint(parse_hex("0xa76801d09a0eabbfa545f1577084b6f3bafb0b6250e7f5c89efcfd4e3499fb55"), 1), CellDep::DepType::CODE)
    };
    tx.inputs = {
            CellInput(OutPoint(parse_hex("0xa80a8e01d45b10e1cbc8a2557c62ba40edbdc36cd63a31fc717006ca7b157b50"), 0), 0)
    };
    tx.outputs = {
            CellOutput(
                    100000000000,
                    Script(parse_hex("0x9e3b3557f11b2b3532ce352bfe8017e9fd11d154c4c7f9b7aaaa1e621b539a08"), parse_hex("0xe2193df51d78411601796b35b17b4f8f2cd85bd0"), SCRIPT_DATA)
            ),
            CellOutput(
                    4900000000000,
                    Script(parse_hex("0x9e3b3557f11b2b3532ce352bfe8017e9fd11d154c4c7f9b7aaaa1e621b539a08"), parse_hex("0x36c329ed630d6ce750712a477543672adab57f4c"), SCRIPT_DATA)
            )
    };
    tx.outputsData = {Data(), Data()};
    ASSERT_THROW(auto hash = tx.messageHash(), std::invalid_argument);
}
