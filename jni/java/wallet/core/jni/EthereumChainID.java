// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

package wallet.core.jni;


/// Chain identifiers for Ethereum-based blockchains, for convenience. Recommended to use the dynamic CoinType.ChainId() instead.
/// See also TWChainId.
public enum EthereumChainID {
    ETHEREUM (1),
    CLASSIC (61),
    POA (99),
    VECHAIN (74),
    CALLISTO (820),
    TOMOCHAIN (88),
    POLYGON (137),
    OKC (66),
    THUNDERTOKEN (108),
    HECO (128),
    GOCHAIN (60),
    BASE (8453),
    METER (82),
    CELO (42220),
    COINEXSMARTCHAIN (52),
    WANCHAIN (888),
    CRONOS (25),
    OPTIMISM (10),
    XDAI (100),
    SMARTBCH (10000),
    FANTOM (250),
    ZKSYNC (280),
    BOBA (288),
    KCC (321),
    METIS (1088),
    MOONBEAM (1284),
    MOONRIVER (1285),
    RONIN (2020),
    KAVAEVM (2222),
    KLAYTN (8217),
    AVALANCHEC (43114),
    EVMOS (9001),
    ARBITRUM (42161),
    SMARTCHAIN (56),
    AURORA (1313161554);

    private final int value;
    EthereumChainID(int value) {
        this.value = value;
    }
    public int value() { return value; }

    public static EthereumChainID createFromValue(int value) {
        switch (value) {
            case 1: return EthereumChainID.ETHEREUM;
            case 61: return EthereumChainID.CLASSIC;
            case 99: return EthereumChainID.POA;
            case 74: return EthereumChainID.VECHAIN;
            case 820: return EthereumChainID.CALLISTO;
            case 88: return EthereumChainID.TOMOCHAIN;
            case 137: return EthereumChainID.POLYGON;
            case 66: return EthereumChainID.OKC;
            case 108: return EthereumChainID.THUNDERTOKEN;
            case 128: return EthereumChainID.HECO;
            case 60: return EthereumChainID.GOCHAIN;
            case 8453: return EthereumChainID.BASE;
            case 82: return EthereumChainID.METER;
            case 42220: return EthereumChainID.CELO;
            case 52: return EthereumChainID.COINEXSMARTCHAIN;
            case 888: return EthereumChainID.WANCHAIN;
            case 25: return EthereumChainID.CRONOS;
            case 10: return EthereumChainID.OPTIMISM;
            case 100: return EthereumChainID.XDAI;
            case 10000: return EthereumChainID.SMARTBCH;
            case 250: return EthereumChainID.FANTOM;
            case 280: return EthereumChainID.ZKSYNC;
            case 288: return EthereumChainID.BOBA;
            case 321: return EthereumChainID.KCC;
            case 1088: return EthereumChainID.METIS;
            case 1284: return EthereumChainID.MOONBEAM;
            case 1285: return EthereumChainID.MOONRIVER;
            case 2020: return EthereumChainID.RONIN;
            case 2222: return EthereumChainID.KAVAEVM;
            case 8217: return EthereumChainID.KLAYTN;
            case 43114: return EthereumChainID.AVALANCHEC;
            case 9001: return EthereumChainID.EVMOS;
            case 42161: return EthereumChainID.ARBITRUM;
            case 56: return EthereumChainID.SMARTCHAIN;
            case 1313161554: return EthereumChainID.AURORA;
            default: return null;
        }
    }

}
