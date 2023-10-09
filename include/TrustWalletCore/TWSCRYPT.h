// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"

TW_EXTERN_C_BEGIN

/// Password-Based Key Derivation Function 2
TW_EXPORT_STRUCT
struct TWSCRYPT;

/// Derives a key from a password and a salt using scrypt.
///
/// \param password is the master password from which a derived key is generated
/// \param salt is a sequence of bits, known as a cryptographic salt
/// \param N is the number of iterations desired
/// \param r is block size
/// \param p is parallelization parameter
/// \param dkLen is the desired byte-length of the derived key
/// \return the derived key data.
TW_EXPORT_STATIC_METHOD
TWData *_Nullable scrypt(TWData *_Nonnull password, TWData *_Nonnull salt, uint64_t N, uint32_t r, uint32_t p, uint32_t dkLen);


TW_EXTERN_C_END
