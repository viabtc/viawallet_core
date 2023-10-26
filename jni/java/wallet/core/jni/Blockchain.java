// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

package wallet.core.jni;


/// Blockchain enum type
public enum Blockchain {
    BITCOIN (0),
    ETHEREUM (1),
    VECHAIN (3),
    TRON (4),
    ICON (5),
    BINANCE (6),
    RIPPLE (7),
    TEZOS (8),
    NIMIQ (9),
    STELLAR (10),
    AION (11),
    COSMOS (12),
    THETA (13),
    ONTOLOGY (14),
    ZILLIQA (15),
    IOTEX (16),
    EOS (17),
    NANO (18),
    NULS (19),
    WAVES (20),
    AETERNITY (21),
    NEBULAS (22),
    FIO (23),
    SOLANA (24),
    HARMONY (25),
    NEAR (26),
    ALGORAND (27),
    POLKADOT (29),
    CARDANO (30),
    NEO (31),
    FILECOIN (32),
    ELRONDNETWORK (33),
    OASISNETWORK (34),
    DECRED (35),
    ZCASH (36),
    GROESTLCOIN (37),
    THORCHAIN (38),
    RONIN (39),
    KUSAMA (40),
    CONFLUX (41),
    NERVOS (42),
    ERGO (43),
    MINA (44),
    KADENA (45),
    HORIZEN (46),
    HANDSHAKE (47),
    EVERSCALE (48),
    APTOS (49),
    KASPA (50);

    private final int value;
    Blockchain(int value) {
        this.value = value;
    }
    public int value() { return value; }

    public static Blockchain createFromValue(int value) {
        switch (value) {
            case 0: return Blockchain.BITCOIN;
            case 1: return Blockchain.ETHEREUM;
            case 3: return Blockchain.VECHAIN;
            case 4: return Blockchain.TRON;
            case 5: return Blockchain.ICON;
            case 6: return Blockchain.BINANCE;
            case 7: return Blockchain.RIPPLE;
            case 8: return Blockchain.TEZOS;
            case 9: return Blockchain.NIMIQ;
            case 10: return Blockchain.STELLAR;
            case 11: return Blockchain.AION;
            case 12: return Blockchain.COSMOS;
            case 13: return Blockchain.THETA;
            case 14: return Blockchain.ONTOLOGY;
            case 15: return Blockchain.ZILLIQA;
            case 16: return Blockchain.IOTEX;
            case 17: return Blockchain.EOS;
            case 18: return Blockchain.NANO;
            case 19: return Blockchain.NULS;
            case 20: return Blockchain.WAVES;
            case 21: return Blockchain.AETERNITY;
            case 22: return Blockchain.NEBULAS;
            case 23: return Blockchain.FIO;
            case 24: return Blockchain.SOLANA;
            case 25: return Blockchain.HARMONY;
            case 26: return Blockchain.NEAR;
            case 27: return Blockchain.ALGORAND;
            case 29: return Blockchain.POLKADOT;
            case 30: return Blockchain.CARDANO;
            case 31: return Blockchain.NEO;
            case 32: return Blockchain.FILECOIN;
            case 33: return Blockchain.ELRONDNETWORK;
            case 34: return Blockchain.OASISNETWORK;
            case 35: return Blockchain.DECRED;
            case 36: return Blockchain.ZCASH;
            case 37: return Blockchain.GROESTLCOIN;
            case 38: return Blockchain.THORCHAIN;
            case 39: return Blockchain.RONIN;
            case 40: return Blockchain.KUSAMA;
            case 41: return Blockchain.CONFLUX;
            case 42: return Blockchain.NERVOS;
            case 43: return Blockchain.ERGO;
            case 44: return Blockchain.MINA;
            case 45: return Blockchain.KADENA;
            case 46: return Blockchain.HORIZEN;
            case 47: return Blockchain.HANDSHAKE;
            case 48: return Blockchain.EVERSCALE;
            case 49: return Blockchain.APTOS;
            case 50: return Blockchain.KASPA;
            default: return null;
        }
    }

}
