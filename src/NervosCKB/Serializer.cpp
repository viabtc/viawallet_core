// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Serializer.h"
#include "../BinaryCoding.h"
#include "../HexCoding.h"

using namespace TW;
using namespace TW::NervosCKB;

Data NervosCKB::serialize(const Data &header, const Data &body) {
    Data data;
    append(data, header);
    append(data, body);
    return data;
}

Data NervosCKB::byte32Serialize(const H256 &value) {
    if (value.empty()) {
        return Data(32, 0);
    }
    return subData(value, 0, 32);
}

Data NervosCKB::byteSerialize(byte value) {
    return Data({value});
}

Data NervosCKB::uint32Serialize(uint32_t value) {
    Data data;
    encode32LE(value, data);
    return data;
}

Data NervosCKB::uint64Serialize(uint64_t value) {
    Data data;
    encode64LE(value, data);
    return data;
}

Data NervosCKB::serialize(const Data &value) {
    Data headerData;
    encode32LE(uint32_t(value.size()), headerData);
    return serialize(headerData, value);
}

Data NervosCKB::fixVecSerialize(const std::vector<Data> &value) {
    Data header = uint32Serialize(uint32_t(value.size()));
    Data body;
    for (const auto &v: value) {
        append(body, v);
    }
    Data data = serialize(header, body);
    return data;
}

Data NervosCKB::bytesSerialize(const Data &value) {
    std::vector<Data> data;
    for (const auto &v: value) {
        data.push_back(byteSerialize(v));
    }
    return fixVecSerialize(data);
}

Data NervosCKB::structSerialize(const std::vector<Data> &value) {
    Data data;
    for (const auto &v: value) {
        append(data, v);
    }
    return data;
}

Data NervosCKB::tableSerialize(const std::vector<Data> &value) {
    uint32_t headerSize = uint32_t(1 + value.size()) * sizeof(uint32_t);

    Data body;
    std::vector<uint32_t> offsets;

    if (!value.empty()) {
        for (const auto &v: value) {
            append(body, v);
        }
        offsets.push_back(headerSize);
        for (auto i = 0; i < value.size() - 1; i += 1) {
            offsets.push_back(offsets.back() + uint32_t(value[i].size()));
        }
    }

    uint32_t bytesSize = headerSize + uint32_t(body.size());
    Data header;
    encode32LE(bytesSize, header);
    for (const auto &v: offsets) {
        encode32LE(v, header);
    }
    return serialize(header, body);
}

Data NervosCKB::dynVecSerialize(const std::vector<Data> &value) {
    return tableSerialize(value);
}

Data NervosCKB::outPointSerialize(const OutPoint &value) {
    std::vector<Data> field;
    Data txHash = byte32Serialize(value.txHash);
    Data index = uint32Serialize(value.index);
    field.push_back(txHash);
    field.push_back(index);
    return structSerialize(field);
}

Data NervosCKB::cellDepSerialize(const CellDep &value) {
    std::vector<Data> field;
    Data outPoint = outPointSerialize(value.outPoint);
    Data depType = byteSerialize(static_cast<byte>(value.depType));
    field.push_back(outPoint);
    field.push_back(depType);
    return structSerialize(field);
}

Data NervosCKB::cellInputSerialize(const CellInput &value) {
    std::vector<Data> field;
    Data since = uint64Serialize(value.since);
    Data previousOutput = outPointSerialize(value.previousOutput);
    field.push_back(since);
    field.push_back(previousOutput);
    return structSerialize(field);
}

Data NervosCKB::scriptSerialize(const Script &value) {
    Data codeHash = byte32Serialize(value.codeHash);
    Data hashType = byteSerialize(value.hashType);
    Data args = bytesSerialize(value.args);
    std::vector<Data> field;
    field.push_back(codeHash);
    field.push_back(hashType);
    field.push_back(args);
    Data data = tableSerialize(field);
    return data;
}

Data NervosCKB::cellOutputSerialize(const CellOutput &value) {
    Data capacity = uint64Serialize(uint64_t(value.capacity));
    Data lock = scriptSerialize(value.lock);
    Data type = value.type.empty() ? Data() : scriptSerialize(value.type);

    std::vector<Data> field;
    field.push_back(capacity);
    field.push_back(lock);
    field.push_back(type);
    Data data = tableSerialize(field);
    return data;
}

Data NervosCKB::witnessArgsSerialize(const WitnessArgs &value) {
    if (value.type == WitnessArgs::Type::DATA) {
        return value.data;
    } else {
        Data lock;
        Data input;
        Data output;
        if (!value.lock.empty()) {
            lock = bytesSerialize(value.lock);
        }
        if (!value.inputType.empty()) {
            input = bytesSerialize(value.inputType);
        }
        if (!value.outputType.empty()) {
            output = bytesSerialize(value.outputType);
        }
        std::vector<Data> field;
        field.push_back(lock);
        field.push_back(input);
        field.push_back(output);
        return tableSerialize(field);
    }
}

