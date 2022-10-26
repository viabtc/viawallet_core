// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "WitnessArgs.h"

using namespace TW;
using namespace NervosCKB;

const Data WitnessArgs::emptyLockHash = std::vector<byte>(65, 0);
const WitnessArgs WitnessArgs::emptyLock = WitnessArgs(emptyLockHash, Data(), Data());

std::vector<WitnessArgs> WitnessArgs::witnessArgs(size_t size) {
    std::vector<WitnessArgs> witnessArgs;
    for(auto i = 0; i < size; i += 1) {
        if (i == 0) {
            witnessArgs.emplace_back(WitnessArgs::emptyLock);
        } else {
            witnessArgs.emplace_back(WitnessArgs());
        }
    }
    return witnessArgs;
}
