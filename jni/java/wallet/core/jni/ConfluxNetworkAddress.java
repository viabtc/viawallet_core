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

/// Represents a legacy Conflux address.
public class ConfluxNetworkAddress {
    private long nativeHandle;

    private ConfluxNetworkAddress() {
        nativeHandle = 0;
    }

    static ConfluxNetworkAddress createFromNative(long nativeHandle) {
        ConfluxNetworkAddress instance = new ConfluxNetworkAddress();
        instance.nativeHandle = nativeHandle;
        ConfluxNetworkAddressPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Create an address from a sring representaion.
    static native long nativeCreateWithString(String string);
    /// Create an address from a public key and a prefix byte.
    static native long nativeCreateWithPublicKey(PublicKey publicKey);
    static native void nativeDelete(long handle);
    /// Compares two addresses for equality.
    public static native boolean equals(ConfluxNetworkAddress lhs, ConfluxNetworkAddress rhs);
    /// Determines if the string is a valid Conflux address.
    public static native boolean isValidString(String string);

    public static native String encode(String string);
    /// Returns the address string representation.
    public native String description();
    /// Create an address from a sring representaion.
    public ConfluxNetworkAddress(String string) {
        nativeHandle = nativeCreateWithString(string);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        ConfluxNetworkAddressPhantomReference.register(this, nativeHandle);
    }

    /// Create an address from a public key and a prefix byte.
    public ConfluxNetworkAddress(PublicKey publicKey) {
        nativeHandle = nativeCreateWithPublicKey(publicKey);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        ConfluxNetworkAddressPhantomReference.register(this, nativeHandle);
    }

}
class ConfluxNetworkAddressPhantomReference extends java.lang.ref.PhantomReference<ConfluxNetworkAddress> {
    private static java.util.Set<ConfluxNetworkAddressPhantomReference> references = new HashSet<ConfluxNetworkAddressPhantomReference>();
    private static java.lang.ref.ReferenceQueue<ConfluxNetworkAddress> queue = new java.lang.ref.ReferenceQueue<ConfluxNetworkAddress>();
    private long nativeHandle;

    private ConfluxNetworkAddressPhantomReference(ConfluxNetworkAddress referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(ConfluxNetworkAddress referent, long nativeHandle) {
        references.add(new ConfluxNetworkAddressPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        ConfluxNetworkAddressPhantomReference ref = (ConfluxNetworkAddressPhantomReference) queue.poll();
        for (; ref != null; ref = (ConfluxNetworkAddressPhantomReference) queue.poll()) {
            ConfluxNetworkAddress.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
