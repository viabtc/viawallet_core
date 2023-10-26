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

#include <TrustWalletCore/TWBitcoinScript.h>

#include "TWJNI.h"
#include "BitcoinScript.h"

jlong JNICALL Java_wallet_core_jni_BitcoinScript_nativeCreate(JNIEnv *env, jclass thisClass) {
    struct TWBitcoinScript *instance = TWBitcoinScriptCreate();
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_BitcoinScript_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    struct TWBitcoinScript *instance = TWBitcoinScriptCreateWithData(dataData);
    TWDataDelete(dataData);
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_BitcoinScript_nativeCreateCopy(JNIEnv *env, jclass thisClass, jobject script) {
    jclass scriptClass = (*env)->GetObjectClass(env, script);
    jfieldID scriptHandleFieldID = (*env)->GetFieldID(env, scriptClass, "nativeHandle", "J");
    struct TWBitcoinScript *scriptInstance = (struct TWBitcoinScript *) (*env)->GetLongField(env, script, scriptHandleFieldID);
    struct TWBitcoinScript *instance = TWBitcoinScriptCreateCopy(scriptInstance);
    (*env)->DeleteLocalRef(env, scriptClass);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_BitcoinScript_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWBitcoinScriptDelete((struct TWBitcoinScript *) handle);
}

jboolean JNICALL Java_wallet_core_jni_BitcoinScript_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs) {
    jclass lhsClass = (*env)->GetObjectClass(env, lhs);
    jfieldID lhsHandleFieldID = (*env)->GetFieldID(env, lhsClass, "nativeHandle", "J");
    struct TWBitcoinScript *lhsInstance = (struct TWBitcoinScript *) (*env)->GetLongField(env, lhs, lhsHandleFieldID);
    jclass rhsClass = (*env)->GetObjectClass(env, rhs);
    jfieldID rhsHandleFieldID = (*env)->GetFieldID(env, rhsClass, "nativeHandle", "J");
    struct TWBitcoinScript *rhsInstance = (struct TWBitcoinScript *) (*env)->GetLongField(env, rhs, rhsHandleFieldID);
    jboolean resultValue = (jboolean) TWBitcoinScriptEqual(lhsInstance, rhsInstance);

    (*env)->DeleteLocalRef(env, lhsClass);
    (*env)->DeleteLocalRef(env, rhsClass);

    return resultValue;
}

jobject JNICALL Java_wallet_core_jni_BitcoinScript_buildPayToPublicKey(JNIEnv *env, jclass thisClass, jbyteArray pubkey) {
    TWData *pubkeyData = TWDataCreateWithJByteArray(env, pubkey);
    struct TWBitcoinScript *result = TWBitcoinScriptBuildPayToPublicKey(pubkeyData);

    TWDataDelete(pubkeyData);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/BitcoinScript");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/BitcoinScript;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_BitcoinScript_buildPayToPublicKeyHash(JNIEnv *env, jclass thisClass, jbyteArray hash) {
    TWData *hashData = TWDataCreateWithJByteArray(env, hash);
    struct TWBitcoinScript *result = TWBitcoinScriptBuildPayToPublicKeyHash(hashData);

    TWDataDelete(hashData);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/BitcoinScript");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/BitcoinScript;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_BitcoinScript_buildPayToScriptHash(JNIEnv *env, jclass thisClass, jbyteArray scriptHash) {
    TWData *scriptHashData = TWDataCreateWithJByteArray(env, scriptHash);
    struct TWBitcoinScript *result = TWBitcoinScriptBuildPayToScriptHash(scriptHashData);

    TWDataDelete(scriptHashData);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/BitcoinScript");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/BitcoinScript;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_BitcoinScript_buildPayToWitnessPubkeyHash(JNIEnv *env, jclass thisClass, jbyteArray hash) {
    TWData *hashData = TWDataCreateWithJByteArray(env, hash);
    struct TWBitcoinScript *result = TWBitcoinScriptBuildPayToWitnessPubkeyHash(hashData);

    TWDataDelete(hashData);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/BitcoinScript");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/BitcoinScript;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_BitcoinScript_buildPayToWitnessScriptHash(JNIEnv *env, jclass thisClass, jbyteArray scriptHash) {
    TWData *scriptHashData = TWDataCreateWithJByteArray(env, scriptHash);
    struct TWBitcoinScript *result = TWBitcoinScriptBuildPayToWitnessScriptHash(scriptHashData);

    TWDataDelete(scriptHashData);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/BitcoinScript");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/BitcoinScript;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_BitcoinScript_lockScriptForAddress(JNIEnv *env, jclass thisClass, jstring address, jobject coin) {
    TWString *addressString = TWStringCreateWithJString(env, address);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    struct TWBitcoinScript *result = TWBitcoinScriptLockScriptForAddress(addressString, coinValue);

    TWStringDelete(addressString);
    (*env)->DeleteLocalRef(env, coinClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/BitcoinScript");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/BitcoinScript;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jint JNICALL Java_wallet_core_jni_BitcoinScript_hashTypeForCoin(JNIEnv *env, jclass thisClass, jobject coinType) {
    jclass coinTypeClass = (*env)->GetObjectClass(env, coinType);
    jmethodID coinTypeValueMethodID = (*env)->GetMethodID(env, coinTypeClass, "value", "()I");
    jint coinTypeValue = (*env)->CallIntMethod(env, coinType, coinTypeValueMethodID);
    jint resultValue = (jint) TWBitcoinScriptHashTypeForCoin(coinTypeValue);

    (*env)->DeleteLocalRef(env, coinTypeClass);

    return resultValue;
}

jsize JNICALL Java_wallet_core_jni_BitcoinScript_size(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jsize resultValue = (jsize) TWBitcoinScriptSize(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jbyteArray JNICALL Java_wallet_core_jni_BitcoinScript_data(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWBitcoinScriptData(instance);
    result = TWDataJByteArray(resultData, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_BitcoinScript_scriptHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWBitcoinScriptScriptHash(instance);
    result = TWDataJByteArray(resultData, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jboolean JNICALL Java_wallet_core_jni_BitcoinScript_isPayToScriptHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWBitcoinScriptIsPayToScriptHash(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_BitcoinScript_isPayToWitnessScriptHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWBitcoinScriptIsPayToWitnessScriptHash(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_BitcoinScript_isPayToWitnessPublicKeyHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWBitcoinScriptIsPayToWitnessPublicKeyHash(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_BitcoinScript_isWitnessProgram(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWBitcoinScriptIsWitnessProgram(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jbyteArray JNICALL Java_wallet_core_jni_BitcoinScript_matchPayToPubkey(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWBitcoinScriptMatchPayToPubkey(instance);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_BitcoinScript_matchPayToPubkeyHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWBitcoinScriptMatchPayToPubkeyHash(instance);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_BitcoinScript_matchPayToScriptHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWBitcoinScriptMatchPayToScriptHash(instance);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_BitcoinScript_matchPayToWitnessPublicKeyHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWBitcoinScriptMatchPayToWitnessPublicKeyHash(instance);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_BitcoinScript_matchPayToWitnessScriptHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWBitcoinScriptMatchPayToWitnessScriptHash(instance);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_BitcoinScript_encode(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWBitcoinScriptEncode(instance);
    result = TWDataJByteArray(resultData, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

