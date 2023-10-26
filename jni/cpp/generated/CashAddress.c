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

#include <TrustWalletCore/TWCashAddress.h>
#include <TrustWalletCore/TWPublicKey.h>

#include "TWJNI.h"
#include "CashAddress.h"

jlong JNICALL Java_wallet_core_jni_CashAddress_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring hrp, jstring string) {
    TWString *hrpString = TWStringCreateWithJString(env, hrp);
    TWString *stringString = TWStringCreateWithJString(env, string);
    struct TWCashAddress *instance = TWCashAddressCreateWithString(hrpString, stringString);
    TWStringDelete(hrpString);
    TWStringDelete(stringString);
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_CashAddress_nativeCreateWithPublicKey(JNIEnv *env, jclass thisClass, jstring hrp, jobject publicKey) {
    TWString *hrpString = TWStringCreateWithJString(env, hrp);
    jclass publicKeyClass = (*env)->GetObjectClass(env, publicKey);
    jfieldID publicKeyHandleFieldID = (*env)->GetFieldID(env, publicKeyClass, "nativeHandle", "J");
    struct TWPublicKey *publicKeyInstance = (struct TWPublicKey *) (*env)->GetLongField(env, publicKey, publicKeyHandleFieldID);
    struct TWCashAddress *instance = TWCashAddressCreateWithPublicKey(hrpString, publicKeyInstance);
    TWStringDelete(hrpString);
    (*env)->DeleteLocalRef(env, publicKeyClass);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_CashAddress_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWCashAddressDelete((struct TWCashAddress *) handle);
}

jboolean JNICALL Java_wallet_core_jni_CashAddress_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs) {
    jclass lhsClass = (*env)->GetObjectClass(env, lhs);
    jfieldID lhsHandleFieldID = (*env)->GetFieldID(env, lhsClass, "nativeHandle", "J");
    struct TWCashAddress *lhsInstance = (struct TWCashAddress *) (*env)->GetLongField(env, lhs, lhsHandleFieldID);
    jclass rhsClass = (*env)->GetObjectClass(env, rhs);
    jfieldID rhsHandleFieldID = (*env)->GetFieldID(env, rhsClass, "nativeHandle", "J");
    struct TWCashAddress *rhsInstance = (struct TWCashAddress *) (*env)->GetLongField(env, rhs, rhsHandleFieldID);
    jboolean resultValue = (jboolean) TWCashAddressEqual(lhsInstance, rhsInstance);

    (*env)->DeleteLocalRef(env, lhsClass);
    (*env)->DeleteLocalRef(env, rhsClass);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_CashAddress_isValid(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jboolean resultValue = (jboolean) TWCashAddressIsValid(dataData);

    TWDataDelete(dataData);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_CashAddress_isValidString(JNIEnv *env, jclass thisClass, jstring hrp, jstring string) {
    TWString *hrpString = TWStringCreateWithJString(env, hrp);
    TWString *stringString = TWStringCreateWithJString(env, string);
    jboolean resultValue = (jboolean) TWCashAddressIsValidString(hrpString, stringString);

    TWStringDelete(hrpString);
    TWStringDelete(stringString);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_CashAddress_description(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWCashAddress *instance = (struct TWCashAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWCashAddressDescription(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_CashAddress_keyhash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWCashAddress *instance = (struct TWCashAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWCashAddressKeyhash(instance);
    result = TWDataJByteArray(resultData, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

