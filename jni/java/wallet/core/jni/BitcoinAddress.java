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
import java.util.HashSet;

/// Represents a legacy Bitcoin address in C++.
public class BitcoinAddress {
    private long nativeHandle;

    private BitcoinAddress() {
        nativeHandle = 0;
    }

    static BitcoinAddress createFromNative(long nativeHandle) {
        BitcoinAddress instance = new BitcoinAddress();
        instance.nativeHandle = nativeHandle;
        BitcoinAddressPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Initializes an address from a Base58 sring. Must be deleted with TWBitcoinAddressDelete after use.
    ///
    /// \param string Base58 string to initialize the address from.
    /// \return TWBitcoinAddress pointer or nullptr if string is invalid.
    static native long nativeCreateWithString(String string);
    /// Initializes an address from a CashAddress sring representaion.
    static native long nativeCreateWithCashAddressString(String hrp, String string);
    /// Initializes an address from raw data.
    ///
    /// \param data Raw data to initialize the address from. Must be deleted with TWBitcoinAddressDelete after use.
    /// \return TWBitcoinAddress pointer or nullptr if data is invalid.
    static native long nativeCreateWithData(byte[] data);
    /// Initializes an address from a public key and a prefix byte.
    ///
    /// \param publicKey Public key to initialize the address from.
    /// \param prefix Prefix byte (p2pkh, p2sh, etc).
    /// \return TWBitcoinAddress pointer or nullptr if public key is invalid.
    static native long nativeCreateWithPublicKey(PublicKey publicKey, byte prefix);
    static native void nativeDelete(long handle);
    /// Compares two addresses for equality.
    ///
    /// \param lhs The first address to compare.
    /// \param rhs The second address to compare.
    /// \return bool indicating the addresses are equal.
    public static native boolean equals(BitcoinAddress lhs, BitcoinAddress rhs);
    /// Determines if the data is a valid Bitcoin address.
    ///
    /// \param data data to validate.
    /// \return bool indicating if the address data is valid.
    public static native boolean isValid(byte[] data);
    /// Determines if the string is a valid Bitcoin address.
    ///
    /// \param string string to validate.
    /// \return bool indicating if the address string is valid.
    public static native boolean isValidString(String string);
    /// Returns the address in Base58 string representation.
    ///
    /// \param address Address to get the string representation of.
    public native String description();
    /// Returns the address prefix.
    ///
    /// \param address Address to get the prefix of.
    public native byte prefix();
    /// Returns the key hash data.
    ///
    /// \param address Address to get the keyhash data of.
    public native byte[] keyhash();
    /// Initializes an address from a Base58 sring. Must be deleted with TWBitcoinAddressDelete after use.
    ///
    /// \param string Base58 string to initialize the address from.
    /// \return TWBitcoinAddress pointer or nullptr if string is invalid.
    public BitcoinAddress(String string) {
        nativeHandle = nativeCreateWithString(string);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        BitcoinAddressPhantomReference.register(this, nativeHandle);
    }

    /// Initializes an address from a CashAddress sring representaion.
    public BitcoinAddress(String hrp, String string) {
        nativeHandle = nativeCreateWithCashAddressString(hrp, string);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        BitcoinAddressPhantomReference.register(this, nativeHandle);
    }

    /// Initializes an address from raw data.
    ///
    /// \param data Raw data to initialize the address from. Must be deleted with TWBitcoinAddressDelete after use.
    /// \return TWBitcoinAddress pointer or nullptr if data is invalid.
    public BitcoinAddress(byte[] data) {
        nativeHandle = nativeCreateWithData(data);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        BitcoinAddressPhantomReference.register(this, nativeHandle);
    }

    /// Initializes an address from a public key and a prefix byte.
    ///
    /// \param publicKey Public key to initialize the address from.
    /// \param prefix Prefix byte (p2pkh, p2sh, etc).
    /// \return TWBitcoinAddress pointer or nullptr if public key is invalid.
    public BitcoinAddress(PublicKey publicKey, byte prefix) {
        nativeHandle = nativeCreateWithPublicKey(publicKey, prefix);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        BitcoinAddressPhantomReference.register(this, nativeHandle);
    }

}
class BitcoinAddressPhantomReference extends java.lang.ref.PhantomReference<BitcoinAddress> {
    private static java.util.Set<BitcoinAddressPhantomReference> references = new HashSet<BitcoinAddressPhantomReference>();
    private static java.lang.ref.ReferenceQueue<BitcoinAddress> queue = new java.lang.ref.ReferenceQueue<BitcoinAddress>();
    private long nativeHandle;

    private BitcoinAddressPhantomReference(BitcoinAddress referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(BitcoinAddress referent, long nativeHandle) {
        references.add(new BitcoinAddressPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        BitcoinAddressPhantomReference ref = (BitcoinAddressPhantomReference) queue.poll();
        for (; ref != null; ref = (BitcoinAddressPhantomReference) queue.poll()) {
            BitcoinAddress.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
