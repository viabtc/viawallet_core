// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Entry.h"

#include "Address.h"
#include "Signer.h"

using namespace TW::ConfluxNetwork;
using namespace std;

// Note: avoid business logic from here, rather just call into classes like Address, Signer, etc.

bool Entry::validateAddress(TWCoinType coin, const string& address, TW::byte, TW::byte, const char*) const {
    return Address::isValid(address);
}

string Entry::normalizeAddress(TWCoinType coin, const string& address) const {
    // normalized with EIP55 checksum
    return Address(address).string();
}

string Entry::deriveAddress(TWCoinType coin, const PublicKey& publicKey, TW::byte, const char*) const {
    return Address(publicKey).string();
}

void Entry::sign(TWCoinType coin, const TW::Data& dataIn, TW::Data& dataOut) const {
    signTemplate<Signer, Proto::SigningInput>(dataIn, dataOut);
}

void Entry::decodeRawTx(TWCoinType coin, const TW::Data& dataIn, TW::Data& dataOut) const {
    try {
        auto data = RLP::decodeRawTransaction(dataIn);
        dataOut.insert(dataOut.end(), data.begin(), data.end());
    } catch(...) {
        return;
    }
}
