// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Address.h"
#include "ConfluxBase32.h"
#include "../HexCoding.h"

using namespace TW;
using namespace TW::ConfluxNetwork;

static const std::string hrp = "cfx";
static const std::string delimiter = ":";

bool Address::isValid(const std::string& string) {
    if (string.size() == 42 && string[0] == '0' && string[1] == 'x' && string[2] == '1') {
        return true;
    }

    try {
        decode(string);
        return true;
    } catch (...) {
        return false;
    }
}

Address::Address(const std::string& string) {
    if (!isValid(string)) {
        throw std::invalid_argument("Invalid address data");
    }

    if (string.size() == 42 && string[0] == '0' && string[1] == 'x' && string[2] == '1') {
        const auto data = parse_hex(string);
        std::copy(data.begin(), data.end(), bytes.begin());
    } else {
        const auto data = parse_hex(decode(string));
        std::copy(data.begin(), data.end(), bytes.begin());
    }

}

Address::Address(const PublicKey& publicKey) {
    if (publicKey.type != TWPublicKeyTypeSECP256k1Extended) {
        throw std::invalid_argument("ConfluxNetwork::Address needs an extended SECP256k1 public key.");
    }
    const auto data = publicKey.hash({}, static_cast<Hash::HasherSimpleType>(Hash::keccak256), true);
    std::copy(data.end() - Address::size, data.end(), bytes.begin());
}

std::string Address::string() const {
    const Address& address = *this;
    const auto addressString = hex(address.bytes);
    const auto hash = hex(Hash::keccak256(addressString));

    const auto minLen = std::min(addressString.size(), hash.size());
    const auto result = "0x1" + addressString.substr(1, minLen);
    return encode(result);
}

std::string Address::encode(const std::string& hexAddress) {
    if (hexAddress.empty()) {
        throw std::invalid_argument("hexAddress can not be empty.");
    }

    auto addrBytes = parse_hex(hexAddress);
    if (addrBytes.size() != 20) {
        throw std::invalid_argument("hex buffer length should be 20");
    }

    Data addrBytesWithVersion({0x00});
    addrBytesWithVersion.insert(addrBytesWithVersion.end(), addrBytes.begin(), addrBytes.end());
    auto payload = ConfluxBase32::encode(addrBytesWithVersion);
    auto checkSum = ConfluxBase32::createCheckSum(hrp, payload);

    auto result = hrp + delimiter + payload + checkSum;

    return result;
}

std::string Address::decode(const std::string& cfxAddress) {
    if (cfxAddress.empty() || cfxAddress.size() != 46 ||
        cfxAddress.find(hrp) != 0 || cfxAddress.find(delimiter) != 3) {
        throw std::invalid_argument("invalid argument cfxAddress.");
    }
    auto payloadWithSum = cfxAddress.substr(cfxAddress.find(delimiter)+1 , cfxAddress.size());
    if (!ConfluxBase32::isValid(payloadWithSum)) {
        throw std::invalid_argument("input contain invalid base32 chars.");
    }
    if (payloadWithSum.length() != 42) {
        throw std::invalid_argument("address payload should have 42 chars.");
    }

    auto sum = payloadWithSum.substr(payloadWithSum.size() - 8, payloadWithSum.size());
    auto payload = payloadWithSum.substr(0, payloadWithSum.size() - 8);

    auto checkSum = ConfluxBase32::createCheckSum(hrp, payload);
    if (sum.compare(checkSum) != 0) {
        throw std::invalid_argument("invalid checkSum.");
    }

    auto raw = ConfluxBase32::decode(payload);
    raw.erase(raw.begin(), raw.begin()+1);
    return hexEncoded(raw);
}
