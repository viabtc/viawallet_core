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

#include <TrustWalletCore/TWMnemonic.h>

#include "TWJNI.h"
#include "Mnemonic.h"

jboolean JNICALL Java_wallet_core_jni_Mnemonic_isValid(JNIEnv *env, jclass thisClass, jstring mnemonic) {
    TWString *mnemonicString = TWStringCreateWithJString(env, mnemonic);
    jboolean resultValue = (jboolean) TWMnemonicIsValid(mnemonicString);

    TWStringDelete(mnemonicString);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_Mnemonic_isValidWord(JNIEnv *env, jclass thisClass, jstring word) {
    TWString *wordString = TWStringCreateWithJString(env, word);
    jboolean resultValue = (jboolean) TWMnemonicIsValidWord(wordString);

    TWStringDelete(wordString);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_Mnemonic_suggest(JNIEnv *env, jclass thisClass, jstring prefix) {
    TWString *prefixString = TWStringCreateWithJString(env, prefix);
    jstring result = NULL;
    TWString *resultString = TWMnemonicSuggest(prefixString);
    result = TWStringJString(resultString, env);
    TWStringDelete(prefixString);
    return result;
}

jstring JNICALL Java_wallet_core_jni_Mnemonic_wordList(JNIEnv *env, jclass thisClass) {
    jstring result = NULL;
    TWString *resultString = TWMnemonicWordList();
    result = TWStringJString(resultString, env);
    return result;
}

