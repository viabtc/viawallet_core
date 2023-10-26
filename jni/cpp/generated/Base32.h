// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_BASE32_H
#define JNI_TW_BASE32_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_Base32_decodeWithAlphabet(JNIEnv *env, jclass thisClass, jstring string, jstring alphabet);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_Base32_decode(JNIEnv *env, jclass thisClass, jstring string);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_Base32_encodeWithAlphabet(JNIEnv *env, jclass thisClass, jbyteArray data, jstring alphabet);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_Base32_encode(JNIEnv *env, jclass thisClass, jbyteArray data);


TW_EXTERN_C_END

#endif // JNI_TW_BASE32_H
