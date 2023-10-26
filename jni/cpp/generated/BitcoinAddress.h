// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_BITCOINADDRESS_H
#define JNI_TW_BITCOINADDRESS_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_BitcoinAddress_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring string);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_BitcoinAddress_nativeCreateWithCashAddressString(JNIEnv *env, jclass thisClass, jstring hrp, jstring string);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_BitcoinAddress_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_BitcoinAddress_nativeCreateWithPublicKey(JNIEnv *env, jclass thisClass, jobject publicKey, jchar prefix);

JNIEXPORT
void JNICALL Java_wallet_core_jni_BitcoinAddress_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_BitcoinAddress_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_BitcoinAddress_isValid(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_BitcoinAddress_isValidString(JNIEnv *env, jclass thisClass, jstring string);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_BitcoinAddress_description(JNIEnv *env, jobject thisObject);

JNIEXPORT
jchar JNICALL Java_wallet_core_jni_BitcoinAddress_prefix(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_BitcoinAddress_keyhash(JNIEnv *env, jobject thisObject);


TW_EXTERN_C_END

#endif // JNI_TW_BITCOINADDRESS_H
