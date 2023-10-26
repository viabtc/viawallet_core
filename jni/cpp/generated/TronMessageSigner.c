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

#include <TrustWalletCore/TWTronMessageSigner.h>
#include <TrustWalletCore/TWPrivateKey.h>
#include <TrustWalletCore/TWPublicKey.h>

#include "TWJNI.h"
#include "TronMessageSigner.h"

jstring JNICALL Java_wallet_core_jni_TronMessageSigner_signMessage(JNIEnv *env, jclass thisClass, jobject privateKey, jstring message) {
    jclass privateKeyClass = (*env)->GetObjectClass(env, privateKey);
    jfieldID privateKeyHandleFieldID = (*env)->GetFieldID(env, privateKeyClass, "nativeHandle", "J");
    struct TWPrivateKey *privateKeyInstance = (struct TWPrivateKey *) (*env)->GetLongField(env, privateKey, privateKeyHandleFieldID);
    TWString *messageString = TWStringCreateWithJString(env, message);
    jstring result = NULL;
    TWString *resultString = TWTronMessageSignerSignMessage(privateKeyInstance, messageString);
    result = TWStringJString(resultString, env);
    (*env)->DeleteLocalRef(env, privateKeyClass);
    TWStringDelete(messageString);
    return result;
}

jboolean JNICALL Java_wallet_core_jni_TronMessageSigner_verifyMessage(JNIEnv *env, jclass thisClass, jobject pubKey, jstring message, jstring signature) {
    jclass pubKeyClass = (*env)->GetObjectClass(env, pubKey);
    jfieldID pubKeyHandleFieldID = (*env)->GetFieldID(env, pubKeyClass, "nativeHandle", "J");
    struct TWPublicKey *pubKeyInstance = (struct TWPublicKey *) (*env)->GetLongField(env, pubKey, pubKeyHandleFieldID);
    TWString *messageString = TWStringCreateWithJString(env, message);
    TWString *signatureString = TWStringCreateWithJString(env, signature);
    jboolean resultValue = (jboolean) TWTronMessageSignerVerifyMessage(pubKeyInstance, messageString, signatureString);

    (*env)->DeleteLocalRef(env, pubKeyClass);
    TWStringDelete(messageString);
    TWStringDelete(signatureString);

    return resultValue;
}

