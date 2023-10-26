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

/// Represents a BIP44 DerivationPath in C++.
public class DerivationPath {
    private long nativeHandle;

    private DerivationPath() {
        nativeHandle = 0;
    }

    static DerivationPath createFromNative(long nativeHandle) {
        DerivationPath instance = new DerivationPath();
        instance.nativeHandle = nativeHandle;
        DerivationPathPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Creates a new DerivationPath with a purpose, coin, account, change and address.
    /// Must be deleted with TWDerivationPathDelete after use.
    ///
    /// \param purpose The purpose of the Path.
    /// \param coin The coin type of the Path.
    /// \param account The derivation of the Path.
    /// \param change The derivation path of the Path.
    /// \param address hex encoded public key.
    /// \return A new DerivationPath.
    static native long nativeCreate(Purpose purpose, int coin, int account, int change, int address);
    /// Creates a new DerivationPath with a string
    ///
    /// \param string The string of the Path.
    /// \return A new DerivationPath or null if string is invalid.
    static native long nativeCreateWithString(String string);
    static native void nativeDelete(long handle);
    /// Returns the purpose enum of a DerivationPath.
    ///
    /// \param path DerivationPath to get the purpose of.
    /// \return DerivationPathPurpose.
    public native Purpose purpose();
    /// Returns the coin value of a derivation path.
    ///
    /// \param path DerivationPath to get the coin of.
    /// \return The coin part of the DerivationPath.
    public native int coin();
    /// Returns the account value of a derivation path.
    ///
    /// \param path DerivationPath to get the account of.
    /// \return the account part of a derivation path.
    public native int account();
    /// Returns the change value of a derivation path.
    ///
    /// \param path DerivationPath to get the change of.
    /// \return The change part of a derivation path.
    public native int change();
    /// Returns the address value of a derivation path.
    ///
    /// \param path DerivationPath to get the address of.
    /// \return The address part of the derivation path.
    public native int address();
    /// Returns the string description of a derivation path.
    ///
    /// \param path DerivationPath to get the address of.
    /// \return The string description of the derivation path.
    public native String description();
    /// Returns the index component of a DerivationPath.
    ///
    /// \param path DerivationPath to get the index of.
    /// \param index The index component of the DerivationPath.
    /// \return DerivationPathIndex or null if index is invalid.
    public native DerivationPathIndex indexAt(int index);
    /// Returns the indices count of a DerivationPath.
    ///
    /// \param path DerivationPath to get the indices count of.
    /// \return The indices count of the DerivationPath.
    public native int indicesCount();
    /// Creates a new DerivationPath with a purpose, coin, account, change and address.
    /// Must be deleted with TWDerivationPathDelete after use.
    ///
    /// \param purpose The purpose of the Path.
    /// \param coin The coin type of the Path.
    /// \param account The derivation of the Path.
    /// \param change The derivation path of the Path.
    /// \param address hex encoded public key.
    /// \return A new DerivationPath.
    public DerivationPath(Purpose purpose, int coin, int account, int change, int address) {
        nativeHandle = nativeCreate(purpose, coin, account, change, address);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        DerivationPathPhantomReference.register(this, nativeHandle);
    }

    /// Creates a new DerivationPath with a string
    ///
    /// \param string The string of the Path.
    /// \return A new DerivationPath or null if string is invalid.
    public DerivationPath(String string) {
        nativeHandle = nativeCreateWithString(string);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        DerivationPathPhantomReference.register(this, nativeHandle);
    }

}
class DerivationPathPhantomReference extends java.lang.ref.PhantomReference<DerivationPath> {
    private static java.util.Set<DerivationPathPhantomReference> references = new HashSet<DerivationPathPhantomReference>();
    private static java.lang.ref.ReferenceQueue<DerivationPath> queue = new java.lang.ref.ReferenceQueue<DerivationPath>();
    private long nativeHandle;

    private DerivationPathPhantomReference(DerivationPath referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(DerivationPath referent, long nativeHandle) {
        references.add(new DerivationPathPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        DerivationPathPhantomReference ref = (DerivationPathPhantomReference) queue.poll();
        for (; ref != null; ref = (DerivationPathPhantomReference) queue.poll()) {
            DerivationPath.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
