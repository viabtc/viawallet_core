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

#include <TrustWalletCore/TWTHORChainSwap.h>

#include "TWJNI.h"
#include "THORChainSwap.h"

jbyteArray JNICALL Java_wallet_core_jni_THORChainSwap_buildSwap(JNIEnv *env, jclass thisClass, jbyteArray input) {
    TWData *inputData = TWDataCreateWithJByteArray(env, input);
    jbyteArray result = NULL;
    TWData *resultData = TWTHORChainSwapBuildSwap(inputData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(inputData);
    return result;
}

