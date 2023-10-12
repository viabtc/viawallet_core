// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrezorCrypto/memzero.h>
#include <TrezorCrypto/scrypt.h>
#include <TrustWalletCore/TWSCRYPT.h>

#include "Data.h"

using namespace TW;

TWData *_Nullable TWSCRYPTScrypt(TWData *_Nonnull password, TWData *_Nonnull salt, uint64_t N, uint32_t r, uint32_t p, uint32_t dkLen) {

    Data key(dkLen);
    int passLen = static_cast<int>(TWDataSize(password));
    int saltLen = static_cast<int>(TWDataSize(salt));
    scrypt(
        TWDataBytes(password), 
        passLen, 
        TWDataBytes(salt), 
        saltLen,
        N,
        r,
        p,
        key.data(),
        dkLen
    );
    return TWDataCreateWithData(&key);
}

