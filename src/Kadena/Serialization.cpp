// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Serialization.h"

#include "Base64.h"
#include "PrivateKey.h"
#include "HexCoding.h"

using namespace TW;
using namespace TW::Kadena;

using json = nlohmann::json;
using string = std::string;


std::string transferCode(const std::string& sender, const std::string& receiver,
                         const std::string& amount) {
    return "(coin.transfer \"" + sender + "\" \"" + receiver + "\" " + amount + ")";
}

std::string transferCreateCode(const std::string& sender, const std::string& receiver,
                               const std::string& amount) {
    return "(coin.transfer-create \"" + sender + "\" \"" + receiver +
           "\" (read-keyset \"receiver-guard\") " + amount + ")";
}

std::string transferCrossChainCode(const std::string& sender, const std::string& receiver,
                                   const std::string& amount, const std::string& targetChainId) {
    return "(coin.transfer-crosschain \"" + sender + "\" \"" + receiver +
           "\" (read-keyset \"receiver-guard\") \"" + targetChainId + "\" " + amount + ")";
}

std::string chooseCode(const Proto::SigningInput& input) {
    if (input.chainid() == input.targetchainid()) {

        return transferCreateCode(input.sender(), input.receiver(), input.amount());
    } else {
        return transferCrossChainCode(input.sender(), input.receiver(), input.amount(), input.targetchainid());
    }
}

json transferReceiverGuard(const Proto::SigningInput& input) {

    auto pubKeys = input.receiverpubkeys();
    json pubKeyJsonArray = json::array();
    for (const auto& pubKey : pubKeys) {
        pubKeyJsonArray.push_back(pubKey);
    }

    return {{"receiver-guard", { {"keys", pubKeyJsonArray}, {"pred", input.pred()}}}};
}

json payloadJSON(const json& transferReceiverGuard, const std::string& code) {
    return {{"exec", {{"data", transferReceiverGuard}, {"code", code}}}};
}

json transferClistJSON(const std::string& sender, const std::string& receiver,
                       const std::string& amount) {
    return {
        {{"name", "coin.TRANSFER"}, {"args", {sender, receiver, std::stod(amount)}}},
        {{"name", "coin.GAS"}, {"args", json::array()}}
    };
}

json transferCrossChainClistJSON(const std::string& sender,
                                 const std::string& receiver,
                                 const std::string& amount,
                                 const std::string& targetChain) {
    return {
        {{"name", "coin.TRANSFER_XCHAIN"}, {"args", {sender, receiver, std::stod(amount), targetChain}}},
        {{"name", "coin.GAS"}, {"args", json::array()}}
    };
}

json chooseCList(const Proto::SigningInput& input) {
    if (input.chainid() == input.targetchainid()) {
        return transferClistJSON(input.sender(), input.receiver(), input.amount());
    } else {
        return transferCrossChainClistJSON(input.sender(), input.receiver(), input.amount(), input.targetchainid());
    }
}

json signersJSON(const json& clist, const std::string& pubKey) {
    return {{{"clist", clist}, {"pubKey", pubKey}}};
}

json metaJSON(const Proto::SigningInput& input) {
    return {
        {"creationTime", input.creationtime()},
        {"ttl", input.ttl()},
        {"gasLimit", input.gaslimit()},
        {"chainId", input.chainid()},
        {"gasPrice", input.gasprice()},
        {"sender", input.sender()}
    };
}

json transactionJSON(const json& signers, const json& meta, const json& payload,
                     const std::string& nonce, const std::string& networkId) {
    return {
        {"signers", signers},
        {"meta", meta},
        {"payload", payload},
        {"nonce", nonce},
        {"networkId", networkId}
    };
}

json Kadena::transactionJSON(const Proto::SigningInput& input) {

    auto privateKey = PrivateKey(input.privatekey());
    auto publicKey = privateKey.getPublicKey(TWPublicKeyTypeKadena);
    auto pubKeyHex = hex(publicKey.bytes);

    auto networkId = input.networkid();
    auto nonce = input.nonce();
    auto metaJson = metaJSON(input);

    auto clistJson = chooseCList(input);
    auto signersJson = signersJSON(clistJson, pubKeyHex);

    auto receiverGuardJson = transferReceiverGuard(input);;
    auto code = chooseCode(input);
    auto payloadJson = payloadJSON(receiverGuardJson, code);

    return {
        {"networkId", networkId},
        {"payload", payloadJson},
        {"signers", signersJson},
        {"meta", metaJson},
        {"nonce", nonce}
    };
}

json Kadena::signedTransactionJSON(const std::string& cmd, const std::string& signature,
                          const std::string& hash) {
    return {{"cmds", {{{"hash", hash}, {"sigs", {{{"sig", signature}}}}, {"cmd", cmd}}}}};
}
