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

/// Represents Ethereum ABI value
public class EthereumAbiValue {
    private byte[] bytes;

    private EthereumAbiValue() {
    }

    static EthereumAbiValue createFromNative(byte[] bytes) {
        EthereumAbiValue instance = new EthereumAbiValue();
        instance.bytes = bytes;
        return instance;
    }
    /// Encode a bool according to Ethereum ABI, into 32 bytes.  Values are padded by 0 on the left, unless specified otherwise
    ///
    /// \param value a boolean value
    /// \return Encoded value stored in a block of data
    public static native byte[] encodeBool(boolean value);
    /// Encode a int32 according to Ethereum ABI, into 32 bytes. Values are padded by 0 on the left, unless specified otherwise
    ///
    /// \param value a int32 value
    /// \return Encoded value stored in a block of data
    public static native byte[] encodeInt32(int value);
    /// Encode a uint32 according to Ethereum ABI, into 32 bytes.  Values are padded by 0 on the left, unless specified otherwise
    ///
    /// \param value a uint32 value
    /// \return Encoded value stored in a block of data
    public static native byte[] encodeUInt32(int value);
    /// Encode a int256 according to Ethereum ABI, into 32 bytes.  Values are padded by 0 on the left, unless specified otherwise
    ///
    /// \param value a int256 value stored in a block of data
    /// \return Encoded value stored in a block of data
    public static native byte[] encodeInt256(byte[] value);
    /// Encode an int256 according to Ethereum ABI, into 32 bytes.  Values are padded by 0 on the left, unless specified otherwise
    ///
    /// \param value a int256 value stored in a block of data
    /// \return Encoded value stored in a block of data
    public static native byte[] encodeUInt256(byte[] value);
    /// Encode an address according to Ethereum ABI, 20 bytes of the address.
    ///
    /// \param value an address value stored in a block of data
    /// \return Encoded value stored in a block of data
    public static native byte[] encodeAddress(byte[] value);
    /// Encode a string according to Ethereum ABI by encoding its hash.
    ///
    /// \param value a string value
    /// \return Encoded value stored in a block of data
    public static native byte[] encodeString(String value);
    /// Encode a number of bytes, up to 32 bytes, padded on the right.  Longer arrays are truncated.
    ///
    /// \param value bunch of bytes
    /// \return Encoded value stored in a block of data
    public static native byte[] encodeBytes(byte[] value);
    /// Encode a dynamic number of bytes by encoding its hash
    ///
    /// \param value bunch of bytes
    /// \return Encoded value stored in a block of data
    public static native byte[] encodeBytesDyn(byte[] value);
    /// Decodes input data (bytes longer than 32 will be truncated) as uint256
    ///
    /// \param input Data to be decoded
    /// \return Non-null decoded string value
    public static native String decodeUInt256(byte[] input);
    /// Decode an arbitrary type, return value as string
    ///
    /// \param input Data to be decoded
    /// \param type the underlying type that need to be decoded
    /// \return Non-null decoded string value
    public static native String decodeValue(byte[] input, String type);
    /// Decode an array of given simple types.  Return a '\n'-separated string of elements
    ///
    /// \param input Data to be decoded
    /// \param type the underlying type that need to be decoded
    /// \return Non-null decoded string value
    public static native String decodeArray(byte[] input, String type);
}
