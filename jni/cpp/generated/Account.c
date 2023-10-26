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

#include <TrustWalletCore/TWAccount.h>

#include "TWJNI.h"
#include "Account.h"

jlong JNICALL Java_wallet_core_jni_Account_nativeCreate(JNIEnv *env, jclass thisClass, jstring address, jobject coin, jobject derivation, jstring derivationPath, jstring publicKey, jstring extendedPublicKey) {
    TWString *addressString = TWStringCreateWithJString(env, address);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    jclass derivationClass = (*env)->GetObjectClass(env, derivation);
    jmethodID derivationValueMethodID = (*env)->GetMethodID(env, derivationClass, "value", "()I");
    jint derivationValue = (*env)->CallIntMethod(env, derivation, derivationValueMethodID);
    TWString *derivationPathString = TWStringCreateWithJString(env, derivationPath);
    TWString *publicKeyString = TWStringCreateWithJString(env, publicKey);
    TWString *extendedPublicKeyString = TWStringCreateWithJString(env, extendedPublicKey);
    struct TWAccount *instance = TWAccountCreate(addressString, coinValue, derivationValue, derivationPathString, publicKeyString, extendedPublicKeyString);
    TWStringDelete(addressString);
    (*env)->DeleteLocalRef(env, coinClass);
    (*env)->DeleteLocalRef(env, derivationClass);
    TWStringDelete(derivationPathString);
    TWStringDelete(publicKeyString);
    TWStringDelete(extendedPublicKeyString);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_Account_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWAccountDelete((struct TWAccount *) handle);
}

jstring JNICALL Java_wallet_core_jni_Account_address(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWAccount *instance = (struct TWAccount *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWAccountAddress(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jobject JNICALL Java_wallet_core_jni_Account_derivation(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWAccount *instance = (struct TWAccount *) (*env)->GetLongField(env, thisObject, handleFieldID);

    enum TWDerivation result = TWAccountDerivation(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/Derivation");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromValue", "(I)Lwallet/core/jni/Derivation;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jint) result);
}

jstring JNICALL Java_wallet_core_jni_Account_derivationPath(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWAccount *instance = (struct TWAccount *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWAccountDerivationPath(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_Account_publicKey(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWAccount *instance = (struct TWAccount *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWAccountPublicKey(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_Account_extendedPublicKey(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWAccount *instance = (struct TWAccount *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWAccountExtendedPublicKey(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jobject JNICALL Java_wallet_core_jni_Account_coin(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWAccount *instance = (struct TWAccount *) (*env)->GetLongField(env, thisObject, handleFieldID);

    enum TWCoinType result = TWAccountCoin(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/CoinType");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromValue", "(I)Lwallet/core/jni/CoinType;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jint) result);
}

