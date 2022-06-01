// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Script.h"
#include "../Bitcoin/TransactionPlan.h"
#include "../Bitcoin/TransactionBuilder.h"
#include "../HexCoding.h"
#include "../proto/Bitcoin.pb.h"
#include <TrustWalletCore/TWCoinType.h>
#include <algorithm>

namespace TW::Horizen {

class TransactionBuilder {
  public:
    /// Plans a transaction by selecting UTXOs and calculating fees.
    static Bitcoin::TransactionPlan plan(const Bitcoin::Proto::SigningInput& input) {
        return TW::Bitcoin::TransactionBuilder::plan(input);
    }

    /// Builds a transaction by selecting UTXOs and calculating fees.
    static Bitcoin::Transaction build(const Bitcoin::TransactionPlan& plan, const std::string& toAddress,
                             const std::string& changeAddress) {

        auto blockHeight = plan.blockHeight;
        auto blockHash = plan.blockHash;

        auto lockingScriptTo = Script::lockScriptForAddress(toAddress, blockHeight, blockHash);
        if (lockingScriptTo.empty()) {
            return {};
        }

        Bitcoin::Transaction tx;
        tx.outputs.emplace_back(plan.amount, lockingScriptTo);

        if (plan.change > 0) {
            auto lockingScriptChange = Script::lockScriptForAddress(changeAddress, blockHeight, blockHash);
            tx.outputs.emplace_back(plan.change, lockingScriptChange);
        }

        for (auto& utxo : plan.utxos) {
            const auto script = Script(utxo.script.bytes);
            tx.inputs.emplace_back(utxo.outPoint, script, utxo.outPoint.sequence);
        }

        return tx;
    }
};

} // namespace TW::Horizen
