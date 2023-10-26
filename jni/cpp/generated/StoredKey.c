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

#include <TrustWalletCore/TWStoredKey.h>

#include "TWJNI.h"
#include "StoredKey.h"

jlong JNICALL Java_wallet_core_jni_StoredKey_nativeCreateLevel(JNIEnv *env, jclass thisClass, jstring name, jbyteArray password, jobject encryptionLevel) {
    TWString *nameString = TWStringCreateWithJString(env, name);
    TWData *passwordData = TWDataCreateWithJByteArray(env, password);
    jclass encryptionLevelClass = (*env)->GetObjectClass(env, encryptionLevel);
    jmethodID encryptionLevelValueMethodID = (*env)->GetMethodID(env, encryptionLevelClass, "value", "()I");
    jint encryptionLevelValue = (*env)->CallIntMethod(env, encryptionLevel, encryptionLevelValueMethodID);
    struct TWStoredKey *instance = TWStoredKeyCreateLevel(nameString, passwordData, encryptionLevelValue);
    TWStringDelete(nameString);
    TWDataDelete(passwordData);
    (*env)->DeleteLocalRef(env, encryptionLevelClass);
    return (jlong) instance;
}

jlong JNICALL Java_wallet_core_jni_StoredKey_nativeCreate(JNIEnv *env, jclass thisClass, jstring name, jbyteArray password) {
    TWString *nameString = TWStringCreateWithJString(env, name);
    TWData *passwordData = TWDataCreateWithJByteArray(env, password);
    struct TWStoredKey *instance = TWStoredKeyCreate(nameString, passwordData);
    TWStringDelete(nameString);
    TWDataDelete(passwordData);
    return (jlong) instance;
}

void JNICALL Java_wallet_core_jni_StoredKey_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWStoredKeyDelete((struct TWStoredKey *) handle);
}

