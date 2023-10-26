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

#include <TrustWalletCore/TWFIOAccount.h>

#include "TWJNI.h"
#include "FIOAccount.h"

jlong JNICALL Java_wallet_core_jni_FIOAccount_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring string) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    struct TWFIOAccount *instance = TWFIOAccountCreateWithString(stringString);
    TWStringDelete(stringString);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_FIOAccount_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWFIOAccountDelete((struct TWFIOAccount *) handle);
}

jstring JNICALL Java_wallet_core_jni_FIOAccount_description(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWFIOAccount *instance = (struct TWFIOAccount *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWFIOAccountDescription(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

