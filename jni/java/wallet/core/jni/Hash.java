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

/// Hash functions
public class Hash {
    private byte[] bytes;

    private Hash() {
    }

    static Hash createFromNative(byte[] bytes) {
        Hash instance = new Hash();
        instance.bytes = bytes;
        return instance;
    }
    /// Computes the SHA1 of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed SHA1 block of data
    public static native byte[] sha1(byte[] data);
    /// Computes the SHA256 of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed SHA256 block of data
    public static native byte[] sha256(byte[] data);
    /// Computes the SHA512 of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed SHA512 block of data
    public static native byte[] sha512(byte[] data);
    /// Computes the SHA512_256 of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed SHA512_256 block of data
    public static native byte[] sha512256(byte[] data);
    /// Computes the Keccak256 of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed Keccak256 block of data
    public static native byte[] keccak256(byte[] data);
    /// Computes the Keccak512 of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed Keccak512 block of data
    public static native byte[] keccak512(byte[] data);
    /// Computes the SHA3_256 of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed SHA3_256 block of data
    public static native byte[] sha3256(byte[] data);
    /// Computes the SHA3_512 of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed SHA3_512 block of data
    public static native byte[] sha3512(byte[] data);
    /// Computes the RIPEMD of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed RIPEMD block of data
    public static native byte[] ripemd(byte[] data);
    /// Computes the Blake256 of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed Blake256 block of data
    public static native byte[] blake256(byte[] data);
    /// Computes the Blake2b of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed Blake2b block of data
    public static native byte[] blake2b(byte[] data, int size);
    /// Computes the Blake2b of a block of data with personal.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed Blake2b block of data
    public static native byte[] blake2bPersonal(byte[] data, int size, byte[] personal);
    /// Computes the Groestl512 of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed Groestl512 block of data
    public static native byte[] groestl512(byte[] data);
    /// Computes the SHA256D of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed SHA256D block of data
    public static native byte[] sha256SHA256(byte[] data);
    /// Computes the SHA256RIPEMD of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed SHA256RIPEMD block of data
    public static native byte[] sha256RIPEMD(byte[] data);
    /// Computes the SHA3_256RIPEMD of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed SHA3_256RIPEMD block of data
    public static native byte[] sha3256RIPEMD(byte[] data);
    /// Computes the Blake256D of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed Blake256D block of data
    public static native byte[] blake256Blake256(byte[] data);
    /// Computes the Blake256RIPEMD of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed Blake256RIPEMD block of data
    public static native byte[] blake256RIPEMD(byte[] data);
    /// Computes the Groestl512D of a block of data.
    ///
    /// \param data Non-null block of data
    /// \return Non-null computed Groestl512D block of data
    public static native byte[] groestl512Groestl512(byte[] data);
}
