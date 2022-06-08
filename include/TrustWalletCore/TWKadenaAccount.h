// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWString.h"

TW_EXTERN_C_BEGIN

/// Represents a Kadena Account name
TW_EXPORT_CLASS
struct TWKadenaAccount;

TW_EXPORT_STATIC_METHOD
struct TWKadenaAccount *_Nullable TWKadenaAccountCreateWithString(TWString *_Nonnull string);

TW_EXPORT_METHOD
void TWKadenaAccountDelete(struct TWKadenaAccount *_Nonnull account);

/// Returns the user friendly string representation.
TW_EXPORT_PROPERTY
TWString *_Nonnull TWKadenaAccountDescription(struct TWKadenaAccount *_Nonnull account);

/// Determines if a Kadena account is valid.
TW_EXPORT_STATIC_METHOD
bool TWKadenaAccountIsValid(TWString *_Nonnull string);

TW_EXTERN_C_END