jobject JNICALL Java_wallet_core_jni_StoredKey_load(JNIEnv *env, jclass thisClass, jstring path) {
    TWString *pathString = TWStringCreateWithJString(env, path);
    struct TWStoredKey *result = TWStoredKeyLoad(pathString);

    TWStringDelete(pathString);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/StoredKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/StoredKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_StoredKey_importPrivateKey(JNIEnv *env, jclass thisClass, jbyteArray privateKey, jstring name, jbyteArray password, jobject coin) {
    TWData *privateKeyData = TWDataCreateWithJByteArray(env, privateKey);
    TWString *nameString = TWStringCreateWithJString(env, name);
    TWData *passwordData = TWDataCreateWithJByteArray(env, password);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    struct TWStoredKey *result = TWStoredKeyImportPrivateKey(privateKeyData, nameString, passwordData, coinValue);

    TWDataDelete(privateKeyData);
    TWStringDelete(nameString);
    TWDataDelete(passwordData);
    (*env)->DeleteLocalRef(env, coinClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/StoredKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/StoredKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_StoredKey_importHDWallet(JNIEnv *env, jclass thisClass, jstring mnemonic, jstring name, jbyteArray password, jobject coin) {
    TWString *mnemonicString = TWStringCreateWithJString(env, mnemonic);
    TWString *nameString = TWStringCreateWithJString(env, name);
    TWData *passwordData = TWDataCreateWithJByteArray(env, password);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    struct TWStoredKey *result = TWStoredKeyImportHDWallet(mnemonicString, nameString, passwordData, coinValue);

    TWStringDelete(mnemonicString);
    TWStringDelete(nameString);
    TWDataDelete(passwordData);
    (*env)->DeleteLocalRef(env, coinClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/StoredKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/StoredKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_StoredKey_importHDWalletSingle(JNIEnv *env, jclass thisClass, jstring mnemonic, jstring name, jbyteArray password, jobject coin) {
    TWString *mnemonicString = TWStringCreateWithJString(env, mnemonic);
    TWString *nameString = TWStringCreateWithJString(env, name);
    TWData *passwordData = TWDataCreateWithJByteArray(env, password);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    struct TWStoredKey *result = TWStoredKeyImportHDWalletSingle(mnemonicString, nameString, passwordData, coinValue);

    TWStringDelete(mnemonicString);
    TWStringDelete(nameString);
    TWDataDelete(passwordData);
    (*env)->DeleteLocalRef(env, coinClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/StoredKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/StoredKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_StoredKey_importJSON(JNIEnv *env, jclass thisClass, jbyteArray json) {
    TWData *jsonData = TWDataCreateWithJByteArray(env, json);
    struct TWStoredKey *result = TWStoredKeyImportJSON(jsonData);

    TWDataDelete(jsonData);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/StoredKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/StoredKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jstring JNICALL Java_wallet_core_jni_StoredKey_identifier(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWStoredKeyIdentifier(instance);

    if (resultString == NULL) {
        goto cleanup;
    }
    result = TWStringJString(resultString, env);

cleanup:

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_StoredKey_name(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWStoredKeyName(instance);
    result = TWStringJString(resultString, env);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jboolean JNICALL Java_wallet_core_jni_StoredKey_isMnemonic(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWStoredKeyIsMnemonic(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_StoredKey_isPrivateKey(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWStoredKeyIsPrivateKey(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jboolean JNICALL Java_wallet_core_jni_StoredKey_isMnemonicSingle(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWStoredKeyIsMnemonicSingle(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jsize JNICALL Java_wallet_core_jni_StoredKey_accountCount(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jsize resultValue = (jsize) TWStoredKeyAccountCount(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jstring JNICALL Java_wallet_core_jni_StoredKey_encryptionParameters(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = NULL;
    TWString *resultString = TWStoredKeyEncryptionParameters(instance);

    if (resultString == NULL) {
        goto cleanup;
    }
    result = TWStringJString(resultString, env);

cleanup:

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jobject JNICALL Java_wallet_core_jni_StoredKey_account(JNIEnv *env, jobject thisObject, jsize index) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWAccount *result = TWStoredKeyAccount(instance, index);


    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/Account");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/Account;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_StoredKey_accountForCoin(JNIEnv *env, jobject thisObject, jobject coin, jobject wallet) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    jclass walletClass = (*env)->GetObjectClass(env, wallet);
    jfieldID walletHandleFieldID = (*env)->GetFieldID(env, walletClass, "nativeHandle", "J");
    struct TWHDWallet *walletInstance = (struct TWHDWallet *) (*env)->GetLongField(env, wallet, walletHandleFieldID);
    struct TWAccount *result = TWStoredKeyAccountForCoin(instance, coinValue, walletInstance);

    (*env)->DeleteLocalRef(env, coinClass);
    (*env)->DeleteLocalRef(env, walletClass);

    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/Account");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/Account;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_StoredKey_accountForCoinDerivation(JNIEnv *env, jobject thisObject, jobject coin, jobject derivation, jobject wallet) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    jclass derivationClass = (*env)->GetObjectClass(env, derivation);
    jmethodID derivationValueMethodID = (*env)->GetMethodID(env, derivationClass, "value", "()I");
    jint derivationValue = (*env)->CallIntMethod(env, derivation, derivationValueMethodID);
    jclass walletClass = (*env)->GetObjectClass(env, wallet);
    jfieldID walletHandleFieldID = (*env)->GetFieldID(env, walletClass, "nativeHandle", "J");
    struct TWHDWallet *walletInstance = (struct TWHDWallet *) (*env)->GetLongField(env, wallet, walletHandleFieldID);
    struct TWAccount *result = TWStoredKeyAccountForCoinDerivation(instance, coinValue, derivationValue, walletInstance);

    (*env)->DeleteLocalRef(env, coinClass);
    (*env)->DeleteLocalRef(env, derivationClass);
    (*env)->DeleteLocalRef(env, walletClass);

    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/Account");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/Account;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

void JNICALL Java_wallet_core_jni_StoredKey_addAccountDerivation(JNIEnv *env, jobject thisObject, jstring address, jobject coin, jobject derivation, jstring derivationPath, jstring publicKey, jstring extendedPublicKey) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWString *addressString = TWStringCreateWithJString(env, address);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    jclass derivationClass = (*env)->GetObjectClass(env, derivation);
    jmethodID derivationValueMethodID = (*env)->GetMethodID(env, derivationClass, "value", "()I");
    jint derivationValue = (*env)->CallIntMethod(env, derivation, derivationValueMethodID);
    TWString *derivationPathString = TWStringCreateWithJString(env, derivationPath);
    TWString *publicKeyString = TWStringCreateWithJString(env, publicKey);
    TWString *extendedPublicKeyString = TWStringCreateWithJString(env, extendedPublicKey);
    TWStoredKeyAddAccountDerivation(instance, addressString, coinValue, derivationValue, derivationPathString, publicKeyString, extendedPublicKeyString);

    TWStringDelete(addressString);
    (*env)->DeleteLocalRef(env, coinClass);
    (*env)->DeleteLocalRef(env, derivationClass);
    TWStringDelete(derivationPathString);
    TWStringDelete(publicKeyString);
    TWStringDelete(extendedPublicKeyString);

    (*env)->DeleteLocalRef(env, thisClass);
}

void JNICALL Java_wallet_core_jni_StoredKey_addAccount(JNIEnv *env, jobject thisObject, jstring address, jobject coin, jstring derivationPath, jstring publicKey, jstring extendedPublicKey) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWString *addressString = TWStringCreateWithJString(env, address);
    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    TWString *derivationPathString = TWStringCreateWithJString(env, derivationPath);
    TWString *publicKeyString = TWStringCreateWithJString(env, publicKey);
    TWString *extendedPublicKeyString = TWStringCreateWithJString(env, extendedPublicKey);
    TWStoredKeyAddAccount(instance, addressString, coinValue, derivationPathString, publicKeyString, extendedPublicKeyString);

    TWStringDelete(addressString);
    (*env)->DeleteLocalRef(env, coinClass);
    TWStringDelete(derivationPathString);
    TWStringDelete(publicKeyString);
    TWStringDelete(extendedPublicKeyString);

    (*env)->DeleteLocalRef(env, thisClass);
}

void JNICALL Java_wallet_core_jni_StoredKey_removeAccountForCoin(JNIEnv *env, jobject thisObject, jobject coin) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    TWStoredKeyRemoveAccountForCoin(instance, coinValue);

    (*env)->DeleteLocalRef(env, coinClass);

    (*env)->DeleteLocalRef(env, thisClass);
}

void JNICALL Java_wallet_core_jni_StoredKey_removeAccountForCoinDerivation(JNIEnv *env, jobject thisObject, jobject coin, jobject derivation) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    jclass derivationClass = (*env)->GetObjectClass(env, derivation);
    jmethodID derivationValueMethodID = (*env)->GetMethodID(env, derivationClass, "value", "()I");
    jint derivationValue = (*env)->CallIntMethod(env, derivation, derivationValueMethodID);
    TWStoredKeyRemoveAccountForCoinDerivation(instance, coinValue, derivationValue);

    (*env)->DeleteLocalRef(env, coinClass);
    (*env)->DeleteLocalRef(env, derivationClass);

    (*env)->DeleteLocalRef(env, thisClass);
}

void JNICALL Java_wallet_core_jni_StoredKey_removeAccountForCoinDerivationPath(JNIEnv *env, jobject thisObject, jobject coin, jstring derivationPath) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    TWString *derivationPathString = TWStringCreateWithJString(env, derivationPath);
    TWStoredKeyRemoveAccountForCoinDerivationPath(instance, coinValue, derivationPathString);

    (*env)->DeleteLocalRef(env, coinClass);
    TWStringDelete(derivationPathString);

    (*env)->DeleteLocalRef(env, thisClass);
}

jboolean JNICALL Java_wallet_core_jni_StoredKey_store(JNIEnv *env, jobject thisObject, jstring path) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWString *pathString = TWStringCreateWithJString(env, path);
    jboolean resultValue = (jboolean) TWStoredKeyStore(instance, pathString);

    TWStringDelete(pathString);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jbyteArray JNICALL Java_wallet_core_jni_StoredKey_decryptPrivateKey(JNIEnv *env, jobject thisObject, jbyteArray password) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *passwordData = TWDataCreateWithJByteArray(env, password);
    jbyteArray result = NULL;
    TWData *resultData = TWStoredKeyDecryptPrivateKey(instance, passwordData);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:
    TWDataDelete(passwordData);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jstring JNICALL Java_wallet_core_jni_StoredKey_decryptMnemonic(JNIEnv *env, jobject thisObject, jbyteArray password) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *passwordData = TWDataCreateWithJByteArray(env, password);
    jstring result = NULL;
    TWString *resultString = TWStoredKeyDecryptMnemonic(instance, passwordData);

    if (resultString == NULL) {
        goto cleanup;
    }
    result = TWStringJString(resultString, env);

cleanup:
    TWDataDelete(passwordData);

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jobject JNICALL Java_wallet_core_jni_StoredKey_privateKey(JNIEnv *env, jobject thisObject, jobject coin, jbyteArray password) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass coinClass = (*env)->GetObjectClass(env, coin);
    jmethodID coinValueMethodID = (*env)->GetMethodID(env, coinClass, "value", "()I");
    jint coinValue = (*env)->CallIntMethod(env, coin, coinValueMethodID);
    TWData *passwordData = TWDataCreateWithJByteArray(env, password);
    struct TWPrivateKey *result = TWStoredKeyPrivateKey(instance, coinValue, passwordData);

    (*env)->DeleteLocalRef(env, coinClass);
    TWDataDelete(passwordData);

    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/PrivateKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/PrivateKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jobject JNICALL Java_wallet_core_jni_StoredKey_wallet(JNIEnv *env, jobject thisObject, jbyteArray password) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *passwordData = TWDataCreateWithJByteArray(env, password);
    struct TWHDWallet *result = TWStoredKeyWallet(instance, passwordData);

    TWDataDelete(passwordData);

    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "wallet/core/jni/HDWallet");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lwallet/core/jni/HDWallet;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jbyteArray JNICALL Java_wallet_core_jni_StoredKey_exportJSON(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = NULL;
    TWData *resultData = TWStoredKeyExportJSON(instance);

    if (resultData == NULL) {
        goto cleanup;
    }
    result = TWDataJByteArray(resultData, env);

cleanup:

    (*env)->DeleteLocalRef(env, thisClass);
    return result;
}

jboolean JNICALL Java_wallet_core_jni_StoredKey_fixAddresses(JNIEnv *env, jobject thisObject, jbyteArray password) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWStoredKey *instance = (struct TWStoredKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *passwordData = TWDataCreateWithJByteArray(env, password);
    jboolean resultValue = (jboolean) TWStoredKeyFixAddresses(instance, passwordData);

    TWDataDelete(passwordData);

    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

