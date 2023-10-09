// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWString.h"

TW_EXTERN_C_BEGIN

struct TWPublicKey;

/// Represents a CashAddress in C++.
TW_EXPORT_CLASS
struct TWCashAddress;

/// Compares two addresses for equality.
///
/// \param lhs The first address to compare.
/// \param rhs The second address to compare.
/// \return bool indicating the addresses are equal.
TW_EXPORT_STATIC_METHOD
bool TWCashAddressEqual(struct TWCashAddress *_Nonnull lhs, struct TWCashAddress *_Nonnull rhs);

/// Determines if the data is a valid CashAddress.
///
/// \param data data to validate.
/// \return bool indicating if the address data is valid.
TW_EXPORT_STATIC_METHOD
bool TWCashAddressIsValid(TWData *_Nonnull data);

/// Determines if the string is a valid CashAddress.
///
/// \param hrp hrp to validate.
/// \param string string to validate.
/// \return bool indicating if the address string is valid.
TW_EXPORT_STATIC_METHOD
bool TWCashAddressIsValidString(TWString *_Nonnull hrp, TWString *_Nonnull string);

/// Initializes a CashAddress.
TW_EXPORT_STATIC_METHOD
struct TWCashAddress *_Nullable TWCashAddressCreateWithString(TWString *_Nonnull hrp, TWString *_Nonnull string);


/// Initializes an CashAddress from a public key and hrp.
///
/// \param hrp hrp to initialize the CashAddress from.
/// \param publicKey Public key to initialize the CashAddress from.
/// \return TWCashAddress pointer or nullptr if public key is invalid.
TW_EXPORT_STATIC_METHOD
struct TWCashAddress *_Nullable TWCashAddressCreateWithPublicKey(TWString *_Nonnull hrp, struct TWPublicKey *_Nonnull publicKey);

/// Deletes a CashAddress.
///
/// \param address CashAddress to delete.
TW_EXPORT_METHOD
void TWCashAddressDelete(struct TWCashAddress *_Nonnull address);

/// Returns the address in cash encode string representation.
///
/// \param address CashAddress to get the string representation of.
TW_EXPORT_PROPERTY
TWString *_Nonnull TWCashAddressDescription(struct TWCashAddress *_Nonnull address);

/// Returns the key hash data.
///
/// \param address CashAddress to get the keyhash data of.
TW_EXPORT_PROPERTY
TWData *_Nonnull TWCashAddressKeyhash(struct TWCashAddress *_Nonnull address);

TW_EXTERN_C_END
