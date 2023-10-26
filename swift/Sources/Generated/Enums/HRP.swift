// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

///  Registered human-readable parts for BIP-0173
///
/// - SeeAlso: https://github.com/satoshilabs/slips/blob/master/slip-0173.md
public enum HRP: UInt32, CaseIterable, CustomStringConvertible  {
    case unknown = 0
    case bitcoin = 1
    case litecoin = 2
    case viacoin = 3
    case groestlcoin = 4
    case digiByte = 5
    case monacoin = 6
    case syscoin = 7
    case cosmos = 8
    case lbrycredits = 9
    case bitcoinCash = 10
    case bitcoinGold = 11
    case ioTeX = 12
    case nervosCKB = 13
    case zilliqa = 14
    case cryptoOrg = 15
    case kava = 16
    case oasis = 17
    case bluzelle = 18
    case bandChain = 19
    case elrond = 20
    case binance = 21
    case thorchain = 22
    case harmony = 23
    case cardano = 24
    case qtum = 25
    case handshake = 26
    case kaspa = 27
    case irisnet = 28
    case terraClassic = 29
    case osmosis = 30
    case ecash = 31
    case terra = 32
    case nativeEvmos = 33

    public var description: String {
        switch self {
        case .unknown: return ""
        case .bitcoin: return "bc"
        case .litecoin: return "ltc"
        case .viacoin: return "via"
        case .groestlcoin: return "grs"
        case .digiByte: return "dgb"
        case .monacoin: return "mona"
        case .syscoin: return "sys"
        case .cosmos: return "cosmos"
        case .lbrycredits: return "lbc"
        case .bitcoinCash: return "bitcoincash"
        case .bitcoinGold: return "btg"
        case .ioTeX: return "io"
        case .nervosCKB: return "ckb"
        case .zilliqa: return "zil"
        case .cryptoOrg: return "cro"
        case .kava: return "kava"
        case .oasis: return "oasis"
        case .bluzelle: return "bluzelle"
        case .bandChain: return "band"
        case .elrond: return "erd"
        case .binance: return "bnb"
        case .thorchain: return "thor"
        case .harmony: return "one"
        case .cardano: return "addr"
        case .qtum: return "qc"
        case .handshake: return "hs"
        case .kaspa: return "kaspa"
        case .irisnet: return "iaa"
        case .terraClassic: return "terra"
        case .osmosis: return "osmo"
        case .ecash: return "ecash"
        case .terra: return "terra"
        case .nativeEvmos: return "evmos"
        }
    }
}
