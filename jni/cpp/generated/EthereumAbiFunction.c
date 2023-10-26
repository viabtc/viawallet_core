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

#include <TrustWalletCore/TWEthereumAbiFunction.h>

#include "TWJNI.h"
#include "EthereumAbiFunction.h"

jlong JNICALL Java_wallet_core_jni_EthereumAbiFunction_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring name) {
    TWString *nameString = TWStringCreateWithJString(env, name);
    struct TWEthereumAbiFunction *instance = TWEthereumAbiFunctionCreateWithString(nameString);
    TWStringDelete(nameString);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_EthereumAbiFunction_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWEthereumAbiFunctionDelete((struct TWEthereumAbiFunction *) handle);
}

jstring JNICALL Java_wallet_core_jni_EthereumAbiFunction_getType(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWEthereumAbiFunctionGetType(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamUInt8(JNIEnv *env, jobject thisObject, jchar val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddParamUInt8(instance, val, isOutput);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamUInt16(JNIEnv *env, jobject thisObject, jshort val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddParamUInt16(instance, val, isOutput);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamUInt32(JNIEnv *env, jobject thisObject, jint val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddParamUInt32(instance, val, isOutput);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamUInt64(JNIEnv *env, jobject thisObject, jlong val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddParamUInt64(instance, val, isOutput);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamUInt256(JNIEnv *env, jobject thisObject, jbyteArray val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *valData = TWDataCreateWithJByteArray(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddParamUInt256(instance, valData, isOutput);

    TWDataDelete(valData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamUIntN(JNIEnv *env, jobject thisObject, jint bits, jbyteArray val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *valData = TWDataCreateWithJByteArray(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddParamUIntN(instance, bits, valData, isOutput);

    TWDataDelete(valData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamInt8(JNIEnv *env, jobject thisObject, jbyte val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddParamInt8(instance, val, isOutput);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamInt16(JNIEnv *env, jobject thisObject, jshort val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddParamInt16(instance, val, isOutput);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamInt32(JNIEnv *env, jobject thisObject, jint val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddParamInt32(instance, val, isOutput);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamInt64(JNIEnv *env, jobject thisObject, jlong val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddParamInt64(instance, val, isOutput);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamInt256(JNIEnv *env, jobject thisObject, jbyteArray val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *valData = TWDataCreateWithJByteArray(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddParamInt256(instance, valData, isOutput);

    TWDataDelete(valData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamIntN(JNIEnv *env, jobject thisObject, jint bits, jbyteArray val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *valData = TWDataCreateWithJByteArray(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddParamIntN(instance, bits, valData, isOutput);

    TWDataDelete(valData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamBool(JNIEnv *env, jobject thisObject, jboolean val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddParamBool(instance, val, isOutput);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamString(JNIEnv *env, jobject thisObject, jstring val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWString *valString = TWStringCreateWithJString(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddParamString(instance, valString, isOutput);

    TWStringDelete(valString);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamAddress(JNIEnv *env, jobject thisObject, jbyteArray val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *valData = TWDataCreateWithJByteArray(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddParamAddress(instance, valData, isOutput);

    TWDataDelete(valData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamBytes(JNIEnv *env, jobject thisObject, jbyteArray val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *valData = TWDataCreateWithJByteArray(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddParamBytes(instance, valData, isOutput);

    TWDataDelete(valData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamBytesFix(JNIEnv *env, jobject thisObject, jsize size, jbyteArray val, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *valData = TWDataCreateWithJByteArray(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddParamBytesFix(instance, size, valData, isOutput);

    TWDataDelete(valData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addParamArray(JNIEnv *env, jobject thisObject, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddParamArray(instance, isOutput);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jchar JNICALL Java_wallet_core_jni_EthereumAbiFunction_getParamUInt8(JNIEnv *env, jobject thisObject, jint idx, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jchar resultValue = (jchar) TWEthereumAbiFunctionGetParamUInt8(instance, idx, isOutput);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jlong JNICALL Java_wallet_core_jni_EthereumAbiFunction_getParamUInt64(JNIEnv *env, jobject thisObject, jint idx, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jlong resultValue = (jlong) TWEthereumAbiFunctionGetParamUInt64(instance, idx, isOutput);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiFunction_getParamUInt256(JNIEnv *env, jobject thisObject, jint idx, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWEthereumAbiFunctionGetParamUInt256(instance, idx, isOutput);
    result = TWDataJByteArray(resultData, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jboolean JNICALL Java_wallet_core_jni_EthereumAbiFunction_getParamBool(JNIEnv *env, jobject thisObject, jint idx, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWEthereumAbiFunctionGetParamBool(instance, idx, isOutput);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_EthereumAbiFunction_getParamString(JNIEnv *env, jobject thisObject, jint idx, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWEthereumAbiFunctionGetParamString(instance, idx, isOutput);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiFunction_getParamAddress(JNIEnv *env, jobject thisObject, jint idx, jboolean isOutput) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWEthereumAbiFunctionGetParamAddress(instance, idx, isOutput);
    result = TWDataJByteArray(resultData, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamUInt8(JNIEnv *env, jobject thisObject, jint arrayIdx, jchar val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamUInt8(instance, arrayIdx, val);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamUInt16(JNIEnv *env, jobject thisObject, jint arrayIdx, jshort val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamUInt16(instance, arrayIdx, val);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamUInt32(JNIEnv *env, jobject thisObject, jint arrayIdx, jint val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamUInt32(instance, arrayIdx, val);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamUInt64(JNIEnv *env, jobject thisObject, jint arrayIdx, jlong val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamUInt64(instance, arrayIdx, val);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamUInt256(JNIEnv *env, jobject thisObject, jint arrayIdx, jbyteArray val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *valData = TWDataCreateWithJByteArray(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamUInt256(instance, arrayIdx, valData);

    TWDataDelete(valData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamUIntN(JNIEnv *env, jobject thisObject, jint arrayIdx, jint bits, jbyteArray val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *valData = TWDataCreateWithJByteArray(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamUIntN(instance, arrayIdx, bits, valData);

    TWDataDelete(valData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamInt8(JNIEnv *env, jobject thisObject, jint arrayIdx, jbyte val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamInt8(instance, arrayIdx, val);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamInt16(JNIEnv *env, jobject thisObject, jint arrayIdx, jshort val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamInt16(instance, arrayIdx, val);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamInt32(JNIEnv *env, jobject thisObject, jint arrayIdx, jint val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamInt32(instance, arrayIdx, val);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamInt64(JNIEnv *env, jobject thisObject, jint arrayIdx, jlong val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamInt64(instance, arrayIdx, val);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamInt256(JNIEnv *env, jobject thisObject, jint arrayIdx, jbyteArray val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *valData = TWDataCreateWithJByteArray(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamInt256(instance, arrayIdx, valData);

    TWDataDelete(valData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamIntN(JNIEnv *env, jobject thisObject, jint arrayIdx, jint bits, jbyteArray val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *valData = TWDataCreateWithJByteArray(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamIntN(instance, arrayIdx, bits, valData);

    TWDataDelete(valData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamBool(JNIEnv *env, jobject thisObject, jint arrayIdx, jboolean val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamBool(instance, arrayIdx, val);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamString(JNIEnv *env, jobject thisObject, jint arrayIdx, jstring val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWString *valString = TWStringCreateWithJString(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamString(instance, arrayIdx, valString);

    TWStringDelete(valString);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamAddress(JNIEnv *env, jobject thisObject, jint arrayIdx, jbyteArray val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *valData = TWDataCreateWithJByteArray(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamAddress(instance, arrayIdx, valData);

    TWDataDelete(valData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamBytes(JNIEnv *env, jobject thisObject, jint arrayIdx, jbyteArray val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *valData = TWDataCreateWithJByteArray(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamBytes(instance, arrayIdx, valData);

    TWDataDelete(valData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jint JNICALL Java_wallet_core_jni_EthereumAbiFunction_addInArrayParamBytesFix(JNIEnv *env, jobject thisObject, jint arrayIdx, jsize size, jbyteArray val) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *instance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *valData = TWDataCreateWithJByteArray(env, val);
    jint resultValue = (jint) TWEthereumAbiFunctionAddInArrayParamBytesFix(instance, arrayIdx, size, valData);

    TWDataDelete(valData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

