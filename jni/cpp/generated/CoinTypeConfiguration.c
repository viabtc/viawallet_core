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

#include <TrustWalletCore/TWCoinTypeConfiguration.h>

#include "TWJNI.h"
#include "CoinTypeConfiguration.h"

jstring JNICALL Java_wallet_core_jni_CoinTypeConfiguration_getSymbol(JNIEnv *env, jclass thisClass, jobject type) {
    jclass typeClass = (*env)->GetObjectClass(env, type);
    jmethodID typeValueMethodID = (*env)->GetMethodID(env, typeClass, "value", "()I");
    jint typeValue = (*env)->CallIntMethod(env, type, typeValueMethodID);
    jstring result = NULL;
    TWString *resultString = TWCoinTypeConfigurationGetSymbol(typeValue);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, typeClass);
    return result;
}

jint JNICALL Java_wallet_core_jni_CoinTypeConfiguration_getDecimals(JNIEnv *env, jclass thisClass, jobject type) {
    jclass typeClass = (*env)->GetObjectClass(env, type);
    jmethodID typeValueMethodID = (*env)->GetMethodID(env, typeClass, "value", "()I");
    jint typeValue = (*env)->CallIntMethod(env, type, typeValueMethodID);
    jint resultValue = (jint) TWCoinTypeConfigurationGetDecimals(typeValue);

    (*env)->DeleteLocalRef(env, typeClass);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_CoinTypeConfiguration_getTransactionURL(JNIEnv *env, jclass thisClass, jobject type, jstring transactionID) {
    jclass typeClass = (*env)->GetObjectClass(env, type);
    jmethodID typeValueMethodID = (*env)->GetMethodID(env, typeClass, "value", "()I");
    jint typeValue = (*env)->CallIntMethod(env, type, typeValueMethodID);
    TWString *transactionIDString = TWStringCreateWithJString(env, transactionID);
    jstring result = NULL;
    TWString *resultString = TWCoinTypeConfigurationGetTransactionURL(typeValue, transactionIDString);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, typeClass);
    TWStringDelete(transactionIDString);
    return result;
}

jstring JNICALL Java_wallet_core_jni_CoinTypeConfiguration_getAccountURL(JNIEnv *env, jclass thisClass, jobject type, jstring accountID) {
    jclass typeClass = (*env)->GetObjectClass(env, type);
    jmethodID typeValueMethodID = (*env)->GetMethodID(env, typeClass, "value", "()I");
    jint typeValue = (*env)->CallIntMethod(env, type, typeValueMethodID);
    TWString *accountIDString = TWStringCreateWithJString(env, accountID);
    jstring result = NULL;
    TWString *resultString = TWCoinTypeConfigurationGetAccountURL(typeValue, accountIDString);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, typeClass);
    TWStringDelete(accountIDString);
    return result;
}

jstring JNICALL Java_wallet_core_jni_CoinTypeConfiguration_getID(JNIEnv *env, jclass thisClass, jobject type) {
    jclass typeClass = (*env)->GetObjectClass(env, type);
    jmethodID typeValueMethodID = (*env)->GetMethodID(env, typeClass, "value", "()I");
    jint typeValue = (*env)->CallIntMethod(env, type, typeValueMethodID);
    jstring result = NULL;
    TWString *resultString = TWCoinTypeConfigurationGetID(typeValue);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, typeClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_CoinTypeConfiguration_getName(JNIEnv *env, jclass thisClass, jobject type) {
    jclass typeClass = (*env)->GetObjectClass(env, type);
    jmethodID typeValueMethodID = (*env)->GetMethodID(env, typeClass, "value", "()I");
    jint typeValue = (*env)->CallIntMethod(env, type, typeValueMethodID);
    jstring result = NULL;
    TWString *resultString = TWCoinTypeConfigurationGetName(typeValue);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, typeClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_CoinTypeConfiguration_getFullName(JNIEnv *env, jclass thisClass, jobject type) {
    jclass typeClass = (*env)->GetObjectClass(env, type);
    jmethodID typeValueMethodID = (*env)->GetMethodID(env, typeClass, "value", "()I");
    jint typeValue = (*env)->CallIntMethod(env, type, typeValueMethodID);
    jstring result = NULL;
    TWString *resultString = TWCoinTypeConfigurationGetFullName(typeValue);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, typeClass);
    return result;
}

