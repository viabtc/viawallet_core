// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

package wallet.core.jni;


/// Coin type for Level 2 of BIP44.
///
/// \see https://github.com/satoshilabs/slips/blob/master/slip-0044.md
public enum CoinType {
    AETERNITY (457),
    AION (425),
    BINANCE (714),
    BITCOIN (0),
    BITCOINCASH (145),
    BITCOINGOLD (156),
    CALLISTO (820),
    CARDANO (1815),
    COSMOS (118),
    DASH (5),
    DECRED (42),
    DIGIBYTE (20),
    DOGECOIN (3),
    EOS (194),
    ETHEREUM (60),
    ETHEREUMCLASSIC (61),
    FIO (235),
    GOCHAIN (6060),
    GROESTLCOIN (17),
    ICON (74),
    IOTEX (304),
    KAVA (459),
    KIN (2017),
    LITECOIN (2),
    MONACOIN (22),
    NEBULAS (2718),
    NULS (8964),
    NANO (165),
    NEAR (397),
    NIMIQ (242),
    ONTOLOGY (1024),
    POANETWORK (178),
    QTUM (2301),
    XRP (144),
    SOLANA (501),
    STELLAR (148),
    TEZOS (1729),
    THETA (500),
    THUNDERTOKEN (1001),
    NEO (888),
    TOMOCHAIN (889),
    TRON (195),
    VECHAIN (818),
    VIACOIN (14),
    WANCHAIN (5718350),
    ZCASH (133),
    FIRO (136),
    ZILLIQA (313),
    ZELCASH (19167),
    RAVENCOIN (175),
    WAVES (5741564),
    HARMONY (1023),
    ALGORAND (283),
    KUSAMA (434),
    POLKADOT (354),
    FILECOIN (461),
    ELROND (508),
    BANDCHAIN (494),
    SMARTCHAINLEGACY (10000714),
    SMARTCHAIN (20000714),
    OASIS (474),
    POLYGON (966),
    THORCHAIN (931),
    BLUZELLE (483),
    OPTIMISM (10000070),
    ZKSYNC (10000280),
    ARBITRUM (10042221),
    ECOCHAIN (1010),
    AVALANCHECCHAIN (10009000),
    XDAI (10000100),
    FANTOM (10000250),
    CRYPTOORG (394),
    CELO (52752),
    RONIN (10002020),
    OSMOSIS (20000118),
    ECASH (20000145),
    CRONOSCHAIN (10000025),
    SMARTBITCOINCASH (10000145),
    KUCOINCOMMUNITYCHAIN (10000321),
    BOBA (10000288),
    METIS (1001088),
    AURORA (1323161554),
    EVMOS (10009001),
    NATIVEEVMOS (20009001),
    MOONRIVER (10001285),
    MOONBEAM (10001284),
    KAVAEVM (10002222),
    KLAYTN (10008217),
    FREECASH (485),
    COINEXSMARTCHAIN (1000052),
    SYSCOIN (57),
    BITCOINSV (236),
    TERRA (20000330),
    TERRACLASSIC (10000330),
    LBRYCREDITS (140),
    IRISNET (10000118),
    CONFLUXNETWORK (503),
    NERVOSCKB (309),
    ERGO (429),
    HORIZEN (121),
    HANDSHAKE (5353),
    MINA (12586),
    KADENA (626),
    METER (18000),
    OKXCHAIN (996),
    EVERSCALE (396),
    APTOS (637),
    BASE (8453),
    KASPA (111111);

    private final int value;
    CoinType(int value) {
        this.value = value;
    }
    public int value() { return value; }

