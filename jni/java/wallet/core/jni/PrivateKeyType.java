// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

package wallet.core.jni;


/// Private key types, the vast majority of chains use the default, 32-byte key.
public enum PrivateKeyType {
    DEFAULT (0),
    CARDANO (1);

    private final int value;
    PrivateKeyType(int value) {
        this.value = value;
    }
    public int value() { return value; }

    public static PrivateKeyType createFromValue(int value) {
        switch (value) {
            case 0: return PrivateKeyType.DEFAULT;
            case 1: return PrivateKeyType.CARDANO;
            default: return null;
        }
    }

}
