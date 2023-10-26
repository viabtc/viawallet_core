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

/// Represents a Cosmos public key.
public class CosmosPublicKey {
    private long nativeHandle;

    private CosmosPublicKey() {
        nativeHandle = 0;
    }

    static CosmosPublicKey createFromNative(long nativeHandle) {
        CosmosPublicKey instance = new CosmosPublicKey();
        instance.nativeHandle = nativeHandle;
        CosmosPublicKeyPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Creates an public key from human-readable part and data.
    static native long nativeCreateWithData(String hrp, byte[] data);
    static native void nativeDelete(long handle);
    /// Compares two public key for equality.
    public static native boolean equals(CosmosPublicKey lhs, CosmosPublicKey rhs);
    /// Returns the public key string representation.
    public native String description();
    /// Returns the public key data.
    public native byte[] data();
    /// Returns the public key human-readable part.
    public native String hrp();
    /// Creates an public key from human-readable part and data.
    public CosmosPublicKey(String hrp, byte[] data) {
        nativeHandle = nativeCreateWithData(hrp, data);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        CosmosPublicKeyPhantomReference.register(this, nativeHandle);
    }

}
class CosmosPublicKeyPhantomReference extends java.lang.ref.PhantomReference<CosmosPublicKey> {
    private static java.util.Set<CosmosPublicKeyPhantomReference> references = new HashSet<CosmosPublicKeyPhantomReference>();
    private static java.lang.ref.ReferenceQueue<CosmosPublicKey> queue = new java.lang.ref.ReferenceQueue<CosmosPublicKey>();
    private long nativeHandle;

    private CosmosPublicKeyPhantomReference(CosmosPublicKey referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(CosmosPublicKey referent, long nativeHandle) {
        references.add(new CosmosPublicKeyPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        CosmosPublicKeyPhantomReference ref = (CosmosPublicKeyPhantomReference) queue.poll();
        for (; ref != null; ref = (CosmosPublicKeyPhantomReference) queue.poll()) {
            CosmosPublicKey.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
