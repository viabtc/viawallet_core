// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"
#include "Address.h"
#include "Transaction.h"
#include "Serializer.h"

using namespace TW;
using namespace TW::NervosCKB;

const static Capacity kMinAmount = 6100000000;

inline Capacity transferFee(int64_t inputs, int64_t outputs, int64_t feeRate) {
    const auto witnessesSize = inputs <= 0 ? 0 : inputs * 8 + 85;
    const auto txSize = ((44 * inputs) + (109 * outputs) + witnessesSize + 109);
    return Transaction::fee(txSize, feeRate);
}

inline Capacity sum(const std::vector<CellInput> &inputs) {
    Capacity sum = 0;
    for (auto &cell : inputs) {
        sum += cell.capacity;
    }
    return sum;
}

inline auto slice(const std::vector<CellInput> &elements, size_t sliceSize) {
    std::vector<std::vector<CellInput>> slices;
    for (auto i = 0; i <= elements.size() - sliceSize; i += 1) {
        slices.emplace_back();
        slices[i].reserve(sliceSize);
        for (auto j = i; j < i + sliceSize; j += 1) {
            slices[i].push_back(elements[j]);
        }
    }
    return slices;
}

static std::vector<CellInput>
transferSelect(const std::vector<CellInput> &inputs, Capacity targetValue, int64_t feeRate, int64_t numOutputs) {

    if (targetValue == 0) {
        return {};
    }

    if (inputs.empty() || sum(inputs) < targetValue) {
        return {};
    }

    const auto doubleTargetValue = targetValue * 2;

    auto sortedInputs = inputs;
    std::sort(sortedInputs.begin(), sortedInputs.end(),
              [](const CellInput &lhs, const CellInput &rhs) {
                  return lhs.capacity < rhs.capacity;
              });

    auto distFrom2x = [doubleTargetValue](int64_t val) -> int64_t {
        if (val > doubleTargetValue)
            return val - doubleTargetValue;
        else
            return doubleTargetValue - val;
    };

    for (int64_t numInputs = 1; numInputs <= sortedInputs.size(); numInputs += 1) {
        const auto fee = transferFee(numInputs, numOutputs, feeRate);
        const auto value = targetValue + fee + kMinAmount;
        auto slices = slice(sortedInputs, static_cast<size_t>(numInputs));
        slices.erase(std::remove_if(slices.begin(), slices.end(),
                                    [value](
                                            const std::vector<CellInput> &slice) {
                                        return sum(slice) < value;
                                    }),
                     slices.end());
        if (!slices.empty()) {
            std::sort(slices.begin(), slices.end(),
                      [distFrom2x](const std::vector<CellInput> &lhs,
                                   const std::vector<CellInput> &rhs) {
                          return distFrom2x(sum(lhs)) < distFrom2x(sum(rhs));
                      });
            return slices.front();
        }
    }
    return {};
}

static Transaction
transferTx(const std::string &from, const std::string &to, Capacity amount, Capacity feeRate,
           const std::vector<CellInput> &inputs,
           bool useMaxAmount) {

    auto tx = Transaction();

    tx.cellDeps = {CellDep::secp256k1CellDep()};

    if (useMaxAmount) {
        auto available = sum(inputs);
        auto fee = transferFee(inputs.size(), 1, feeRate);
        auto outputAmount = available - fee;
        tx.inputs = inputs;
        tx.outputs = {CellOutput(outputAmount, Script::parseLockScript(to))};
        tx.outputsData = {Data()};
        tx.unsignedWitnesses = WitnessArgs::witnessArgs(inputs.size());
    } else {
        auto selectInputs = transferSelect(inputs, amount, feeRate, 2);
        auto available = sum(selectInputs);
        auto fee = transferFee(selectInputs.size(), 2, feeRate);
        auto change = available - fee - amount;
        tx.inputs = selectInputs;
        tx.outputs = {
                CellOutput(amount, Script::parseLockScript(to)),
                CellOutput(change, Script::parseLockScript(from))
        };
        tx.outputsData = {Data(), Data()};
        tx.unsignedWitnesses = WitnessArgs::witnessArgs(selectInputs.size());
    }
    return tx;
}

