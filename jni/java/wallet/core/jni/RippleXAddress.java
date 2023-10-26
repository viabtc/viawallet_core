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

/// Represents a Ripple X-address.
public class RippleXAddress {
    private long nativeHandle;

    private RippleXAddress() {
        nativeHandle = 0;
    }

    static RippleXAddress createFromNative(long nativeHandle) {
        RippleXAddress instance = new RippleXAddress();
        instance.nativeHandle = nativeHandle;
        RippleXAddressPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Creates an address from a string representation.
    ///
    /// \param string Non-null pointer to a string that should be a valid ripple address
    /// \note Should be deleted with \TWRippleXAddressDelete
    /// \return Null pointer if the given string is an invalid ripple address, pointer to a Ripple address otherwise
    static native long nativeCreateWithString(String string);
    /// Creates an address from a public key and destination tag.
    ///
    /// \param publicKey Non-null pointer to a public key
    /// \param tag valid ripple destination tag (1-10)
    /// \note Should be deleted with \TWRippleXAddressDelete
    /// \return Non-null pointer to a Ripple Address
    static native long nativeCreateWithPublicKey(PublicKey publicKey, int tag);
    static native void nativeDelete(long handle);
    /// Compares two addresses for equality.
    ///
    /// \param lhs left non-null pointer to a Ripple Address
    /// \param rhs right non-null pointer to a Ripple Address
    /// \return true if both address are equal, false otherwise
    public static native boolean equals(RippleXAddress lhs, RippleXAddress rhs);
    /// Determines if the string is a valid Ripple address.
    ///
    /// \param string Non-null pointer to a string that represent the Ripple Address to be checked
    /// \return true if the given address is a valid Ripple address, false otherwise
    public static native boolean isValidString(String string);
    /// Returns the address string representation.
    ///
    /// \param address Non-null pointer to a Ripple Address
    /// \return Non-null pointer to the ripple address string representation
    public native String description();
    /// Returns the destination tag.
    ///
    /// \param address Non-null pointer to a Ripple Address
    /// \return The destination tag of the given Ripple Address (1-10)
    public native int tag();
    /// Creates an address from a string representation.
    ///
    /// \param string Non-null pointer to a string that should be a valid ripple address
    /// \note Should be deleted with \TWRippleXAddressDelete
    /// \return Null pointer if the given string is an invalid ripple address, pointer to a Ripple address otherwise
    public RippleXAddress(String string) {
        nativeHandle = nativeCreateWithString(string);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        RippleXAddressPhantomReference.register(this, nativeHandle);
    }

    /// Creates an address from a public key and destination tag.
    ///
    /// \param publicKey Non-null pointer to a public key
    /// \param tag valid ripple destination tag (1-10)
    /// \note Should be deleted with \TWRippleXAddressDelete
    /// \return Non-null pointer to a Ripple Address
    public RippleXAddress(PublicKey publicKey, int tag) {
        nativeHandle = nativeCreateWithPublicKey(publicKey, tag);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        RippleXAddressPhantomReference.register(this, nativeHandle);
    }

}
class RippleXAddressPhantomReference extends java.lang.ref.PhantomReference<RippleXAddress> {
    private static java.util.Set<RippleXAddressPhantomReference> references = new HashSet<RippleXAddressPhantomReference>();
    private static java.lang.ref.ReferenceQueue<RippleXAddress> queue = new java.lang.ref.ReferenceQueue<RippleXAddress>();
    private long nativeHandle;

    private RippleXAddressPhantomReference(RippleXAddress referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(RippleXAddress referent, long nativeHandle) {
        references.add(new RippleXAddressPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        RippleXAddressPhantomReference ref = (RippleXAddressPhantomReference) queue.poll();
        for (; ref != null; ref = (RippleXAddressPhantomReference) queue.poll()) {
            RippleXAddress.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
