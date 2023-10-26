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

/// Represents a Kadena Account name
public class KadenaAccount {
    private long nativeHandle;

    private KadenaAccount() {
        nativeHandle = 0;
    }

    static KadenaAccount createFromNative(long nativeHandle) {
        KadenaAccount instance = new KadenaAccount();
        instance.nativeHandle = nativeHandle;
        KadenaAccountPhantomReference.register(instance, nativeHandle);
        return instance;
    }

    static native long nativeCreateWithString(String string);
    static native void nativeDelete(long handle);
    /// Determines if a Kadena account is valid.
    public static native boolean isValid(String string);
    /// Returns the user friendly string representation.
    public native String description();

    public KadenaAccount(String string) {
        nativeHandle = nativeCreateWithString(string);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        KadenaAccountPhantomReference.register(this, nativeHandle);
    }

}
class KadenaAccountPhantomReference extends java.lang.ref.PhantomReference<KadenaAccount> {
    private static java.util.Set<KadenaAccountPhantomReference> references = new HashSet<KadenaAccountPhantomReference>();
    private static java.lang.ref.ReferenceQueue<KadenaAccount> queue = new java.lang.ref.ReferenceQueue<KadenaAccount>();
    private long nativeHandle;

    private KadenaAccountPhantomReference(KadenaAccount referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(KadenaAccount referent, long nativeHandle) {
        references.add(new KadenaAccountPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        KadenaAccountPhantomReference ref = (KadenaAccountPhantomReference) queue.poll();
        for (; ref != null; ref = (KadenaAccountPhantomReference) queue.poll()) {
            KadenaAccount.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
