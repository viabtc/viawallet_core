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

#include <TrustWalletCore/TWCosmosPublicKey.h>

#include "TWJNI.h"
#include "CosmosPublicKey.h"

jlong JNICALL Java_wallet_core_jni_CosmosPublicKey_nativeCreateWithData(JNIEnv *env, jclass thisClass, jstring hrp, jbyteArray data) {
    TWString *hrpString = TWStringCreateWithJString(env, hrp);
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    struct TWCosmosPublicKey *instance = TWCosmosPublicKeyCreateWithData(hrpString, dataData);
    TWStringDelete(hrpString);
    TWDataDelete(dataData);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_CosmosPublicKey_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWCosmosPublicKeyDelete((struct TWCosmosPublicKey *) handle);
}

jboolean JNICALL Java_wallet_core_jni_CosmosPublicKey_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs) {
    jclass lhsClass = (*env)->GetObjectClass(env, lhs);
    jfieldID lhsHandleFieldID = (*env)->GetFieldID(env, lhsClass, "nativeHandle", "J");
    struct TWCosmosPublicKey *lhsInstance = (struct TWCosmosPublicKey *) (*env)->GetLongField(env, lhs, lhsHandleFieldID);
    jclass rhsClass = (*env)->GetObjectClass(env, rhs);
    jfieldID rhsHandleFieldID = (*env)->GetFieldID(env, rhsClass, "nativeHandle", "J");
    struct TWCosmosPublicKey *rhsInstance = (struct TWCosmosPublicKey *) (*env)->GetLongField(env, rhs, rhsHandleFieldID);
    jboolean resultValue = (jboolean) TWCosmosPublicKeyEqual(lhsInstance, rhsInstance);

    (*env)->DeleteLocalRef(env, lhsClass);
    (*env)->DeleteLocalRef(env, rhsClass);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_CosmosPublicKey_description(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWCosmosPublicKey *instance = (struct TWCosmosPublicKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWCosmosPublicKeyDescription(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_CosmosPublicKey_data(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWCosmosPublicKey *instance = (struct TWCosmosPublicKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWCosmosPublicKeyData(instance);
    result = TWDataJByteArray(resultData, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_CosmosPublicKey_hrp(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWCosmosPublicKey *instance = (struct TWCosmosPublicKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWCosmosPublicKeyHrp(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

