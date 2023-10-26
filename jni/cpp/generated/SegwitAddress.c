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

#include <TrustWalletCore/TWSegwitAddress.h>
#include <TrustWalletCore/TWPublicKey.h>

#include "TWJNI.h"
#include "SegwitAddress.h"

jlong JNICALL Java_wallet_core_jni_SegwitAddress_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring string) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    struct TWSegwitAddress *instance = TWSegwitAddressCreateWithString(stringString);
    TWStringDelete(stringString);
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_SegwitAddress_nativeCreateWithPublicKey(JNIEnv *env, jclass thisClass, jobject hrp, jobject publicKey) {
    jclass hrpClass = (*env)->GetObjectClass(env, hrp);
    jmethodID hrpValueMethodID = (*env)->GetMethodID(env, hrpClass, "value", "()I");
    jint hrpValue = (*env)->CallIntMethod(env, hrp, hrpValueMethodID);
    jclass publicKeyClass = (*env)->GetObjectClass(env, publicKey);
    jfieldID publicKeyHandleFieldID = (*env)->GetFieldID(env, publicKeyClass, "nativeHandle", "J");
    struct TWPublicKey *publicKeyInstance = (struct TWPublicKey *) (*env)->GetLongField(env, publicKey, publicKeyHandleFieldID);
    struct TWSegwitAddress *instance = TWSegwitAddressCreateWithPublicKey(hrpValue, publicKeyInstance);
    (*env)->DeleteLocalRef(env, hrpClass);
    (*env)->DeleteLocalRef(env, publicKeyClass);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_SegwitAddress_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWSegwitAddressDelete((struct TWSegwitAddress *) handle);
}

jboolean JNICALL Java_wallet_core_jni_SegwitAddress_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs) {
    jclass lhsClass = (*env)->GetObjectClass(env, lhs);
    jfieldID lhsHandleFieldID = (*env)->GetFieldID(env, lhsClass, "nativeHandle", "J");
    struct TWSegwitAddress *lhsInstance = (struct TWSegwitAddress *) (*env)->GetLongField(env, lhs, lhsHandleFieldID);
    jclass rhsClass = (*env)->GetObjectClass(env, rhs);
    jfieldID rhsHandleFieldID = (*env)->GetFieldID(env, rhsClass, "nativeHandle", "J");
    struct TWSegwitAddress *rhsInstance = (struct TWSegwitAddress *) (*env)->GetLongField(env, rhs, rhsHandleFieldID);
    jboolean resultValue = (jboolean) TWSegwitAddressEqual(lhsInstance, rhsInstance);

    (*env)->DeleteLocalRef(env, lhsClass);
    (*env)->DeleteLocalRef(env, rhsClass);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_SegwitAddress_isValidString(JNIEnv *env, jclass thisClass, jstring string) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    jboolean resultValue = (jboolean) TWSegwitAddressIsValidString(stringString);

    TWStringDelete(stringString);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_SegwitAddress_description(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWSegwitAddress *instance = (struct TWSegwitAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWSegwitAddressDescription(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jobject JNICALL Java_wallet_core_jni_SegwitAddress_hrp(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWSegwitAddress *instance = (struct TWSegwitAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    enum TWHRP result = TWSegwitAddressHRP(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/HRP");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromValue", "(I)Lwallet/core/jni/HRP;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jint) result);
}

jint JNICALL Java_wallet_core_jni_SegwitAddress_witnessVersion(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWSegwitAddress *instance = (struct TWSegwitAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWSegwitAddressWitnessVersion(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jbyteArray JNICALL Java_wallet_core_jni_SegwitAddress_witnessProgram(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWSegwitAddress *instance = (struct TWSegwitAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWSegwitAddressWitnessProgram(instance);
    result = TWDataJByteArray(resultData, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

