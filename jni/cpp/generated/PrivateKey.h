// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_PRIVATEKEY_H
#define JNI_TW_PRIVATEKEY_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_PrivateKey_nativeCreate(JNIEnv *env, jclass thisClass);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_PrivateKey_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jlong JNICALL Java_wallet_core_jni_PrivateKey_nativeCreateCopy(JNIEnv *env, jclass thisClass, jobject key);

JNIEXPORT
void JNICALL Java_wallet_core_jni_PrivateKey_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_PrivateKey_isValid(JNIEnv *env, jclass thisClass, jbyteArray data, jobject curve);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_PrivateKey_transform(JNIEnv *env, jclass thisClass, jbyteArray data, jobject curve);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_PrivateKey_data(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeySecp256k1(JNIEnv *env, jobject thisObject, jboolean compressed);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeyNist256p1(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeyEd25519(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeyEd25519Blake2b(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeyEd25519Cardano(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeySr25519(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeyMina(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeyKadena(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeyCurve25519(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_PrivateKey_getSharedKey(JNIEnv *env, jobject thisObject, jobject publicKey, jobject curve);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_PrivateKey_sign(JNIEnv *env, jobject thisObject, jbyteArray digest, jobject curve);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_PrivateKey_signAsDER(JNIEnv *env, jobject thisObject, jbyteArray digest);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_PrivateKey_signZilliqaSchnorr(JNIEnv *env, jobject thisObject, jbyteArray message);


TW_EXTERN_C_END

#endif // JNI_TW_PRIVATEKEY_H
