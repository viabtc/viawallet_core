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

#include <TrustWalletCore/TWDataVector.h>

#include "TWJNI.h"
#include "DataVector.h"

jlong JNICALL Java_wallet_core_jni_DataVector_nativeCreate(JNIEnv *env, jclass thisClass) {
    struct TWDataVector *instance = TWDataVectorCreate();
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_DataVector_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    struct TWDataVector *instance = TWDataVectorCreateWithData(dataData);
    TWDataDelete(dataData);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_DataVector_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWDataVectorDelete((struct TWDataVector *) handle);
}

jsize JNICALL Java_wallet_core_jni_DataVector_size(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWDataVector *instance = (struct TWDataVector *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jsize resultValue = (jsize) TWDataVectorSize(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

void JNICALL Java_wallet_core_jni_DataVector_add(JNIEnv *env, jobject thisObject, jbyteArray data) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWDataVector *instance = (struct TWDataVector *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    TWDataVectorAdd(instance, dataData);

    TWDataDelete(dataData);

    (*env)->DeleteLocalRef(env, thisClass);
}

jbyteArray JNICALL Java_wallet_core_jni_DataVector_get(JNIEnv *env, jobject thisObject, jsize index) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWDataVector *instance = (struct TWDataVector *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWDataVectorGet(instance, index);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

