// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

package wallet.core.jni;


/// Padding mode used in AES encryption.
public enum AESPaddingMode {
    ZERO (0),
    PKCS7 (1);

    private final int value;
    AESPaddingMode(int value) {
        this.value = value;
    }
    public int value() { return value; }

    public static AESPaddingMode createFromValue(int value) {
        switch (value) {
            case 0: return AESPaddingMode.ZERO;
            case 1: return AESPaddingMode.PKCS7;
            default: return null;
        }
    }

}
