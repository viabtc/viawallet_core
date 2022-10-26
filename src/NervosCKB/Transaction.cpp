// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Transaction.h"
#include "Serializer.h"
#include "WitnessArgs.h"
#include "../Hash.h"

using namespace TW;
using namespace TW::NervosCKB;

Data Transaction::hash() const {
    auto personal = data("ckb-default-hash");
    auto blake2bHash = Hash::blake2b(transactionSerialize(*this), 32, personal);
    return blake2bHash;
}

std::vector<Data> Transaction::serializeWitnessArgs() const {
    std::vector<Data> data;
    for (const auto &value : unsignedWitnesses) {
        data.push_back(witnessArgsSerialize(value));
    }
    return data;
}

size_t Transaction::serializedSizeInBlock() const {
    auto serializedTxOffsetByteSize = 4;
    auto size = transactionPlusWitnessesSerialize(*this).size();
    return size + serializedTxOffsetByteSize;
}

Capacity Transaction::fee(size_t txSize, int64_t rate) {
    auto base = int64_t(txSize) * rate;
    auto result = base / 1000;
    return base % 1000 == 0 ? result : result + 1;
}

Capacity Transaction::fee(int64_t rate) const {
    return Transaction::fee(serializedSizeInBlock(), rate);
}

Data Transaction::messageHash() const {
    if (unsignedWitnesses.empty()) {
        throw std::invalid_argument("Invalid number Of witnesses");
    }
    if (unsignedWitnesses[0].type == WitnessArgs::Type::DATA) {
        throw std::invalid_argument("Invalid number Of witnesses");
    }
    auto message = hash();
    WitnessArgs emptyWitness = WitnessArgs(
            WitnessArgs::emptyLockHash,
            unsignedWitnesses[0].inputType,
            unsignedWitnesses[0].outputType
    );
    auto emptiedWitnessData = witnessArgsSerialize(emptyWitness);
    append(message, uint64Serialize(uint64_t(emptiedWitnessData.size())));
    append(message, emptiedWitnessData);
    for(auto i = 1; i < unsignedWitnesses.size(); i += 1) {
        auto value = unsignedWitnesses[i];
        auto witnessData = witnessArgsSerialize(value);
        append(message, uint64Serialize(uint64_t(witnessData.size())));
        append(message, witnessData);
    }
    auto personal = data("ckb-default-hash");
    auto blake2bHash = Hash::blake2b(message, 32, personal);
    return blake2bHash;
}
