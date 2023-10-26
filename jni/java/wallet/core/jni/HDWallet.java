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

/// Hierarchical Deterministic (HD) Wallet
public class HDWallet {
    private long nativeHandle;

    private HDWallet() {
        nativeHandle = 0;
    }

    static HDWallet createFromNative(long nativeHandle) {
        HDWallet instance = new HDWallet();
        instance.nativeHandle = nativeHandle;
        HDWalletPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Creates a new HDWallet with a new random mnemonic with the provided strength in bits.
    ///
    /// \param strength strength in bits
    /// \param passphrase non-null passphrase
    /// \note Null is returned on invalid strength
    /// \note Returned object needs to be deleted with \TWHDWalletDelete
    /// \return Nullable TWHDWallet
    static native long nativeCreate(int strength, String passphrase);
    /// Creates an HDWallet from a valid BIP39 English mnemonic and a passphrase.
    ///
    /// \param mnemonic non-null Valid BIP39 mnemonic
    /// \param passphrase  non-null passphrase
    /// \note Null is returned on invalid mnemonic
    /// \note Returned object needs to be deleted with \TWHDWalletDelete
    /// \return Nullable TWHDWallet
    static native long nativeCreateWithMnemonic(String mnemonic, String passphrase);
    /// Creates an HDWallet from a BIP39 mnemonic, a passphrase and validation flag.
    ///
    /// \param mnemonic non-null Valid BIP39 mnemonic
    /// \param passphrase  non-null passphrase
    /// \param check validation flag
    /// \note Null is returned on invalid mnemonic
    /// \note Returned object needs to be deleted with \TWHDWalletDelete
    /// \return Nullable TWHDWallet
    static native long nativeCreateWithMnemonicCheck(String mnemonic, String passphrase, boolean check);
    /// Creates an HDWallet from entropy (corresponding to a mnemonic).
    ///
    /// \param entropy Non-null entropy data (corresponding to a mnemonic)
    /// \param passphrase non-null passphrase
    /// \note Null is returned on invalid input
    /// \note Returned object needs to be deleted with \TWHDWalletDelete
    /// \return Nullable TWHDWallet
    static native long nativeCreateWithEntropy(byte[] entropy, String passphrase);
    static native void nativeDelete(long handle);
    /// Computes the public key from an extended public key representation.
    ///
    /// \param extended extended public key
    /// \param coin a coin type
    /// \param derivationPath a derivation path
    /// \note Returned object needs to be deleted with \TWPublicKeyDelete
    /// \return Nullable TWPublic key
    public static native PublicKey getPublicKeyFromExtended(String extended, CoinType coin, String derivationPath);
    /// Wallet seed.
    ///
    /// \param wallet non-null TWHDWallet
    /// \return The wallet seed as a Non-null block of data.
    public native byte[] seed();
    /// Wallet seed of entropy.
    public native byte[] seedOfEntropy();
    /// Wallet Mnemonic
    ///
    /// \param wallet non-null TWHDWallet
    /// \return The wallet mnemonic as a non-null TWString
    public native String mnemonic();
    /// Wallet entropy
    ///
    /// \param wallet non-null TWHDWallet
    /// \return The wallet entropy as a non-null block of data.
    public native byte[] entropy();
    /// Returns master key.
    ///
    /// \param wallet non-null TWHDWallet
    /// \param curve  a curve
    /// \note Returned object needs to be deleted with \TWPrivateKeyDelete
    /// \return Non-null corresponding private key
    public native PrivateKey getMasterKey(Curve curve);
    /// Generates the default private key for the specified coin.
    ///
    /// \param wallet non-null TWHDWallet
    /// \param coin  a coin type
    /// \note Returned object needs to be deleted with \TWPrivateKeyDelete
    /// \return return the default private key for the specified coin
    public native PrivateKey getKeyForCoin(CoinType coin);
    /// Generates the default address for the specified coin (without exposing intermediary private key).
    ///
    /// \param wallet non-null TWHDWallet
    /// \param coin  a coin type
    /// \return return the default address for the specified coin as a non-null TWString
    public native String getAddressForCoin(CoinType coin);
    /// Generates the private key for the specified derivation path.
    ///
    /// \param wallet non-null TWHDWallet
    /// \param coin a coin type
    /// \param derivationPath  a non-null derivation path
    /// \note Returned object needs to be deleted with \TWPrivateKeyDelete
    /// \return The private key for the specified derivation path/coin
    public native PrivateKey getKey(CoinType coin, String derivationPath);
    /// Generates the private key for the specified derivation path and curve.
    ///
    /// \param wallet non-null TWHDWallet
    /// \param curve a curve
    /// \param derivationPath  a non-null derivation path
    /// \note Returned object needs to be deleted with \TWPrivateKeyDelete
    /// \return The private key for the specified derivation path/curve
    public native PrivateKey getKeyByCurve(Curve curve, String derivationPath);
    /// Shortcut method to generate private key with the specified account/change/address (bip44 standard).
    ///
    /// \see https://github.com/bitcoin/bips/blob/master/bip-0044.mediawiki
    ///
    /// \param wallet non-null TWHDWallet
    /// \param coin a coin type
    /// \param account valid bip44 account
    /// \param change valid bip44 change
    /// \param address valid bip44 address
    /// \note Returned object needs to be deleted with \TWPrivateKeyDelete
    /// \return The private key for the specified bip44 parameters
    public native PrivateKey getDerivedKey(CoinType coin, int account, int change, int address);
    /// Returns the extended private key (for default 0 account).
    ///
    /// \param wallet non-null TWHDWallet
    /// \param purpose a purpose
    /// \param coin a coin type
    /// \param version hd version
    /// \note Returned object needs to be deleted with \TWStringDelete
    /// \return  Extended private key as a non-null TWString
    public native String getExtendedPrivateKey(Purpose purpose, CoinType coin, HDVersion version);
    /// Returns the extended public key (for default 0 account).
    ///
    /// \param wallet non-null TWHDWallet
    /// \param purpose a purpose
    /// \param coin a coin type
    /// \param version hd version
    /// \note Returned object needs to be deleted with \TWStringDelete
    /// \return  Extended public key as a non-null TWString
    public native String getExtendedPublicKey(Purpose purpose, CoinType coin, HDVersion version);
    /// Returns the extended private key, for custom account.
    ///
    /// \param wallet non-null TWHDWallet
    /// \param purpose a purpose
    /// \param coin a coin type
    /// \param derivation a derivation
    /// \param version an hd version
    /// \param account valid bip44 account
    /// \note Returned object needs to be deleted with \TWStringDelete
    /// \return  Extended private key as a non-null TWString
    public native String getExtendedPrivateKeyAccount(Purpose purpose, CoinType coin, Derivation derivation, HDVersion version, int account);
    /// Returns the extended public key, for custom account.
    ///
    /// \param wallet non-null TWHDWallet
    /// \param purpose a purpose
    /// \param coin a coin type
    /// \param derivation a derivation
    /// \param version an hd version
    /// \param account valid bip44 account
    /// \note Returned object needs to be deleted with \TWStringDelete
    /// \return Extended public key as a non-null TWString
    public native String getExtendedPublicKeyAccount(Purpose purpose, CoinType coin, Derivation derivation, HDVersion version, int account);
    /// Returns the extended private key (for default 0 account with derivation).
    ///
    /// \param wallet non-null TWHDWallet
    /// \param purpose a purpose
    /// \param coin a coin type
    /// \param derivation a derivation
    /// \param version an hd version
    /// \note Returned object needs to be deleted with \TWStringDelete
    /// \return  Extended private key as a non-null TWString
    public native String getExtendedPrivateKeyDerivation(Purpose purpose, CoinType coin, Derivation derivation, HDVersion version);
    /// Returns the extended public key (for default 0 account with derivation).
    ///
    /// \param wallet non-null TWHDWallet
    /// \param purpose a purpose
    /// \param coin a coin type
    /// \param derivation a derivation
    /// \param version an hd version
    /// \note Returned object needs to be deleted with \TWStringDelete
    /// \return  Extended public key as a non-null TWString
    public native String getExtendedPublicKeyDerivation(Purpose purpose, CoinType coin, Derivation derivation, HDVersion version);
    /// Creates a new HDWallet with a new random mnemonic with the provided strength in bits.
    ///
    /// \param strength strength in bits
    /// \param passphrase non-null passphrase
    /// \note Null is returned on invalid strength
    /// \note Returned object needs to be deleted with \TWHDWalletDelete
    /// \return Nullable TWHDWallet
    public HDWallet(int strength, String passphrase) {
        nativeHandle = nativeCreate(strength, passphrase);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        HDWalletPhantomReference.register(this, nativeHandle);
    }

    /// Creates an HDWallet from a valid BIP39 English mnemonic and a passphrase.
    ///
    /// \param mnemonic non-null Valid BIP39 mnemonic
    /// \param passphrase  non-null passphrase
    /// \note Null is returned on invalid mnemonic
    /// \note Returned object needs to be deleted with \TWHDWalletDelete
    /// \return Nullable TWHDWallet
    public HDWallet(String mnemonic, String passphrase) {
        nativeHandle = nativeCreateWithMnemonic(mnemonic, passphrase);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        HDWalletPhantomReference.register(this, nativeHandle);
    }

    /// Creates an HDWallet from a BIP39 mnemonic, a passphrase and validation flag.
    ///
    /// \param mnemonic non-null Valid BIP39 mnemonic
    /// \param passphrase  non-null passphrase
    /// \param check validation flag
    /// \note Null is returned on invalid mnemonic
    /// \note Returned object needs to be deleted with \TWHDWalletDelete
    /// \return Nullable TWHDWallet
    public HDWallet(String mnemonic, String passphrase, boolean check) {
        nativeHandle = nativeCreateWithMnemonicCheck(mnemonic, passphrase, check);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        HDWalletPhantomReference.register(this, nativeHandle);
    }

    /// Creates an HDWallet from entropy (corresponding to a mnemonic).
    ///
    /// \param entropy Non-null entropy data (corresponding to a mnemonic)
    /// \param passphrase non-null passphrase
    /// \note Null is returned on invalid input
    /// \note Returned object needs to be deleted with \TWHDWalletDelete
    /// \return Nullable TWHDWallet
    public HDWallet(byte[] entropy, String passphrase) {
        nativeHandle = nativeCreateWithEntropy(entropy, passphrase);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        HDWalletPhantomReference.register(this, nativeHandle);
    }

}
class HDWalletPhantomReference extends java.lang.ref.PhantomReference<HDWallet> {
    private static java.util.Set<HDWalletPhantomReference> references = new HashSet<HDWalletPhantomReference>();
    private static java.lang.ref.ReferenceQueue<HDWallet> queue = new java.lang.ref.ReferenceQueue<HDWallet>();
    private long nativeHandle;

    private HDWalletPhantomReference(HDWallet referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(HDWallet referent, long nativeHandle) {
        references.add(new HDWalletPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        HDWalletPhantomReference ref = (HDWalletPhantomReference) queue.poll();
        for (; ref != null; ref = (HDWalletPhantomReference) queue.poll()) {
            HDWallet.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
