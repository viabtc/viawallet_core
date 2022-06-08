/**
 * Copyright (c) 2017 Saleem Rashid
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __KADENA_ENCRYPTED_SIGN_H__
#define __KADENA_ENCRYPTED_SIGN_H__

#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "TrezorCrypto/ed25519.h"
#include <TrezorCrypto/bip32.h>
#include <TrezorCrypto/bip39.h>
#include <TrezorCrypto/curves.h>
#include <TrezorCrypto/pbkdf2.h>
#include <TrezorCrypto/hmac.h>
#include <TrezorCrypto/memzero.h>
#include <TrezorCrypto/ed25519-donna/modm-donna-32bit.h>
#include <TrezorCrypto/chacha20poly1305/ecrypt-portable.h>


#ifdef __cplusplus
extern "C" {
#endif

#define SECRET_KEY_SEED_SIZE 32
#define ENCRYPTED_KEY_SIZE 64
#define PUBLIC_KEY_SIZE    32
#define CHAIN_CODE_SIZE    32

#define FULL_KEY_SIZE      (ENCRYPTED_KEY_SIZE + PUBLIC_KEY_SIZE + CHAIN_CODE_SIZE)

typedef struct {
    uint8_t ekey[ENCRYPTED_KEY_SIZE];
    uint8_t pkey[PUBLIC_KEY_SIZE];
    uint8_t cc[CHAIN_CODE_SIZE];
} encrypted_key;

typedef enum {
    DERIVATION_V1 = 1,
    DERIVATION_V2 = 2,
} derivation_scheme_mode;

typedef unsigned char ed25519_secret_key_64[64];

void wallet_encrypted_derive_private
    (encrypted_key *in,
     uint32_t index,
     uint8_t *result,
     derivation_scheme_mode mode);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
