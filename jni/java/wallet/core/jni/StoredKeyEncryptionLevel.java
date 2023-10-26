// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

package wallet.core.jni;


/// Preset encryption parameter with different security strength, for key store
public enum StoredKeyEncryptionLevel {
    DEFAULT (0),
    MINIMAL (1),
    WEAK (2),
    STANDARD (3);

    private final int value;
    StoredKeyEncryptionLevel(int value) {
        this.value = value;
    }
    public int value() { return value; }

    public static StoredKeyEncryptionLevel createFromValue(int value) {
        switch (value) {
            case 0: return StoredKeyEncryptionLevel.DEFAULT;
            case 1: return StoredKeyEncryptionLevel.MINIMAL;
            case 2: return StoredKeyEncryptionLevel.WEAK;
            case 3: return StoredKeyEncryptionLevel.STANDARD;
            default: return null;
        }
    }

}
