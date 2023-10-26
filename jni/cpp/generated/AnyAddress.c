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

#include <TrustWalletCore/TWAnyAddress.h>
#include <TrustWalletCore/TWPublicKey.h>

#include "TWJNI.h"
#include "AnyAddress.h"

jlong JNICALL Java_wallet_core_jni_AnyAddress_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring string, jobject coin) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    struct TWAnyAddress *instance = TWAnyAddressCreateWithString(stringString, coinValue);
    TWStringDelete(stringString);
    (*env)->DeleteLocalRef(env, coinClass);
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_AnyAddress_nativeCreateWithPublicKey(JNIEnv *env, jclass thisClass, jobject publicKey, jobject coin) {
    jclass publicKeyClass = (*env)->GetObjectClass(env, publicKey);
    jfieldID publicKeyHandleFieldID = (*env)->GetFieldID(env, publicKeyClass, "nativeHandle", "J");
    struct TWPublicKey *publicKeyInstance = (struct TWPublicKey *) (*env)->GetLongField(env, publicKey, publicKeyHandleFieldID);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    struct TWAnyAddress *instance = TWAnyAddressCreateWithPublicKey(publicKeyInstance, coinValue);
    (*env)->DeleteLocalRef(env, publicKeyClass);
    (*env)->DeleteLocalRef(env, coinClass);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_AnyAddress_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWAnyAddressDelete((struct TWAnyAddress *) handle);
}

jboolean JNICALL Java_wallet_core_jni_AnyAddress_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs) {
    jclass lhsClass = (*env)->GetObjectClass(env, lhs);
    jfieldID lhsHandleFieldID = (*env)->GetFieldID(env, lhsClass, "nativeHandle", "J");
    struct TWAnyAddress *lhsInstance = (struct TWAnyAddress *) (*env)->GetLongField(env, lhs, lhsHandleFieldID);
    jclass rhsClass = (*env)->GetObjectClass(env, rhs);
    jfieldID rhsHandleFieldID = (*env)->GetFieldID(env, rhsClass, "nativeHandle", "J");
    struct TWAnyAddress *rhsInstance = (struct TWAnyAddress *) (*env)->GetLongField(env, rhs, rhsHandleFieldID);
    jboolean resultValue = (jboolean) TWAnyAddressEqual(lhsInstance, rhsInstance);

    (*env)->DeleteLocalRef(env, lhsClass);
    (*env)->DeleteLocalRef(env, rhsClass);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_AnyAddress_isValid(JNIEnv *env, jclass thisClass, jstring string, jobject coin) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    jboolean resultValue = (jboolean) TWAnyAddressIsValid(stringString, coinValue);

    TWStringDelete(stringString);
    (*env)->DeleteLocalRef(env, coinClass);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_AnyAddress_description(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWAnyAddress *instance = (struct TWAnyAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWAnyAddressDescription(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jobject JNICALL Java_wallet_core_jni_AnyAddress_coin(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWAnyAddress *instance = (struct TWAnyAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    enum TWCoinType result = TWAnyAddressCoin(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/CoinType");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromValue", "(I)Lwallet/core/jni/CoinType;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jint) result);
}

jbyteArray JNICALL Java_wallet_core_jni_AnyAddress_data(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWAnyAddress *instance = (struct TWAnyAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWAnyAddressData(instance);
    result = TWDataJByteArray(resultData, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

