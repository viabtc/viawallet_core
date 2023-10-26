// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_CASHADDRESS_H
#define JNI_TW_CASHADDRESS_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_CashAddress_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring hrp, jstring string);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_CashAddress_nativeCreateWithPublicKey(JNIEnv *env, jclass thisClass, jstring hrp, jobject publicKey);

JNIEXPORT
void JNICALL Java_wallet_core_jni_CashAddress_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_CashAddress_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_CashAddress_isValid(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_CashAddress_isValidString(JNIEnv *env, jclass thisClass, jstring hrp, jstring string);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_CashAddress_description(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_CashAddress_keyhash(JNIEnv *env, jobject thisObject);


TW_EXTERN_C_END

#endif // JNI_TW_CASHADDRESS_H
