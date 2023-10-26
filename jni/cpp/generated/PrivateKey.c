// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWPrivateKey.h>

#include "TWJNI.h"
#include "PrivateKey.h"

jlong JNICALL Java_wallet_core_jni_PrivateKey_nativeCreate(JNIEnv *env, jclass thisClass) {
    struct TWPrivateKey *instance = TWPrivateKeyCreate();
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_PrivateKey_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    struct TWPrivateKey *instance = TWPrivateKeyCreateWithData(dataData);
    TWDataDelete(dataData);
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_PrivateKey_nativeCreateCopy(JNIEnv *env, jclass thisClass, jobject key) {
    jclass keyClass = (*env)->GetObjectClass(env, key);
    jfieldID keyHandleFieldID = (*env)->GetFieldID(env, keyClass, "nativeHandle", "J");
    struct TWPrivateKey *keyInstance = (struct TWPrivateKey *) (*env)->GetLongField(env, key, keyHandleFieldID);
    struct TWPrivateKey *instance = TWPrivateKeyCreateCopy(keyInstance);
    (*env)->DeleteLocalRef(env, keyClass);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_PrivateKey_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWPrivateKeyDelete((struct TWPrivateKey *) handle);
}

jboolean JNICALL Java_wallet_core_jni_PrivateKey_isValid(JNIEnv *env, jclass thisClass, jbyteArray data, jobject curve) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jclass curveClass = (*env)->GetObjectClass(env, curve);
    jmethodID curveValueMethodID = (*env)->GetMethodID(env, curveClass, "value", "()I");
    jint curveValue = (*env)->CallIntMethod(env, curve, curveValueMethodID);
    jboolean resultValue = (jboolean) TWPrivateKeyIsValid(dataData, curveValue);

    TWDataDelete(dataData);
    (*env)->DeleteLocalRef(env, curveClass);

    return resultValue;
}

jbyteArray JNICALL Java_wallet_core_jni_PrivateKey_transform(JNIEnv *env, jclass thisClass, jbyteArray data, jobject curve) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jclass curveClass = (*env)->GetObjectClass(env, curve);
    jmethodID curveValueMethodID = (*env)->GetMethodID(env, curveClass, "value", "()I");
    jint curveValue = (*env)->CallIntMethod(env, curve, curveValueMethodID);
    jbyteArray result = NULL;
    TWData *resultData = TWPrivateKeyTransform(dataData, curveValue);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWDataDelete(dataData);
    (*env)->DeleteLocalRef(env, curveClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_PrivateKey_data(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWPrivateKeyData(instance);
    result = TWDataJByteArray(resultData, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeySecp256k1(JNIEnv *env, jobject thisObject, jboolean compressed) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWPublicKey *result = TWPrivateKeyGetPublicKeySecp256k1(instance, compressed);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PublicKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PublicKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeyNist256p1(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWPublicKey *result = TWPrivateKeyGetPublicKeyNist256p1(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PublicKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PublicKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeyEd25519(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWPublicKey *result = TWPrivateKeyGetPublicKeyEd25519(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PublicKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PublicKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeyEd25519Blake2b(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWPublicKey *result = TWPrivateKeyGetPublicKeyEd25519Blake2b(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PublicKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PublicKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeyEd25519Cardano(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWPublicKey *result = TWPrivateKeyGetPublicKeyEd25519Cardano(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PublicKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PublicKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeySr25519(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWPublicKey *result = TWPrivateKeyGetPublicKeySr25519(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PublicKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PublicKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeyMina(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWPublicKey *result = TWPrivateKeyGetPublicKeyMina(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PublicKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PublicKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeyKadena(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWPublicKey *result = TWPrivateKeyGetPublicKeyKadena(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PublicKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PublicKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_PrivateKey_getPublicKeyCurve25519(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWPublicKey *result = TWPrivateKeyGetPublicKeyCurve25519(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PublicKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PublicKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jbyteArray JNICALL Java_wallet_core_jni_PrivateKey_getSharedKey(JNIEnv *env, jobject thisObject, jobject publicKey, jobject curve) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass publicKeyClass = (*env)->GetObjectClass(env, publicKey);
    jfieldID publicKeyHandleFieldID = (*env)->GetFieldID(env, publicKeyClass, "nativeHandle", "J");
    struct TWPublicKey *publicKeyInstance = (struct TWPublicKey *) (*env)->GetLongField(env, publicKey, publicKeyHandleFieldID);
    jclass curveClass = (*env)->GetObjectClass(env, curve);
    jmethodID curveValueMethodID = (*env)->GetMethodID(env, curveClass, "value", "()I");
    jint curveValue = (*env)->CallIntMethod(env, curve, curveValueMethodID);
    jbyteArray result = NULL;
    TWData *resultData = TWPrivateKeyGetSharedKey(instance, publicKeyInstance, curveValue);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    (*env)->DeleteLocalRef(env, publicKeyClass);
    (*env)->DeleteLocalRef(env, curveClass);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_PrivateKey_sign(JNIEnv *env, jobject thisObject, jbyteArray digest, jobject curve) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *digestData = TWDataCreateWithJByteArray(env, digest);
    jclass curveClass = (*env)->GetObjectClass(env, curve);
    jmethodID curveValueMethodID = (*env)->GetMethodID(env, curveClass, "value", "()I");
    jint curveValue = (*env)->CallIntMethod(env, curve, curveValueMethodID);
    jbyteArray result = NULL;
    TWData *resultData = TWPrivateKeySign(instance, digestData, curveValue);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWDataDelete(digestData);
    (*env)->DeleteLocalRef(env, curveClass);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_PrivateKey_signAsDER(JNIEnv *env, jobject thisObject, jbyteArray digest) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *digestData = TWDataCreateWithJByteArray(env, digest);
    jbyteArray result = NULL;
    TWData *resultData = TWPrivateKeySignAsDER(instance, digestData);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWDataDelete(digestData);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_PrivateKey_signZilliqaSchnorr(JNIEnv *env, jobject thisObject, jbyteArray message) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *messageData = TWDataCreateWithJByteArray(env, message);
    jbyteArray result = NULL;
    TWData *resultData = TWPrivateKeySignZilliqaSchnorr(instance, messageData);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWDataDelete(messageData);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

