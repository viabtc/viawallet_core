// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWString.h"
#include "TWData.h"

TW_EXTERN_C_BEGIN

struct TWPublicKey;

/// Represents a legacy Conflux address.
TW_EXPORT_CLASS
struct TWConfluxNetworkAddress;

/// Compares two addresses for equality.
TW_EXPORT_STATIC_METHOD
bool TWConfluxNetworkAddressEqual(struct TWConfluxNetworkAddress *_Nonnull lhs, struct TWConfluxNetworkAddress *_Nonnull rhs);

/// Determines if the string is a valid Conflux address.
TW_EXPORT_STATIC_METHOD
bool TWConfluxNetworkAddressIsValidString(TWString *_Nonnull string);

/// Create an address from a sring representaion.
TW_EXPORT_STATIC_METHOD
struct TWConfluxNetworkAddress *_Nullable TWConfluxNetworkAddressCreateWithString(TWString *_Nonnull string);

/// Create an address from a public key and a prefix byte.
TW_EXPORT_STATIC_METHOD
struct TWConfluxNetworkAddress *_Nonnull TWConfluxNetworkAddressCreateWithPublicKey(struct TWPublicKey *_Nonnull publicKey);

TW_EXPORT_STATIC_METHOD
TWString *_Nonnull TWConfluxNetworkAddressEncode(TWString *_Nonnull string);

TW_EXPORT_METHOD
void TWConfluxNetworkAddressDelete(struct TWConfluxNetworkAddress *_Nonnull address);

/// Returns the address string representation.
TW_EXPORT_PROPERTY
TWString *_Nonnull TWConfluxNetworkAddressDescription(struct TWConfluxNetworkAddress *_Nonnull address);

TW_EXTERN_C_END
