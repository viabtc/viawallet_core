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

#include <TrustWalletCore/TWHDWallet.h>
#include <TrustWalletCore/TWPublicKey.h>

#include "TWJNI.h"
#include "HDWallet.h"

jlong JNICALL Java_wallet_core_jni_HDWallet_nativeCreate(JNIEnv *env, jclass thisClass, jint strength, jstring passphrase) {
    TWString *passphraseString = TWStringCreateWithJString(env, passphrase);
    struct TWHDWallet *instance = TWHDWalletCreate(strength, passphraseString);
    TWStringDelete(passphraseString);
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_HDWallet_nativeCreateWithMnemonic(JNIEnv *env, jclass thisClass, jstring mnemonic, jstring passphrase) {
    TWString *mnemonicString = TWStringCreateWithJString(env, mnemonic);
    TWString *passphraseString = TWStringCreateWithJString(env, passphrase);
    struct TWHDWallet *instance = TWHDWalletCreateWithMnemonic(mnemonicString, passphraseString);
    TWStringDelete(mnemonicString);
    TWStringDelete(passphraseString);
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_HDWallet_nativeCreateWithMnemonicCheck(JNIEnv *env, jclass thisClass, jstring mnemonic, jstring passphrase, jboolean check) {
    TWString *mnemonicString = TWStringCreateWithJString(env, mnemonic);
    TWString *passphraseString = TWStringCreateWithJString(env, passphrase);
    struct TWHDWallet *instance = TWHDWalletCreateWithMnemonicCheck(mnemonicString, passphraseString, check);
    TWStringDelete(mnemonicString);
    TWStringDelete(passphraseString);
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_HDWallet_nativeCreateWithEntropy(JNIEnv *env, jclass thisClass, jbyteArray entropy, jstring passphrase) {
    TWData *entropyData = TWDataCreateWithJByteArray(env, entropy);
    TWString *passphraseString = TWStringCreateWithJString(env, passphrase);
    struct TWHDWallet *instance = TWHDWalletCreateWithEntropy(entropyData, passphraseString);
    TWDataDelete(entropyData);
    TWStringDelete(passphraseString);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_HDWallet_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWHDWalletDelete((struct TWHDWallet *) handle);
}

jobject JNICALL Java_wallet_core_jni_HDWallet_getPublicKeyFromExtended(JNIEnv *env, jclass thisClass, jstring extended, jobject coin, jstring derivationPath) {
    TWString *extendedString = TWStringCreateWithJString(env, extended);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    TWString *derivationPathString = TWStringCreateWithJString(env, derivationPath);
    struct TWPublicKey *result = TWHDWalletGetPublicKeyFromExtended(extendedString, coinValue, derivationPathString);

    TWStringDelete(extendedString);
    (*env)->DeleteLocalRef(env, coinClass);
    TWStringDelete(derivationPathString);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PublicKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PublicKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jbyteArray JNICALL Java_wallet_core_jni_HDWallet_seed(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWHDWalletSeed(instance);
    result = TWDataJByteArray(resultData, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_HDWallet_seedOfEntropy(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWHDWalletSeedOfEntropy(instance);
    result = TWDataJByteArray(resultData, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_HDWallet_mnemonic(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWHDWalletMnemonic(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_HDWallet_entropy(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWHDWalletEntropy(instance);
    result = TWDataJByteArray(resultData, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jobject JNICALL Java_wallet_core_jni_HDWallet_getMasterKey(JNIEnv *env, jobject thisObject, jobject curve) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass curveClass = (*env)->GetObjectClass(env, curve);
    jmethodID curveValueMethodID = (*env)->GetMethodID(env, curveClass, "value", "()I");
    jint curveValue = (*env)->CallIntMethod(env, curve, curveValueMethodID);
    struct TWPrivateKey *result = TWHDWalletGetMasterKey(instance, curveValue);

    (*env)->DeleteLocalRef(env, curveClass);

    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PrivateKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PrivateKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_HDWallet_getKeyForCoin(JNIEnv *env, jobject thisObject, jobject coin) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    struct TWPrivateKey *result = TWHDWalletGetKeyForCoin(instance, coinValue);

    (*env)->DeleteLocalRef(env, coinClass);

    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PrivateKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PrivateKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jstring JNICALL Java_wallet_core_jni_HDWallet_getAddressForCoin(JNIEnv *env, jobject thisObject, jobject coin) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    jstring result = NULL;
    TWString *resultString = TWHDWalletGetAddressForCoin(instance, coinValue);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, coinClass);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jobject JNICALL Java_wallet_core_jni_HDWallet_getKey(JNIEnv *env, jobject thisObject, jobject coin, jstring derivationPath) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    TWString *derivationPathString = TWStringCreateWithJString(env, derivationPath);
    struct TWPrivateKey *result = TWHDWalletGetKey(instance, coinValue, derivationPathString);

    (*env)->DeleteLocalRef(env, coinClass);
    TWStringDelete(derivationPathString);

    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PrivateKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PrivateKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_HDWallet_getKeyByCurve(JNIEnv *env, jobject thisObject, jobject curve, jstring derivationPath) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass curveClass = (*env)->GetObjectClass(env, curve);
    jmethodID curveValueMethodID = (*env)->GetMethodID(env, curveClass, "value", "()I");
    jint curveValue = (*env)->CallIntMethod(env, curve, curveValueMethodID);
    TWString *derivationPathString = TWStringCreateWithJString(env, derivationPath);
    struct TWPrivateKey *result = TWHDWalletGetKeyByCurve(instance, curveValue, derivationPathString);

    (*env)->DeleteLocalRef(env, curveClass);
    TWStringDelete(derivationPathString);

    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PrivateKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PrivateKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_HDWallet_getDerivedKey(JNIEnv *env, jobject thisObject, jobject coin, jint account, jint change, jint address) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    struct TWPrivateKey *result = TWHDWalletGetDerivedKey(instance, coinValue, account, change, address);

    (*env)->DeleteLocalRef(env, coinClass);

    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PrivateKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PrivateKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jstring JNICALL Java_wallet_core_jni_HDWallet_getExtendedPrivateKey(JNIEnv *env, jobject thisObject, jobject purpose, jobject coin, jobject version) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass purposeClass = (*env)->GetObjectClass(env, purpose);
    jmethodID purposeValueMethodID = (*env)->GetMethodID(env, purposeClass, "value", "()I");
    jint purposeValue = (*env)->CallIntMethod(env, purpose, purposeValueMethodID);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    jclass versionClass = (*env)->GetObjectClass(env, version);
    jmethodID versionValueMethodID = (*env)->GetMethodID(env, versionClass, "value", "()I");
    jint versionValue = (*env)->CallIntMethod(env, version, versionValueMethodID);
    jstring result = NULL;
    TWString *resultString = TWHDWalletGetExtendedPrivateKey(instance, purposeValue, coinValue, versionValue);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, purposeClass);
    (*env)->DeleteLocalRef(env, coinClass);
    (*env)->DeleteLocalRef(env, versionClass);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_HDWallet_getExtendedPublicKey(JNIEnv *env, jobject thisObject, jobject purpose, jobject coin, jobject version) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass purposeClass = (*env)->GetObjectClass(env, purpose);
    jmethodID purposeValueMethodID = (*env)->GetMethodID(env, purposeClass, "value", "()I");
    jint purposeValue = (*env)->CallIntMethod(env, purpose, purposeValueMethodID);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    jclass versionClass = (*env)->GetObjectClass(env, version);
    jmethodID versionValueMethodID = (*env)->GetMethodID(env, versionClass, "value", "()I");
    jint versionValue = (*env)->CallIntMethod(env, version, versionValueMethodID);
    jstring result = NULL;
    TWString *resultString = TWHDWalletGetExtendedPublicKey(instance, purposeValue, coinValue, versionValue);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, purposeClass);
    (*env)->DeleteLocalRef(env, coinClass);
    (*env)->DeleteLocalRef(env, versionClass);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_HDWallet_getExtendedPrivateKeyAccount(JNIEnv *env, jobject thisObject, jobject purpose, jobject coin, jobject derivation, jobject version, jint account) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass purposeClass = (*env)->GetObjectClass(env, purpose);
    jmethodID purposeValueMethodID = (*env)->GetMethodID(env, purposeClass, "value", "()I");
    jint purposeValue = (*env)->CallIntMethod(env, purpose, purposeValueMethodID);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    jclass derivationClass = (*env)->GetObjectClass(env, derivation);
    jmethodID derivationValueMethodID = (*env)->GetMethodID(env, derivationClass, "value", "()I");
    jint derivationValue = (*env)->CallIntMethod(env, derivation, derivationValueMethodID);
    jclass versionClass = (*env)->GetObjectClass(env, version);
    jmethodID versionValueMethodID = (*env)->GetMethodID(env, versionClass, "value", "()I");
    jint versionValue = (*env)->CallIntMethod(env, version, versionValueMethodID);
    jstring result = NULL;
    TWString *resultString = TWHDWalletGetExtendedPrivateKeyAccount(instance, purposeValue, coinValue, derivationValue, versionValue, account);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, purposeClass);
    (*env)->DeleteLocalRef(env, coinClass);
    (*env)->DeleteLocalRef(env, derivationClass);
    (*env)->DeleteLocalRef(env, versionClass);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_HDWallet_getExtendedPublicKeyAccount(JNIEnv *env, jobject thisObject, jobject purpose, jobject coin, jobject derivation, jobject version, jint account) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass purposeClass = (*env)->GetObjectClass(env, purpose);
    jmethodID purposeValueMethodID = (*env)->GetMethodID(env, purposeClass, "value", "()I");
    jint purposeValue = (*env)->CallIntMethod(env, purpose, purposeValueMethodID);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    jclass derivationClass = (*env)->GetObjectClass(env, derivation);
    jmethodID derivationValueMethodID = (*env)->GetMethodID(env, derivationClass, "value", "()I");
    jint derivationValue = (*env)->CallIntMethod(env, derivation, derivationValueMethodID);
    jclass versionClass = (*env)->GetObjectClass(env, version);
    jmethodID versionValueMethodID = (*env)->GetMethodID(env, versionClass, "value", "()I");
    jint versionValue = (*env)->CallIntMethod(env, version, versionValueMethodID);
    jstring result = NULL;
    TWString *resultString = TWHDWalletGetExtendedPublicKeyAccount(instance, purposeValue, coinValue, derivationValue, versionValue, account);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, purposeClass);
    (*env)->DeleteLocalRef(env, coinClass);
    (*env)->DeleteLocalRef(env, derivationClass);
    (*env)->DeleteLocalRef(env, versionClass);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_HDWallet_getExtendedPrivateKeyDerivation(JNIEnv *env, jobject thisObject, jobject purpose, jobject coin, jobject derivation, jobject version) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass purposeClass = (*env)->GetObjectClass(env, purpose);
    jmethodID purposeValueMethodID = (*env)->GetMethodID(env, purposeClass, "value", "()I");
    jint purposeValue = (*env)->CallIntMethod(env, purpose, purposeValueMethodID);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    jclass derivationClass = (*env)->GetObjectClass(env, derivation);
    jmethodID derivationValueMethodID = (*env)->GetMethodID(env, derivationClass, "value", "()I");
    jint derivationValue = (*env)->CallIntMethod(env, derivation, derivationValueMethodID);
    jclass versionClass = (*env)->GetObjectClass(env, version);
    jmethodID versionValueMethodID = (*env)->GetMethodID(env, versionClass, "value", "()I");
    jint versionValue = (*env)->CallIntMethod(env, version, versionValueMethodID);
    jstring result = NULL;
    TWString *resultString = TWHDWalletGetExtendedPrivateKeyDerivation(instance, purposeValue, coinValue, derivationValue, versionValue);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, purposeClass);
    (*env)->DeleteLocalRef(env, coinClass);
    (*env)->DeleteLocalRef(env, derivationClass);
    (*env)->DeleteLocalRef(env, versionClass);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_HDWallet_getExtendedPublicKeyDerivation(JNIEnv *env, jobject thisObject, jobject purpose, jobject coin, jobject derivation, jobject version) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass purposeClass = (*env)->GetObjectClass(env, purpose);
    jmethodID purposeValueMethodID = (*env)->GetMethodID(env, purposeClass, "value", "()I");
    jint purposeValue = (*env)->CallIntMethod(env, purpose, purposeValueMethodID);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    jclass derivationClass = (*env)->GetObjectClass(env, derivation);
    jmethodID derivationValueMethodID = (*env)->GetMethodID(env, derivationClass, "value", "()I");
    jint derivationValue = (*env)->CallIntMethod(env, derivation, derivationValueMethodID);
    jclass versionClass = (*env)->GetObjectClass(env, version);
    jmethodID versionValueMethodID = (*env)->GetMethodID(env, versionClass, "value", "()I");
    jint versionValue = (*env)->CallIntMethod(env, version, versionValueMethodID);
    jstring result = NULL;
    TWString *resultString = TWHDWalletGetExtendedPublicKeyDerivation(instance, purposeValue, coinValue, derivationValue, versionValue);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, purposeClass);
    (*env)->DeleteLocalRef(env, coinClass);
    (*env)->DeleteLocalRef(env, derivationClass);
    (*env)->DeleteLocalRef(env, versionClass);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

