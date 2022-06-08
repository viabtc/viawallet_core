// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWKadenaAccount.h>

#include "Kadena/Address.h"
#include "Kadena/Account.h"

#include <string>

using namespace TW;
using namespace TW::Kadena;

struct TWKadenaAccount {
    std::string description;
};

struct TWKadenaAccount *_Nullable TWKadenaAccountCreateWithString(TWString *_Nonnull string) {
    const auto& account = *reinterpret_cast<const std::string*>(string);
    if (Account::isValid(account)) {
        return new TWKadenaAccount{account};
    }
    return nullptr;
}

void TWKadenaAccountDelete(struct TWKadenaAccount *_Nonnull account) {
    delete account;
}

TWString *_Nonnull TWKadenaAccountDescription(struct TWKadenaAccount *_Nonnull account) {
    return TWStringCreateWithUTF8Bytes(account->description.c_str());
}

bool TWKadenaAccountIsValid(TWString *_Nonnull string) {
    const auto& account = *reinterpret_cast<const std::string*>(string);
    return Account::isValid(account) || Address::isValid(account);
}
