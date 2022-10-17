// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "AnyAddress.h"

#include <utility>
#include "Coin.h"

namespace TW {

Data AnyAddress::getData() const {
    return TW::addressToData(coin, address);
}

AnyAddress* AnyAddress::createAddress(const std::string& address, enum TWCoinType coin) {
    auto normalized = TW::normalizeAddress(coin, address);
    if (normalized.empty()) {
        return nullptr;
    }

    return new AnyAddress{.address = std::move(normalized), .coin = coin};
}

AnyAddress* AnyAddress::createAddress(const PublicKey& publicKey, enum TWCoinType coin) {
    auto derivedAddress = TW::deriveAddress(coin, publicKey);
    return new AnyAddress{.address = std::move(derivedAddress), .coin = coin};
}

} // namespace TW