Data NervosCKB::transactionSerialize(const Transaction &value) {
    std::vector<Data> cellDepsValue;

    for (const auto &v: value.cellDeps) {
        cellDepsValue.push_back(cellDepSerialize(v));
    }

    std::vector<Data> headerDepsValue;
    for (const auto &v: value.headerDeps) {
        headerDepsValue.push_back(byte32Serialize(v));
    }

    std::vector<Data> inputsValue;
    for (const auto &v: value.inputs) {
        inputsValue.push_back(cellInputSerialize(v));
    }

    std::vector<Data> outputsValue;
    for (const auto &v: value.outputs) {
        outputsValue.push_back(cellOutputSerialize(v));
    }

    std::vector<Data> outputsDataValue;
    for (const auto &v: value.outputsData) {
        outputsDataValue.push_back(bytesSerialize(v));
    }

    std::vector<Data> field = {
            uint32Serialize(value.version),
            fixVecSerialize(cellDepsValue),
            fixVecSerialize(headerDepsValue),
            fixVecSerialize(inputsValue),
            dynVecSerialize(outputsValue),
            dynVecSerialize(outputsDataValue)
    };

    return tableSerialize(field);
}

Data NervosCKB::transactionPlusWitnessesSerialize(const Transaction &value) {
    std::vector<Data> witnesses;
    if (value.witnesses.empty()) {
        witnesses = value.serializeWitnessArgs();
    } else {
        witnesses = value.witnesses;
    }

    std::vector<Data> witnessesData;
    witnessesData.reserve(witnesses.size());
    for (const auto &v: witnesses) {
        witnessesData.push_back(bytesSerialize(v));
    }

    std::vector<Data> field = {
            transactionSerialize(value),
            dynVecSerialize(witnessesData)
    };
    return tableSerialize(field);
}

template<typename T>
inline std::string intToHex(T value) {
    auto bytes = reinterpret_cast<const uint8_t *>(&value);
    auto string = hex(std::reverse_iterator<const uint8_t *>(bytes + sizeof(value)),
                      std::reverse_iterator<const uint8_t *>(bytes));
    string.erase(string.begin(), std::find_if(string.begin(), string.end() - 1, [](const auto &value) {
        return value != '0';
    }));
    return string.insert(0, "0x");
}

static json outPointJSON(const OutPoint &value) {
    json j;
    j["index"] = intToHex(value.index);
    j["tx_hash"] = hexEncoded(value.txHash);
    return j;
}

static json cellDepJSON(const CellDep &value) {
    json j;
    j["out_point"] = outPointJSON(value.outPoint);
    switch (value.depType) {
        case CellDep::DepType::CODE:
            j["dep_type"] = "code";
            break;
        case CellDep::DepType::DEP_GROUP:
            j["dep_type"] = "dep_group";
            break;
    }
    return j;
}

static json cellDepsJSON(const std::vector<CellDep> &values) {
    json j = json::array();
    for (auto &v : values) {
        j.push_back(cellDepJSON(v));
    }
    return j;
}

static json headerDepsJSON(const std::vector<H256> &values) {
    json j = json::array();
    for (auto &v : values) {
        j.push_back(hexEncoded(v));
    }
    return j;
}

static json cellInputJSON(const CellInput &value) {
    json j;
    j["since"] = intToHex(value.since);
    j["previous_output"] = outPointJSON(value.previousOutput);
    return j;
}

static json inputsJSON(const std::vector<CellInput> &values) {
    json j = json::array();
    for (auto &v : values) {
        j.push_back(cellInputJSON(v));
    }
    return j;
}

static json scriptJSON(const Script &value) {
    json j;
    j["args"] = hexEncoded(value.args);
    j["code_hash"] = hexEncoded(value.codeHash);
    j["hash_type"] = 0;
    switch (value.hashType) {
        case SCRIPT_DATA:
            j["hash_type"] = "data";
            break;
        case SCRIPT_TYPE:
            j["hash_type"] = "type";
            break;
        case SCRIPT_DATA1:
            j["hash_type"] = "data1";
            break;
    }
    return j;
}

static json cellOutputJSON(const CellOutput &value) {
    json j;
    j["capacity"] = intToHex(value.capacity);
    j["lock"] = scriptJSON(value.lock);
    if (value.type.empty()) {
        j["type"] = nullptr;
    } else {
        j["type"] = scriptJSON(value.type);
    }
    return j;
}

static json outputsJSON(const std::vector<CellOutput> &values) {
    json j = json::array();
    for (auto &v : values) {
        j.push_back(cellOutputJSON(v));
    }
    return j;
}

static json outputsDataJSON(const std::vector<Data> &values) {
    json j = json::array();
    for (auto &v : values) {
        j.push_back(hexEncoded(v));
    }
    return j;
}

static json witnessesJSON(const std::vector<Data> &values) {
    json j = json::array();
    for (auto &v : values) {
        j.push_back(hexEncoded(v));
    }
    return j;
}

json NervosCKB::transactionJSON(const Transaction &value) {
    json json;
    json["version"] = intToHex(value.version);
    json["cell_deps"] = cellDepsJSON(value.cellDeps);
    json["header_deps"] = headerDepsJSON(value.headerDeps);
    json["inputs"] = inputsJSON(value.inputs);
    json["outputs"] = outputsJSON(value.outputs);
    json["outputs_data"] = outputsDataJSON(value.outputsData);
    json["witnesses"] = witnessesJSON(value.witnesses);
    return json;
}