    public static CoinType createFromValue(int value) {
        switch (value) {
            case 457: return CoinType.AETERNITY;
            case 425: return CoinType.AION;
            case 714: return CoinType.BINANCE;
            case 0: return CoinType.BITCOIN;
            case 145: return CoinType.BITCOINCASH;
            case 156: return CoinType.BITCOINGOLD;
            case 820: return CoinType.CALLISTO;
            case 1815: return CoinType.CARDANO;
            case 118: return CoinType.COSMOS;
            case 5: return CoinType.DASH;
            case 42: return CoinType.DECRED;
            case 20: return CoinType.DIGIBYTE;
            case 3: return CoinType.DOGECOIN;
            case 194: return CoinType.EOS;
            case 60: return CoinType.ETHEREUM;
            case 61: return CoinType.ETHEREUMCLASSIC;
            case 235: return CoinType.FIO;
            case 6060: return CoinType.GOCHAIN;
            case 17: return CoinType.GROESTLCOIN;
            case 74: return CoinType.ICON;
            case 304: return CoinType.IOTEX;
            case 459: return CoinType.KAVA;
            case 2017: return CoinType.KIN;
            case 2: return CoinType.LITECOIN;
            case 22: return CoinType.MONACOIN;
            case 2718: return CoinType.NEBULAS;
            case 8964: return CoinType.NULS;
            case 165: return CoinType.NANO;
            case 397: return CoinType.NEAR;
            case 242: return CoinType.NIMIQ;
            case 1024: return CoinType.ONTOLOGY;
            case 178: return CoinType.POANETWORK;
            case 2301: return CoinType.QTUM;
            case 144: return CoinType.XRP;
            case 501: return CoinType.SOLANA;
            case 148: return CoinType.STELLAR;
            case 1729: return CoinType.TEZOS;
            case 500: return CoinType.THETA;
            case 1001: return CoinType.THUNDERTOKEN;
            case 888: return CoinType.NEO;
            case 889: return CoinType.TOMOCHAIN;
            case 195: return CoinType.TRON;
            case 818: return CoinType.VECHAIN;
            case 14: return CoinType.VIACOIN;
            case 5718350: return CoinType.WANCHAIN;
            case 133: return CoinType.ZCASH;
            case 136: return CoinType.FIRO;
            case 313: return CoinType.ZILLIQA;
            case 19167: return CoinType.ZELCASH;
            case 175: return CoinType.RAVENCOIN;
            case 5741564: return CoinType.WAVES;
            case 1023: return CoinType.HARMONY;
            case 283: return CoinType.ALGORAND;
            case 434: return CoinType.KUSAMA;
            case 354: return CoinType.POLKADOT;
            case 461: return CoinType.FILECOIN;
            case 508: return CoinType.ELROND;
            case 494: return CoinType.BANDCHAIN;
            case 10000714: return CoinType.SMARTCHAINLEGACY;
            case 20000714: return CoinType.SMARTCHAIN;
            case 474: return CoinType.OASIS;
            case 966: return CoinType.POLYGON;
            case 931: return CoinType.THORCHAIN;
            case 483: return CoinType.BLUZELLE;
            case 10000070: return CoinType.OPTIMISM;
            case 10000280: return CoinType.ZKSYNC;
            case 10042221: return CoinType.ARBITRUM;
            case 1010: return CoinType.ECOCHAIN;
            case 10009000: return CoinType.AVALANCHECCHAIN;
            case 10000100: return CoinType.XDAI;
            case 10000250: return CoinType.FANTOM;
            case 394: return CoinType.CRYPTOORG;
            case 52752: return CoinType.CELO;
            case 10002020: return CoinType.RONIN;
            case 20000118: return CoinType.OSMOSIS;
            case 20000145: return CoinType.ECASH;
            case 10000025: return CoinType.CRONOSCHAIN;
            case 10000145: return CoinType.SMARTBITCOINCASH;
            case 10000321: return CoinType.KUCOINCOMMUNITYCHAIN;
            case 10000288: return CoinType.BOBA;
            case 1001088: return CoinType.METIS;
            case 1323161554: return CoinType.AURORA;
            case 10009001: return CoinType.EVMOS;
            case 20009001: return CoinType.NATIVEEVMOS;
            case 10001285: return CoinType.MOONRIVER;
            case 10001284: return CoinType.MOONBEAM;
            case 10002222: return CoinType.KAVAEVM;
            case 10008217: return CoinType.KLAYTN;
            case 485: return CoinType.FREECASH;
            case 1000052: return CoinType.COINEXSMARTCHAIN;
            case 57: return CoinType.SYSCOIN;
            case 236: return CoinType.BITCOINSV;
            case 20000330: return CoinType.TERRA;
            case 10000330: return CoinType.TERRACLASSIC;
            case 140: return CoinType.LBRYCREDITS;
            case 10000118: return CoinType.IRISNET;
            case 503: return CoinType.CONFLUXNETWORK;
            case 309: return CoinType.NERVOSCKB;
            case 429: return CoinType.ERGO;
            case 121: return CoinType.HORIZEN;
            case 5353: return CoinType.HANDSHAKE;
            case 12586: return CoinType.MINA;
            case 626: return CoinType.KADENA;
            case 18000: return CoinType.METER;
            case 996: return CoinType.OKXCHAIN;
            case 396: return CoinType.EVERSCALE;
            case 637: return CoinType.APTOS;
            case 8453: return CoinType.BASE;
            case 111111: return CoinType.KASPA;
            default: return null;
        }
    }

    public native Blockchain blockchain();
    public native Purpose purpose();
    public native Curve curve();
    public native HDVersion xpubVersion();
    public native HDVersion xprvVersion();
    public native HRP hrp();
    public native byte p2pkhPrefix();
    public native byte p2shPrefix();
    public native byte staticPrefix();
    public native String chainId();
    public native int slip44Id();
    public native PublicKeyType publicKeyType();
    public native boolean validate(String address);
    public native String derivationPath();
    public native String derivationPathWithDerivation(Derivation derivation);
    public native String deriveAddress(PrivateKey privateKey);
    public native String deriveAddressFromPublicKey(PublicKey publicKey);
}
