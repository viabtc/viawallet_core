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

#include <TrustWalletCore/TWBitcoinSigHashType.h>

#include "TWJNI.h"
#include "BitcoinSigHashType.h"

jboolean JNICALL Java_wallet_core_jni_BitcoinSigHashType_isSingle(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWBitcoinSigHashType instance = (enum TWBitcoinSigHashType) (*env)->GetIntField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWBitcoinSigHashTypeIsSingle(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_BitcoinSigHashType_isNone(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "value", "I");
    enum TWBitcoinSigHashType instance = (enum TWBitcoinSigHashType) (*env)->GetIntField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWBitcoinSigHashTypeIsNone(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

