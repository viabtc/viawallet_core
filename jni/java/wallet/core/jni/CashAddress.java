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

/// Represents a CashAddress in C++.
public class CashAddress {
    private long nativeHandle;

    private CashAddress() {
        nativeHandle = 0;
    }

    static CashAddress createFromNative(long nativeHandle) {
        CashAddress instance = new CashAddress();
        instance.nativeHandle = nativeHandle;
        CashAddressPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Initializes a CashAddress.
    static native long nativeCreateWithString(String hrp, String string);
    /// Initializes an CashAddress from a public key and hrp.
    ///
    /// \param hrp hrp to initialize the CashAddress from.
    /// \param publicKey Public key to initialize the CashAddress from.
    /// \return TWCashAddress pointer or nullptr if public key is invalid.
    static native long nativeCreateWithPublicKey(String hrp, PublicKey publicKey);
    static native void nativeDelete(long handle);
    /// Compares two addresses for equality.
    ///
    /// \param lhs The first address to compare.
    /// \param rhs The second address to compare.
    /// \return bool indicating the addresses are equal.
    public static native boolean equals(CashAddress lhs, CashAddress rhs);
    /// Determines if the data is a valid CashAddress.
    ///
    /// \param data data to validate.
    /// \return bool indicating if the address data is valid.
    public static native boolean isValid(byte[] data);
    /// Determines if the string is a valid CashAddress.
    ///
    /// \param hrp hrp to validate.
    /// \param string string to validate.
    /// \return bool indicating if the address string is valid.
    public static native boolean isValidString(String hrp, String string);
    /// Returns the address in cash encode string representation.
    ///
    /// \param address CashAddress to get the string representation of.
    public native String description();
    /// Returns the key hash data.
    ///
    /// \param address CashAddress to get the keyhash data of.
    public native byte[] keyhash();
    /// Initializes a CashAddress.
    public CashAddress(String hrp, String string) {
        nativeHandle = nativeCreateWithString(hrp, string);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        CashAddressPhantomReference.register(this, nativeHandle);
    }

    /// Initializes an CashAddress from a public key and hrp.
    ///
    /// \param hrp hrp to initialize the CashAddress from.
    /// \param publicKey Public key to initialize the CashAddress from.
    /// \return TWCashAddress pointer or nullptr if public key is invalid.
    public CashAddress(String hrp, PublicKey publicKey) {
        nativeHandle = nativeCreateWithPublicKey(hrp, publicKey);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        CashAddressPhantomReference.register(this, nativeHandle);
    }

}
class CashAddressPhantomReference extends java.lang.ref.PhantomReference<CashAddress> {
    private static java.util.Set<CashAddressPhantomReference> references = new HashSet<CashAddressPhantomReference>();
    private static java.lang.ref.ReferenceQueue<CashAddress> queue = new java.lang.ref.ReferenceQueue<CashAddress>();
    private long nativeHandle;

    private CashAddressPhantomReference(CashAddress referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(CashAddress referent, long nativeHandle) {
        references.add(new CashAddressPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        CashAddressPhantomReference ref = (CashAddressPhantomReference) queue.poll();
        for (; ref != null; ref = (CashAddressPhantomReference) queue.poll()) {
            CashAddress.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
