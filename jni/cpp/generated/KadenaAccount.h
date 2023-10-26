// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_KADENAACCOUNT_H
#define JNI_TW_KADENAACCOUNT_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_KadenaAccount_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring string);

JNIEXPORT
void JNICALL Java_wallet_core_jni_KadenaAccount_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_KadenaAccount_isValid(JNIEnv *env, jclass thisClass, jstring string);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_KadenaAccount_description(JNIEnv *env, jobject thisObject);


TW_EXTERN_C_END

#endif // JNI_TW_KADENAACCOUNT_H
