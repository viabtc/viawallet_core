// Copyright © 2017-2021 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE from \registry.json, changes made here WILL BE LOST.
//

#include <TrustWalletCore/TWHRP.h>

#include <cstring>

const char* stringForHRP(enum TWHRP hrp) {
    switch (hrp) {
    case TWHRPBitcoin:
        return HRP_BITCOIN;
    case TWHRPLitecoin:
        return HRP_LITECOIN;
    case TWHRPViacoin:
        return HRP_VIACOIN;
    case TWHRPGroestlcoin:
        return HRP_GROESTLCOIN;
    case TWHRPDigiByte:
        return HRP_DIGIBYTE;
    case TWHRPMonacoin:
        return HRP_MONACOIN;
    case TWHRPSyscoin:
        return HRP_SYSCOIN;
    case TWHRPCosmos:
        return HRP_COSMOS;
    case TWHRPLBRYCredits:
        return HRP_LBRY;
    case TWHRPBitcoinCash:
        return HRP_BITCOINCASH;
    case TWHRPBitcoinGold:
        return HRP_BITCOINGOLD;
    case TWHRPIoTeX:
        return HRP_IOTEX;
    case TWHRPNervosCKB:
        return HRP_NERVOSCKB;
    case TWHRPZilliqa:
        return HRP_ZILLIQA;
    case TWHRPCryptoOrg:
        return HRP_CRYPTOORG;
    case TWHRPKava:
        return HRP_KAVA;
    case TWHRPOasis:
        return HRP_OASIS;
    case TWHRPBluzelle:
        return HRP_BLUZELLE;
    case TWHRPBandChain:
        return HRP_BAND;
    case TWHRPElrond:
        return HRP_ELROND;
    case TWHRPBinance:
        return HRP_BINANCE;
    case TWHRPTHORChain:
        return HRP_THORCHAIN;
    case TWHRPHarmony:
        return HRP_HARMONY;
    case TWHRPCardano:
        return HRP_CARDANO;
    case TWHRPQtum:
        return HRP_QTUM;
    case TWHRPHandshake:
        return HRP_HANDSHAKE;
    case TWHRPKaspa:
        return HRP_KASPA;
    case TWHRPIRISnet:
        return HRP_IRIS;
    case TWHRPTerraClassic:
        return HRP_TERRACLASSIC;
    case TWHRPOsmosis:
        return HRP_OSMOSIS;
    case TWHRPECash:
        return HRP_ECASH;
    case TWHRPTerra:
        return HRP_TERRA;
    case TWHRPNativeEvmos:
        return HRP_NATIVEEVMOS;
    default: return nullptr;
    }
}

enum TWHRP hrpForString(const char *_Nonnull string) {
    if (std::strcmp(string, HRP_BITCOIN) == 0) {
        return TWHRPBitcoin;
    } else if (std::strcmp(string, HRP_LITECOIN) == 0) {
        return TWHRPLitecoin;
    } else if (std::strcmp(string, HRP_VIACOIN) == 0) {
        return TWHRPViacoin;
    } else if (std::strcmp(string, HRP_GROESTLCOIN) == 0) {
        return TWHRPGroestlcoin;
    } else if (std::strcmp(string, HRP_DIGIBYTE) == 0) {
        return TWHRPDigiByte;
    } else if (std::strcmp(string, HRP_MONACOIN) == 0) {
        return TWHRPMonacoin;
    } else if (std::strcmp(string, HRP_SYSCOIN) == 0) {
        return TWHRPSyscoin;
    } else if (std::strcmp(string, HRP_COSMOS) == 0) {
        return TWHRPCosmos;
    } else if (std::strcmp(string, HRP_LBRY) == 0) {
        return TWHRPLBRYCredits;
    } else if (std::strcmp(string, HRP_BITCOINCASH) == 0) {
        return TWHRPBitcoinCash;
    } else if (std::strcmp(string, HRP_BITCOINGOLD) == 0) {
        return TWHRPBitcoinGold;
    } else if (std::strcmp(string, HRP_IOTEX) == 0) {
        return TWHRPIoTeX;
    } else if (std::strcmp(string, HRP_NERVOSCKB) == 0) {
        return TWHRPNervosCKB;
    } else if (std::strcmp(string, HRP_ZILLIQA) == 0) {
        return TWHRPZilliqa;
    } else if (std::strcmp(string, HRP_CRYPTOORG) == 0) {
        return TWHRPCryptoOrg;
    } else if (std::strcmp(string, HRP_KAVA) == 0) {
        return TWHRPKava;
    } else if (std::strcmp(string, HRP_OASIS) == 0) {
        return TWHRPOasis;
    } else if (std::strcmp(string, HRP_BLUZELLE) == 0) {
        return TWHRPBluzelle;
    } else if (std::strcmp(string, HRP_BAND) == 0) {
        return TWHRPBandChain;
    } else if (std::strcmp(string, HRP_ELROND) == 0) {
        return TWHRPElrond;
    } else if (std::strcmp(string, HRP_BINANCE) == 0) {
        return TWHRPBinance;
    } else if (std::strcmp(string, HRP_THORCHAIN) == 0) {
        return TWHRPTHORChain;
    } else if (std::strcmp(string, HRP_HARMONY) == 0) {
        return TWHRPHarmony;
    } else if (std::strcmp(string, HRP_CARDANO) == 0) {
        return TWHRPCardano;
    } else if (std::strcmp(string, HRP_QTUM) == 0) {
        return TWHRPQtum;
    } else if (std::strcmp(string, HRP_HANDSHAKE) == 0) {
        return TWHRPHandshake;
    } else if (std::strcmp(string, HRP_KASPA) == 0) {
        return TWHRPKaspa;
    } else if (std::strcmp(string, HRP_IRIS) == 0) {
        return TWHRPIRISnet;
    } else if (std::strcmp(string, HRP_TERRACLASSIC) == 0) {
        return TWHRPTerraClassic;
    } else if (std::strcmp(string, HRP_OSMOSIS) == 0) {
        return TWHRPOsmosis;
    } else if (std::strcmp(string, HRP_ECASH) == 0) {
        return TWHRPECash;
    } else if (std::strcmp(string, HRP_TERRA) == 0) {
        return TWHRPTerra;
    } else if (std::strcmp(string, HRP_NATIVEEVMOS) == 0) {
        return TWHRPNativeEvmos;
    } else {
        return TWHRPUnknown;
    }
}
