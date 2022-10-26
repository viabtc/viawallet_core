// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <cstdint>
#include "../Data.h"

namespace TW::NervosCKB {
    using Capacity = int64_t;
    using Version = uint32_t;
    /// 32 byte
    using H256 = Data;
} // namespace TW::NervosCKB
