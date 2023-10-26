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

#include <TrustWalletCore/TWCardano.h>

#include "TWJNI.h"
#include "Cardano.h"

jlong JNICALL Java_wallet_core_jni_Cardano_minAdaAmount(JNIEnv *env, jclass thisClass, jbyteArray tokenBundle) {
    TWData *tokenBundleData = TWDataCreateWithJByteArray(env, tokenBundle);
    jlong resultValue = (jlong) TWCardanoMinAdaAmount(tokenBundleData);

    TWDataDelete(tokenBundleData);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_Cardano_getStakingAddress(JNIEnv *env, jclass thisClass, jstring baseAddress) {
    TWString *baseAddressString = TWStringCreateWithJString(env, baseAddress);
    jstring result = NULL;
    TWString *resultString = TWCardanoGetStakingAddress(baseAddressString);
    result = TWStringJString(resultString, env);
    TWStringDelete(baseAddressString);
    return result;
}

