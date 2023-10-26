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

#include <TrustWalletCore/TWBase64.h>

#include "TWJNI.h"
#include "Base64.h"

jbyteArray JNICALL Java_wallet_core_jni_Base64_decode(JNIEnv *env, jclass thisClass, jstring string) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    jbyteArray result = NULL;
    TWData *resultData = TWBase64Decode(stringString);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWStringDelete(stringString);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Base64_decodeUrl(JNIEnv *env, jclass thisClass, jstring string) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    jbyteArray result = NULL;
    TWData *resultData = TWBase64DecodeUrl(stringString);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWStringDelete(stringString);
    return result;
}

jstring JNICALL Java_wallet_core_jni_Base64_encode(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jstring result = NULL;
    TWString *resultString = TWBase64Encode(dataData);
    result = TWStringJString(resultString, env);
    TWDataDelete(dataData);
    return result;
}

jstring JNICALL Java_wallet_core_jni_Base64_encodeUrl(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jstring result = NULL;
    TWString *resultString = TWBase64EncodeUrl(dataData);
    result = TWStringJString(resultString, env);
    TWDataDelete(dataData);
    return result;
}

