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

/// Represents a NervosCKB address.
TW_EXPORT_CLASS
struct TWNervosCKBAddress;

/// Compares two addresses for equality.
TW_EXPORT_STATIC_METHOD
bool TWNervosCKBAddressEqual(struct TWNervosCKBAddress *_Nonnull lhs, struct TWNervosCKBAddress *_Nonnull rhs);

/// Determines if the string is a valid NervosCKB address.
TW_EXPORT_STATIC_METHOD
bool TWNervosCKBAddressIsValid(TWString *_Nonnull string);

/// Create an address from a public key and a prefix byte.
TW_EXPORT_STATIC_METHOD
struct TWNervosCKBAddress *_Nonnull TWNervosCKBAddressCreateWithPublicKey(struct TWPublicKey *_Nonnull publicKey);

/// Convert an address to Bech32mFullAddress.
TW_EXPORT_STATIC_METHOD
TWString *_Nonnull TWNervosCKBAddressConvertToBech32mFullAddress(TWString *_Nonnull address);


TW_EXPORT_METHOD
void TWNervosCKBAddressDelete(struct TWNervosCKBAddress *_Nonnull address);

/// Returns the address string representation.
TW_EXPORT_PROPERTY
TWString *_Nonnull TWNervosCKBAddressDescription(struct TWNervosCKBAddress *_Nonnull address);

TW_EXTERN_C_END
