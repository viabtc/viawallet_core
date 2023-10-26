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

#include <TrustWalletCore/TWSolanaAddress.h>

#include "TWJNI.h"
#include "SolanaAddress.h"

jlong JNICALL Java_wallet_core_jni_SolanaAddress_nativeCreateWithString(JNIEnv *env, jclass thisClass, jstring string) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    struct TWSolanaAddress *instance = TWSolanaAddressCreateWithString(stringString);
    TWStringDelete(stringString);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_SolanaAddress_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWSolanaAddressDelete((struct TWSolanaAddress *) handle);
}

jstring JNICALL Java_wallet_core_jni_SolanaAddress_description(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWSolanaAddress *instance = (struct TWSolanaAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWSolanaAddressDescription(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_SolanaAddress_defaultTokenAddress(JNIEnv *env, jobject thisObject, jstring tokenMintAddress) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWSolanaAddress *instance = (struct TWSolanaAddress *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWString *tokenMintAddressString = TWStringCreateWithJString(env, tokenMintAddress);
    jstring result = NULL;
    TWString *resultString = TWSolanaAddressDefaultTokenAddress(instance, tokenMintAddressString);

    if (resultString == NULL) {
        goto cleanup;
    }
    result = TWStringJString(resultString, env);

cleanup:
    TWStringDelete(tokenMintAddressString);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

