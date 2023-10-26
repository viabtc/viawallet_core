// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

package wallet.core.jni;

import java.security.InvalidParameterException;

/// Non-core transaction utility methods, like building a transaction using an external signature.
public class TransactionCompiler {
    private byte[] bytes;

    private TransactionCompiler() {
    }

    static TransactionCompiler createFromNative(byte[] bytes) {
        TransactionCompiler instance = new TransactionCompiler();
        instance.bytes = bytes;
        return instance;
    }
    /// Builds a coin-specific SigningInput (proto object) from a simple transaction.
    ///
    /// \param coin coin type.
    /// \param from sender of the transaction.
    /// \param to receiver of the transaction.
    /// \param amount transaction amount in string
    /// \param asset optional asset name, like "BNB"
    /// \param memo optional memo
    /// \param chainId optional chainId to override default
    /// \return serialized data of the SigningInput proto object.
    public static native byte[] buildInput(CoinType coinType, String from, String to, String amount, String asset, String memo, String chainId);
    /// Obtains pre-signing hashes of a transaction.
    ///
    /// We provide a default `PreSigningOutput` in TransactionCompiler.proto. 
    /// For some special coins, such as bitcoin, we will create a custom `PreSigningOutput` object in its proto file.
    /// \param coin coin type.
    /// \param txInputData The serialized data of a signing input
    /// \return serialized data of a proto object `PreSigningOutput` includes hash.
    public static native byte[] preImageHashes(CoinType coinType, byte[] txInputData);
    /// Compiles a complete transation with one or more external signatures.
    /// 
    /// Puts together from transaction input and provided public keys and signatures. The signatures must match the hashes
    /// returned by TWTransactionCompilerPreImageHashes, in the same order. The publicKeyHash attached
    /// to the hashes enable identifying the private key needed for signing the hash.
    /// \param coin coin type.
    /// \param txInputData The serialized data of a signing input.
    /// \param signatures signatures to compile, using TWDataVector.
    /// \param publicKeys public keys for signers to match private keys, using TWDataVector.
    /// \return serialized data of a proto object `SigningOutput`.
    public static native byte[] compileWithSignatures(CoinType coinType, byte[] txInputData, DataVector signatures, DataVector publicKeys);
}
