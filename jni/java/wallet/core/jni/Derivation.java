// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

package wallet.core.jni;


/// Non-default coin address derivation names (default, unnamed derivations are not included).
public enum Derivation {
    DEFAULT (0),
    CUSTOM (1),
    BITCOINSEGWIT (2),
    BITCOINLEGACY (3),
    BITCOINTESTNET (4),
    LITECOINLEGACY (5),
    SOLANASOLANA (6);

    private final int value;
    Derivation(int value) {
        this.value = value;
    }
    public int value() { return value; }

    public static Derivation createFromValue(int value) {
        switch (value) {
            case 0: return Derivation.DEFAULT;
            case 1: return Derivation.CUSTOM;
            case 2: return Derivation.BITCOINSEGWIT;
            case 3: return Derivation.BITCOINLEGACY;
            case 4: return Derivation.BITCOINTESTNET;
            case 5: return Derivation.LITECOINLEGACY;
            case 6: return Derivation.SOLANASOLANA;
            default: return null;
        }
    }

}
