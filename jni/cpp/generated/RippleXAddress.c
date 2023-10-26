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

#include <TrustWalletCore/TWRippleXAddress.h>
#include <TrustWalletCore/TWPublicKey.h>

#include "TWJNI.h"
#include "RippleXAddress.h"

jlong JNICALL Java_wallet_core_jni_RippleXAddress_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring string) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    struct TWRippleXAddress *instance = TWRippleXAddressCreateWithString(stringString);
    TWStringDelete(stringString);
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_RippleXAddress_nativeCreateWithPublicKey(JNIEnv *env, jclass thisClass, jobject publicKey, jint tag) {
    jclass publicKeyClass = (*env)->GetObjectClass(env, publicKey);
    jfieldID publicKeyHandleFieldID = (*env)->GetFieldID(env, publicKeyClass, "nativeHandle", "J");
    struct TWPublicKey *publicKeyInstance = (struct TWPublicKey *) (*env)->GetLongField(env, publicKey, publicKeyHandleFieldID);
    struct TWRippleXAddress *instance = TWRippleXAddressCreateWithPublicKey(publicKeyInstance, tag);
    (*env)->DeleteLocalRef(env, publicKeyClass);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_RippleXAddress_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWRippleXAddressDelete((struct TWRippleXAddress *) handle);
}

jboolean JNICALL Java_wallet_core_jni_RippleXAddress_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs) {
    jclass lhsClass = (*env)->GetObjectClass(env, lhs);
    jfieldID lhsHandleFieldID = (*env)->GetFieldID(env, lhsClass, "nativeHandle", "J");
    struct TWRippleXAddress *lhsInstance = (struct TWRippleXAddress *) (*env)->GetLongField(env, lhs, lhsHandleFieldID);
    jclass rhsClass = (*env)->GetObjectClass(env, rhs);
    jfieldID rhsHandleFieldID = (*env)->GetFieldID(env, rhsClass, "nativeHandle", "J");
    struct TWRippleXAddress *rhsInstance = (struct TWRippleXAddress *) (*env)->GetLongField(env, rhs, rhsHandleFieldID);
    jboolean resultValue = (jboolean) TWRippleXAddressEqual(lhsInstance, rhsInstance);

    (*env)->DeleteLocalRef(env, lhsClass);
    (*env)->DeleteLocalRef(env, rhsClass);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_RippleXAddress_isValidString(JNIEnv *env, jclass thisClass, jstring string) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    jboolean resultValue = (jboolean) TWRippleXAddressIsValidString(stringString);

    TWStringDelete(stringString);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_RippleXAddress_description(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWRippleXAddress *instance = (struct TWRippleXAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWRippleXAddressDescription(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jint JNICALL Java_wallet_core_jni_RippleXAddress_tag(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWRippleXAddress *instance = (struct TWRippleXAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWRippleXAddressTag(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

