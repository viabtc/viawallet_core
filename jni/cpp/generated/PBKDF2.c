// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWPBKDF2.h>

#include "TWJNI.h"
#include "PBKDF2.h"

jbyteArray JNICALL Java_wallet_core_jni_PBKDF2_hmacSha256(JNIEnv *env, jclass thisClass, jbyteArray password, jbyteArray salt, jint iterations, jint dkLen) {
    TWData *passwordData = TWDataCreateWithJByteArray(env, password);
    TWData *saltData = TWDataCreateWithJByteArray(env, salt);
    jbyteArray result = NULL;
    TWData *resultData = TWPBKDF2HmacSha256(passwordData, saltData, iterations, dkLen);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWDataDelete(passwordData);
    TWDataDelete(saltData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_PBKDF2_hmacSha512(JNIEnv *env, jclass thisClass, jbyteArray password, jbyteArray salt, jint iterations, jint dkLen) {
    TWData *passwordData = TWDataCreateWithJByteArray(env, password);
    TWData *saltData = TWDataCreateWithJByteArray(env, salt);
    jbyteArray result = NULL;
    TWData *resultData = TWPBKDF2HmacSha512(passwordData, saltData, iterations, dkLen);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWDataDelete(passwordData);
    TWDataDelete(saltData);
    return result;
}

