// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_DERIVATIONPATH_H
#define JNI_TW_DERIVATIONPATH_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_DerivationPath_nativeCreate(JNIEnv *env, jclass thisClass, jobject purpose, jint coin, jint account, jint change, jint address);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_DerivationPath_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring string);

JNIEXPORT
void JNICALL Java_wallet_core_jni_DerivationPath_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_DerivationPath_purpose(JNIEnv *env, jobject thisObject);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_DerivationPath_coin(JNIEnv *env, jobject thisObject);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_DerivationPath_account(JNIEnv *env, jobject thisObject);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_DerivationPath_change(JNIEnv *env, jobject thisObject);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_DerivationPath_address(JNIEnv *env, jobject thisObject);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_DerivationPath_description(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_DerivationPath_indexAt(JNIEnv *env, jobject thisObject, jint index);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_DerivationPath_indicesCount(JNIEnv *env, jobject thisObject);


TW_EXTERN_C_END

#endif // JNI_TW_DERIVATIONPATH_H
