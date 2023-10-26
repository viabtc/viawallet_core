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

/// Represents a FIO Account name
public class FIOAccount {
    private long nativeHandle;

    private FIOAccount() {
        nativeHandle = 0;
    }

    static FIOAccount createFromNative(long nativeHandle) {
        FIOAccount instance = new FIOAccount();
        instance.nativeHandle = nativeHandle;
        FIOAccountPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Create a FIO Account
    ///
    /// \param string Account name
    /// \note Must be deleted with \TWFIOAccountDelete
    /// \return Pointer to a nullable FIO Account
    static native long nativeCreateWithString(String string);
    static native void nativeDelete(long handle);
    /// Returns the short account string representation.
    ///
    /// \param account Pointer to a non-null FIO Account
    /// \return Account non-null string representation
    public native String description();
    /// Create a FIO Account
    ///
    /// \param string Account name
    /// \note Must be deleted with \TWFIOAccountDelete
    /// \return Pointer to a nullable FIO Account
    public FIOAccount(String string) {
        nativeHandle = nativeCreateWithString(string);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        FIOAccountPhantomReference.register(this, nativeHandle);
    }

}
class FIOAccountPhantomReference extends java.lang.ref.PhantomReference<FIOAccount> {
    private static java.util.Set<FIOAccountPhantomReference> references = new HashSet<FIOAccountPhantomReference>();
    private static java.lang.ref.ReferenceQueue<FIOAccount> queue = new java.lang.ref.ReferenceQueue<FIOAccount>();
    private long nativeHandle;

    private FIOAccountPhantomReference(FIOAccount referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(FIOAccount referent, long nativeHandle) {
        references.add(new FIOAccountPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        FIOAccountPhantomReference ref = (FIOAccountPhantomReference) queue.poll();
        for (; ref != null; ref = (FIOAccountPhantomReference) queue.poll()) {
            FIOAccount.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
