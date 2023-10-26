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

#include <TrustWalletCore/TWCoinType.h>

#include "TWJNI.h"
#include "CoinType.h"

jobject JNICALL Java_wallet_core_jni_CoinType_blockchain(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    enum TWBlockchain result = TWCoinTypeBlockchain(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/Blockchain");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromValue", "(I)Lwallet/core/jni/Blockchain;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jint) result);
}

jobject JNICALL Java_wallet_core_jni_CoinType_purpose(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    enum TWPurpose result = TWCoinTypePurpose(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/Purpose");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromValue", "(I)Lwallet/core/jni/Purpose;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jint) result);
}

jobject JNICALL Java_wallet_core_jni_CoinType_curve(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    enum TWCurve result = TWCoinTypeCurve(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/Curve");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromValue", "(I)Lwallet/core/jni/Curve;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jint) result);
}

jobject JNICALL Java_wallet_core_jni_CoinType_xpubVersion(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    enum TWHDVersion result = TWCoinTypeXpubVersion(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/HDVersion");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromValue", "(I)Lwallet/core/jni/HDVersion;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jint) result);
}

jobject JNICALL Java_wallet_core_jni_CoinType_xprvVersion(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    enum TWHDVersion result = TWCoinTypeXprvVersion(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/HDVersion");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromValue", "(I)Lwallet/core/jni/HDVersion;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jint) result);
}

jobject JNICALL Java_wallet_core_jni_CoinType_hrp(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    enum TWHRP result = TWCoinTypeHRP(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/HRP");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromValue", "(I)Lwallet/core/jni/HRP;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jint) result);
}

jchar JNICALL Java_wallet_core_jni_CoinType_p2pkhPrefix(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    jchar resultValue = (jchar) TWCoinTypeP2pkhPrefix(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jchar JNICALL Java_wallet_core_jni_CoinType_p2shPrefix(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    jchar resultValue = (jchar) TWCoinTypeP2shPrefix(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jchar JNICALL Java_wallet_core_jni_CoinType_staticPrefix(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    jchar resultValue = (jchar) TWCoinTypeStaticPrefix(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_CoinType_chainId(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWCoinTypeChainId(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jint JNICALL Java_wallet_core_jni_CoinType_slip44Id(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWCoinTypeSlip44Id(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jobject JNICALL Java_wallet_core_jni_CoinType_publicKeyType(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    enum TWPublicKeyType result = TWCoinTypePublicKeyType(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PublicKeyType");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromValue", "(I)Lwallet/core/jni/PublicKeyType;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jint) result);
}

jboolean JNICALL Java_wallet_core_jni_CoinType_validate(JNIEnv *env, jobject thisObject, jstring address) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    TWString *addressString = TWStringCreateWithJString(env, address);
    jboolean resultValue = (jboolean) TWCoinTypeValidate(instance, addressString);

    TWStringDelete(addressString);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_CoinType_derivationPath(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWCoinTypeDerivationPath(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_CoinType_derivationPathWithDerivation(JNIEnv *env, jobject thisObject, jobject derivation) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    jclass derivationClass = (*env)->GetObjectClass(env, derivation);
    jmethodID derivationValueMethodID = (*env)->GetMethodID(env, derivationClass, "value", "()I");
    jint derivationValue = (*env)->CallIntMethod(env, derivation, derivationValueMethodID);
    jstring result = NULL;
    TWString *resultString = TWCoinTypeDerivationPathWithDerivation(instance, derivationValue);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, derivationClass);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_CoinType_deriveAddress(JNIEnv *env, jobject thisObject, jobject privateKey) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    jclass privateKeyClass = (*env)->GetObjectClass(env, privateKey);
    jfieldID privateKeyHandleFieldID = (*env)->GetFieldID(env, privateKeyClass, "nativeHandle", "J");
    struct TWPrivateKey *privateKeyInstance = (struct TWPrivateKey *) (*env)->GetLongField(env, privateKey, privateKeyHandleFieldID);
    jstring result = NULL;
    TWString *resultString = TWCoinTypeDeriveAddress(instance, privateKeyInstance);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, privateKeyClass);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_CoinType_deriveAddressFromPublicKey(JNIEnv *env, jobject thisObject, jobject publicKey) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWCoinType instance = (enum TWCoinType) (*env)->GetIntField(env, thisObject, handleFieldID);

    jclass publicKeyClass = (*env)->GetObjectClass(env, publicKey);
    jfieldID publicKeyHandleFieldID = (*env)->GetFieldID(env, publicKeyClass, "nativeHandle", "J");
    struct TWPublicKey *publicKeyInstance = (struct TWPublicKey *) (*env)->GetLongField(env, publicKey, publicKeyHandleFieldID);
    jstring result = NULL;
    TWString *resultString = TWCoinTypeDeriveAddressFromPublicKey(instance, publicKeyInstance);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, publicKeyClass);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

