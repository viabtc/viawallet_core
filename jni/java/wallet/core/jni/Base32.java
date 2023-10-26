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

/// Base32 encode / decode functions
public class Base32 {
    private byte[] bytes;

    private Base32() {
    }

    static Base32 createFromNative(byte[] bytes) {
        Base32 instance = new Base32();
        instance.bytes = bytes;
        return instance;
    }
    /// Decode a Base32 input with the given alphabet
    ///
    /// \param string Encoded base32 input to be decoded
    /// \param alphabet Decode with the given alphabet, if nullptr ALPHABET_RFC4648 is used by default
    /// \return The decoded data, can be null.
    /// \note ALPHABET_RFC4648 doesn't support padding in the default alphabet
    public static native byte[] decodeWithAlphabet(String string, String alphabet);
    /// Decode a Base32 input with the default alphabet (ALPHABET_RFC4648)
    ///
    /// \param string Encoded input to be decoded
    /// \return The decoded data
    /// \note Call TWBase32DecodeWithAlphabet with nullptr.
    public static native byte[] decode(String string);
    /// Encode an input to Base32 with the given alphabet
    ///
    /// \param data Data to be encoded (raw bytes)
    /// \param alphabet Encode with the given alphabet, if nullptr ALPHABET_RFC4648 is used by default
    /// \return The encoded data
    /// \note ALPHABET_RFC4648 doesn't support padding in the default alphabet
    public static native String encodeWithAlphabet(byte[] data, String alphabet);
    /// Encode an input to Base32 with the default alphabet (ALPHABET_RFC4648)
    ///
    /// \param data Data to be encoded (raw bytes)
    /// \return The encoded data
    /// \note Call TWBase32EncodeWithAlphabet with nullptr.
    public static native String encode(byte[] data);
}
