// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Address.h"
#include "Script.h"
#include "TransactionPlan.h"
#include "UnspentSelector.h"
#include "../proto/SimpleLedger.pb.h"
#include "Bitcoin/Transaction.h"
#include "Bitcoin/InputSelector.h"
#include "Bitcoin/FeeCalculator.h"

namespace TW::SimpleLedger {

    struct TransactionBuilder {

        /// Plans a transaction by selecting UTXOs and calculating fees.
        static TransactionPlan plan(const Proto::SigningInput &input) {

            const auto &simpleLedgerInput = input.simple_ledger_input();
            const auto &bitcoinCashInput = input.bitcoin_cash_input();
            auto plan = TransactionPlan();

            // Set simple ledger plan.
            plan.simpleLedgerPlan.tokenId = Data(simpleLedgerInput.token_id().begin(),
                                                 simpleLedgerInput.token_id().end());
            plan.simpleLedgerPlan.amount = simpleLedgerInput.amount();
            plan.simpleLedgerPlan.toAddress = simpleLedgerInput.to_address();
            plan.simpleLedgerPlan.changeAddress = simpleLedgerInput.change_address();

            if (input.use_max_amount()) {
                plan.simpleLedgerPlan.utxos = {simpleLedgerInput.utxo().begin(), simpleLedgerInput.utxo().end()};
            } else {
                plan.simpleLedgerPlan.utxos = UnspentSelector::select(
                        {simpleLedgerInput.utxo().begin(), simpleLedgerInput.utxo().end()},
                        simpleLedgerInput.amount()
                );
            }
            plan.simpleLedgerPlan.availableAmount = UnspentSelector::sum(plan.simpleLedgerPlan.utxos);
            if (plan.simpleLedgerPlan.amount > plan.simpleLedgerPlan.availableAmount) {
                return TransactionPlan();
            }
            plan.simpleLedgerPlan.change = plan.simpleLedgerPlan.availableAmount - plan.simpleLedgerPlan.amount;

            // Set bitcoin cash plan.
            plan.bitcoinCashPlan.changeAddress = bitcoinCashInput.change_address();

            const auto &feeCalculator = Bitcoin::getFeeCalculator(TWCoinTypeSimpleLedger);
//            const int64_t dustThreshold = feeCalculator.calculateSingleInput(input.byte_fee());
            const int64_t dustThreshold = 3 * 182;

            auto simpleLedgerOutputNumber = 1;
            auto opReturnSize = 55 + 10;
            auto bitcoinCashThreshold = dustThreshold;
            if (plan.simpleLedgerPlan.change > 0) {
                simpleLedgerOutputNumber += 1;
                opReturnSize += 9;
                bitcoinCashThreshold += dustThreshold;
            }

            auto simpleLedgerFee = feeCalculator.calculate(plan.simpleLedgerPlan.utxos.size(),
                                                           simpleLedgerOutputNumber,
                                                           input.byte_fee());
            auto opReturnFee = opReturnSize * input.byte_fee();
            auto bitcoinCashCost = simpleLedgerFee + opReturnFee + bitcoinCashThreshold;
            auto bitcoinCashOutputFee = 34 * input.byte_fee();
//            auto bitcoinCashSum = Bitcoin::UnspentSelector::sum(plan.simpleLedgerPlan.utxos);
            auto bitcoinCashSum = Bitcoin::InputSelector<Proto::UnspentTransaction>::sum(plan.simpleLedgerPlan.utxos);

            if (bitcoinCashSum >= bitcoinCashCost) {
                auto change = bitcoinCashSum - bitcoinCashCost - bitcoinCashOutputFee;
                if (change >= dustThreshold) {
                    plan.bitcoinCashPlan.change = change;
                    plan.fee = simpleLedgerFee + opReturnFee + bitcoinCashOutputFee;
                } else {
                    plan.fee = simpleLedgerFee + opReturnFee + (bitcoinCashSum - bitcoinCashCost);
                }
            } else {
                auto unspentSelector = Bitcoin::InputSelector<Bitcoin::Proto::UnspentTransaction>(plan.bitcoinCashPlan.utxos, feeCalculator);
                auto differenceValue = bitcoinCashCost - bitcoinCashSum;
//                auto utxos = unspentSelector.select(bitcoinCashInput.utxo(),
//                                                    differenceValue,
//                                                    input.byte_fee(),
//                                                    1);
                auto utxos = unspentSelector.select(differenceValue,
                                                    input.byte_fee(),
                                                    1);
                auto sum = Bitcoin::InputSelector<Bitcoin::Proto::UnspentTransaction>::sum(utxos);
                if (differenceValue > sum) {
                    return TransactionPlan();
                }
                plan.bitcoinCashPlan.utxos = utxos;

                plan.bitcoinCashPlan.availableAmount = sum;
                auto bitcoinCashInputFee = feeCalculator.calculateSingleInput(input.byte_fee()) * utxos.size();
                auto change = sum - differenceValue - bitcoinCashInputFee - bitcoinCashOutputFee;
                if (change >= dustThreshold) {
                    plan.bitcoinCashPlan.change = change;
                    plan.fee = simpleLedgerFee + opReturnFee + bitcoinCashInputFee + bitcoinCashOutputFee;
                } else {
                    plan.fee = simpleLedgerFee + opReturnFee + (sum - differenceValue);
                }
            }
            return plan;
        }

