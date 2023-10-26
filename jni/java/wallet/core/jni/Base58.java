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

/// Base58 encode / decode functions
public class Base58 {
    private byte[] bytes;

    private Base58() {
    }

    static Base58 createFromNative(byte[] bytes) {
        Base58 instance = new Base58();
        instance.bytes = bytes;
        return instance;
    }
    /// Encodes data as a Base58 string, including the checksum.
    ///
    /// \param data The data to encode.
    /// \return the encoded Base58 string with checksum.
    public static native String encode(byte[] data);
    /// Encodes data as a Base58 string, not including the checksum.
    ///
    /// \param data The data to encode.
    /// \return then encoded Base58 string without checksum.
    public static native String encodeNoCheck(byte[] data);
    /// Decodes a Base58 string, checking the checksum. Returns null if the string is not a valid Base58 string.
    ///
    /// \param string The Base58 string to decode.
    /// \return the decoded data, empty if the string is not a valid Base58 string with checksum.
    public static native byte[] decode(String string);
    /// Decodes a Base58 string, w/o checking the checksum. Returns null if the string is not a valid Base58 string.
    ///
    /// \param string The Base58 string to decode.
    /// \return the decoded data, empty if the string is not a valid Base58 string without checksum.
    public static native byte[] decodeNoCheck(String string);
}
