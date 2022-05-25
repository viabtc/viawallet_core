// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../proto/SimpleLedger.pb.h"
#include "Bitcoin/Amount.h"

namespace TW::SimpleLedger {

    struct SimpleLedgerPlan {

        /// Token id
        Data tokenId;

        /// Amount to be received at the other end.
        TW::Bitcoin::Amount amount = 0;

        /// Maximum available amount.
        TW::Bitcoin::Amount availableAmount = 0;

        /// Change.
        TW::Bitcoin::Amount change = 0;

        /// Recipient's address.
        std::string toAddress = "";

        /// Change address.
        std::string  changeAddress = "";

        /// Selected unspent transaction outputs.
        std::vector<Proto::UnspentTransaction> utxos;

        SimpleLedgerPlan() = default;

        SimpleLedgerPlan(const Proto::SimpleLedgerPlan &plan)
                : tokenId(plan.token_id().begin(), plan.token_id().end())
                , amount(plan.amount())
                , availableAmount(plan.available_amount())
                , change(plan.change())
                , toAddress(plan.to_address())
                , changeAddress(plan.change_address())
                , utxos(plan.utxos().begin(), plan.utxos().end()) {}

        Proto::SimpleLedgerPlan proto() const {
            auto plan = Proto::SimpleLedgerPlan();
            *plan.mutable_token_id() = {tokenId.begin(), tokenId.end()};
            plan.set_amount(amount);
            plan.set_available_amount(availableAmount);
            plan.set_change(change);
            plan.set_to_address(toAddress);
            plan.set_change_address(changeAddress);
            *plan.mutable_utxos() = {utxos.begin(), utxos.end()};
            return plan;
        }
    };

    struct BitcoinCashPlan {

        /// Maximum available amount.
        TW::Bitcoin::Amount availableAmount = 0;

        /// Change.
        TW::Bitcoin::Amount change = 0;

        /// Change address.
        std::string  changeAddress = "";

        /// Selected unspent transaction outputs.
        std::vector<Bitcoin::Proto::UnspentTransaction> utxos;

        BitcoinCashPlan() = default;

        explicit BitcoinCashPlan(const Proto::BitcoinCashPlan &plan)
                : availableAmount(plan.available_amount())
                , change(plan.change())
                , changeAddress(plan.change_address())
                , utxos(plan.utxos().begin(), plan.utxos().end()) {}

        Proto::BitcoinCashPlan proto() const {
            auto plan = Proto::BitcoinCashPlan();
            plan.set_available_amount(availableAmount);
            plan.set_change(change);
            plan.set_change_address(changeAddress);
            *plan.mutable_utxos() = {utxos.begin(), utxos.end()};
            return plan;
        }
    };

    /// Describes a preliminary transaction plan.
    struct TransactionPlan {

        /// Estimated transaction fee.
        TW::Bitcoin::Amount fee = 0;

        SimpleLedgerPlan simpleLedgerPlan = SimpleLedgerPlan();

        BitcoinCashPlan bitcoinCashPlan = BitcoinCashPlan();

        TransactionPlan() = default;

        explicit TransactionPlan(const Proto::TransactionPlan &plan)
                : fee(plan.fee())
                , simpleLedgerPlan(plan.simple_ledger_plan())
                , bitcoinCashPlan(plan.bitcoin_cash_plan()) {}

        Proto::TransactionPlan proto() const {
            auto plan = Proto::TransactionPlan();
            plan.set_fee(fee);
            *plan.mutable_simple_ledger_plan() = simpleLedgerPlan.proto();
            *plan.mutable_bitcoin_cash_plan() = bitcoinCashPlan.proto();
            return plan;
        }
    };

} // namespace TW::SimpleLedger