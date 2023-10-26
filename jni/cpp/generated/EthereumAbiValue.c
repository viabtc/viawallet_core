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

#include <TrustWalletCore/TWEthereumAbiValue.h>

#include "TWJNI.h"
#include "EthereumAbiValue.h"

jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeBool(JNIEnv *env, jclass thisClass, jboolean value) {
    jbyteArray result = NULL;
    TWData *resultData = TWEthereumAbiValueEncodeBool(value);
    result = TWDataJByteArray(resultData, env);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeInt32(JNIEnv *env, jclass thisClass, jint value) {
    jbyteArray result = NULL;
    TWData *resultData = TWEthereumAbiValueEncodeInt32(value);
    result = TWDataJByteArray(resultData, env);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeUInt32(JNIEnv *env, jclass thisClass, jint value) {
    jbyteArray result = NULL;
    TWData *resultData = TWEthereumAbiValueEncodeUInt32(value);
    result = TWDataJByteArray(resultData, env);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeInt256(JNIEnv *env, jclass thisClass, jbyteArray value) {
    TWData *valueData = TWDataCreateWithJByteArray(env, value);
    jbyteArray result = NULL;
    TWData *resultData = TWEthereumAbiValueEncodeInt256(valueData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(valueData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeUInt256(JNIEnv *env, jclass thisClass, jbyteArray value) {
    TWData *valueData = TWDataCreateWithJByteArray(env, value);
    jbyteArray result = NULL;
    TWData *resultData = TWEthereumAbiValueEncodeUInt256(valueData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(valueData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeAddress(JNIEnv *env, jclass thisClass, jbyteArray value) {
    TWData *valueData = TWDataCreateWithJByteArray(env, value);
    jbyteArray result = NULL;
    TWData *resultData = TWEthereumAbiValueEncodeAddress(valueData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(valueData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeString(JNIEnv *env, jclass thisClass, jstring value) {
    TWString *valueString = TWStringCreateWithJString(env, value);
    jbyteArray result = NULL;
    TWData *resultData = TWEthereumAbiValueEncodeString(valueString);
    result = TWDataJByteArray(resultData, env);
    TWStringDelete(valueString);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeBytes(JNIEnv *env, jclass thisClass, jbyteArray value) {
    TWData *valueData = TWDataCreateWithJByteArray(env, value);
    jbyteArray result = NULL;
    TWData *resultData = TWEthereumAbiValueEncodeBytes(valueData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(valueData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_EthereumAbiValue_encodeBytesDyn(JNIEnv *env, jclass thisClass, jbyteArray value) {
    TWData *valueData = TWDataCreateWithJByteArray(env, value);
    jbyteArray result = NULL;
    TWData *resultData = TWEthereumAbiValueEncodeBytesDyn(valueData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(valueData);
    return result;
}

jstring JNICALL Java_wallet_core_jni_EthereumAbiValue_decodeUInt256(JNIEnv *env, jclass thisClass, jbyteArray input) {
    TWData *inputData = TWDataCreateWithJByteArray(env, input);
    jstring result = NULL;
    TWString *resultString = TWEthereumAbiValueDecodeUInt256(inputData);
    result = TWStringJString(resultString, env);
    TWDataDelete(inputData);
    return result;
}

jstring JNICALL Java_wallet_core_jni_EthereumAbiValue_decodeValue(JNIEnv *env, jclass thisClass, jbyteArray input, jstring type) {
    TWData *inputData = TWDataCreateWithJByteArray(env, input);
    TWString *typeString = TWStringCreateWithJString(env, type);
    jstring result = NULL;
    TWString *resultString = TWEthereumAbiValueDecodeValue(inputData, typeString);
    result = TWStringJString(resultString, env);
    TWDataDelete(inputData);
    TWStringDelete(typeString);
    return result;
}

jstring JNICALL Java_wallet_core_jni_EthereumAbiValue_decodeArray(JNIEnv *env, jclass thisClass, jbyteArray input, jstring type) {
    TWData *inputData = TWDataCreateWithJByteArray(env, input);
    TWString *typeString = TWStringCreateWithJString(env, type);
    jstring result = NULL;
    TWString *resultString = TWEthereumAbiValueDecodeArray(inputData, typeString);
    result = TWStringJString(resultString, env);
    TWDataDelete(inputData);
    TWStringDelete(typeString);
    return result;
}

