// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

package wallet.core.jni;


///  Registered human-readable parts for BIP-0173
///
/// - SeeAlso: https://github.com/satoshilabs/slips/blob/master/slip-0173.md
public enum HRP {
    UNKNOWN (0),
    BITCOIN (1),
    LITECOIN (2),
    VIACOIN (3),
    GROESTLCOIN (4),
    DIGIBYTE (5),
    MONACOIN (6),
    SYSCOIN (7),
    COSMOS (8),
    LBRYCREDITS (9),
    BITCOINCASH (10),
    BITCOINGOLD (11),
    IOTEX (12),
    NERVOSCKB (13),
    ZILLIQA (14),
    CRYPTOORG (15),
    KAVA (16),
    OASIS (17),
    BLUZELLE (18),
    BANDCHAIN (19),
    ELROND (20),
    BINANCE (21),
    THORCHAIN (22),
    HARMONY (23),
    CARDANO (24),
    QTUM (25),
    HANDSHAKE (26),
    KASPA (27),
    IRISNET (28),
    TERRACLASSIC (29),
    OSMOSIS (30),
    ECASH (31),
    TERRA (32),
    NATIVEEVMOS (33);

    private final int value;
    HRP(int value) {
        this.value = value;
    }
    public int value() { return value; }

    public static HRP createFromValue(int value) {
        switch (value) {
            case 0: return HRP.UNKNOWN;
            case 1: return HRP.BITCOIN;
            case 2: return HRP.LITECOIN;
            case 3: return HRP.VIACOIN;
            case 4: return HRP.GROESTLCOIN;
            case 5: return HRP.DIGIBYTE;
            case 6: return HRP.MONACOIN;
            case 7: return HRP.SYSCOIN;
            case 8: return HRP.COSMOS;
            case 9: return HRP.LBRYCREDITS;
            case 10: return HRP.BITCOINCASH;
            case 11: return HRP.BITCOINGOLD;
            case 12: return HRP.IOTEX;
            case 13: return HRP.NERVOSCKB;
            case 14: return HRP.ZILLIQA;
            case 15: return HRP.CRYPTOORG;
            case 16: return HRP.KAVA;
            case 17: return HRP.OASIS;
            case 18: return HRP.BLUZELLE;
            case 19: return HRP.BANDCHAIN;
            case 20: return HRP.ELROND;
            case 21: return HRP.BINANCE;
            case 22: return HRP.THORCHAIN;
            case 23: return HRP.HARMONY;
            case 24: return HRP.CARDANO;
            case 25: return HRP.QTUM;
            case 26: return HRP.HANDSHAKE;
            case 27: return HRP.KASPA;
            case 28: return HRP.IRISNET;
            case 29: return HRP.TERRACLASSIC;
            case 30: return HRP.OSMOSIS;
            case 31: return HRP.ECASH;
            case 32: return HRP.TERRA;
            case 33: return HRP.NATIVEEVMOS;
            default: return null;
        }
    }


    public String toString() {
        switch (this) {
        case UNKNOWN: return "";
        case BITCOIN: return "bc";
        case LITECOIN: return "ltc";
        case VIACOIN: return "via";
        case GROESTLCOIN: return "grs";
        case DIGIBYTE: return "dgb";
        case MONACOIN: return "mona";
        case SYSCOIN: return "sys";
        case COSMOS: return "cosmos";
        case LBRYCREDITS: return "lbc";
        case BITCOINCASH: return "bitcoincash";
        case BITCOINGOLD: return "btg";
        case IOTEX: return "io";
        case NERVOSCKB: return "ckb";
        case ZILLIQA: return "zil";
        case CRYPTOORG: return "cro";
        case KAVA: return "kava";
        case OASIS: return "oasis";
        case BLUZELLE: return "bluzelle";
        case BANDCHAIN: return "band";
        case ELROND: return "erd";
        case BINANCE: return "bnb";
        case THORCHAIN: return "thor";
        case HARMONY: return "one";
        case CARDANO: return "addr";
        case QTUM: return "qc";
        case HANDSHAKE: return "hs";
        case KASPA: return "kaspa";
        case IRISNET: return "iaa";
        case TERRACLASSIC: return "terra";
        case OSMOSIS: return "osmo";
        case ECASH: return "ecash";
        case TERRA: return "terra";
        case NATIVEEVMOS: return "evmos";
        default: return "";
        }
    }
}
