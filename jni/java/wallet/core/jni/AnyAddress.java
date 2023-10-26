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

/// Represents an address in C++ for almost any blockchain.
public class AnyAddress {
    private long nativeHandle;

    private AnyAddress() {
        nativeHandle = 0;
    }

    static AnyAddress createFromNative(long nativeHandle) {
        AnyAddress instance = new AnyAddress();
        instance.nativeHandle = nativeHandle;
        AnyAddressPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Creates an address from a string representation and a coin type. Must be deleted with TWAnyAddressDelete after use.
    ///
    /// \param string address to create.
    /// \param coin coin type of the address.
    /// \return TWAnyAddress pointer or nullptr if address and coin are invalid.
    static native long nativeCreateWithString(String string, CoinType coin);
    /// Creates an address from a public key.
    ///
    /// \param publicKey derivates the address from the public key.
    /// \param coin coin type of the address.
    /// \return TWAnyAddress pointer or nullptr if public key is invalid.
    static native long nativeCreateWithPublicKey(PublicKey publicKey, CoinType coin);
    static native void nativeDelete(long handle);
    /// Compares two addresses for equality.
    ///
    /// \param lhs The first address to compare.
    /// \param rhs The second address to compare.
    /// \return bool indicating the addresses are equal.
    public static native boolean equals(AnyAddress lhs, AnyAddress rhs);
    /// Determines if the string is a valid Any address.
    ///
    /// \param string address to validate.
    /// \param coin coin type of the address.
    /// \return bool indicating if the address is valid.
    public static native boolean isValid(String string, CoinType coin);
    /// Returns the address string representation.
    ///
    /// \param address address to get the string representation of.
    public native String description();
    /// Returns coin type of address.
    ///
    /// \param address address to get the coin type of.
    public native CoinType coin();
    /// Returns underlaying data (public key or key hash)
    ///
    /// \param address address to get the data of.
    public native byte[] data();
    /// Creates an address from a string representation and a coin type. Must be deleted with TWAnyAddressDelete after use.
    ///
    /// \param string address to create.
    /// \param coin coin type of the address.
    /// \return TWAnyAddress pointer or nullptr if address and coin are invalid.
    public AnyAddress(String string, CoinType coin) {
        nativeHandle = nativeCreateWithString(string, coin);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        AnyAddressPhantomReference.register(this, nativeHandle);
    }

    /// Creates an address from a public key.
    ///
    /// \param publicKey derivates the address from the public key.
    /// \param coin coin type of the address.
    /// \return TWAnyAddress pointer or nullptr if public key is invalid.
    public AnyAddress(PublicKey publicKey, CoinType coin) {
        nativeHandle = nativeCreateWithPublicKey(publicKey, coin);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        AnyAddressPhantomReference.register(this, nativeHandle);
    }

}
class AnyAddressPhantomReference extends java.lang.ref.PhantomReference<AnyAddress> {
    private static java.util.Set<AnyAddressPhantomReference> references = new HashSet<AnyAddressPhantomReference>();
    private static java.lang.ref.ReferenceQueue<AnyAddress> queue = new java.lang.ref.ReferenceQueue<AnyAddress>();
    private long nativeHandle;

    private AnyAddressPhantomReference(AnyAddress referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(AnyAddress referent, long nativeHandle) {
        references.add(new AnyAddressPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        AnyAddressPhantomReference ref = (AnyAddressPhantomReference) queue.poll();
        for (; ref != null; ref = (AnyAddressPhantomReference) queue.poll()) {
            AnyAddress.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
