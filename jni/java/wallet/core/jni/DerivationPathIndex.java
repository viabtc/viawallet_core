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

/// Represents a derivation path index in C++ with value and hardened flag.
public class DerivationPathIndex {
    private long nativeHandle;

    private DerivationPathIndex() {
        nativeHandle = 0;
    }

    static DerivationPathIndex createFromNative(long nativeHandle) {
        DerivationPathIndex instance = new DerivationPathIndex();
        instance.nativeHandle = nativeHandle;
        DerivationPathIndexPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Creates a new Index with a value and hardened flag.
    /// Must be deleted with TWDerivationPathIndexDelete after use.
    ///
    /// \param value Index value
    /// \param hardened Indicates if the Index is hardened.
    /// \return A new Index.
    static native long nativeCreate(int value, boolean hardened);
    static native void nativeDelete(long handle);
    /// Returns numeric value of an Index.
    ///
    /// \param index Index to get the numeric value of.
    public native int value();
    /// Returns hardened flag of an Index.
    ///
    /// \param index Index to get hardened flag.
    /// \return true if hardened, false otherwise.
    public native boolean hardened();
    /// Returns the string description of a derivation path index.
    ///
    /// \param path Index to get the address of.
    /// \return The string description of the derivation path index.
    public native String description();
    /// Creates a new Index with a value and hardened flag.
    /// Must be deleted with TWDerivationPathIndexDelete after use.
    ///
    /// \param value Index value
    /// \param hardened Indicates if the Index is hardened.
    /// \return A new Index.
    public DerivationPathIndex(int value, boolean hardened) {
        nativeHandle = nativeCreate(value, hardened);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        DerivationPathIndexPhantomReference.register(this, nativeHandle);
    }

}
class DerivationPathIndexPhantomReference extends java.lang.ref.PhantomReference<DerivationPathIndex> {
    private static java.util.Set<DerivationPathIndexPhantomReference> references = new HashSet<DerivationPathIndexPhantomReference>();
    private static java.lang.ref.ReferenceQueue<DerivationPathIndex> queue = new java.lang.ref.ReferenceQueue<DerivationPathIndex>();
    private long nativeHandle;

    private DerivationPathIndexPhantomReference(DerivationPathIndex referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(DerivationPathIndex referent, long nativeHandle) {
        references.add(new DerivationPathIndexPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        DerivationPathIndexPhantomReference ref = (DerivationPathIndexPhantomReference) queue.poll();
        for (; ref != null; ref = (DerivationPathIndexPhantomReference) queue.poll()) {
            DerivationPathIndex.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
