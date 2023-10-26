// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_ANYADDRESS_H
#define JNI_TW_ANYADDRESS_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_AnyAddress_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring string, jobject coin);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_AnyAddress_nativeCreateWithPublicKey(JNIEnv *env, jclass thisClass, jobject publicKey, jobject coin);

JNIEXPORT
void JNICALL Java_wallet_core_jni_AnyAddress_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_AnyAddress_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_AnyAddress_isValid(JNIEnv *env, jclass thisClass, jstring string, jobject coin);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_AnyAddress_description(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_AnyAddress_coin(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_AnyAddress_data(JNIEnv *env, jobject thisObject);


TW_EXTERN_C_END

#endif // JNI_TW_ANYADDRESS_H
