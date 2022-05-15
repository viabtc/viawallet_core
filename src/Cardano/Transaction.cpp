// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Transaction.h"

#include "Cbor.h"
#include "Hash.h"
#include "HexCoding.h"

using namespace TW::Cardano;
using namespace TW;
using namespace std;


TokenAmount TokenAmount::fromProto(const Proto::TokenAmount& proto) {
    auto ret = TokenAmount();
    ret.policyId = proto.policy_id();
    ret.assetName = proto.asset_name();
    ret.amount = load(proto.amount());
    return ret;
}

Proto::TokenAmount TokenAmount::toProto() const {
    Proto::TokenAmount tokenAmount;
    tokenAmount.set_policy_id(policyId.data(), policyId.size());
    tokenAmount.set_asset_name(assetName.data(), assetName.size());
    const auto amountData = store(amount);
    tokenAmount.set_amount(amountData.data(), amountData.size());
    return tokenAmount;
}

TxInput TxInput::fromProto(const Cardano::Proto::TxInput& proto) {
    auto ret = TxInput();
    ret.txHash = data(proto.out_point().tx_hash());
    ret.outputIndex = proto.out_point().output_index();
    ret.address = proto.address();
    ret.amount = proto.amount();
    for (auto i = 0; i < proto.token_amount_size(); ++i) {
        auto ta = TokenAmount::fromProto(proto.token_amount(i));
        ret.tokenBundle.add(ta);
    }
    return ret;
}

Proto::TxInput TxInput::toProto() const {
    Proto::TxInput txInput;
    txInput.mutable_out_point()->set_tx_hash(txHash.data(), txHash.size());
    txInput.mutable_out_point()->set_output_index(outputIndex);
    txInput.set_address(address.data(), address.size());
    txInput.set_amount(amount);
    for (auto iter = tokenBundle.bundle.begin(); iter != tokenBundle.bundle.end(); ++iter) {
        *txInput.add_token_amount() = iter->second.toProto();
    }
    return txInput;
}

bool TW::Cardano::operator==(const TxInput& i1, const TxInput& i2) { return i1.outputIndex == i2.outputIndex && i1.txHash == i2.txHash; }

TransactionPlan TransactionPlan::fromProto(const Proto::TransactionPlan& proto) {
    auto ret = TransactionPlan();
    ret.availableAmount = proto.available_amount();
    ret.amount = proto.amount();
    ret.fee = proto.fee();
    ret.change = proto.change();
    for (auto i = 0; i < proto.available_tokens_size(); ++i) {
        ret.availableTokens.add(TokenAmount::fromProto(proto.available_tokens(i)));
    }
    for (auto i = 0; i < proto.output_tokens_size(); ++i) {
        ret.outputTokens.add(TokenAmount::fromProto(proto.output_tokens(i)));
    }
    for (auto i = 0; i < proto.change_tokens_size(); ++i) {
        ret.changeTokens.add(TokenAmount::fromProto(proto.change_tokens(i)));
    }
    for (auto i = 0; i < proto.utxos_size(); ++i) {
        ret.utxos.push_back(TxInput::fromProto(proto.utxos(i)));
    }
    ret.error = proto.error();
    return ret;
}

Proto::TransactionPlan TransactionPlan::toProto() const {
    Proto::TransactionPlan plan;
    plan.set_available_amount(availableAmount);
    plan.set_amount(amount);
    plan.set_fee(fee);
    plan.set_change(change);
    for (const auto& t: availableTokens.bundle) {
        *plan.add_available_tokens() = t.second.toProto();
    }
    for (const auto& t: outputTokens.bundle) {
        *plan.add_output_tokens() = t.second.toProto();
    }
    for (const auto& t: changeTokens.bundle) {
        *plan.add_change_tokens() = t.second.toProto();
    }
    for (const auto& u: utxos) {
        *plan.add_utxos() = u.toProto();
    }
    plan.set_error(error);
    return plan;
}

Cbor::Encode cborizeInputs(const std::vector<OutPoint>& inputs) {
    std::vector<Cbor::Encode> ii;
    for (const auto& i: inputs) {
        ii.push_back(Cbor::Encode::array({
            Cbor::Encode::bytes(i.txHash),
            Cbor::Encode::uint(i.outputIndex)
        }));
    }
    return Cbor::Encode::array(ii);
}

Cbor::Encode cborizeTokenAmount(const TokenAmount& tokenAmount) {
    return Cbor::Encode::array({
    });
}

Cbor::Encode cborizeOutputAmounts(const Amount& amount, const TokenBundle& tokenBundle) {
    if (tokenBundle.size() == 0) {
        // native amount only
        return Cbor::Encode::uint(amount);
    }
    // native and token amounts
    std::vector<pair<Cbor::Encode, Cbor::Encode>> tokensMap;
    for (auto iter = tokenBundle.bundle.begin(); iter != tokenBundle.bundle.end(); ++iter) {
        tokensMap.push_back(make_pair(
            Cbor::Encode::bytes(parse_hex(iter->second.policyId)),
            Cbor::Encode::map({make_pair(
                Cbor::Encode::bytes(data(iter->second.assetName)),
                Cbor::Encode::uint(uint64_t(iter->second.amount)) // 64 bits
            )})
        ));
    }
    return Cbor::Encode::array({
        Cbor::Encode::uint(amount),
        Cbor::Encode::map(tokensMap)
    });
}

Cbor::Encode cborizeOutput(const TxOutput& output) {
    return Cbor::Encode::array({
        Cbor::Encode::bytes(output.address),
        cborizeOutputAmounts(output.amount, output.tokenBundle)
    });
}

Cbor::Encode cborizeOutputs(const std::vector<TxOutput>& outputs) {
    std::vector<Cbor::Encode> oo;
    for (const auto& o: outputs) {
        oo.push_back(cborizeOutput(o));
    }
    return Cbor::Encode::array(oo);
}

Data Transaction::encode() const {
    const auto ii = cborizeInputs(inputs);
    const auto oo = cborizeOutputs(outputs);

    // Encode elements in a map, with fixed numbers as keys
    Cbor::Encode encode = Cbor::Encode::map({
        make_pair(Cbor::Encode::uint(0), ii),
        make_pair(Cbor::Encode::uint(1), oo),
        make_pair(Cbor::Encode::uint(2), Cbor::Encode::uint(fee)),
        make_pair(Cbor::Encode::uint(3), Cbor::Encode::uint(ttl)),
    });
    // Note: following fields are not included:
    // 4 certificates, 5 withdrawals, 7 AUXILIARY_DATA_HASH, 8 VALIDITY_INTERVAL_START

    return encode.encoded();
}

Data Transaction::getId() const {
    const auto encoded = encode();
    const auto hash = Hash::blake2b(encoded, 32);
    return hash;
}
