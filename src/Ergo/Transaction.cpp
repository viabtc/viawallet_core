// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Transaction.h"
#include "Address.h"
#include "../BinaryCoding.h"

using namespace TW;
using namespace TW::Ergo;

using json = nlohmann::json;

Data Transaction::serialize() {

    Data data;

    // inputs length
    encodeVarInt(inputs.size(), data);

    // inputs
    for (auto& input : inputs) {
        // boxId
        auto boxId = parse_hex(input.boxId);
        std::copy(std::begin(boxId), std::end(boxId), std::back_inserter(data));

        // proofBytes length
        encodeVarInt(input.spendingProof.proofBytes.size() >> 1, data);

        //proofBytes
        auto proofBytes = parse_hex(input.spendingProof.proofBytes);
        std::copy(std::begin(proofBytes), std::end(proofBytes), std::back_inserter(data));

        // spendingProof.extension length
        encodeVarInt(0, data);
    }

    // dataInputs length
    encodeVarInt(dataInputs.size(), data);

    // distinctIds
    encodeVarInt(0, data);

    // outputs length
    encodeVarInt(outputs.size(), data);

    // outputs
    for (auto& output : outputs) {
        // value
        encodeVarInt(output.value, data);

        // ergoTree
        auto ergoTreeData = Address(output.address).ergoTree();
        append(data, ergoTreeData);

        // creationHeight
        encodeVarInt(output.creationHeight, data);

        // asset length
        encodeVarInt(0, data);

        // additionalRegisters length
        encodeVarInt(0, data);
    }

    return data;
}

nlohmann::json Transaction::toJson() {
    auto jsonTx = nlohmann::json();

    auto jsonInputs = json::array();
    for (Input& input : inputs) {
        jsonInputs.emplace_back(input.toJson());
    }

    auto jsonOutputs = json::array();
    for (ErgoBox& output : outputs) {
        jsonOutputs.emplace_back(output.toJson());
    }

    auto jsonDataInputs = json::array();

    jsonTx["inputs"] = jsonInputs;
    jsonTx["outputs"] = jsonOutputs;
    jsonTx["dataInputs"] = jsonDataInputs;

    return jsonTx;
}

uint8_t Transaction::encodeVarInt(uint64_t num, Data &data) {
    uint8_t count = 0;
    while (true) {
        ++count;
        if (num >> 7) {
            TW::append(data, 0x80 | (num & 0x7F));
            num = num >> 7;
        } else {
            TW::append(data, static_cast<uint8_t>(num));
            break;
        }
    }
    return count;
}
