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

#include <TrustWalletCore/TWAES.h>

#include "TWJNI.h"
#include "AES.h"

jbyteArray JNICALL Java_wallet_core_jni_AES_encryptCBC(JNIEnv *env, jclass thisClass, jbyteArray key, jbyteArray data, jbyteArray iv, jobject mode) {
    TWData *keyData = TWDataCreateWithJByteArray(env, key);
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    TWData *ivData = TWDataCreateWithJByteArray(env, iv);
    jclass modeClass = (*env)->GetObjectClass(env, mode);
    jmethodID modeValueMethodID = (*env)->GetMethodID(env, modeClass, "value", "()I");
    jint modeValue = (*env)->CallIntMethod(env, mode, modeValueMethodID);
    jbyteArray result = NULL;
    TWData *resultData = TWAESEncryptCBC(keyData, dataData, ivData, modeValue);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWDataDelete(keyData);
    TWDataDelete(dataData);
    TWDataDelete(ivData);
    (*env)->DeleteLocalRef(env, modeClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_AES_decryptCBC(JNIEnv *env, jclass thisClass, jbyteArray key, jbyteArray data, jbyteArray iv, jobject mode) {
    TWData *keyData = TWDataCreateWithJByteArray(env, key);
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    TWData *ivData = TWDataCreateWithJByteArray(env, iv);
    jclass modeClass = (*env)->GetObjectClass(env, mode);
    jmethodID modeValueMethodID = (*env)->GetMethodID(env, modeClass, "value", "()I");
    jint modeValue = (*env)->CallIntMethod(env, mode, modeValueMethodID);
    jbyteArray result = NULL;
    TWData *resultData = TWAESDecryptCBC(keyData, dataData, ivData, modeValue);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWDataDelete(keyData);
    TWDataDelete(dataData);
    TWDataDelete(ivData);
    (*env)->DeleteLocalRef(env, modeClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_AES_encryptCTR(JNIEnv *env, jclass thisClass, jbyteArray key, jbyteArray data, jbyteArray iv) {
    TWData *keyData = TWDataCreateWithJByteArray(env, key);
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    TWData *ivData = TWDataCreateWithJByteArray(env, iv);
    jbyteArray result = NULL;
    TWData *resultData = TWAESEncryptCTR(keyData, dataData, ivData);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWDataDelete(keyData);
    TWDataDelete(dataData);
    TWDataDelete(ivData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_AES_decryptCTR(JNIEnv *env, jclass thisClass, jbyteArray key, jbyteArray data, jbyteArray iv) {
    TWData *keyData = TWDataCreateWithJByteArray(env, key);
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    TWData *ivData = TWDataCreateWithJByteArray(env, iv);
    jbyteArray result = NULL;
    TWData *resultData = TWAESDecryptCTR(keyData, dataData, ivData);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWDataDelete(keyData);
    TWDataDelete(dataData);
    TWDataDelete(ivData);
    return result;
}

