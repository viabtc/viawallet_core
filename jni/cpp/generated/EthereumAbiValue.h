// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_ETHEREUMABIVALUE_H
#define JNI_TW_ETHEREUMABIVALUE_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeBool(JNIEnv *env, jclass thisClass, jboolean value);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeInt32(JNIEnv *env, jclass thisClass, jint value);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeUInt32(JNIEnv *env, jclass thisClass, jint value);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeInt256(JNIEnv *env, jclass thisClass, jbyteArray value);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeUInt256(JNIEnv *env, jclass thisClass, jbyteArray value);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeAddress(JNIEnv *env, jclass thisClass, jbyteArray value);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeString(JNIEnv *env, jclass thisClass, jstring value);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeBytes(JNIEnv *env, jclass thisClass, jbyteArray value);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeBytesDyn(JNIEnv *env, jclass thisClass, jbyteArray value);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_EthereumAbiValue_decodeUInt256(JNIEnv *env, jclass thisClass, jbyteArray input);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_EthereumAbiValue_decodeValue(JNIEnv *env, jclass thisClass, jbyteArray input, jstring type);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_EthereumAbiValue_decodeArray(JNIEnv *env, jclass thisClass, jbyteArray input, jstring type);


TW_EXTERN_C_END

#endif // JNI_TW_ETHEREUMABIVALUE_H
