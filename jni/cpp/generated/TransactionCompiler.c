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

#include <TrustWalletCore/TWTransactionCompiler.h>
#include <TrustWalletCore/TWDataVector.h>

#include "TWJNI.h"
#include "TransactionCompiler.h"

jbyteArray JNICALL Java_wallet_core_jni_TransactionCompiler_buildInput(JNIEnv *env, jclass thisClass, jobject coinType, jstring from, jstring to, jstring amount, jstring asset, jstring memo, jstring chainId) {
    jclass coinTypeClass = (*env)->GetObjectClass(env, coinType);
    jmethodID coinTypeValueMethodID = (*env)->GetMethodID(env, coinTypeClass, "value", "()I");
    jint coinTypeValue = (*env)->CallIntMethod(env, coinType, coinTypeValueMethodID);
    TWString *fromString = TWStringCreateWithJString(env, from);
    TWString *toString = TWStringCreateWithJString(env, to);
    TWString *amountString = TWStringCreateWithJString(env, amount);
    TWString *assetString = TWStringCreateWithJString(env, asset);
    TWString *memoString = TWStringCreateWithJString(env, memo);
    TWString *chainIdString = TWStringCreateWithJString(env, chainId);
    jbyteArray result = NULL;
    TWData *resultData = TWTransactionCompilerBuildInput(coinTypeValue, fromString, toString, amountString, assetString, memoString, chainIdString);
    result = TWDataJByteArray(resultData, env);
    (*env)->DeleteLocalRef(env, coinTypeClass);
    TWStringDelete(fromString);
    TWStringDelete(toString);
    TWStringDelete(amountString);
    TWStringDelete(assetString);
    TWStringDelete(memoString);
    TWStringDelete(chainIdString);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_TransactionCompiler_preImageHashes(JNIEnv *env, jclass thisClass, jobject coinType, jbyteArray txInputData) {
    jclass coinTypeClass = (*env)->GetObjectClass(env, coinType);
    jmethodID coinTypeValueMethodID = (*env)->GetMethodID(env, coinTypeClass, "value", "()I");
    jint coinTypeValue = (*env)->CallIntMethod(env, coinType, coinTypeValueMethodID);
    TWData *txInputDataData = TWDataCreateWithJByteArray(env, txInputData);
    jbyteArray result = NULL;
    TWData *resultData = TWTransactionCompilerPreImageHashes(coinTypeValue, txInputDataData);
    result = TWDataJByteArray(resultData, env);
    (*env)->DeleteLocalRef(env, coinTypeClass);
    TWDataDelete(txInputDataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_TransactionCompiler_compileWithSignatures(JNIEnv *env, jclass thisClass, jobject coinType, jbyteArray txInputData, jobject signatures, jobject publicKeys) {
    jclass coinTypeClass = (*env)->GetObjectClass(env, coinType);
    jmethodID coinTypeValueMethodID = (*env)->GetMethodID(env, coinTypeClass, "value", "()I");
    jint coinTypeValue = (*env)->CallIntMethod(env, coinType, coinTypeValueMethodID);
    TWData *txInputDataData = TWDataCreateWithJByteArray(env, txInputData);
    jclass signaturesClass = (*env)->GetObjectClass(env, signatures);
    jfieldID signaturesHandleFieldID = (*env)->GetFieldID(env, signaturesClass, "nativeHandle", "J");
    struct TWDataVector *signaturesInstance = (struct TWDataVector *) (*env)->GetLongField(env, signatures, signaturesHandleFieldID);
    jclass publicKeysClass = (*env)->GetObjectClass(env, publicKeys);
    jfieldID publicKeysHandleFieldID = (*env)->GetFieldID(env, publicKeysClass, "nativeHandle", "J");
    struct TWDataVector *publicKeysInstance = (struct TWDataVector *) (*env)->GetLongField(env, publicKeys, publicKeysHandleFieldID);
    jbyteArray result = NULL;
    TWData *resultData = TWTransactionCompilerCompileWithSignatures(coinTypeValue, txInputDataData, signaturesInstance, publicKeysInstance);
    result = TWDataJByteArray(resultData, env);
    (*env)->DeleteLocalRef(env, coinTypeClass);
    TWDataDelete(txInputDataData);
    (*env)->DeleteLocalRef(env, signaturesClass);
    (*env)->DeleteLocalRef(env, publicKeysClass);
    return result;
}

