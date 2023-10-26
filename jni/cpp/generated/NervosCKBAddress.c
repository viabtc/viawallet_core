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

#include <TrustWalletCore/TWNervosCKBAddress.h>

#include "TWJNI.h"
#include "NervosCKBAddress.h"

jlong JNICALL Java_wallet_core_jni_NervosCKBAddress_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring string) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    struct TWNervosCKBAddress *instance = TWNervosCKBAddressCreateWithString(stringString);
    TWStringDelete(stringString);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_NervosCKBAddress_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWNervosCKBAddressDelete((struct TWNervosCKBAddress *) handle);
}

jboolean JNICALL Java_wallet_core_jni_NervosCKBAddress_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs) {
    jclass lhsClass = (*env)->GetObjectClass(env, lhs);
    jfieldID lhsHandleFieldID = (*env)->GetFieldID(env, lhsClass, "nativeHandle", "J");
    struct TWNervosCKBAddress *lhsInstance = (struct TWNervosCKBAddress *) (*env)->GetLongField(env, lhs, lhsHandleFieldID);
    jclass rhsClass = (*env)->GetObjectClass(env, rhs);
    jfieldID rhsHandleFieldID = (*env)->GetFieldID(env, rhsClass, "nativeHandle", "J");
    struct TWNervosCKBAddress *rhsInstance = (struct TWNervosCKBAddress *) (*env)->GetLongField(env, rhs, rhsHandleFieldID);
    jboolean resultValue = (jboolean) TWNervosCKBAddressEqual(lhsInstance, rhsInstance);

    (*env)->DeleteLocalRef(env, lhsClass);
    (*env)->DeleteLocalRef(env, rhsClass);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_NervosCKBAddress_isValidString(JNIEnv *env, jclass thisClass, jstring string) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    jboolean resultValue = (jboolean) TWNervosCKBAddressIsValidString(stringString);

    TWStringDelete(stringString);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_NervosCKBAddress_convertToBech32mFullAddress(JNIEnv *env, jclass thisClass, jstring address) {
    TWString *addressString = TWStringCreateWithJString(env, address);
    jstring result = NULL;
    TWString *resultString = TWNervosCKBAddressConvertToBech32mFullAddress(addressString);
    result = TWStringJString(resultString, env);
    TWStringDelete(addressString);
    return result;
}

jstring JNICALL Java_wallet_core_jni_NervosCKBAddress_description(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWNervosCKBAddress *instance = (struct TWNervosCKBAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWNervosCKBAddressDescription(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

