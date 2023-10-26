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

/// Represents a BIP 0173 address.
public class SegwitAddress {
    private long nativeHandle;

    private SegwitAddress() {
        nativeHandle = 0;
    }

    static SegwitAddress createFromNative(long nativeHandle) {
        SegwitAddress instance = new SegwitAddress();
        instance.nativeHandle = nativeHandle;
        SegwitAddressPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Creates an address from a string representation.
    ///
    /// \param string Non-null pointer to a Bech32 address as a string
    /// \note should be deleted with \TWSegwitAddressDelete
    /// \return Pointer to a Bech32 address if the string is a valid Bech32 address, null pointer otherwise
    static native long nativeCreateWithString(String string);
    /// Creates a segwit-version-0 address from a public key and HRP prefix.
    /// Taproot (v>=1) is not supported by this method.
    ///
    /// \param hrp HRP of the utxo coin targeted
    /// \param publicKey Non-null pointer to the public key of the targeted coin
    /// \note should be deleted with \TWSegwitAddressDelete
    /// \return Non-null pointer to the corresponding Segwit address
    static native long nativeCreateWithPublicKey(HRP hrp, PublicKey publicKey);
    static native void nativeDelete(long handle);
    /// Compares two addresses for equality.
    ///
    /// \param lhs left non-null pointer to a Bech32 Address
    /// \param rhs right non-null pointer to a Bech32 Address
    /// \return true if both address are equal, false otherwise
    public static native boolean equals(SegwitAddress lhs, SegwitAddress rhs);
    /// Determines if the string is a valid Bech32 address.
    ///
    /// \param string Non-null pointer to a Bech32 address as a string
    /// \return true if the string is a valid Bech32 address, false otherwise.
    public static native boolean isValidString(String string);
    /// Returns the address string representation.
    ///
    /// \param address Non-null pointer to a Segwit Address
    /// \return Non-null pointer to the segwit address string representation
    public native String description();
    /// Returns the human-readable part.
    ///
    /// \param address Non-null pointer to a Segwit Address
    /// \return the HRP part of the given address
    public native HRP hrp();
    /// Returns the human-readable part.
    ///
    /// \param address Non-null pointer to a Segwit Address
    /// \return returns the witness version of the given segwit address
    public native int witnessVersion();
    /// Returns the witness program
    ///
    /// \param address Non-null pointer to a Segwit Address
    /// \return returns the witness data of the given segwit address as a non-null pointer block of data
    public native byte[] witnessProgram();
    /// Creates an address from a string representation.
    ///
    /// \param string Non-null pointer to a Bech32 address as a string
    /// \note should be deleted with \TWSegwitAddressDelete
    /// \return Pointer to a Bech32 address if the string is a valid Bech32 address, null pointer otherwise
    public SegwitAddress(String string) {
        nativeHandle = nativeCreateWithString(string);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        SegwitAddressPhantomReference.register(this, nativeHandle);
    }

    /// Creates a segwit-version-0 address from a public key and HRP prefix.
    /// Taproot (v>=1) is not supported by this method.
    ///
    /// \param hrp HRP of the utxo coin targeted
    /// \param publicKey Non-null pointer to the public key of the targeted coin
    /// \note should be deleted with \TWSegwitAddressDelete
    /// \return Non-null pointer to the corresponding Segwit address
    public SegwitAddress(HRP hrp, PublicKey publicKey) {
        nativeHandle = nativeCreateWithPublicKey(hrp, publicKey);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        SegwitAddressPhantomReference.register(this, nativeHandle);
    }

}
class SegwitAddressPhantomReference extends java.lang.ref.PhantomReference<SegwitAddress> {
    private static java.util.Set<SegwitAddressPhantomReference> references = new HashSet<SegwitAddressPhantomReference>();
    private static java.lang.ref.ReferenceQueue<SegwitAddress> queue = new java.lang.ref.ReferenceQueue<SegwitAddress>();
    private long nativeHandle;

    private SegwitAddressPhantomReference(SegwitAddress referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(SegwitAddress referent, long nativeHandle) {
        references.add(new SegwitAddressPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        SegwitAddressPhantomReference ref = (SegwitAddressPhantomReference) queue.poll();
        for (; ref != null; ref = (SegwitAddressPhantomReference) queue.poll()) {
            SegwitAddress.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
