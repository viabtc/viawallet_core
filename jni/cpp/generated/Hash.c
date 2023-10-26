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

#include <TrustWalletCore/TWHash.h>

#include "TWJNI.h"
#include "Hash.h"

jbyteArray JNICALL Java_wallet_core_jni_Hash_sha1(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashSHA1(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_sha256(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashSHA256(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_sha512(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashSHA512(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_sha512256(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashSHA512_256(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_keccak256(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashKeccak256(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_keccak512(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashKeccak512(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_sha3256(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashSHA3_256(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_sha3512(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashSHA3_512(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_ripemd(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashRIPEMD(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_blake256(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashBlake256(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_blake2b(JNIEnv *env, jclass thisClass, jbyteArray data, jsize size) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashBlake2b(dataData, size);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_blake2bPersonal(JNIEnv *env, jclass thisClass, jbyteArray data, jsize size, jbyteArray personal) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    TWData *personalData = TWDataCreateWithJByteArray(env, personal);
    jbyteArray result = NULL;
    TWData *resultData = TWHashBlake2bPersonal(dataData, size, personalData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    TWDataDelete(personalData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_groestl512(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashGroestl512(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_sha256SHA256(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashSHA256SHA256(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_sha256RIPEMD(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashSHA256RIPEMD(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_sha3256RIPEMD(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashSHA3_256RIPEMD(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_blake256Blake256(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashBlake256Blake256(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_blake256RIPEMD(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashBlake256RIPEMD(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

jbyteArray JNICALL Java_wallet_core_jni_Hash_groestl512Groestl512(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jbyteArray result = NULL;
    TWData *resultData = TWHashGroestl512Groestl512(dataData);
    result = TWDataJByteArray(resultData, env);
    TWDataDelete(dataData);
    return result;
}

