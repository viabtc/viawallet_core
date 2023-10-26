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

#include <TrustWalletCore/TWSCRYPT.h>

#include "TWJNI.h"
#include "SCRYPT.h"

jbyteArray JNICALL Java_wallet_core_jni_SCRYPT_scrypt(JNIEnv *env, jclass thisClass, jbyteArray password, jbyteArray salt, jlong N, jint r, jint p, jint dkLen) {
    TWData *passwordData = TWDataCreateWithJByteArray(env, password);
    TWData *saltData = TWDataCreateWithJByteArray(env, salt);
    jbyteArray result = NULL;
    TWData *resultData = TWSCRYPTScrypt(passwordData, saltData, N, r, p, dkLen);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWDataDelete(passwordData);
    TWDataDelete(saltData);
    return result;
}

