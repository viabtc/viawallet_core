// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Type.h"
#include "CellDep.h"
#include "CellInput.h"
#include "CellOutput.h"
#include "OutPoint.h"
#include "Script.h"
#include "WitnessArgs.h"
#include "Transaction.h"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace TW::NervosCKB {

    Data serialize(const Data& header, const Data& body);
    Data byte32Serialize(const H256& value);
    Data byteSerialize(byte value);
    Data uint32Serialize(uint32_t value);
    Data uint64Serialize(uint64_t value);
    Data serialize(const Data& value);
    Data fixVecSerialize(const std::vector<Data>& value);
    Data bytesSerialize(const Data& value);
    Data structSerialize(const std::vector<Data>& value);
    Data tableSerialize(const std::vector<Data>& value);
    Data dynVecSerialize(const std::vector<Data>& value);
    Data outPointSerialize(const OutPoint& value);
    Data cellDepSerialize(const CellDep& value);
    Data cellInputSerialize(const CellInput& value);
    Data scriptSerialize(const Script& value);
    Data cellOutputSerialize(const CellOutput& value);
    Data witnessArgsSerialize(const WitnessArgs& value);
    Data transactionSerialize(const Transaction& value);
    Data transactionPlusWitnessesSerialize(const Transaction& value);
    json transactionJSON(const Transaction& value);

} // namespace TW::NervosCKB