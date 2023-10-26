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

#include <TrustWalletCore/TWBase32.h>

#include "TWJNI.h"
#include "Base32.h"

jbyteArray JNICALL Java_wallet_core_jni_Base32_decodeWithAlphabet(JNIEnv *env, jclass thisClass, jstring string, jstring alphabet) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    TWString *alphabetString = TWStringCreateWithJString(env, alphabet);
    jbyteArray result = NULL;
    TWData *resultData = TWBase32DecodeWithAlphabet(stringString, alphabetString);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWStringDelete(stringString);
    TWStringDelete(alphabetString);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Base32_decode(JNIEnv *env, jclass thisClass, jstring string) {
    TWString *stringString = TWStringCreateWithJString(env, string);
    jbyteArray result = NULL;
    TWData *resultData = TWBase32Decode(stringString);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWStringDelete(stringString);
    return result;
}

jstring JNICALL Java_wallet_core_jni_Base32_encodeWithAlphabet(JNIEnv *env, jclass thisClass, jbyteArray data, jstring alphabet) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    TWString *alphabetString = TWStringCreateWithJString(env, alphabet);
    jstring result = NULL;
    TWString *resultString = TWBase32EncodeWithAlphabet(dataData, alphabetString);
    result = TWStringJString(resultString, env);
    TWDataDelete(dataData);
    TWStringDelete(alphabetString);
    return result;
}

jstring JNICALL Java_wallet_core_jni_Base32_encode(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jstring result = NULL;
    TWString *resultString = TWBase32Encode(dataData);
    result = TWStringJString(resultString, env);
    TWDataDelete(dataData);
    return result;
}

