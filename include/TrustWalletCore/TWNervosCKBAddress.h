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

/// Represents a Nervos address.
TW_EXPORT_CLASS
struct TWNervosCKBAddress;

/// Compares two addresses for equality.
///
/// \param lhs The first address to compare.
/// \param rhs The second address to compare.
/// \return bool indicating the addresses are equal.
TW_EXPORT_STATIC_METHOD
bool TWNervosCKBAddressEqual(struct TWNervosCKBAddress*_Nonnull lhs, struct TWNervosCKBAddress*_Nonnull rhs);

/// Determines if the string is a valid Nervos address.
///
/// \param string string to validate.
/// \return bool indicating if the address is valid.
TW_EXPORT_STATIC_METHOD
bool TWNervosCKBAddressIsValidString(TWString *_Nonnull string);

/// Initializes an address from a sring representaion.
///
/// \param string Bech32 string to initialize the address from.
/// \return TWNervosCKBAddress pointer or nullptr if string is invalid.
TW_EXPORT_STATIC_METHOD
struct TWNervosCKBAddress*_Nullable TWNervosCKBAddressCreateWithString(TWString *_Nonnull string);

/// Deletes a Nervos address.
///
/// \param address Address to delete.
TW_EXPORT_METHOD
void TWNervosCKBAddressDelete(struct TWNervosCKBAddress*_Nonnull address);

/// Returns the address string representation.
///
/// \param address Address to get the string representation of.
TW_EXPORT_PROPERTY
TWString *_Nonnull TWNervosCKBAddressDescription(struct TWNervosCKBAddress*_Nonnull address);

/// Convert an address to Bech32mFullAddress.
TW_EXPORT_STATIC_METHOD
TWString *_Nonnull TWNervosCKBAddressConvertToBech32mFullAddress(TWString *_Nonnull address);


TW_EXTERN_C_END
