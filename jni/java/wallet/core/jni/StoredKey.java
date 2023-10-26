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

/// Represents a key stored as an encrypted file.
public class StoredKey {
    private long nativeHandle;

    private StoredKey() {
        nativeHandle = 0;
    }

    static StoredKey createFromNative(long nativeHandle) {
        StoredKey instance = new StoredKey();
        instance.nativeHandle = nativeHandle;
        StoredKeyPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Creates a new key, with given encryption strength level.  Returned object needs to be deleted.
    ///
    /// \param name The name of the key to be stored
    /// \param password Non-null block of data, password of the stored key
    /// \param encryptionLevel The level of encryption, see \TWStoredKeyEncryptionLevel
    /// \note Returned object needs to be deleted with \TWStoredKeyDelete
    /// \return The stored key as a non-null pointer
    static native long nativeCreateLevel(String name, byte[] password, StoredKeyEncryptionLevel encryptionLevel);
    /// Creates a new key.
    ///
    /// \deprecated use TWStoredKeyCreateLevel.
    /// \param name The name of the key to be stored
    /// \param password Non-null block of data, password of the stored key
    /// \note Returned object needs to be deleted with \TWStoredKeyDelete
    /// \return The stored key as a non-null pointer
    static native long nativeCreate(String name, byte[] password);
    static native void nativeDelete(long handle);
    /// Loads a key from a file.
    ///
    /// \param path filepath to the key as a non-null string
    /// \note Returned object needs to be deleted with \TWStoredKeyDelete
    /// \return Nullptr if the key can't be load, the stored key otherwise
    public static native StoredKey load(String path);
    /// Imports a private key.
    ///
    /// \param privateKey Non-null Block of data private key
    /// \param name The name of the stored key to import as a non-null string
    /// \param password Non-null block of data, password of the stored key
    /// \param coin the coin type
    /// \note Returned object needs to be deleted with \TWStoredKeyDelete
    /// \return Nullptr if the key can't be imported, the stored key otherwise
    public static native StoredKey importPrivateKey(byte[] privateKey, String name, byte[] password, CoinType coin);
    /// Imports an HD wallet.
    ///
    /// \param mnemonic Non-null bip39 mnemonic
    /// \param name The name of the stored key to import as a non-null string
    /// \param password Non-null block of data, password of the stored key
    /// \param coin the coin type
    /// \note Returned object needs to be deleted with \TWStoredKeyDelete
    /// \return Nullptr if the key can't be imported, the stored key otherwise
    public static native StoredKey importHDWallet(String mnemonic, String name, byte[] password, CoinType coin);
    /// Imports an HD wallet with only one chain.  Returned object needs to be deleted.
    public static native StoredKey importHDWalletSingle(String mnemonic, String name, byte[] password, CoinType coin);
    /// Imports a key from JSON.  Returned object needs to be deleted.
    /// Imports a key from JSON.
    ///
    /// \param json Json stored key import format as a non-null block of data
    /// \note Returned object needs to be deleted with \TWStoredKeyDelete
    /// \return Nullptr if the key can't be imported, the stored key otherwise
    public static native StoredKey importJSON(byte[] json);
    /// Stored key unique identifier.
    ///
    /// \param key Non-null pointer to a stored key
    /// \note Returned object needs to be deleted with \TWStringDelete
    /// \return The stored key unique identifier if it's found, null pointer otherwise.
    public native String identifier();
    /// Stored key namer.
    ///
    /// \param key Non-null pointer to a stored key
    /// \note Returned object needs to be deleted with \TWStringDelete
    /// \return The stored key name as a non-null string pointer.
    public native String name();
    /// Whether this key is a mnemonic phrase for a HD wallet.
    ///
    /// \param key Non-null pointer to a stored key
    /// \return true if the given stored key is a mnemonic, false otherwise
    public native boolean isMnemonic();
    /// Whether this key is a private key wallet.
    public native boolean isPrivateKey();
    /// Whether this key is a mnemonic phrase for a HD wallet with only one chain.
    public native boolean isMnemonicSingle();
    /// The number of accounts.
    ///
    /// \param key Non-null pointer to a stored key
    /// \return the number of accounts associated to the given stored key
    public native int accountCount();
    /// Retrieve stored key encoding parameters, as JSON string.
    ///
    /// \param key Non-null pointer to a stored key
    /// \return Null pointer on failure, encoding parameter as a json string otherwise.
    public native String encryptionParameters();
    /// Returns the account at a given index.
    ///
    /// \param key Non-null pointer to a stored key
    /// \param index the account index to be retrieved
    /// \note Returned object needs to be deleted with \TWAccountDelete
    /// \return Null pointer if the associated account is not found, pointer to the account otherwise.
    public native Account account(int index);
    /// Returns the account for a specific coin, creating it if necessary.
    ///
    /// \param key Non-null pointer to a stored key
    /// \param coin The coin type
    /// \param wallet The associated HD wallet, can be null.
    /// \note Returned object needs to be deleted with \TWAccountDelete
    /// \return Null pointer if the associated account is not found/not created, pointer to the account otherwise.
    public native Account accountForCoin(CoinType coin, HDWallet wallet);
    /// Returns the account for a specific coin + derivation, creating it if necessary.
    ///
    /// \param key Non-null pointer to a stored key
    /// \param coin The coin type
    /// \param derivation The derivation for the given coin
    /// \param wallet the associated HD wallet, can be null.
    /// \note Returned object needs to be deleted with \TWAccountDelete
    /// \return Null pointer if the associated account is not found/not created, pointer to the account otherwise.
    public native Account accountForCoinDerivation(CoinType coin, Derivation derivation, HDWallet wallet);
    /// Adds a new account, using given derivation (usually TWDerivationDefault)
    /// and derivation path (usually matches path from derivation, but custom possible).
    ///
    /// \param key Non-null pointer to a stored key
    /// \param address Non-null pointer to the address of the coin for this account
    /// \param coin coin type
    /// \param derivation derivation of the given coin type
    /// \param derivationPath HD bip44 derivation path of the given coin
    /// \param publicKey Non-null public key of the given coin/address
    /// \param extendedPublicKey Non-null extended public key of the given coin/address
    public native void addAccountDerivation(String address, CoinType coin, Derivation derivation, String derivationPath, String publicKey, String extendedPublicKey);
    /// Adds a new account, using given derivation path.
    ///
    /// \deprecated Use TWStoredKeyAddAccountDerivation (with TWDerivationDefault) instead.
    /// \param key Non-null pointer to a stored key
    /// \param address Non-null pointer to the address of the coin for this account
    /// \param coin coin type
    /// \param derivationPath HD bip44 derivation path of the given coin
    /// \param publicKey Non-null public key of the given coin/address
    /// \param extendedPublicKey Non-null extended public key of the given coin/address
    public native void addAccount(String address, CoinType coin, String derivationPath, String publicKey, String extendedPublicKey);
    /// Remove the account for a specific coin
    ///
    /// \param key Non-null pointer to a stored key
    /// \param coin Account coin type to be removed
    public native void removeAccountForCoin(CoinType coin);
    /// Remove the account for a specific coin with the given derivation.
    ///
    /// \param key Non-null pointer to a stored key
    /// \param coin Account coin type to be removed
    /// \param derivation The derivation of the given coin type
    public native void removeAccountForCoinDerivation(CoinType coin, Derivation derivation);
    /// Remove the account for a specific coin with the given derivation path.
    ///
    /// \param key Non-null pointer to a stored key
    /// \param coin Account coin type to be removed
    /// \param derivationPath The derivation path (bip44) of the given coin type
    public native void removeAccountForCoinDerivationPath(CoinType coin, String derivationPath);
    /// Saves the key to a file.
    ///
    /// \param key Non-null pointer to a stored key
    /// \param path Non-null string filepath where the key will be saved
    /// \return true if the key was successfully stored in the given filepath file, false otherwise
    public native boolean store(String path);
    /// Decrypts the private key.
    ///
    /// \param key Non-null pointer to a stored key
    /// \param password Non-null block of data, password of the stored key
    /// \return Decrypted private key as a block of data if success, null pointer otherwise
    public native byte[] decryptPrivateKey(byte[] password);
    /// Decrypts the mnemonic phrase.
    ///
    /// \param key Non-null pointer to a stored key
    /// \param password Non-null block of data, password of the stored key
    /// \return Bip39 decrypted mnemonic if success, null pointer otherwise
    public native String decryptMnemonic(byte[] password);
    /// Returns the private key for a specific coin.  Returned object needs to be deleted.
    ///
    /// \param key Non-null pointer to a stored key
    /// \param coin Account coin type to be queried
    /// \note Returned object needs to be deleted with \TWPrivateKeyDelete
    /// \return Null pointer on failure, pointer to the private key otherwise
    public native PrivateKey privateKey(CoinType coin, byte[] password);
    /// Decrypts and returns the HD Wallet for mnemonic phrase keys.  Returned object needs to be deleted.
    ///
    /// \param key Non-null pointer to a stored key
    /// \param password Non-null block of data, password of the stored key
    /// \note Returned object needs to be deleted with \TWHDWalletDelete
    /// \return Null pointer on failure, pointer to the HDWallet otherwise
    public native HDWallet wallet(byte[] password);
    /// Exports the key as JSON
    ///
    /// \param key Non-null pointer to a stored key
    /// \return Null pointer on failure, pointer to a block of data containing the json otherwise
    public native byte[] exportJSON();
    /// Fills in empty and invalid addresses.
    /// This method needs the encryption password to re-derive addresses from private keys.
    ///
    /// \param key Non-null pointer to a stored key
    /// \param password Non-null block of data, password of the stored key
    /// \return `false` if the password is incorrect, true otherwise.
    public native boolean fixAddresses(byte[] password);
    /// Creates a new key, with given encryption strength level.  Returned object needs to be deleted.
    ///
    /// \param name The name of the key to be stored
    /// \param password Non-null block of data, password of the stored key
    /// \param encryptionLevel The level of encryption, see \TWStoredKeyEncryptionLevel
    /// \note Returned object needs to be deleted with \TWStoredKeyDelete
    /// \return The stored key as a non-null pointer
    public StoredKey(String name, byte[] password, StoredKeyEncryptionLevel encryptionLevel) {
        nativeHandle = nativeCreateLevel(name, password, encryptionLevel);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        StoredKeyPhantomReference.register(this, nativeHandle);
    }

    /// Creates a new key.
    ///
    /// \deprecated use TWStoredKeyCreateLevel.
    /// \param name The name of the key to be stored
    /// \param password Non-null block of data, password of the stored key
    /// \note Returned object needs to be deleted with \TWStoredKeyDelete
    /// \return The stored key as a non-null pointer
    public StoredKey(String name, byte[] password) {
        nativeHandle = nativeCreate(name, password);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        StoredKeyPhantomReference.register(this, nativeHandle);
    }

}
class StoredKeyPhantomReference extends java.lang.ref.PhantomReference<StoredKey> {
    private static java.util.Set<StoredKeyPhantomReference> references = new HashSet<StoredKeyPhantomReference>();
    private static java.lang.ref.ReferenceQueue<StoredKey> queue = new java.lang.ref.ReferenceQueue<StoredKey>();
    private long nativeHandle;

    private StoredKeyPhantomReference(StoredKey referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(StoredKey referent, long nativeHandle) {
        references.add(new StoredKeyPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        StoredKeyPhantomReference ref = (StoredKeyPhantomReference) queue.poll();
        for (; ref != null; ref = (StoredKeyPhantomReference) queue.poll()) {
            StoredKey.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
