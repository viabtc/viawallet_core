// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "CellDep.h"

TW::NervosCKB::CellDep TW::NervosCKB::CellDep::secp256k1CellDep() {
    return TW::NervosCKB::CellDep(
            OutPoint::secp256k1OutPoint(),
            TW::NervosCKB::CellDep::DepType::DEP_GROUP
    );
}
