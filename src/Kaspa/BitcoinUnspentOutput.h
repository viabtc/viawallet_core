// Copyright © 2017-2023 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include <string>
namespace TW::Kaspa {

class BitcoinUnspentOutput {
public:
    std::string transactionHash;
    int outputIndex;
    uint64_t amount;
    std::string outputScript;
    std::string address;
    BitcoinUnspentOutput() = default;

    BitcoinUnspentOutput(std::string transactionHash, int outputIndex, uint64_t amount, std::string outputScript, std::string address) :
        transactionHash(transactionHash),
        outputIndex(outputIndex),
        amount(amount),
        outputScript(outputScript),
        address(address) {}
};
} // namespace Kaspa

struct TWKaspaBitCoinUnspentOutput {
    TW::Kaspa::BitcoinUnspentOutput impl;
};
