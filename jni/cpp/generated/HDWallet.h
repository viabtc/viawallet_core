// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_HDWALLET_H
#define JNI_TW_HDWALLET_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_HDWallet_nativeCreate(JNIEnv *env, jclass thisClass, jint strength, jstring passphrase);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_HDWallet_nativeCreateWithMnemonic(JNIEnv *env, jclass thisClass, jstring mnemonic, jstring passphrase);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_HDWallet_nativeCreateWithMnemonicCheck(JNIEnv *env, jclass thisClass, jstring mnemonic, jstring passphrase, jboolean check);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_HDWallet_nativeCreateWithEntropy(JNIEnv *env, jclass thisClass, jbyteArray entropy, jstring passphrase);

JNIEXPORT
void JNICALL Java_wallet_core_jni_HDWallet_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_HDWallet_getPublicKeyFromExtended(JNIEnv *env, jclass thisClass, jstring extended, jobject coin, jstring derivationPath);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_HDWallet_seed(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_HDWallet_seedOfEntropy(JNIEnv *env, jobject thisObject);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_HDWallet_mnemonic(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_HDWallet_entropy(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_HDWallet_getMasterKey(JNIEnv *env, jobject thisObject, jobject curve);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_HDWallet_getKeyForCoin(JNIEnv *env, jobject thisObject, jobject coin);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_HDWallet_getAddressForCoin(JNIEnv *env, jobject thisObject, jobject coin);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_HDWallet_getKey(JNIEnv *env, jobject thisObject, jobject coin, jstring derivationPath);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_HDWallet_getKeyByCurve(JNIEnv *env, jobject thisObject, jobject curve, jstring derivationPath);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_HDWallet_getDerivedKey(JNIEnv *env, jobject thisObject, jobject coin, jint account, jint change, jint address);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_HDWallet_getExtendedPrivateKey(JNIEnv *env, jobject thisObject, jobject purpose, jobject coin, jobject version);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_HDWallet_getExtendedPublicKey(JNIEnv *env, jobject thisObject, jobject purpose, jobject coin, jobject version);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_HDWallet_getExtendedPrivateKeyAccount(JNIEnv *env, jobject thisObject, jobject purpose, jobject coin, jobject derivation, jobject version, jint account);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_HDWallet_getExtendedPublicKeyAccount(JNIEnv *env, jobject thisObject, jobject purpose, jobject coin, jobject derivation, jobject version, jint account);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_HDWallet_getExtendedPrivateKeyDerivation(JNIEnv *env, jobject thisObject, jobject purpose, jobject coin, jobject derivation, jobject version);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_HDWallet_getExtendedPublicKeyDerivation(JNIEnv *env, jobject thisObject, jobject purpose, jobject coin, jobject derivation, jobject version);


TW_EXTERN_C_END

#endif // JNI_TW_HDWALLET_H