        /// Builds a transaction by selecting UTXOs and calculating fees.
        static Bitcoin::Transaction build(const TransactionPlan &plan) {
            const int64_t dustThreshold = 3 * 182;

            if (plan.simpleLedgerPlan.amount == 0)
                return {};
            if (!Address::isValid(plan.simpleLedgerPlan.toAddress))
                return {};

            auto coin = TWCoinTypeSimpleLedger;
            Bitcoin::Transaction tx;

            // Build simple ledger token script.
            std::vector<Bitcoin::Amount> values;
            values.emplace_back(plan.simpleLedgerPlan.amount);
            if (plan.simpleLedgerPlan.change > 0) {
                values.emplace_back(plan.simpleLedgerPlan.change);
            }
            auto simpleLedgerScript = Script::buildSimpleLedgerTokenSend(plan.simpleLedgerPlan.tokenId, values);
            if (simpleLedgerScript.empty()) {
                return {};
            }
            tx.outputs.emplace_back(0, simpleLedgerScript);

            // Build transfer to address script.
            auto toLegacyAddress = Address(plan.simpleLedgerPlan.toAddress).legacyAddress().string();
            auto toAddressScript = Script::lockScriptForAddress(toLegacyAddress, coin);
            if (toAddressScript.empty()) {
                return {};
            }
            tx.outputs.emplace_back(dustThreshold, toAddressScript);

            // If have change amount.
            if (plan.simpleLedgerPlan.change > 0 && Address::isValid(plan.simpleLedgerPlan.changeAddress)) {
                auto address = Address(plan.simpleLedgerPlan.changeAddress).legacyAddress().string();
                auto script = Script::lockScriptForAddress(address, coin);
                if (script.empty()) {
                    return {};
                }
                tx.outputs.emplace_back(dustThreshold, script);
            }

            if (plan.bitcoinCashPlan.change > 0) {
                auto script = Script::lockScriptForAddress(plan.bitcoinCashPlan.changeAddress, TWCoinTypeBitcoinCash);
                if (script.empty()) {
                    return {};
                }
                tx.outputs.emplace_back(plan.bitcoinCashPlan.change, script);
            }

            // Add inputs.
            const auto emptyScript = Script();
            for (auto &utxo : plan.simpleLedgerPlan.utxos) {
                tx.inputs.emplace_back(utxo.out_point(), emptyScript, utxo.out_point().sequence());
            }
            for (auto &utxo : plan.bitcoinCashPlan.utxos) {
                tx.inputs.emplace_back(utxo.out_point(), emptyScript, utxo.out_point().sequence());
            }

            return tx;
        }
    };

} // namespace TW::SimpleLedger