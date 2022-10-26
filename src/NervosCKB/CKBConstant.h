// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

namespace TW::NervosCKB {


    /// script hash type of DATA
    static const byte SCRIPT_DATA = 0x0;

    /// script hash type of TYPE
    static const byte SCRIPT_TYPE = 0x1;

    /// script hash type of DATA1
    static const byte SCRIPT_DATA1 = 0x2;



    /// short version for locks with popular code_hash
    static const byte TYPE_SHORT = 0x1;

    /// full version with hash_type = "Data"
    static const byte TYPE_FULL_DATA = 0x2;

    /// full version with hash_type = "Type"
    static const byte TYPE_FULL_TYPE = 0x4;

    /// full version with bech32m
    static const byte TYPE_FULL_WITH_BECH32M = 0x0;




    /// code hash type flag of blake160
    static const byte CODE_HASH_IDX_BLAKE160 = 0x0;

    /// code hash type flag of multisig
    static const byte CODE_HASH_IDX_MULTISIG = 0x1;

    /// code hash type flag of anyone can pay
    static const byte CODE_HASH_IDX_ANYONE_CAN_PAY = 0x2;





    /// code hash of blake160
    static const H256 SECP_BLAKE160_CODE_HASH = {0x9b, 0xd7, 0xe0, 0x6f,
                                                 0x3e, 0xcf, 0x4b, 0xe0,
                                                 0xf2, 0xfc, 0xd2, 0x18,
                                                 0x8b, 0x23, 0xf1, 0xb9,
                                                 0xfc, 0xc8, 0x8e, 0x5d,
                                                 0x4b, 0x65, 0xa8, 0x63,
                                                 0x7b, 0x17, 0x72, 0x3b,
                                                 0xbd, 0xa3, 0xcc, 0xe8};
    /// code hash of multisig
    static const H256 MULTISIG_CODE_HASH =      {0x5c, 0x50, 0x69, 0xeb,
                                                 0x08, 0x57, 0xef, 0xc6,
                                                 0x5e, 0x1b, 0xca, 0x0c,
                                                 0x07, 0xdf, 0x34, 0xc3,
                                                 0x16, 0x63, 0xb3, 0x62,
                                                 0x2f, 0xd3, 0x87, 0x6c,
                                                 0x87, 0x63, 0x20, 0xfc,
                                                 0x96, 0x34, 0xe2, 0xa8};

    /// code hash of anyone can pay
    static const H256 ACP_MAINNET_CODE_HASH =   {0xd3, 0x69, 0x59, 0x7f,
                                                 0xf4, 0x7f, 0x29, 0xfb,
                                                 0xc0, 0xd4, 0x7d, 0x2e,
                                                 0x37, 0x75, 0x37, 0x0d,
                                                 0x12, 0x50, 0xb8, 0x51,
                                                 0x40, 0xc6, 0x70, 0xe4,
                                                 0x71, 0x8a, 0xf7, 0x12,
                                                 0x98, 0x3a, 0x23, 0x54};

} // TW::NervosCKB namespace
