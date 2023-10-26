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

/// Represents an Account in C++ with address, coin type and public key info, an item within a keystore.
public class Account {
    private long nativeHandle;

    private Account() {
        nativeHandle = 0;
    }

    static Account createFromNative(long nativeHandle) {
        Account instance = new Account();
        instance.nativeHandle = nativeHandle;
        AccountPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Creates a new Account with an address, a coin type, derivation enum, derivationPath, publicKey,
    /// and extendedPublicKey. Must be deleted with TWAccountDelete after use.
    ///
    /// \param address The address of the Account.
    /// \param coin The coin type of the Account.
    /// \param derivation The derivation of the Account.
    /// \param derivationPath The derivation path of the Account.
    /// \param publicKey hex encoded public key.
    /// \param extendedPublicKey Base58 encoded extended public key.
    /// \return A new Account.
    static native long nativeCreate(String address, CoinType coin, Derivation derivation, String derivationPath, String publicKey, String extendedPublicKey);
    static native void nativeDelete(long handle);
    /// Returns the address of an account.
    ///
    /// \param account Account to get the address of.
    public native String address();
    /// Returns the derivation enum of an account.
    ///
    /// \param account Account to get the derivation enum of.
    public native Derivation derivation();
    /// Returns derivationPath of an account.
    ///
    /// \param account Account to get the derivation path of.
    public native String derivationPath();
    /// Returns hex encoded publicKey of an account.
    ///
    /// \param account Account to get the public key of.
    public native String publicKey();
    /// Returns Base58 encoded extendedPublicKey of an account.
    ///
    /// \param account Account to get the extended public key of.
    public native String extendedPublicKey();
    /// Return CoinType enum of an account.
    ///
    /// \param account Account to get the coin type of.
    public native CoinType coin();
    /// Creates a new Account with an address, a coin type, derivation enum, derivationPath, publicKey,
    /// and extendedPublicKey. Must be deleted with TWAccountDelete after use.
    ///
    /// \param address The address of the Account.
    /// \param coin The coin type of the Account.
    /// \param derivation The derivation of the Account.
    /// \param derivationPath The derivation path of the Account.
    /// \param publicKey hex encoded public key.
    /// \param extendedPublicKey Base58 encoded extended public key.
    /// \return A new Account.
    public Account(String address, CoinType coin, Derivation derivation, String derivationPath, String publicKey, String extendedPublicKey) {
        nativeHandle = nativeCreate(address, coin, derivation, derivationPath, publicKey, extendedPublicKey);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        AccountPhantomReference.register(this, nativeHandle);
    }

}
class AccountPhantomReference extends java.lang.ref.PhantomReference<Account> {
    private static java.util.Set<AccountPhantomReference> references = new HashSet<AccountPhantomReference>();
    private static java.lang.ref.ReferenceQueue<Account> queue = new java.lang.ref.ReferenceQueue<Account>();
    private long nativeHandle;

    private AccountPhantomReference(Account referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(Account referent, long nativeHandle) {
        references.add(new AccountPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        AccountPhantomReference ref = (AccountPhantomReference) queue.poll();
        for (; ref != null; ref = (AccountPhantomReference) queue.poll()) {
            Account.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
