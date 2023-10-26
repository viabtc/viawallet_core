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

#include <TrustWalletCore/TWEthereumAbi.h>
#include <TrustWalletCore/TWEthereumAbiFunction.h>

#include "TWJNI.h"
#include "EthereumAbi.h"

jbyteArray JNICALL Java_wallet_core_jni_EthereumAbi_encode(JNIEnv *env, jclass thisClass, jobject fn) {
    jclass fnClass = (*env)->GetObjectClass(env, fn);
    jfieldID fnHandleFieldID = (*env)->GetFieldID(env, fnClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *fnInstance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, fn, fnHandleFieldID);
    jbyteArray result = NULL;
    TWData *resultData = TWEthereumAbiEncode(fnInstance);
    result = TWDataJByteArray(resultData, env);
    (*env)->DeleteLocalRef(env, fnClass);
    return result;
}

jboolean JNICALL Java_wallet_core_jni_EthereumAbi_decodeOutput(JNIEnv *env, jclass thisClass, jobject fn, jbyteArray encoded) {
    jclass fnClass = (*env)->GetObjectClass(env, fn);
    jfieldID fnHandleFieldID = (*env)->GetFieldID(env, fnClass, "nativeHandle", "J");
    struct TWEthereumAbiFunction *fnInstance = (struct TWEthereumAbiFunction *) (*env)->GetLongField(env, fn, fnHandleFieldID);
    TWData *encodedData = TWDataCreateWithJByteArray(env, encoded);
    jboolean resultValue = (jboolean) TWEthereumAbiDecodeOutput(fnInstance, encodedData);

    (*env)->DeleteLocalRef(env, fnClass);
    TWDataDelete(encodedData);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_EthereumAbi_decodeCall(JNIEnv *env, jclass thisClass, jbyteArray data, jstring abi) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    TWString *abiString = TWStringCreateWithJString(env, abi);
    jstring result = NULL;
    TWString *resultString = TWEthereumAbiDecodeCall(dataData, abiString);

    if (resultString == NULL) {
        goto cleanup;
    }
    result = TWStringJString(resultString, env);

cleanup:
    TWDataDelete(dataData);
    TWStringDelete(abiString);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_EthereumAbi_encodeTyped(JNIEnv *env, jclass thisClass, jstring messageJson) {
    TWString *messageJsonString = TWStringCreateWithJString(env, messageJson);
    jbyteArray result = NULL;
    TWData *resultData = TWEthereumAbiEncodeTyped(messageJsonString);
    result = TWDataJByteArray(resultData, env);
    TWStringDelete(messageJsonString);
    return result;
}

