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

/// Represents a legacy Groestlcoin address.
public class GroestlcoinAddress {
    private long nativeHandle;

    private GroestlcoinAddress() {
        nativeHandle = 0;
    }

    static GroestlcoinAddress createFromNative(long nativeHandle) {
        GroestlcoinAddress instance = new GroestlcoinAddress();
        instance.nativeHandle = nativeHandle;
        GroestlcoinAddressPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Create an address from a base58 string representation.
    ///
    /// \param string Non-null string
    /// \note Must be deleted with \TWGroestlcoinAddressDelete
    /// \return Non-null GroestlcoinAddress
    static native long nativeCreateWithString(String string);
    /// Create an address from a public key and a prefix byte.
    ///
    /// \param publicKey Non-null public key
    /// \param prefix public key prefix
    /// \note Must be deleted with \TWGroestlcoinAddressDelete
    /// \return Non-null GroestlcoinAddress
    static native long nativeCreateWithPublicKey(PublicKey publicKey, byte prefix);
    static native void nativeDelete(long handle);
    /// Compares two addresses for equality.
    ///
    /// \param lhs left Non-null GroestlCoin address to be compared
    /// \param rhs right Non-null GroestlCoin address to be compared
    /// \return true if both address are equal, false otherwise
    public static native boolean equals(GroestlcoinAddress lhs, GroestlcoinAddress rhs);
    /// Determines if the string is a valid Groestlcoin address.
    ///
    /// \param string Non-null string.
    /// \return true if it's a valid address, false otherwise
    public static native boolean isValidString(String string);
    /// Returns the address base58 string representation.
    ///
    /// \param address Non-null GroestlcoinAddress
    /// \return Address description as a non-null string
    public native String description();
    /// Create an address from a base58 string representation.
    ///
    /// \param string Non-null string
    /// \note Must be deleted with \TWGroestlcoinAddressDelete
    /// \return Non-null GroestlcoinAddress
    public GroestlcoinAddress(String string) {
        nativeHandle = nativeCreateWithString(string);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        GroestlcoinAddressPhantomReference.register(this, nativeHandle);
    }

    /// Create an address from a public key and a prefix byte.
    ///
    /// \param publicKey Non-null public key
    /// \param prefix public key prefix
    /// \note Must be deleted with \TWGroestlcoinAddressDelete
    /// \return Non-null GroestlcoinAddress
    public GroestlcoinAddress(PublicKey publicKey, byte prefix) {
        nativeHandle = nativeCreateWithPublicKey(publicKey, prefix);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        GroestlcoinAddressPhantomReference.register(this, nativeHandle);
    }

}
class GroestlcoinAddressPhantomReference extends java.lang.ref.PhantomReference<GroestlcoinAddress> {
    private static java.util.Set<GroestlcoinAddressPhantomReference> references = new HashSet<GroestlcoinAddressPhantomReference>();
    private static java.lang.ref.ReferenceQueue<GroestlcoinAddress> queue = new java.lang.ref.ReferenceQueue<GroestlcoinAddress>();
    private long nativeHandle;

    private GroestlcoinAddressPhantomReference(GroestlcoinAddress referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(GroestlcoinAddress referent, long nativeHandle) {
        references.add(new GroestlcoinAddressPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        GroestlcoinAddressPhantomReference ref = (GroestlcoinAddressPhantomReference) queue.poll();
        for (; ref != null; ref = (GroestlcoinAddressPhantomReference) queue.poll()) {
            GroestlcoinAddress.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
