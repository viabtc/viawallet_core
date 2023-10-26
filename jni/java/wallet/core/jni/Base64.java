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

/// Base64 encode / decode functions
public class Base64 {
    private byte[] bytes;

    private Base64() {
    }

    static Base64 createFromNative(byte[] bytes) {
        Base64 instance = new Base64();
        instance.bytes = bytes;
        return instance;
    }
    /// Decode a Base64 input with the default alphabet (RFC4648 with '+', '/')
    ///
    /// \param string Encoded input to be decoded
    /// \return The decoded data, empty if decoding failed.
    public static native byte[] decode(String string);
    /// Decode a Base64 input with the alphabet safe for URL-s and filenames (RFC4648 with '-', '_')
    ///
    /// \param string Encoded base64 input to be decoded
    /// \return The decoded data, empty if decoding failed.
    public static native byte[] decodeUrl(String string);
    /// Encode an input to Base64 with the default alphabet (RFC4648 with '+', '/')
    ///
    /// \param data Data to be encoded (raw bytes)
    /// \return The encoded data
    public static native String encode(byte[] data);
    /// Encode an input to Base64 with the alphabet safe for URL-s and filenames (RFC4648 with '-', '_')
    ///
    /// \param data Data to be encoded (raw bytes)
    /// \return The encoded data
    public static native String encodeUrl(byte[] data);
}
