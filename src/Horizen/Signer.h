// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include "TransactionBuilder.h"
#include "../Result.h"
#include "../proto/Bitcoin.pb.h"
#include <Bitcoin/Transaction.h>
#include <Bitcoin/TransactionPlan.h>

namespace TW::Horizen {

using SigningInput = Bitcoin::Proto::SigningInput;
using SigningOutput = Bitcoin::Proto::SigningOutput;
using TransactionPlan = Bitcoin::Proto::TransactionPlan;

class Signer {
  public:
    /// Initializes a transaction signer.
    Signer() = default;
    /// Private key and redeem script provider for signing.
    Bitcoin::Proto::SigningInput input;

    /// Transaction plan.
    Bitcoin::TransactionPlan txPlan;

    /// Transaction being signed.
    Bitcoin::Transaction transaction;

    /// Returns a transaction plan (utxo selection, fee estimation)
    static TransactionPlan plan(const SigningInput& input) noexcept;

    /// Signs a Proto::SigningInput transaction
    static SigningOutput sign(const SigningInput& input) noexcept;


    /// Initializes a transaction signer with signing input.
    explicit Signer(const Bitcoin::Proto::SigningInput& input) : input(input) {
        if (input.has_plan()) {
            txPlan = Bitcoin::TransactionPlan(input.plan());
        } else {
            txPlan = TransactionBuilder::plan(input);
        }
        transaction = TransactionBuilder::build(txPlan, input.to_address(), input.change_address());
    }

  private:
    /// List of signed inputs.
    Bitcoin::TransactionInputs<Bitcoin::TransactionInput> signedInputs;

    /// Signs the transaction.
    /// returns the signed transaction or an error.
    Result<Bitcoin::Transaction, Common::Proto::SigningError> sign();

    /// Signs a particular input.
    Result<Horizen::Script, Common::Proto::SigningError> sign(Script& script,
                                 size_t index,
                                 const Bitcoin::UTXO &utxo);

    /// Search the utxo key.
    Data searchKey(Script& script);

    /// Returns the private key for the given public key hash.
    Data keyForPublicKeyHash(const Data& hash);

};

} // namespace TW::Horizen
