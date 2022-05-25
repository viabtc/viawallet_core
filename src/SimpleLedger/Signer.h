// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Data.h"
#include "../PrivateKey.h"
#include "../proto/SimpleLedger.pb.h"
#include "../Result.h"
#include "TransactionPlan.h"
#include "TransactionBuilder.h"
#include "Bitcoin/Transaction.h"
#include "Bitcoin/TransactionInput.h"

namespace TW::SimpleLedger {

    /// Helper class that performs SimpleLedger transaction signing.
    class Signer {

    public:
        /// Initializes a transaction signer.
        Signer() = default;

        /// Transaction plan.
        TransactionPlan txPlan;

        /// Transaction being signed.
        Bitcoin::Transaction transaction;

        /// Returns a transaction plan (utxo selection, fee estimation)
        static Proto::TransactionPlan plan(const Proto::SigningInput &input) noexcept;

        /// Signs a Proto::SigningInput transaction
        static Proto::SigningOutput sign(const Proto::SigningInput &input) noexcept;

        /// Initializes a transaction signer with signing input.
        explicit Signer(const Proto::SigningInput &input) : input(input) {
            txPlan = TransactionBuilder::plan(input);
            transaction = TransactionBuilder::build(txPlan);
        }

        /// Signs the transaction.
        ///
        /// \returns the signed transaction or an error.
        Result<Bitcoin::Transaction> sign();

    private:
        /// Private key and redeem script provider for signing.
        Proto::SigningInput input;

        /// List of signed inputs.
        Bitcoin::TransactionInputs<Bitcoin::TransactionInput> signedInputs;
    private:
        /// Signs a particular input.
        Result<void> sign(const Bitcoin::Script& script, size_t index, const Bitcoin::Proto::UnspentTransaction &utxo);

        Result<std::vector<Data>>
        signStep(const Bitcoin::Script &script, size_t index, const Bitcoin::Proto::UnspentTransaction &utxo);

        static Data createSignature(const Bitcoin::Transaction &transaction,
                                    const Bitcoin::Script &script,
                                    const Data &key,
                                    size_t index,
                                    uint64_t amount);

        /// Returns the private key for the given public key hash.
        Data keyForPublicKeyHash(const Data &hash) const;

        /// internal, public for testability and Decred
        static Data pushAll(const std::vector<Data> &results);
    };

} // namespace TW::SimpleLedger