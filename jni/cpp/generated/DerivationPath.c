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

#include <TrustWalletCore/TWDerivationPath.h>

#include "TWJNI.h"
#include "DerivationPath.h"

jlong JNICALL Java_wallet_core_jni_DerivationPath_nativeCreate(JNIEnv *env, jclass thisClass, jobject purpose, jint coin, jint account, jint change, jint address) {
    jclass purposeClass = (*env)->GetObjectClass(env, purpose);
    jmethodID purposeValueMethodID = (*env)->GetMethodID(env, purposeClass, "value", "()I");
    jint purposeValue = (*env)->CallIntMethod(env, purpose, purposeValueMethodID);
    struct TWDerivationPath *instance = TWDerivationPathCreate(purposeValue, coin, account, change, address);
    (*env)->DeleteLocalRef(env, purposeClass);
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_DerivationPath_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring string) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    struct TWDerivationPath *instance = TWDerivationPathCreateWithString(stringString);
    TWStringDelete(stringString);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_DerivationPath_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWDerivationPathDelete((struct TWDerivationPath *) handle);
}

jobject JNICALL Java_wallet_core_jni_DerivationPath_purpose(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWDerivationPath *instance = (struct TWDerivationPath *) (*env)->GetLongField(env, thisObject, handleFieldID);

    enum TWPurpose result = TWDerivationPathPurpose(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/Purpose");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromValue", "(I)Lwallet/core/jni/Purpose;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jint) result);
}

jint JNICALL Java_wallet_core_jni_DerivationPath_coin(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWDerivationPath *instance = (struct TWDerivationPath *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWDerivationPathCoin(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_DerivationPath_account(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWDerivationPath *instance = (struct TWDerivationPath *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWDerivationPathAccount(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_DerivationPath_change(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWDerivationPath *instance = (struct TWDerivationPath *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWDerivationPathChange(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_DerivationPath_address(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWDerivationPath *instance = (struct TWDerivationPath *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWDerivationPathAddress(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_DerivationPath_description(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWDerivationPath *instance = (struct TWDerivationPath *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWDerivationPathDescription(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jobject JNICALL Java_wallet_core_jni_DerivationPath_indexAt(JNIEnv *env, jobject thisObject, jint index) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWDerivationPath *instance = (struct TWDerivationPath *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWDerivationPathIndex *result = TWDerivationPathIndexAt(instance, index);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/DerivationPathIndex");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/DerivationPathIndex;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jint JNICALL Java_wallet_core_jni_DerivationPath_indicesCount(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWDerivationPath *instance = (struct TWDerivationPath *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWDerivationPathIndicesCount(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

