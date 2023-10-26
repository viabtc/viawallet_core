// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_ETHEREUMABI_H
#define JNI_TW_ETHEREUMABI_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_EthereumAbi_encode(JNIEnv *env, jclass thisClass, jobject fn);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_EthereumAbi_decodeOutput(JNIEnv *env, jclass thisClass, jobject fn, jbyteArray encoded);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_EthereumAbi_decodeCall(JNIEnv *env, jclass thisClass, jbyteArray data, jstring abi);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_EthereumAbi_encodeTyped(JNIEnv *env, jclass thisClass, jstring messageJson);


TW_EXTERN_C_END

#endif // JNI_TW_ETHEREUMABI_H
