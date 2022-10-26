// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <utility>

#include "../Data.h"
#include "Type.h"
#include "CKBConstant.h"

namespace TW::NervosCKB {

    class Script {

    public:

        /// The interpretation of code hash when looking for matched dep cells.
        byte hashType = SCRIPT_DATA;

        /// 32 bytes, The hash of ELF formatted RISC-V binary that contains a CKB script.
        H256 codeHash;

        /// The argument as the script input.
        Data args;

        /// Initializes an empty script.
        Script() = default;

        /// Initializes a script with args and codeHash and hashType
        Script(H256 codeHash, Data args, byte hashType)
                : hashType(hashType), codeHash(std::move(codeHash)), args(std::move(args)) {}

        /// Whether the script is empty.
        [[nodiscard]] bool empty() const {
            return args.empty() && codeHash.empty();
        }

        /// Returns the script's script hash.
        [[nodiscard]] Data hash() const;

        /// Builds a appropriate lock script for the given
        /// address.
        static Script secp256k1LockScript(const std::string &address);

        /// Builds a appropriate lock script for the given
        /// address.
        static Script parseLockScript(const std::string &address);
    };

} // namespace TW::NervosCKB

/// Wrapper for C interface.
struct TWNervosCKBScript {
    TW::NervosCKB::Script impl;
};
