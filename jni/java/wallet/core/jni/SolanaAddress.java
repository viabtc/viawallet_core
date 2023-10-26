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

/// Solana address helper functions
public class SolanaAddress {
    private long nativeHandle;

    private SolanaAddress() {
        nativeHandle = 0;
    }

    static SolanaAddress createFromNative(long nativeHandle) {
        SolanaAddress instance = new SolanaAddress();
        instance.nativeHandle = nativeHandle;
        SolanaAddressPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Creates an address from a string representation.
    ///
    /// \param string Non-null pointer to a solana address string
    /// \note Should be deleted with \TWSolanaAddressDelete
    /// \return Non-null pointer to a Solana address data structure
    static native long nativeCreateWithString(String string);
    static native void nativeDelete(long handle);
    /// Returns the address string representation.
    ///
    /// \param address Non-null pointer to a Solana Address
    /// \return Non-null pointer to the Solana address string representation
    public native String description();
    /// Derive default token address for token
    ///
    /// \param address Non-null pointer to a Solana Address
    /// \param tokenMintAddress Non-null pointer to a token mint address as a string
    /// \return Null pointer if the Default token address for a token is not found, valid pointer otherwise
    public native String defaultTokenAddress(String tokenMintAddress);
    /// Creates an address from a string representation.
    ///
    /// \param string Non-null pointer to a solana address string
    /// \note Should be deleted with \TWSolanaAddressDelete
    /// \return Non-null pointer to a Solana address data structure
    public SolanaAddress(String string) {
        nativeHandle = nativeCreateWithString(string);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        SolanaAddressPhantomReference.register(this, nativeHandle);
    }

}
class SolanaAddressPhantomReference extends java.lang.ref.PhantomReference<SolanaAddress> {
    private static java.util.Set<SolanaAddressPhantomReference> references = new HashSet<SolanaAddressPhantomReference>();
    private static java.lang.ref.ReferenceQueue<SolanaAddress> queue = new java.lang.ref.ReferenceQueue<SolanaAddress>();
    private long nativeHandle;

    private SolanaAddressPhantomReference(SolanaAddress referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(SolanaAddress referent, long nativeHandle) {
        references.add(new SolanaAddressPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        SolanaAddressPhantomReference ref = (SolanaAddressPhantomReference) queue.poll();
        for (; ref != null; ref = (SolanaAddressPhantomReference) queue.poll()) {
            SolanaAddress.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
