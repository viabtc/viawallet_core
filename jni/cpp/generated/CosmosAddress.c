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

#include <TrustWalletCore/TWCosmosAddress.h>
#include <TrustWalletCore/TWPublicKey.h>

#include "TWJNI.h"
#include "CosmosAddress.h"

jlong JNICALL Java_wallet_core_jni_CosmosAddress_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring string) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    struct TWCosmosAddress *instance = TWCosmosAddressCreateWithString(stringString);
    TWStringDelete(stringString);
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_CosmosAddress_nativeCreateWithKeyHash(JNIEnv *env, jclass thisClass, jobject hrp, jbyteArray keyHash) {
    jclass hrpClass = (*env)->GetObjectClass(env, hrp);
    jmethodID hrpValueMethodID = (*env)->GetMethodID(env, hrpClass, "value", "()I");
    jint hrpValue = (*env)->CallIntMethod(env, hrp, hrpValueMethodID);
    TWData *keyHashData = TWDataCreateWithJByteArray(env, keyHash);
    struct TWCosmosAddress *instance = TWCosmosAddressCreateWithKeyHash(hrpValue, keyHashData);
    (*env)->DeleteLocalRef(env, hrpClass);
    TWDataDelete(keyHashData);
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_CosmosAddress_nativeCreateWithPublicKey(JNIEnv *env, jclass thisClass, jobject hrp, jobject publicKey) {
    jclass hrpClass = (*env)->GetObjectClass(env, hrp);
    jmethodID hrpValueMethodID = (*env)->GetMethodID(env, hrpClass, "value", "()I");
    jint hrpValue = (*env)->CallIntMethod(env, hrp, hrpValueMethodID);
    jclass publicKeyClass = (*env)->GetObjectClass(env, publicKey);
    jfieldID publicKeyHandleFieldID = (*env)->GetFieldID(env, publicKeyClass, "nativeHandle", "J");
    struct TWPublicKey *publicKeyInstance = (struct TWPublicKey *) (*env)->GetLongField(env, publicKey, publicKeyHandleFieldID);
    struct TWCosmosAddress *instance = TWCosmosAddressCreateWithPublicKey(hrpValue, publicKeyInstance);
    (*env)->DeleteLocalRef(env, hrpClass);
    (*env)->DeleteLocalRef(env, publicKeyClass);
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_CosmosAddress_nativeCreateWithHRP(JNIEnv *env, jclass thisClass, jstring hrp, jobject publicKey) {
    TWString *hrpString = TWStringCreateWithJString(env, hrp);
    jclass publicKeyClass = (*env)->GetObjectClass(env, publicKey);
    jfieldID publicKeyHandleFieldID = (*env)->GetFieldID(env, publicKeyClass, "nativeHandle", "J");
    struct TWPublicKey *publicKeyInstance = (struct TWPublicKey *) (*env)->GetLongField(env, publicKey, publicKeyHandleFieldID);
    struct TWCosmosAddress *instance = TWCosmosAddressCreateWithHRP(hrpString, publicKeyInstance);
    TWStringDelete(hrpString);
    (*env)->DeleteLocalRef(env, publicKeyClass);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_CosmosAddress_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWCosmosAddressDelete((struct TWCosmosAddress *) handle);
}

jboolean JNICALL Java_wallet_core_jni_CosmosAddress_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs) {
    jclass lhsClass = (*env)->GetObjectClass(env, lhs);
    jfieldID lhsHandleFieldID = (*env)->GetFieldID(env, lhsClass, "nativeHandle", "J");
    struct TWCosmosAddress *lhsInstance = (struct TWCosmosAddress *) (*env)->GetLongField(env, lhs, lhsHandleFieldID);
    jclass rhsClass = (*env)->GetObjectClass(env, rhs);
    jfieldID rhsHandleFieldID = (*env)->GetFieldID(env, rhsClass, "nativeHandle", "J");
    struct TWCosmosAddress *rhsInstance = (struct TWCosmosAddress *) (*env)->GetLongField(env, rhs, rhsHandleFieldID);
    jboolean resultValue = (jboolean) TWCosmosAddressEqual(lhsInstance, rhsInstance);

    (*env)->DeleteLocalRef(env, lhsClass);
    (*env)->DeleteLocalRef(env, rhsClass);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_CosmosAddress_isValid(JNIEnv *env, jclass thisClass, jobject coin, jstring string) {
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    TWString *stringString = TWStringCreateWithJString(env, string);
    jboolean resultValue = (jboolean) TWCosmosAddressIsValid(coinValue, stringString);

    (*env)->DeleteLocalRef(env, coinClass);
    TWStringDelete(stringString);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_CosmosAddress_description(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWCosmosAddress *instance = (struct TWCosmosAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWCosmosAddressDescription(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jobject JNICALL Java_wallet_core_jni_CosmosAddress_hrp(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWCosmosAddress *instance = (struct TWCosmosAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    enum TWHRP result = TWCosmosAddressHRP(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/HRP");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromValue", "(I)Lwallet/core/jni/HRP;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jint) result);
}

jbyteArray JNICALL Java_wallet_core_jni_CosmosAddress_keyHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWCosmosAddress *instance = (struct TWCosmosAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWCosmosAddressKeyHash(instance);
    result = TWDataJByteArray(resultData, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

