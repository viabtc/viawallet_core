// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

package wallet.core.jni;


/// Substrate based chains Address Type
///
/// \see https://github.com/paritytech/substrate/wiki/External-Address-Format-(SS58)#address-type
public enum SS58AddressType {
    POLKADOT ((byte) 0),
    KUSAMA ((byte) 2);

    private final byte value;
    SS58AddressType(byte value) {
        this.value = value;
    }
    public byte value() { return value; }

    public static SS58AddressType createFromValue(byte value) {
        switch (value) {
            case (byte) 0: return SS58AddressType.POLKADOT;
            case (byte) 2: return SS58AddressType.KUSAMA;
            default: return null;
        }
    }

}
