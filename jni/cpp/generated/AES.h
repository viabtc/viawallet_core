// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_AES_H
#define JNI_TW_AES_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_AES_encryptCBC(JNIEnv *env, jclass thisClass, jbyteArray key, jbyteArray data, jbyteArray iv, jobject mode);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_AES_decryptCBC(JNIEnv *env, jclass thisClass, jbyteArray key, jbyteArray data, jbyteArray iv, jobject mode);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_AES_encryptCTR(JNIEnv *env, jclass thisClass, jbyteArray key, jbyteArray data, jbyteArray iv);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_AES_decryptCTR(JNIEnv *env, jclass thisClass, jbyteArray key, jbyteArray data, jbyteArray iv);


TW_EXTERN_C_END

#endif // JNI_TW_AES_H
