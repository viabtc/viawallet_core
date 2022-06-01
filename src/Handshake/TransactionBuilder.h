// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Bitcoin/TransactionPlan.h"
#include "../Bitcoin/TransactionBuilder.h"
#include "../HexCoding.h"
#include "../proto/Bitcoin.pb.h"
#include <TrustWalletCore/TWCoinType.h>
#include <algorithm>

#include "Script.h"
#include "Transaction.h"

namespace TW::Handshake {

class TransactionBuilder {
  public:
    /// Plans a transaction by selecting UTXOs and calculating fees.
    static Bitcoin::TransactionPlan plan(const Bitcoin::Proto::SigningInput& input) {
        return TW::Bitcoin::TransactionBuilder::plan(input);
    }

    /// Builds a transaction by selecting UTXOs and calculating fees.
    static Transaction build(const Bitcoin::TransactionPlan& plan, const std::string& toAddress,
                             const std::string& changeAddress) {
        TWCoinType coinType = TWCoinTypeHandshake;

        auto lockingScriptTo = Script::lockScriptForAddress(toAddress, coinType);
        if (lockingScriptTo.empty()) {
            return {};
        }

        Transaction tx;
        tx.outputs.emplace_back(plan.amount, lockingScriptTo);

        if (plan.change > 0) {
            auto lockingScriptChange = Script::lockScriptForAddress(changeAddress, coinType);
            tx.outputs.emplace_back(plan.change, lockingScriptChange);
        }
//        const auto script = Script();
        for (auto& utxo : plan.utxos) {
            const auto script = Script(utxo.script.bytes);
            tx.inputs.emplace_back(utxo.outPoint, script, utxo.outPoint.sequence);
        }

        return tx;
    }
};

} // namespace TW::Handshake
