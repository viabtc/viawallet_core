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

#include <TrustWalletCore/TWPublicKey.h>

#include "TWJNI.h"
#include "PublicKey.h"

jlong JNICALL Java_wallet_core_jni_PublicKey_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray data, jobject type) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jclass typeClass = (*env)->GetObjectClass(env, type);
    jmethodID typeValueMethodID = (*env)->GetMethodID(env, typeClass, "value", "()I");
    jint typeValue = (*env)->CallIntMethod(env, type, typeValueMethodID);
    struct TWPublicKey *instance = TWPublicKeyCreateWithData(dataData, typeValue);
    TWDataDelete(dataData);
    (*env)->DeleteLocalRef(env, typeClass);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_PublicKey_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWPublicKeyDelete((struct TWPublicKey *) handle);
}

jboolean JNICALL Java_wallet_core_jni_PublicKey_isValid(JNIEnv *env, jclass thisClass, jbyteArray data, jobject type) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jclass typeClass = (*env)->GetObjectClass(env, type);
    jmethodID typeValueMethodID = (*env)->GetMethodID(env, typeClass, "value", "()I");
    jint typeValue = (*env)->CallIntMethod(env, type, typeValueMethodID);
    jboolean resultValue = (jboolean) TWPublicKeyIsValid(dataData, typeValue);

    TWDataDelete(dataData);
    (*env)->DeleteLocalRef(env, typeClass);

    return resultValue;
}

jobject JNICALL Java_wallet_core_jni_PublicKey_recover(JNIEnv *env, jclass thisClass, jbyteArray signature, jbyteArray message) {
    TWData *signatureData = TWDataCreateWithJByteArray(env, signature);
    TWData *messageData = TWDataCreateWithJByteArray(env, message);
    struct TWPublicKey *result = TWPublicKeyRecover(signatureData, messageData);

    TWDataDelete(signatureData);
    TWDataDelete(messageData);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PublicKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PublicKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jboolean JNICALL Java_wallet_core_jni_PublicKey_isCompressed(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPublicKey *instance = (struct TWPublicKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWPublicKeyIsCompressed(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jobject JNICALL Java_wallet_core_jni_PublicKey_compressed(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPublicKey *instance = (struct TWPublicKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWPublicKey *result = TWPublicKeyCompressed(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PublicKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PublicKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_PublicKey_uncompressed(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPublicKey *instance = (struct TWPublicKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWPublicKey *result = TWPublicKeyUncompressed(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PublicKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PublicKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jbyteArray JNICALL Java_wallet_core_jni_PublicKey_data(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPublicKey *instance = (struct TWPublicKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWPublicKeyData(instance);
    result = TWDataJByteArray(resultData, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jobject JNICALL Java_wallet_core_jni_PublicKey_keyType(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPublicKey *instance = (struct TWPublicKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    enum TWPublicKeyType result = TWPublicKeyKeyType(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PublicKeyType");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromValue", "(I)Lwallet/core/jni/PublicKeyType;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jint) result);
}

jstring JNICALL Java_wallet_core_jni_PublicKey_description(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPublicKey *instance = (struct TWPublicKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWPublicKeyDescription(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jboolean JNICALL Java_wallet_core_jni_PublicKey_verify(JNIEnv *env, jobject thisObject, jbyteArray signature, jbyteArray message) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPublicKey *instance = (struct TWPublicKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *signatureData = TWDataCreateWithJByteArray(env, signature);
    TWData *messageData = TWDataCreateWithJByteArray(env, message);
    jboolean resultValue = (jboolean) TWPublicKeyVerify(instance, signatureData, messageData);

    TWDataDelete(signatureData);
    TWDataDelete(messageData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_PublicKey_verifyAsDER(JNIEnv *env, jobject thisObject, jbyteArray signature, jbyteArray message) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPublicKey *instance = (struct TWPublicKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *signatureData = TWDataCreateWithJByteArray(env, signature);
    TWData *messageData = TWDataCreateWithJByteArray(env, message);
    jboolean resultValue = (jboolean) TWPublicKeyVerifyAsDER(instance, signatureData, messageData);

    TWDataDelete(signatureData);
    TWDataDelete(messageData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_PublicKey_verifyZilliqaSchnorr(JNIEnv *env, jobject thisObject, jbyteArray signature, jbyteArray message) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPublicKey *instance = (struct TWPublicKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *signatureData = TWDataCreateWithJByteArray(env, signature);
    TWData *messageData = TWDataCreateWithJByteArray(env, message);
    jboolean resultValue = (jboolean) TWPublicKeyVerifyZilliqaSchnorr(instance, signatureData, messageData);

    TWDataDelete(signatureData);
    TWDataDelete(messageData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

