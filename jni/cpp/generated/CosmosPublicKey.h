// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_COSMOSPUBLICKEY_H
#define JNI_TW_COSMOSPUBLICKEY_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_CosmosPublicKey_nativeCreateWithData(JNIEnv *env, jclass thisClass, jstring hrp, jbyteArray data);

JNIEXPORT
void JNICALL Java_wallet_core_jni_CosmosPublicKey_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_CosmosPublicKey_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_CosmosPublicKey_description(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_CosmosPublicKey_data(JNIEnv *env, jobject thisObject);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_CosmosPublicKey_hrp(JNIEnv *env, jobject thisObject);


TW_EXTERN_C_END

#endif // JNI_TW_COSMOSPUBLICKEY_H
