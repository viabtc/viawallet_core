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

/// Represents a Cosmos address.
public class CosmosAddress {
    private long nativeHandle;

    private CosmosAddress() {
        nativeHandle = 0;
    }

    static CosmosAddress createFromNative(long nativeHandle) {
        CosmosAddress instance = new CosmosAddress();
        instance.nativeHandle = nativeHandle;
        CosmosAddressPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Creates an address from a string representaion.
    static native long nativeCreateWithString(String string);
    /// Creates an address from a key hash.
    static native long nativeCreateWithKeyHash(HRP hrp, byte[] keyHash);
    /// Creates an address from a HRP.
    static native long nativeCreateWithPublicKey(HRP hrp, PublicKey publicKey);
    /// Creates an address from a public key.
    static native long nativeCreateWithHRP(String hrp, PublicKey publicKey);
    static native void nativeDelete(long handle);
    /// Compares two addresses for equality.
    public static native boolean equals(CosmosAddress lhs, CosmosAddress rhs);
    /// Determines if the address and hrp is a valid address.
    public static native boolean isValid(CoinType coin, String string);
    /// Returns the address string representation.
    public native String description();
    /// Wheter this is a test net address.
    public native HRP hrp();
    /// Returns the key hash.
    public native byte[] keyHash();
    /// Creates an address from a string representaion.
    public CosmosAddress(String string) {
        nativeHandle = nativeCreateWithString(string);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        CosmosAddressPhantomReference.register(this, nativeHandle);
    }

    /// Creates an address from a key hash.
    public CosmosAddress(HRP hrp, byte[] keyHash) {
        nativeHandle = nativeCreateWithKeyHash(hrp, keyHash);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        CosmosAddressPhantomReference.register(this, nativeHandle);
    }

    /// Creates an address from a HRP.
    public CosmosAddress(HRP hrp, PublicKey publicKey) {
        nativeHandle = nativeCreateWithPublicKey(hrp, publicKey);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        CosmosAddressPhantomReference.register(this, nativeHandle);
    }

    /// Creates an address from a public key.
    public CosmosAddress(String hrp, PublicKey publicKey) {
        nativeHandle = nativeCreateWithHRP(hrp, publicKey);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        CosmosAddressPhantomReference.register(this, nativeHandle);
    }

}
class CosmosAddressPhantomReference extends java.lang.ref.PhantomReference<CosmosAddress> {
    private static java.util.Set<CosmosAddressPhantomReference> references = new HashSet<CosmosAddressPhantomReference>();
    private static java.lang.ref.ReferenceQueue<CosmosAddress> queue = new java.lang.ref.ReferenceQueue<CosmosAddress>();
    private long nativeHandle;

    private CosmosAddressPhantomReference(CosmosAddress referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(CosmosAddress referent, long nativeHandle) {
        references.add(new CosmosAddressPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        CosmosAddressPhantomReference ref = (CosmosAddressPhantomReference) queue.poll();
        for (; ref != null; ref = (CosmosAddressPhantomReference) queue.poll()) {
            CosmosAddress.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
