// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

package wallet.core.jni;


/// Bitcoin SIGHASH type.
public enum BitcoinSigHashType {
    ALL (0x01),
    NONE (0x02),
    SINGLE (0x03),
    FORK (0x40),
    FORKBTG (0x4f40);

    private final int value;
    BitcoinSigHashType(int value) {
        this.value = value;
    }
    public int value() { return value; }

    public static BitcoinSigHashType createFromValue(int value) {
        switch (value) {
            case 0x01: return BitcoinSigHashType.ALL;
            case 0x02: return BitcoinSigHashType.NONE;
            case 0x03: return BitcoinSigHashType.SINGLE;
            case 0x40: return BitcoinSigHashType.FORK;
            case 0x4f40: return BitcoinSigHashType.FORKBTG;
            default: return null;
        }
    }

    public native boolean isSingle();
    public native boolean isNone();
}
