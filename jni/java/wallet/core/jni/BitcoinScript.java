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

/// Bitcoin script manipulating functions
public class BitcoinScript {
    private long nativeHandle;

    static BitcoinScript createFromNative(long nativeHandle) {
        BitcoinScript instance = new BitcoinScript();
        instance.nativeHandle = nativeHandle;
        BitcoinScriptPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Creates an empty script.
    ///
    /// \return A pointer to the script
    static native long nativeCreate();
    /// Creates a script from a raw data representation.
    ///
    /// \param data The data buffer
    /// \note Must be deleted with \TWBitcoinScriptDelete
    /// \return A pointer to the script
    static native long nativeCreateWithData(byte[] data);
    /// Creates a script from a raw bytes and size.
    ///
    /// \param bytes The buffer
    /// \param size The size of the buffer
    /// \note Must be deleted with \TWBitcoinScriptDelete
    /// \return A pointer to the script    /// Creates a script by copying an existing script.
    ///
    /// \param script Non-null pointer to a script
    /// \note Must be deleted with \TWBitcoinScriptDelete
    /// \return A pointer to the script
    static native long nativeCreateCopy(BitcoinScript script);
    static native void nativeDelete(long handle);
    /// Determines whether 2 scripts have the same content
    ///
    /// \param lhs Non-null pointer to the first script
    /// \param rhs Non-null pointer to the second script
    /// \return true if both script have the same content
    public static native boolean equals(BitcoinScript lhs, BitcoinScript rhs);
    /// Builds a standard 'pay to public key' script.
    ///
    /// \param pubkey Non-null pointer to a pubkey
    /// \note Must be deleted with \TWBitcoinScriptDelete
    /// \return A pointer to the built script
    public static native BitcoinScript buildPayToPublicKey(byte[] pubkey);
    /// Builds a standard 'pay to public key hash' script.
    ///
    /// \param hash Non-null pointer to a PublicKey hash
    /// \note Must be deleted with \TWBitcoinScriptDelete
    /// \return A pointer to the built script
    public static native BitcoinScript buildPayToPublicKeyHash(byte[] hash);
    /// Builds a standard 'pay to script hash' script.
    ///
    /// \param scriptHash Non-null pointer to a script hash
    /// \note Must be deleted with \TWBitcoinScriptDelete
    /// \return A pointer to the built script
    public static native BitcoinScript buildPayToScriptHash(byte[] scriptHash);
    /// Builds a pay-to-witness-public-key-hash (P2WPKH) script..
    ///
    /// \param hash Non-null pointer to a witness public key hash
    /// \note Must be deleted with \TWBitcoinScriptDelete
    /// \return A pointer to the built script
    public static native BitcoinScript buildPayToWitnessPubkeyHash(byte[] hash);
    /// Builds a pay-to-witness-script-hash (P2WSH) script.
    ///
    /// \param scriptHash Non-null pointer to a script hash
    /// \note Must be deleted with \TWBitcoinScriptDelete
    /// \return A pointer to the built script
    public static native BitcoinScript buildPayToWitnessScriptHash(byte[] scriptHash);
    /// Builds a appropriate lock script for the given address..
    ///
    /// \param address Non-null pointer to an address
    /// \param coin coin type
    /// \note Must be deleted with \TWBitcoinScriptDelete
    /// \return A pointer to the built script
    public static native BitcoinScript lockScriptForAddress(String address, CoinType coin);
    /// Return the default HashType for the given coin, such as TWBitcoinSigHashTypeAll.
    ///
    /// \param coinType coin type
    /// \return default HashType for the given coin
    public static native int hashTypeForCoin(CoinType coinType);
    /// Get size of a script
    ///
    /// \param script Non-null pointer to a script
    /// \return size of the script
    public native int size();
    /// Get data of a script
    ///
    /// \param script Non-null pointer to a script
    /// \return data of the given script
    public native byte[] data();
    /// Return script hash of a script
    ///
    /// \param script Non-null pointer to a script
    /// \return script hash of the given script
    public native byte[] scriptHash();
    /// Determines whether this is a pay-to-script-hash (P2SH) script.
    ///
    /// \param script Non-null pointer to a script
    /// \return true if this is a pay-to-script-hash (P2SH) script, false otherwise
    public native boolean isPayToScriptHash();
    /// Determines whether this is a pay-to-witness-script-hash (P2WSH) script.
    ///
    /// \param script Non-null pointer to a script
    /// \return true if this is a pay-to-witness-script-hash (P2WSH) script, false otherwise
    public native boolean isPayToWitnessScriptHash();
    /// Determines whether this is a pay-to-witness-public-key-hash (P2WPKH) script.
    ///
    /// \param script Non-null pointer to a script
    /// \return true if this is a pay-to-witness-public-key-hash (P2WPKH) script, false otherwise
    public native boolean isPayToWitnessPublicKeyHash();
    /// Determines whether this is a witness program script.
    ///
    /// \param script Non-null pointer to a script
    /// \return true if this is a witness program script, false otherwise
    public native boolean isWitnessProgram();
    /// Matches the script to a pay-to-public-key (P2PK) script.
    ///
    /// \param script Non-null pointer to a script
    /// \return The public key.
    public native byte[] matchPayToPubkey();
    /// Matches the script to a pay-to-public-key-hash (P2PKH).
    ///
    /// \param script Non-null pointer to a script
    /// \return the key hash.
    public native byte[] matchPayToPubkeyHash();
    /// Matches the script to a pay-to-script-hash (P2SH).
    ///
    /// \param script Non-null pointer to a script
    /// \return the script hash.
    public native byte[] matchPayToScriptHash();
    /// Matches the script to a pay-to-witness-public-key-hash (P2WPKH).
    ///
    /// \param script Non-null pointer to a script
    /// \return the key hash.
    public native byte[] matchPayToWitnessPublicKeyHash();
    /// Matches the script to a pay-to-witness-script-hash (P2WSH).
    ///
    /// \param script Non-null pointer to a script
    /// \return the script hash, a SHA256 of the witness script..
    public native byte[] matchPayToWitnessScriptHash();
    /// Encodes the script.
    ///
    /// \param script Non-null pointer to a script
    /// \return The encoded script
    public native byte[] encode();
    /// Creates an empty script.
    ///
    /// \return A pointer to the script
    public BitcoinScript() {
        nativeHandle = nativeCreate();
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        BitcoinScriptPhantomReference.register(this, nativeHandle);
    }

    /// Creates a script from a raw data representation.
    ///
    /// \param data The data buffer
    /// \note Must be deleted with \TWBitcoinScriptDelete
    /// \return A pointer to the script
    public BitcoinScript(byte[] data) {
        nativeHandle = nativeCreateWithData(data);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        BitcoinScriptPhantomReference.register(this, nativeHandle);
    }

    /// Creates a script from a raw bytes and size.
    ///
    /// \param bytes The buffer
    /// \param size The size of the buffer
    /// \note Must be deleted with \TWBitcoinScriptDelete
    /// \return A pointer to the script    /// Creates a script by copying an existing script.
    ///
    /// \param script Non-null pointer to a script
    /// \note Must be deleted with \TWBitcoinScriptDelete
    /// \return A pointer to the script
    public BitcoinScript(BitcoinScript script) {
        nativeHandle = nativeCreateCopy(script);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        BitcoinScriptPhantomReference.register(this, nativeHandle);
    }

}
class BitcoinScriptPhantomReference extends java.lang.ref.PhantomReference<BitcoinScript> {
    private static java.util.Set<BitcoinScriptPhantomReference> references = new HashSet<BitcoinScriptPhantomReference>();
    private static java.lang.ref.ReferenceQueue<BitcoinScript> queue = new java.lang.ref.ReferenceQueue<BitcoinScript>();
    private long nativeHandle;

    private BitcoinScriptPhantomReference(BitcoinScript referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(BitcoinScript referent, long nativeHandle) {
        references.add(new BitcoinScriptPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        BitcoinScriptPhantomReference ref = (BitcoinScriptPhantomReference) queue.poll();
        for (; ref != null; ref = (BitcoinScriptPhantomReference) queue.poll()) {
            BitcoinScript.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
