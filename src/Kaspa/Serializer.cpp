// Copyright © 2017-2023 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Serializer.h"

 namespace TW::Kaspa {
 static json previousOutpointJSON(const KaspaPreviousOutpoint &value) {
     json json;
     json["index"] = value.index;
     json["transactionId"] = value.transactionId;
     return json;
 }

 static json inputJSON(const KaspaInput &value) {
     json json;
     json["signatureScript"] = value.signatureScript;
     json["sequence"] = value.sequence;
     json["sigOpCount"] = value.sigOpCount;
     json["previousOutpoint"] = previousOutpointJSON(value.previousOutpoint);
     return json;
 }

 static json inputsJSON(const std::vector<KaspaInput> &values) {
     json json = json::array();
     for (auto &value : values) {
         json.push_back(inputJSON(value));
     }
     return json;
 }

 static json scriptPublicKeyJSON(const KaspaScriptPublicKey &value) {
     json json;
     json["script"] = value.scriptPublicKey;
     json["version"] = value.version;
     return json;
 }

 static json outputJSON(const KaspaOutput &value) {
     json json;
     json["amount"] = value.amount;
     json["scriptPublicKey"] = scriptPublicKeyJSON(value.scriptPublicKey);
     return json;
 }

 static json outputsJSON(const std::vector<KaspaOutput> &values) {
     json json = json::array();
     for (auto &v : values) {
         json.push_back(outputJSON(v));
     }
     return json;
 }

 json transactionJSON(const TransactionData& value) {
     json json;
     json["version"] = value.version;
     json["inputs"] = inputsJSON(value.inputs);
     json["outputs"] = outputsJSON(value.outputs);
     json["lockTime"] = value.lockTime;
     json["subnetworkId"] = value.subnetworkId;
     return json;
 }
 
 }
