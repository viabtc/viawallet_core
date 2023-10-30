// Copyright © 2017-2023 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include <string>
#include "BitcoinUnspentOutput.h"
#include "KaspaOutput.h"
#include "Data.h"
#include <map>

namespace TW::Kaspa {

class Transaction {
public:
    std::vector<BitcoinUnspentOutput> inputs;
    std::vector<KaspaOutput> outputs;
    std::vector<std::string> hashes;
    std::map<std::string, Data> privateKeys;

    Data hashForSignatureWitness(int inputIndex, Data connectedScript, uint64_t prevValue) const;
private:
    Data hashPrevouts() const;
    Data blake2bDigest(Data value) const;
    Data hashSequence() const;
    Data hashSigOpCounts() const;
    Data hashOutputs() const;
    Data subnetworkIdData() const;
    Data payloadData() const;
};
}

/// Wrapper for C interface.
struct TWKaspaTransaction {
    TW::Kaspa::Transaction impl;
};
