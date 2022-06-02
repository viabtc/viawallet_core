// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrezorCrypto/mina/mina.h>
#include "Signer.h"
#include "Address.h"
#include "HexCoding.h"
#include <uint1024.h>


using namespace TW;
using namespace TW::Mina;


inline uint1024_t load1024(const Data& data) {
    using boost::multiprecision::cpp_int;
    if (data.empty()) {
        return uint1024_t(0);
    }
    uint1024_t result;
    import_bits(result, data.begin(), data.end());
    return result;
}

Proto::SigningOutput Signer::sign(const Proto::SigningInput &input) noexcept {
    auto protoOutput = Proto::SigningOutput();

    if (input.private_key().empty()) {
        protoOutput.set_error("Missing private key.");
        return protoOutput;
    }

    if (input.from().empty()) {
        protoOutput.set_error("Missing sender.");
        return protoOutput;
    }

    if (input.to().empty()) {
        protoOutput.set_error("Missing receiver.");
        return protoOutput;
    }

    const auto& memo = input.memo();
    if (memo.length() > 32) {
        protoOutput.set_error("Memo cannot exceed 32 characters.");
        return protoOutput;
    }

    auto privateKey = PrivateKey(input.private_key());
    const auto& sender = input.from();
    const auto& receiver = input.to();
    auto amount = input.amount();
    auto fee = input.fee();
    auto nonce = input.nonce();
    auto validUntil = input.valid_until();
    auto delegation = input.delegation();

    char signature[129];
    bool valid = sign_transaction(signature,
                                  sizeof(signature),
                                  hex(privateKey.bytes).c_str(),
                                  receiver.c_str(),
                                  amount,
                                  fee,
                                  nonce,
                                  (uint32_t)validUntil,
                                  memo.c_str(),
                                  delegation);

    if (!valid) {
        protoOutput.set_error("Mina Signing failed.");
        return protoOutput;
    }

    auto sigData = parse_hex(signature, signature + 128);

    if (sigData.size() != 64) {
        protoOutput.set_error("Mina Signing data error.");
        return protoOutput;
    }
    
    auto fieldData = TW::subData(sigData, 0,32);
    auto scalarData = TW::subData(sigData, 32, 32);

    uint1024_t field = load1024(fieldData);
    uint1024_t scalar = load1024(scalarData);
    
    auto fieldStr = toString(field);
    auto scalarStr = toString(scalar);

    auto json = transactionJSON(fieldStr, scalarStr, receiver, sender, fee, amount,
                                                 nonce, memo, validUntil);
    protoOutput.set_json(json.dump());
    protoOutput.set_signature(signature);
    return protoOutput;
}

nlohmann::json Signer::transactionJSON(const std::string& field, const std::string& scalar,
                                       const std::string& to, const std::string& from,
                                       uint64_t fee, uint64_t amount,
                                       uint32_t nonce, const std::string& memo,
                                       uint64_t validUntil) {

    return {
        {"signature", {
                          {"field", field},
                          {"scalar", scalar}
                      }
        },
        {"input", {
                      {"to", to},
                      {"from", from},
                      {"fee", fee},
                      {"amount", amount},
                      {"nonce", nonce},
                      {"memo", memo},
                      {"token", "1"},
                      {"validUntil", validUntil}
                  }
        }
    };
}
