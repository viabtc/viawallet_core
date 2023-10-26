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

/// Password-Based Key Derivation Function 2
public class PBKDF2 {
    private byte[] bytes;

    private PBKDF2() {
    }

    static PBKDF2 createFromNative(byte[] bytes) {
        PBKDF2 instance = new PBKDF2();
        instance.bytes = bytes;
        return instance;
    }
    /// Derives a key from a password and a salt using PBKDF2 + Sha256.
    ///
    /// \param password is the master password from which a derived key is generated
    /// \param salt is a sequence of bits, known as a cryptographic salt
    /// \param iterations is the number of iterations desired
    /// \param dkLen is the desired bit-length of the derived key
    /// \return the derived key data.
    public static native byte[] hmacSha256(byte[] password, byte[] salt, int iterations, int dkLen);
    /// Derives a key from a password and a salt using PBKDF2 + Sha512.
    ///
    /// \param password is the master password from which a derived key is generated
    /// \param salt is a sequence of bits, known as a cryptographic salt
    /// \param iterations is the number of iterations desired
    /// \param dkLen is the desired bit-length of the derived key
    /// \return the derived key data.
    public static native byte[] hmacSha512(byte[] password, byte[] salt, int iterations, int dkLen);
}
