// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <TrustWalletCore/TWCoinType.h>
#include <TrustWalletCore/TWDerivation.h>

#include "Data.h"
#include "PublicKey.h"
#include "PrivateKey.h"
#include "proto/Common.pb.h"
#include "uint256.h"

#include <string>
#include <vector>
#include <utility>
#include <variant>

namespace TW {

typedef std::vector<std::pair<Data, Data>> HashPubkeyList;

struct Base58Prefix {
    TW::byte p2pkh;
    TW::byte p2sh;
};

using Bech32Prefix = const char *;
using SS58Prefix = uint32_t;

/// Declare a dummy prefix to notify the entry to derive a delegated address.
struct DelegatedPrefix {};

using PrefixVariant = std::variant<Base58Prefix, Bech32Prefix, SS58Prefix, DelegatedPrefix, std::monostate>;

/// Interface for coin-specific entry, used to dispatch calls to coins
/// Implement this for all coins.
class CoinEntry {
public:
    virtual ~CoinEntry() noexcept = default;
    virtual bool validateAddress(TWCoinType coin, const std::string& address, TW::byte p2pkh, TW::byte p2sh, const char* hrp) const = 0;
    // normalizeAddress is optional, it may leave this default, no-change implementation
    virtual std::string normalizeAddress([[maybe_unused]] TWCoinType coin, const std::string& address) const { return address; }
    // Address derivation, default derivation
    virtual std::string deriveAddress(TWCoinType coin, const PublicKey& publicKey, TW::byte p2pkh, const char* hrp) const = 0;
    // Address derivation, by default invoking default
    virtual std::string deriveAddress(TWCoinType coin, [[maybe_unused]] TWDerivation derivation, const PublicKey& publicKey, TW::byte p2pkh, const char* hrp) const {
        return deriveAddress(coin, publicKey, p2pkh, hrp);
    }
    // Return the binary representation of a string address, used by AnyAddress
    // It is optional, if not defined, 'AnyAddress' interface will not support this coin.
    virtual Data addressToData([[maybe_unused]] TWCoinType coin, [[maybe_unused]] const std::string& address) const { return {}; }
    // Signing
    virtual void sign(TWCoinType coin, const Data& dataIn, Data& dataOut) const = 0;
    virtual bool supportsJSONSigning() const { return false; }
    // It is optional, Signing JSON input with private key
    virtual std::string signJSON([[maybe_unused]] TWCoinType coin, [[maybe_unused]] const std::string& json, [[maybe_unused]] const Data& key) const { return ""; }
    // Planning, for UTXO chains, in preparation for signing
    // It is optional, only UTXO chains need it, default impl. leaves empty result.
    virtual void plan([[maybe_unused]] TWCoinType coin, [[maybe_unused]] const Data& dataIn, [[maybe_unused]] Data& dataOut) const { }

    // Optional method for obtaining hash(es) for signing, needed for external signing.
    // It will return a proto object named `PreSigningOutput` which will include hash.
    // We provide a default `PreSigningOutput` in TransactionCompiler.proto.
    // For some special coins, such as bitcoin, we will create a custom `PreSigningOutput` object in its proto file.
    virtual Data preImageHashes([[maybe_unused]] TWCoinType coin, [[maybe_unused]] const Data& txInputData) const { return {}; }
    // Optional method for compiling a transaction with externally-supplied signatures & pubkeys.
    virtual void compile([[maybe_unused]] TWCoinType coin, [[maybe_unused]] const Data& txInputData, [[maybe_unused]] const std::vector<Data>& signatures, [[maybe_unused]] const std::vector<PublicKey>& publicKeys, [[maybe_unused]] Data& dataOut) const {}
    // Optional helper to prepare a SigningInput from simple parameters.
    // Not suitable for UTXO chains. Some parameters, like chain-specific fee/gas paraemters, may need to be set in the SigningInput.
    virtual Data buildTransactionInput([[maybe_unused]] TWCoinType coinType, [[maybe_unused]] const std::string& from, [[maybe_unused]] const std::string& to, [[maybe_unused]] const uint256_t& amount, [[maybe_unused]] const std::string& asset, [[maybe_unused]] const std::string& memo, [[maybe_unused]] const std::string& chainId) const { return Data(); }
};

// In each coin's Entry.cpp the specific types of the coin are used, this template enforces the Signer implement:
// static Proto::SigningOutput sign(const Proto::SigningInput& input) noexcept;
// Note: use output parameter to avoid unneeded copies
template <typename Signer, typename Input>
void signTemplate(const Data& dataIn, Data& dataOut) {
    auto input = Input();
    input.ParseFromArray(dataIn.data(), (int)dataIn.size());
    auto serializedOut = Signer::sign(input).SerializeAsString();
    dataOut.insert(dataOut.end(), serializedOut.begin(), serializedOut.end());
}

// Note: use output parameter to avoid unneeded copies
template <typename Planner, typename Input>
void planTemplate(const Data& dataIn, Data& dataOut) {
    auto input = Input();
    input.ParseFromArray(dataIn.data(), (int)dataIn.size());
    auto serializedOut = Planner::plan(input).SerializeAsString();
    dataOut.insert(dataOut.end(), serializedOut.begin(), serializedOut.end());
}

// This template will be used for preImageHashes and compile in each coin's Entry.cpp.
// It is a helper function to simplify exception handle.
template <typename Input, typename Output, typename Func>
Data txCompilerTemplate(const Data& dataIn, Func&& fnHandler) {
    auto input = Input();
    auto output = Output();
    if (!input.ParseFromArray(dataIn.data(), (int)dataIn.size())) {
        output.set_error(Common::Proto::Error_input_parse);
        output.set_error_message("failed to parse input data");
        return TW::data(output.SerializeAsString());;
    }

    try {
        // each coin function handler
        fnHandler(input, output);
    } catch (const std::exception& e) {
        output.set_error(Common::Proto::Error_internal);
        output.set_error_message(e.what());
    }
    return TW::data(output.SerializeAsString());
}

template <typename Input, typename Output, typename Func>
Data txCompilerSingleTemplate(const Data& dataIn, const std::vector<Data>& signatures, const std::vector<PublicKey>& publicKeys, Func&& fnHandler) {
    auto input = Input();
    auto output = Output();
    if (!input.ParseFromArray(dataIn.data(), (int)dataIn.size())) {
        output.set_error(Common::Proto::Error_input_parse);
        output.set_error_message("failed to parse input data");
        return TW::data(output.SerializeAsString());
    }

    if (signatures.empty() || publicKeys.empty()) {
        output.set_error(Common::Proto::Error_invalid_params);
        output.set_error_message("empty signatures or publickeys");
        return TW::data(output.SerializeAsString());
    }
    if (signatures.size() != 1 || publicKeys.size() != 1) {
        output.set_error(Common::Proto::Error_no_support_n2n);
        output.set_error_message("signatures and publickeys size can only be one");
        return TW::data(output.SerializeAsString());
    }

    try {
        // each coin function handler
        fnHandler(input, output, signatures[0], publicKeys[0]);
    } catch (const std::exception& e) {
        output.set_error(Common::Proto::Error_internal);
        output.set_error_message(e.what());
    }
    return TW::data(output.SerializeAsString());
}

} // namespace TW
