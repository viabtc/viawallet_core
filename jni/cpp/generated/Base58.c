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

#include <TrustWalletCore/TWBase58.h>

#include "TWJNI.h"
#include "Base58.h"

jstring JNICALL Java_wallet_core_jni_Base58_encode(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jstring result = NULL;
    TWString *resultString = TWBase58Encode(dataData);
    result = TWStringJString(resultString, env);
    TWDataDelete(dataData);
    return result;
}

jstring JNICALL Java_wallet_core_jni_Base58_encodeNoCheck(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jstring result = NULL;
    TWString *resultString = TWBase58EncodeNoCheck(dataData);
    result = TWStringJString(resultString, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Base58_decode(JNIEnv *env, jclass thisClass, jstring string) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    jbyteArray result = NULL;
    TWData *resultData = TWBase58Decode(stringString);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWStringDelete(stringString);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Base58_decodeNoCheck(JNIEnv *env, jclass thisClass, jstring string) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    jbyteArray result = NULL;
    TWData *resultData = TWBase58DecodeNoCheck(stringString);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWStringDelete(stringString);
    return result;
}

