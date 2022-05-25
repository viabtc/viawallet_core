// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <vector>
#include "../proto/SimpleLedger.pb.h"

namespace TW::SimpleLedger {

    // Slice Array
    // [0,1,2,3,4,5,6,7,8,9].eachSlices(3)
    // >
    // [[0, 1, 2], [1, 2, 3], [2, 3, 4], [3, 4, 5], [4, 5, 6], [5, 6, 7], [6, 7, 8],
    // [7, 8, 9]]
    template<typename T>
    static inline auto slice(const T &elements, size_t sliceSize) {
        std::vector<std::vector<Proto::UnspentTransaction>> slices;
        for (auto i = 0; i <= elements.size() - sliceSize; i += 1) {
            slices.emplace_back();
            slices[i].reserve(sliceSize);
            for (auto j = i; j < i + sliceSize; j += 1) {
                slices[i].push_back(elements[j]);
            }
        }
        return slices;
    }

    class UnspentSelector {
    public:

        static inline int64_t sum(const std::vector<Proto::UnspentTransaction> &utxos) {
            int64_t sum = 0;
            for (auto &utxo : utxos) {
                sum += utxo.simple_ledger_amount();
            }
            return sum;
        }

        static std::vector<Proto::UnspentTransaction>
        select(const std::vector<Proto::UnspentTransaction> &utxos, int64_t targetValue) {

            // if target value is zero, no UTXOs are needed
            if (targetValue == 0) {
                return {};
            }

            // total values of utxos should be greater than targetValue
            if (utxos.empty() || sum(utxos) < targetValue) {
                return {};
            }
            assert(!utxos.empty());

            // definitions for the following caluculation
            const auto doubleTargetValue = targetValue * 2;

            // Get all possible utxo selections up to a maximum size, sort by total
            // amount
            auto sortedUtxos = utxos;
            sort(sortedUtxos.begin(), sortedUtxos.end(),
                 [](const Proto::UnspentTransaction &lhs, const Proto::UnspentTransaction &rhs) {
                     return lhs.simple_ledger_amount() < rhs.simple_ledger_amount();
                 });

            // difference from 2x targetValue
            auto distFrom2x = [doubleTargetValue](int64_t val) -> int64_t {
                if (val > doubleTargetValue)
                    return val - doubleTargetValue;
                else
                    return doubleTargetValue - val;
            };

            // 1. Find a combination of the fewest inputs that is
            //    (1) bigger than what we need
            //    (2) closer to 2x the amount,
            //    (3) and does not produce dust change.
            for (int64_t numInputs = 1; numInputs <= sortedUtxos.size(); numInputs += 1) {
                const auto target = targetValue;
                auto slices = slice(sortedUtxos, static_cast<size_t>(numInputs));
                slices.erase(remove_if(slices.begin(), slices.end(), [target](
                                     const std::vector<Proto::UnspentTransaction> &slice) {
                                 return sum(slice) < target;
                             }),
                             slices.end());
                if (!slices.empty()) {
                    sort(slices.begin(), slices.end(),
                         [distFrom2x](const std::vector<Proto::UnspentTransaction> &lhs,
                                      const std::vector<Proto::UnspentTransaction> &rhs) {
                             return distFrom2x(sum(lhs)) <
                                    distFrom2x(sum(rhs));
                         });
                    return slices.front();
                }
            }

            // 2. If not, find a valid combination of outputs even if they produce dust change.
            for (int64_t numInputs = 1; numInputs <= sortedUtxos.size(); numInputs += 1) {
                const auto target = targetValue;
                auto slices = slice(sortedUtxos, static_cast<size_t>(numInputs));
                slices.erase(
                        remove_if(slices.begin(), slices.end(),
                                  [target](const std::vector<Proto::UnspentTransaction> &slice) {
                                      return sum(slice) < target;
                                  }),
                        slices.end());
                if (!slices.empty()) {
                    return slices.front();
                }
            }

            return {};
        }
    };
}