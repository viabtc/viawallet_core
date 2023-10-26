// Copyright © 2017-2021 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE from \registry.json, changes made here WILL BE LOST.
//

#pragma once

#include "TWBase.h"

TW_EXTERN_C_BEGIN

///  Registered human-readable parts for BIP-0173
///
/// - SeeAlso: https://github.com/satoshilabs/slips/blob/master/slip-0173.md
TW_EXPORT_ENUM()
enum TWHRP {
    TWHRPUnknown     /* "" */,
    TWHRPBitcoin     /* "bc" */,
    TWHRPLitecoin     /* "ltc" */,
    TWHRPViacoin     /* "via" */,
    TWHRPGroestlcoin     /* "grs" */,
    TWHRPDigiByte     /* "dgb" */,
    TWHRPMonacoin     /* "mona" */,
    TWHRPSyscoin     /* "sys" */,
    TWHRPCosmos     /* "cosmos" */,
    TWHRPLBRYCredits     /* "lbc" */,
    TWHRPBitcoinCash     /* "bitcoincash" */,
    TWHRPBitcoinGold     /* "btg" */,
    TWHRPIoTeX     /* "io" */,
    TWHRPNervosCKB     /* "ckb" */,
    TWHRPZilliqa     /* "zil" */,
    TWHRPCryptoOrg     /* "cro" */,
    TWHRPKava     /* "kava" */,
    TWHRPOasis     /* "oasis" */,
    TWHRPBluzelle     /* "bluzelle" */,
    TWHRPBandChain     /* "band" */,
    TWHRPElrond     /* "erd" */,
    TWHRPBinance     /* "bnb" */,
    TWHRPTHORChain     /* "thor" */,
    TWHRPHarmony     /* "one" */,
    TWHRPCardano     /* "addr" */,
    TWHRPQtum     /* "qc" */,
    TWHRPHandshake     /* "hs" */,
    TWHRPKaspa     /* "kaspa" */,
    TWHRPIRISnet     /* "iaa" */,
    TWHRPTerraClassic     /* "terra" */,
    TWHRPOsmosis     /* "osmo" */,
    TWHRPECash     /* "ecash" */,
    TWHRPTerra     /* "terra" */,
    TWHRPNativeEvmos     /* "evmos" */,
};

static const char *_Nonnull HRP_BITCOIN = "bc";
static const char *_Nonnull HRP_LITECOIN = "ltc";
static const char *_Nonnull HRP_VIACOIN = "via";
static const char *_Nonnull HRP_GROESTLCOIN = "grs";
static const char *_Nonnull HRP_DIGIBYTE = "dgb";
static const char *_Nonnull HRP_MONACOIN = "mona";
static const char *_Nonnull HRP_SYSCOIN = "sys";
static const char *_Nonnull HRP_COSMOS = "cosmos";
static const char *_Nonnull HRP_LBRY = "lbc";
static const char *_Nonnull HRP_BITCOINCASH = "bitcoincash";
static const char *_Nonnull HRP_BITCOINGOLD = "btg";
static const char *_Nonnull HRP_IOTEX = "io";
static const char *_Nonnull HRP_NERVOSCKB = "ckb";
static const char *_Nonnull HRP_ZILLIQA = "zil";
static const char *_Nonnull HRP_CRYPTOORG = "cro";
static const char *_Nonnull HRP_KAVA = "kava";
static const char *_Nonnull HRP_OASIS = "oasis";
static const char *_Nonnull HRP_BLUZELLE = "bluzelle";
static const char *_Nonnull HRP_BAND = "band";
static const char *_Nonnull HRP_ELROND = "erd";
static const char *_Nonnull HRP_BINANCE = "bnb";
static const char *_Nonnull HRP_THORCHAIN = "thor";
static const char *_Nonnull HRP_HARMONY = "one";
static const char *_Nonnull HRP_CARDANO = "addr";
static const char *_Nonnull HRP_QTUM = "qc";
static const char *_Nonnull HRP_HANDSHAKE = "hs";
static const char *_Nonnull HRP_KASPA = "kaspa";
static const char *_Nonnull HRP_IRIS = "iaa";
static const char *_Nonnull HRP_TERRACLASSIC = "terra";
static const char *_Nonnull HRP_OSMOSIS = "osmo";
static const char *_Nonnull HRP_ECASH = "ecash";
static const char *_Nonnull HRP_TERRA = "terra";
static const char *_Nonnull HRP_NATIVEEVMOS = "evmos";

const char *_Nullable stringForHRP(enum TWHRP hrp);
enum TWHRP hrpForString(const char *_Nonnull string);

TW_EXTERN_C_END
