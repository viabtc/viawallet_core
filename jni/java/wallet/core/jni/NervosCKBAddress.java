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

/// Represents a Nervos address.
public class NervosCKBAddress {
    private long nativeHandle;

    private NervosCKBAddress() {
        nativeHandle = 0;
    }

    static NervosCKBAddress createFromNative(long nativeHandle) {
        NervosCKBAddress instance = new NervosCKBAddress();
        instance.nativeHandle = nativeHandle;
        NervosCKBAddressPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Initializes an address from a sring representaion.
    ///
    /// \param string Bech32 string to initialize the address from.
    /// \return TWNervosCKBAddress pointer or nullptr if string is invalid.
    static native long nativeCreateWithString(String string);
    static native void nativeDelete(long handle);
    /// Compares two addresses for equality.
    ///
    /// \param lhs The first address to compare.
    /// \param rhs The second address to compare.
    /// \return bool indicating the addresses are equal.
    public static native boolean equals(NervosCKBAddress lhs, NervosCKBAddress rhs);
    /// Determines if the string is a valid Nervos address.
    ///
    /// \param string string to validate.
    /// \return bool indicating if the address is valid.
    public static native boolean isValidString(String string);
    /// Convert an address to Bech32mFullAddress.
    public static native String convertToBech32mFullAddress(String address);
    /// Returns the address string representation.
    ///
    /// \param address Address to get the string representation of.
    public native String description();
    /// Initializes an address from a sring representaion.
    ///
    /// \param string Bech32 string to initialize the address from.
    /// \return TWNervosCKBAddress pointer or nullptr if string is invalid.
    public NervosCKBAddress(String string) {
        nativeHandle = nativeCreateWithString(string);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        NervosCKBAddressPhantomReference.register(this, nativeHandle);
    }

}
class NervosCKBAddressPhantomReference extends java.lang.ref.PhantomReference<NervosCKBAddress> {
    private static java.util.Set<NervosCKBAddressPhantomReference> references = new HashSet<NervosCKBAddressPhantomReference>();
    private static java.lang.ref.ReferenceQueue<NervosCKBAddress> queue = new java.lang.ref.ReferenceQueue<NervosCKBAddress>();
    private long nativeHandle;

    private NervosCKBAddressPhantomReference(NervosCKBAddress referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(NervosCKBAddress referent, long nativeHandle) {
        references.add(new NervosCKBAddressPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        NervosCKBAddressPhantomReference ref = (NervosCKBAddressPhantomReference) queue.poll();
        for (; ref != null; ref = (NervosCKBAddressPhantomReference) queue.poll()) {
            NervosCKBAddress.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
