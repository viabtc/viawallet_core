// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Handshake/Script.h"
#include "HexCoding.h"
#include <TrezorCrypto/ecdsa.h>
#include <gtest/gtest.h>
#include <vector>

using namespace TW;


TEST(HandshakeAddress, Script) {
    auto lockingScriptTo = Handshake::Script::lockScriptForAddress("hs1qp4q33c8mxg0ecnxk5q6a53v7j5vkleht934tur", TWCoinTypeHandshake);
    EXPECT_EQ(hex(lockingScriptTo.bytes), "00140d4118e0fb321f9c4cd6a035da459e95196fe6eb");
}