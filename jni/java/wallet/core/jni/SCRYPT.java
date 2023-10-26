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

/// SCRYPT Derivation Function
public class SCRYPT {
    private byte[] bytes;

    private SCRYPT() {
    }

    static SCRYPT createFromNative(byte[] bytes) {
        SCRYPT instance = new SCRYPT();
        instance.bytes = bytes;
        return instance;
    }
    /// Derives a key from a password and a salt using scrypt.
    ///
    /// \param password is the master password from which a derived key is generated
    /// \param salt is a sequence of bits, known as a cryptographic salt
    /// \param N is the number of iterations desired
    /// \param r is block size
    /// \param p is parallelization parameter
    /// \param dkLen is the desired byte-length of the derived key
    /// \return the derived key data.
    public static native byte[] scrypt(byte[] password, byte[] salt, long N, int r, int p, int dkLen);
}
