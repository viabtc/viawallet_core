// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "ConfluxBase32.h"
#include "../Base32.h"

using namespace TW;
using namespace TW::ConfluxNetwork;

const char *STANDARD_CHARSET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
const std::string CONFLUX_CHARSET_STR = "abcdefghjkmnprstuvwxyz0123456789";
const std::string STANDARD_CHARSET_STR = std::string(STANDARD_CHARSET);
const Data CHECKSUM_TEMPLATE = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

uint64_t polyMod(const Data& data) {
    uint64_t c = 1L;
    for(size_t i = 0; i < data.size(); i++) {
        uint8_t datum = data[i];
        uint8_t c0 = uint8_t(c >> 35);
        c = ((c & 0x7FFFFFFFFULL) << 5) ^ datum;
        if ((c0 & 0x01) != 0) c ^= 0x98f2bc8e61ULL;
        if ((c0 & 0x02) != 0) c ^= 0x79b76d99e2ULL;
        if ((c0 & 0x04) != 0) c ^= 0xf33e5fb3c4ULL;
        if ((c0 & 0x08) != 0) c ^= 0xae2eabe2a8ULL;
        if ((c0 & 0x10) != 0) c ^= 0x1e4f43e470ULL;
    }
    return c ^ 1;
}

Data decodeWords(const std::string& base32Words) {
    if (!ConfluxBase32::isValid(base32Words)) {
        return {};
    }

    Data result;
    for (size_t i = 0; i < base32Words.size(); i++) {
        uint8_t num = uint8_t(CONFLUX_CHARSET_STR.find(base32Words[i]));
        result.push_back(num);
    }
    return result;
}

std::string toStandard(const std::string& base32Str) {
    std::string result;
    for (size_t i = 0; i < base32Str.size(); i++) {
        auto ch = base32Str[i];
        auto index = CONFLUX_CHARSET_STR.find(ch);
        result.push_back(STANDARD_CHARSET_STR[index]);
    }
    return result;
}

std::string fromStandard(const std::string& standardBase32Str) {
    std::string result;
    for (size_t i = 0; i < standardBase32Str.size(); i++) {
        auto ch = standardBase32Str[i];
        auto index = STANDARD_CHARSET_STR.find(ch);
        result.push_back(CONFLUX_CHARSET_STR[index]);
    }
    return result;
}

Data prefixToWords(const std::string& hrp) {
    auto result = data(hrp);
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] = result[i] & 0x1f;
    }
    return result;
}

Data checksumBytes(uint64_t data) {
    Data result;
    result.push_back((data >> 32) & 0xff);
    result.push_back((data >> 24) & 0xff);
    result.push_back((data >> 16) & 0xff);
    result.push_back((data >> 8) & 0xff);
    result.push_back((data) & 0xff);

    return result;
}

std::string ConfluxBase32::createCheckSum(const std::string& chainPrefix, const std::string& payload) {
    const Data& prefixBuf = prefixToWords(chainPrefix);
    const Data& payloadBuf = decodeWords(payload);

    Data polyModParam;
    std::copy(std::begin(prefixBuf), std::end(prefixBuf), std::back_inserter(polyModParam));
    polyModParam.push_back(0x00);
    std::copy(std::begin(payloadBuf), std::end(payloadBuf), std::back_inserter(polyModParam));
    std::copy(std::begin(CHECKSUM_TEMPLATE), std::end(CHECKSUM_TEMPLATE), std::back_inserter(polyModParam));

    uint64_t n = polyMod(polyModParam);

    return ConfluxBase32::encode(checksumBytes(n));
}

std::string ConfluxBase32::encode(const Data& buffer) {
    if (buffer.empty()) {
        return "";
    }

    auto encode = Base32::encode(buffer, STANDARD_CHARSET);
    return fromStandard(encode);
}

bool ConfluxBase32::isValid(const std::string& base32Str) {
    if (base32Str.empty()) return false;
    for (size_t i = 0; i < base32Str.length(); i++) {
        if(CONFLUX_CHARSET_STR.find(base32Str[i]) == -1) {
            return false;
        }
    }
    return true;
}

Data ConfluxBase32::decode(const std::string& base32Str) {
    if (!isValid(base32Str)) {
        throw std::invalid_argument("include invalid char.");
    }
    auto standard = toStandard(base32Str);

    Data out;
    bool result = Base32::decode(standard, out, STANDARD_CHARSET);
    if (!result) {
        throw std::invalid_argument("Base32 decode failed.");
    }

    return out;
}