template <typename T>
static std::vector<CellInput> messageCellInputToCellInput(const T &cells) {
    std::vector<CellInput> inputs;
    for (const auto &value: cells) {
        auto txHash = Data(value.previous_output().txhash().begin(), value.previous_output().txhash().end());
        auto index = value.previous_output().index();
        auto cell = CellInput(OutPoint(txHash, index), value.since(), value.capacity());
        inputs.emplace_back(cell);
    }
    return inputs;
}

static Transaction transferTx(const std::string &from, const Proto::TransferMessage &message) {

    auto tx = transferTx(from, message.to(), message.amount(), message.fee_rate(),
                         messageCellInputToCellInput(message.cells()),
                         message.use_max_amount());
    return tx;
}

static Transaction signTransferTx(const Proto::TransferMessage &message) {
    const auto privateKey = PrivateKey(Data(message.private_key().begin(), message.private_key().end()));
    const auto from = Address(privateKey.getPublicKey(TWPublicKeyTypeSECP256k1)).string();
    auto tx = transferTx(from, message);
    const auto hash = tx.messageHash();
    const auto signature = privateKey.sign(hash, TWCurveSECP256k1);
    std::vector<Data> witnesses;
    for (auto i = 0; i < tx.unsignedWitnesses.size(); i += 1) {
        auto value = tx.unsignedWitnesses[i];
        if (i == 0) {
            witnesses.emplace_back(witnessArgsSerialize(WitnessArgs(signature, value.inputType, value.outputType)));
        } else {
            witnesses.emplace_back(witnessArgsSerialize(value));
        }
    }
    tx.witnesses = witnesses;
    return tx;
}

static void transferPlan(const Proto::TransferMessage &message, Proto::TransferPlan &plan) {
    auto cellsSum = sum(messageCellInputToCellInput(message.cells()));
    if (message.amount() > cellsSum) {
        plan.set_error(Proto::TransferError::InsufficientBalance);
        return;
    }
    if (message.amount() < kMinAmount) {
        plan.set_error(Proto::TransferError::TransferAmountLessThanMinCapacity);
        return;
    }
    auto tx = transferTx(message.to(), message);
    auto fee = tx.fee(message.fee_rate());
    plan.set_error(Proto::TransferError::NONE);
    plan.set_available_amount(sum(tx.inputs));
    plan.set_fee(fee);
    if (!tx.outputs.empty()) {
        auto amount = tx.outputs[0].capacity;
        plan.set_amount(amount);
        if ((amount + fee) > cellsSum) {
            plan.set_error(Proto::TransferError::InsufficientBalance);
            return;
        }
        if (amount < kMinAmount) {
            plan.set_error(Proto::TransferError::TransferAmountLessThanMinCapacity);
            return;
        }
    }
    if (tx.outputs.size() > 1) {
        auto change = tx.outputs[1].capacity;
        plan.set_change(change);
        if (change < kMinAmount) {
            plan.set_error(Proto::TransferError::ChangeAmountLessThanMinCapacity);
            return;
        }
    }
    for (const auto &v: tx.inputs) {
        auto &cell = *plan.add_cells();
        cell.set_capacity(v.capacity);
        cell.set_since(v.since);
        auto &previousOutput = *cell.mutable_previous_output();
        previousOutput.set_index(v.previousOutput.index);
        previousOutput.set_txhash(v.previousOutput.txHash.data(), v.previousOutput.txHash.size());
    }
}

Proto::TransactionPlan Signer::plan(const Proto::SigningInput &input) noexcept {
    auto plan = Proto::TransactionPlan();
    if (input.has_transfer()) {
        transferPlan(input.transfer(), *plan.mutable_transfer());
    }
    return plan;
}

Proto::SigningOutput Signer::sign(const Proto::SigningInput &input) noexcept {
    auto output = Proto::SigningOutput();
    if (input.has_transfer()) {
        const auto tx = signTransferTx(input.transfer());
        const auto txJson = transactionJSON(tx);
        output.set_json(txJson.dump());
    }
    return output;
}
