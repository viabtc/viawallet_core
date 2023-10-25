// Copyright © 2017-2023 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Transation.h"
#include <array>
#include <cassert>
#include <utility>
#include <string>
#include "HexCoding.h"
#include "../Hash.h"
#include "Data.h"
#include "../BinaryCoding.h"
namespace TW::Kaspa {

Data Transaction::hashForSignatureWitness(int inputIndex, Data connectedScript, uint64_t prevValue) const {
    Data result;
    result.resize(0);
    Data versionData;
    Data scriptVersion;
    encode16LE(0, versionData);
    encode16LE(0, scriptVersion);

    append(result, versionData); // version
    append(result, hashPrevouts()); // prevScriptPublicKey
    append(result, hashSequence()); // sequence
    append(result, hashSigOpCounts()); // sigOpCount
    append(result, parse_hex(inputs[inputIndex].transactionHash)); // transactionHash
    Data outputIndexData;
    encode32LE(inputs[inputIndex].outputIndex, outputIndexData);
    append(result, outputIndexData);
    append(result, scriptVersion); // script version
    Data connectedScriptData;
    encode64LE(connectedScript.capacity(), connectedScriptData);
    append(result, connectedScriptData);
    append(result, connectedScript);
    Data prevData;
    encode64LE(prevValue, prevData);
    append(result, prevData);
    Data sequenceNumber;
    encode64LE(0, sequenceNumber);
    append(result, sequenceNumber); // sequence number
    append(result, 1); // sig op count
    Data hashOutputsData = hashOutputs();
    append(result, hashOutputsData); // outputsHash
    Data lockTime;
    encode64LE(0, lockTime);
    append(result, lockTime); // locktime
    append(result, subnetworkIdData()); // subnetworkId
    Data gas;
    encode64LE(0, gas);
    append(result, gas); // gas
    append(result, payloadData()); // payload hash
    append(result, 1); // hashType
    Data finalData;
    finalData.resize(0);
    auto signMethod = Hash::sha256(data("TransactionSigningHashECDSA")); // sign method ecdsa
    append(finalData, signMethod);
    append(finalData, blake2bDigest(result));
    return Hash::sha256(finalData);
}

Data Transaction::hashPrevouts() const {
    Data result;
    result.resize(0);
    for (const auto &input: inputs) {
        append(result, parse_hex(input.transactionHash));
        Data outputIndexData;
        encode32LE(input.outputIndex, outputIndexData);
        append(result, outputIndexData);
    }
    return blake2bDigest(result);
}

Data Transaction::hashSequence() const {
    Data result;
    result.resize(0);
    for (unsigned long i = 0; i< inputs.size(); i++) {
        Data value;
        encode64LE(0, value);
        append(result, value);
    }
    return blake2bDigest(result);
}

Data Transaction::hashSigOpCounts() const {
    Data result;
    result.resize(0);
    for (unsigned long i = 0; i<inputs.size(); i++) {
        append(result, 1);
    }
    return blake2bDigest(result);
}

Data Transaction::hashOutputs() const {
    Data result;
    result.resize(0);
    for (const auto &output: outputs) {
        Data amountData;
        Data scriptPublicKeyData;
        Data scriptPublicKeyBytesData;
        encode64LE(output.amount, amountData);
        encode16LE(output.scriptPublicKey.version, scriptPublicKeyData);
        append(result, amountData);
        append(result, scriptPublicKeyData);
        Data scriptPublicKeyBytes = parse_hex(output.scriptPublicKey.scriptPublicKey);
        encode64LE(scriptPublicKeyBytes.capacity(), scriptPublicKeyBytesData);
        append(result, scriptPublicKeyBytesData);
        append(result, scriptPublicKeyBytes);
    }
    return blake2bDigest(result);
}

Data Transaction::subnetworkIdData() const {
    Data result;
    result.resize(0);
    for (int i = 0; i < 20; i++) {
        append(result, 0);
    }
    return result;
}

Data Transaction::payloadData() const {
    Data result;
    result.resize(0);
    for (int i = 0; i < 32; i++) {
        append(result, 0);
    }
    return result;
}

Data Transaction::blake2bDigest(Data value) const {
    Data personal = data("TransactionSigningHash");
    auto blake2bHash =
        Hash::blake2bDigest(value, 32, personal);
    return blake2bHash;
}

}
