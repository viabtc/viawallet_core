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

/// AES encryption/decryption methods.
public class AES {
    private byte[] bytes;

    private AES() {
    }

    static AES createFromNative(byte[] bytes) {
        AES instance = new AES();
        instance.bytes = bytes;
        return instance;
    }
    /// Encrypts a block of Data using AES in Cipher Block Chaining (CBC) mode.
    ///
    /// \param key encryption key Data, must be 16, 24, or 32 bytes long.
    /// \param data Data to encrypt.
    /// \param iv initialization vector.
    /// \param mode padding mode.
    /// \return encrypted Data.
    public static native byte[] encryptCBC(byte[] key, byte[] data, byte[] iv, AESPaddingMode mode);
    /// Decrypts a block of data using AES in Cipher Block Chaining (CBC) mode.
    ///
    /// \param key decryption key Data, must be 16, 24, or 32 bytes long.
    /// \param data Data to decrypt.
    /// \param iv initialization vector Data.
    /// \param mode padding mode.
    /// \return decrypted Data.
    public static native byte[] decryptCBC(byte[] key, byte[] data, byte[] iv, AESPaddingMode mode);
    /// Encrypts a block of data using AES in Counter (CTR) mode.
    ///
    /// \param key encryption key Data, must be 16, 24, or 32 bytes long.
    /// \param data Data to encrypt.
    /// \param iv initialization vector Data.
    /// \return encrypted Data.
    public static native byte[] encryptCTR(byte[] key, byte[] data, byte[] iv);
    /// Decrypts a block of data using AES in Counter (CTR) mode.
    ///
    /// \param key decryption key Data, must be 16, 24, or 32 bytes long.
    /// \param data Data to decrypt.
    /// \param iv initialization vector Data.
    /// \return decrypted Data.
    public static native byte[] decryptCTR(byte[] key, byte[] data, byte[] iv);
}
