// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_ETHEREUMABIFUNCTION_H
#define JNI_TW_ETHEREUMABIFUNCTION_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_EthereumAbiFunction_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring name);

JNIEXPORT
void JNICALL Java_wallet_core_jni_EthereumAbiFunction_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_EthereumAbiFunction_getType(JNIEnv *env, jobject thisObject);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamUInt8(JNIEnv *env, jobject thisObject, jchar val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamUInt16(JNIEnv *env, jobject thisObject, jshort val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamUInt32(JNIEnv *env, jobject thisObject, jint val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamUInt64(JNIEnv *env, jobject thisObject, jlong val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamUInt256(JNIEnv *env, jobject thisObject, jbyteArray val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamUIntN(JNIEnv *env, jobject thisObject, jint bits, jbyteArray val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamInt8(JNIEnv *env, jobject thisObject, jbyte val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamInt16(JNIEnv *env, jobject thisObject, jshort val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamInt32(JNIEnv *env, jobject thisObject, jint val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamInt64(JNIEnv *env, jobject thisObject, jlong val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamInt256(JNIEnv *env, jobject thisObject, jbyteArray val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamIntN(JNIEnv *env, jobject thisObject, jint bits, jbyteArray val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamBool(JNIEnv *env, jobject thisObject, jboolean val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamString(JNIEnv *env, jobject thisObject, jstring val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamAddress(JNIEnv *env, jobject thisObject, jbyteArray val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamBytes(JNIEnv *env, jobject thisObject, jbyteArray val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamBytesFix(JNIEnv *env, jobject thisObject, jsize size, jbyteArray val, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamArray(JNIEnv *env, jobject thisObject, jboolean isOutput);

JNIEXPORT
jchar JNICALL Java_wallet_core_jni_EthereumAbiFunction_getParamUInt8(JNIEnv *env, jobject thisObject, jint idx, jboolean isOutput);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_EthereumAbiFunction_getParamUInt64(JNIEnv *env, jobject thisObject, jint idx, jboolean isOutput);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiFunction_getParamUInt256(JNIEnv *env, jobject thisObject, jint idx, jboolean isOutput);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_EthereumAbiFunction_getParamBool(JNIEnv *env, jobject thisObject, jint idx, jboolean isOutput);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_EthereumAbiFunction_getParamString(JNIEnv *env, jobject thisObject, jint idx, jboolean isOutput);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiFunction_getParamAddress(JNIEnv *env, jobject thisObject, jint idx, jboolean isOutput);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamUInt8(JNIEnv *env, jobject thisObject, jint arrayIdx, jchar val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamUInt16(JNIEnv *env, jobject thisObject, jint arrayIdx, jshort val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamUInt32(JNIEnv *env, jobject thisObject, jint arrayIdx, jint val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamUInt64(JNIEnv *env, jobject thisObject, jint arrayIdx, jlong val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamUInt256(JNIEnv *env, jobject thisObject, jint arrayIdx, jbyteArray val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamUIntN(JNIEnv *env, jobject thisObject, jint arrayIdx, jint bits, jbyteArray val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamInt8(JNIEnv *env, jobject thisObject, jint arrayIdx, jbyte val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamInt16(JNIEnv *env, jobject thisObject, jint arrayIdx, jshort val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamInt32(JNIEnv *env, jobject thisObject, jint arrayIdx, jint val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamInt64(JNIEnv *env, jobject thisObject, jint arrayIdx, jlong val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamInt256(JNIEnv *env, jobject thisObject, jint arrayIdx, jbyteArray val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamIntN(JNIEnv *env, jobject thisObject, jint arrayIdx, jint bits, jbyteArray val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamBool(JNIEnv *env, jobject thisObject, jint arrayIdx, jboolean val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamString(JNIEnv *env, jobject thisObject, jint arrayIdx, jstring val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamAddress(JNIEnv *env, jobject thisObject, jint arrayIdx, jbyteArray val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamBytes(JNIEnv *env, jobject thisObject, jint arrayIdx, jbyteArray val);

JNIEXPORT
jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamBytesFix(JNIEnv *env, jobject thisObject, jint arrayIdx, jsize size, jbyteArray val);


TW_EXTERN_C_END

#endif // JNI_TW_ETHEREUMABIFUNCTION_H
