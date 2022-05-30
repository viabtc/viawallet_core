// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "OutPoint.h"

TW::NervosCKB::OutPoint TW::NervosCKB::OutPoint::secp256k1OutPoint() {
    // 0x71a7ba8fc96349fea0ed3a5c47992e3b4084b031a42264a018e0072e8172e46c
    Data txHash = {
            0x71, 0xa7, 0xba, 0x8f, 0xc9, 0x63, 0x49, 0xfe,
            0xa0, 0xed, 0x3a, 0x5c, 0x47, 0x99, 0x2e, 0x3b,
            0x40, 0x84, 0xb0, 0x31, 0xa4, 0x22, 0x64, 0xa0,
            0x18, 0xe0, 0x07, 0x2e, 0x81, 0x72, 0xe4, 0x6c
    };
    return TW::NervosCKB::OutPoint(txHash, 0);
}
