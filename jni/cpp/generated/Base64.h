// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_BASE64_H
#define JNI_TW_BASE64_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_Base64_decode(JNIEnv *env, jclass thisClass, jstring string);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_Base64_decodeUrl(JNIEnv *env, jclass thisClass, jstring string);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_Base64_encode(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_Base64_encodeUrl(JNIEnv *env, jclass thisClass, jbyteArray data);


TW_EXTERN_C_END

#endif // JNI_TW_BASE64_H
