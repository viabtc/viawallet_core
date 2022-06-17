// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWString.h"

TW_EXTERN_C_BEGIN

/// Represents a Cosmos public key.
TW_EXPORT_CLASS
struct TWCosmosPublicKey;

/// Compares two public key for equality.
TW_EXPORT_STATIC_METHOD
bool TWCosmosPublicKeyEqual(struct TWCosmosPublicKey *_Nonnull lhs, struct TWCosmosPublicKey *_Nonnull rhs);

/// Creates an public key from human-readable part and data.
TW_EXPORT_STATIC_METHOD
struct TWCosmosPublicKey *_Nullable TWCosmosPublicKeyCreateWithData(TWString *_Nonnull hrp, TWData *_Nonnull data);

TW_EXPORT_METHOD
void TWCosmosPublicKeyDelete(struct TWCosmosPublicKey *_Nonnull publicKey);

/// Returns the public key string representation.
TW_EXPORT_PROPERTY
TWString *_Nonnull TWCosmosPublicKeyDescription(struct TWCosmosPublicKey *_Nonnull publicKey);

/// Returns the public key data.
TW_EXPORT_PROPERTY
TWData *_Nonnull TWCosmosPublicKeyData(struct TWCosmosPublicKey *_Nonnull publicKey);

/// Returns the public key human-readable part.
TW_EXPORT_PROPERTY
TWString *_Nonnull TWCosmosPublicKeyHrp(struct TWCosmosPublicKey *_Nonnull publicKey);

TW_EXTERN_C_END
