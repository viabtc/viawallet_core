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

#include <TrustWalletCore/TWDerivationPathIndex.h>

#include "TWJNI.h"
#include "DerivationPathIndex.h"

jlong JNICALL Java_wallet_core_jni_DerivationPathIndex_nativeCreate(JNIEnv *env, jclass thisClass, jint value, jboolean hardened) {
    struct TWDerivationPathIndex *instance = TWDerivationPathIndexCreate(value, hardened);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_DerivationPathIndex_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWDerivationPathIndexDelete((struct TWDerivationPathIndex *) handle);
}

jint JNICALL Java_wallet_core_jni_DerivationPathIndex_value(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWDerivationPathIndex *instance = (struct TWDerivationPathIndex *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWDerivationPathIndexValue(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_DerivationPathIndex_hardened(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWDerivationPathIndex *instance = (struct TWDerivationPathIndex *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWDerivationPathIndexHardened(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_DerivationPathIndex_description(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWDerivationPathIndex *instance = (struct TWDerivationPathIndex *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWDerivationPathIndexDescription(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

