// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <TrustWalletCore/TWBitcoinSigHashType.h>
#include <vector>
#include "../Hash.h"
#include "../Data.h"
#include "Script.h"
#include "TransactionOutput.h"
#include "TransactionInput.h"

namespace TW::Handshake {

struct Transaction {
  public:
    /// Transaction data format version (note, this is signed)
    int32_t version = 0;

    /// If all inputs have final (`0xffffffff`) sequence numbers then `lockTime` is irrelevant. Otherwise, the
    /// transaction may not be added to a block until after `lockTime`.
    uint32_t lockTime = 0;

    /// A list of 1 or more transaction inputs or sources for coins
    std::vector<TransactionInput> inputs;

    /// A list of 1 or more transaction outputs or destinations for coins
    std::vector<TransactionOutput> outputs;

    TW::Hash::Hasher hasher = Hash::HasherBlake2b;

    /// Used for diagnostics; store previously estimated virtual size (if any; size in bytes)
    int previousEstimatedVirtualSize = 0;

  public:
    Transaction() = default;

    /// Whether the transaction is empty.
    bool empty() const { return inputs.empty() && outputs.empty(); }

    /// Generates the signature pre-image.
    Data getPreImage(const Script& scriptCode, size_t index, enum TWBitcoinSigHashType hashType, uint64_t amount) const;
    Data getPrevoutHash() const;
    Data getSequenceHash() const;
    Data getOutputsHash() const;

    enum SegwitFormatMode {
        NonSegwit,
        IfHasWitness,
        Segwit
    };

    /// Encodes the transaction into the provided buffer.
    void encode(Data& data, enum SegwitFormatMode segwitFormat) const;

    /// Default one-parameter version, needed for templated usage.
    void encode(Data& data) const { encode(data, SegwitFormatMode::IfHasWitness); }

    /// Encodes the witness part of the transaction into the provided buffer.
    void encodeWitness(Data& data) const;

    bool hasWitness() const;

    /// Generates the signature hash for this transaction.
    Data getSignatureHash(const Script& scriptCode, size_t index, enum TWBitcoinSigHashType hashType,
                          uint64_t amount) const;

    void serializeInput(size_t subindex, const Script&, size_t index, enum TWBitcoinSigHashType hashType, Data& data) const;

    /// Converts to Protobuf model
    Bitcoin::Proto::Transaction proto() const;

  private:
    /// Generates the signature hash for Witness version 0 scripts.
    Data getSignatureHashWitnessV0(const Script& scriptCode, size_t index,
                                   enum TWBitcoinSigHashType hashType, uint64_t amount) const;
};

} // namespace TW::Handshake

/// Wrapper for C interface.
struct TWHandshakeTransaction {
    TW::Handshake::Transaction impl;
};
