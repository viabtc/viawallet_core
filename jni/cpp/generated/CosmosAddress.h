// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_COSMOSADDRESS_H
#define JNI_TW_COSMOSADDRESS_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_CosmosAddress_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring string);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_CosmosAddress_nativeCreateWithKeyHash(JNIEnv *env, jclass thisClass, jobject hrp, jbyteArray keyHash);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_CosmosAddress_nativeCreateWithPublicKey(JNIEnv *env, jclass thisClass, jobject hrp, jobject publicKey);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_CosmosAddress_nativeCreateWithHRP(JNIEnv *env, jclass thisClass, jstring hrp, jobject publicKey);

JNIEXPORT
void JNICALL Java_wallet_core_jni_CosmosAddress_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_CosmosAddress_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_CosmosAddress_isValid(JNIEnv *env, jclass thisClass, jobject coin, jstring string);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_CosmosAddress_description(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_CosmosAddress_hrp(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_CosmosAddress_keyHash(JNIEnv *env, jobject thisObject);


TW_EXTERN_C_END

#endif // JNI_TW_COSMOSADDRESS_H
