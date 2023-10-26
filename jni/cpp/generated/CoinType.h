// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_COINTYPE_H
#define JNI_TW_COINTYPE_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_CoinType_blockchain(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_CoinType_purpose(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_CoinType_curve(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_CoinType_xpubVersion(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_CoinType_xprvVersion(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_CoinType_hrp(JNIEnv *env, jobject thisObject);

JNIEXPORT
jchar JNICALL Java_wallet_core_jni_CoinType_p2pkhPrefix(JNIEnv *env, jobject thisObject);

JNIEXPORT
jchar JNICALL Java_wallet_core_jni_CoinType_p2shPrefix(JNIEnv *env, jobject thisObject);

JNIEXPORT
jchar JNICALL Java_wallet_core_jni_CoinType_staticPrefix(JNIEnv *env, jobject thisObject);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_CoinType_chainId(JNIEnv *env, jobject thisObject);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_CoinType_slip44Id(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_CoinType_publicKeyType(JNIEnv *env, jobject thisObject);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_CoinType_validate(JNIEnv *env, jobject thisObject, jstring address);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_CoinType_derivationPath(JNIEnv *env, jobject thisObject);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_CoinType_derivationPathWithDerivation(JNIEnv *env, jobject thisObject, jobject derivation);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_CoinType_deriveAddress(JNIEnv *env, jobject thisObject, jobject privateKey);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_CoinType_deriveAddressFromPublicKey(JNIEnv *env, jobject thisObject, jobject publicKey);


TW_EXTERN_C_END

#endif // JNI_TW_COINTYPE_H
