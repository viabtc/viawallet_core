// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_DATAVECTOR_H
#define JNI_TW_DATAVECTOR_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_DataVector_nativeCreate(JNIEnv *env, jclass thisClass);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_DataVector_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
void JNICALL Java_wallet_core_jni_DataVector_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jsize JNICALL Java_wallet_core_jni_DataVector_size(JNIEnv *env, jobject thisObject);

JNIEXPORT
void JNICALL Java_wallet_core_jni_DataVector_add(JNIEnv *env, jobject thisObject, jbyteArray data);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_DataVector_get(JNIEnv *env, jobject thisObject, jsize index);


TW_EXTERN_C_END

#endif // JNI_TW_DATAVECTOR_H
