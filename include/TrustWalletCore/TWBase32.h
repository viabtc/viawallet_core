// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWString.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_STRUCT
struct TWBase32;

/// Encodes data as a Base32 string
TW_EXPORT_STATIC_METHOD
TWString *_Nonnull TWBase32Encode(TWData *_Nonnull data);

/// Decodes a Base58 string checking the checksum.
TW_EXPORT_STATIC_METHOD
TWData *_Nullable TWBase32Decode(TWString *_Nonnull string);


TW_EXTERN_C_END
