// Copyright © 2017-2023 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Data.h"
#include "KaspaBech32.h"

#include <array>

// Bech32 address encoding

using namespace TW;

namespace TW::KaspaBech32 {

namespace {

/** The Bech32 character set for encoding. */
const char* charset = "qpzry9x8gf2tvdw0s3jn54khce6mua7l";
const static int checksumLength = 8;

/** The Bech32 character set for decoding. */
constexpr std::array<int8_t, 128> charset_rev = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, 15, -1, 10, 17, 21, 20, 26, 30, 7, 5, -1, -1, -1, -1, -1, -1, -1, 29,
    -1, 24, 13, 25, 9, 8, 23, -1, 18, 22, 31, 27, 19, -1, 1, 0, 3, 16, 11, 28, 12, 14,
    6, 4, 2, -1, -1, -1, -1, -1, -1, 29, -1, 24, 13, 25, 9, 8, 23, -1, 18, 22, 31, 27,
    19, -1, 1, 0, 3, 16, 11, 28, 12, 14, 6, 4, 2, -1, -1, -1, -1, -1};

/** Find the polynomial with value coefficients mod the generator as 30-bit. */
uint64_t polymod(const Data& values) {
    uint64_t c = 1;
    for(size_t i = 0; i < values.size(); i++) {
        uint64_t datum = values[i];
        uint8_t c0 = uint8_t(c >> 35);
        c = ((c & 0x7FFFFFFFFULL) << 5) ^ datum;
        if ((c0 & 0x01) != 0) c ^= 0x98f2bc8e61UL;
        if ((c0 & 0x02) != 0) c ^= 0x79b76d99e2UL;
        if ((c0 & 0x04) != 0) c ^= 0xf33e5fb3c4UL;
        if ((c0 & 0x08) != 0) c ^= 0xae2eabe2a8UL;
        if ((c0 & 0x10) != 0) c ^= 0x1e4f43e470UL;
    }
    return c ^ 1;
}

/** Convert to lower case. */
unsigned char lc(unsigned char c) {
    return (c >= 'A' && c <= 'Z') ? (c - 'A') + 'a' : c;
}

/** Expand a HRP for use in checksum computation. */
Data expand_hrp(const std::string& hrp) {
    Data ret;
    ret.resize(hrp.size() + 1);
    for (size_t i = 0; i < hrp.size(); ++i) {
        unsigned char c = hrp[i];
        ret[i] = c & 0x1f;
    }
    ret[hrp.size()] = 0;
    ret[hrp.size() + 1] = 0;
    return ret;
}

/** Verify a checksum. */
ChecksumVariant verify_checksum(const std::string& hrp, const Data& values) {
    Data enc = expand_hrp(hrp);
    append(enc, values);
    auto poly = polymod(enc);
    if (poly == 0) {
        return ChecksumVariant::Bech32;
    };
    return ChecksumVariant::None;
}

/** Create a checksum. */
Data create_checksum(const std::string& hrp, const Data& values) {
    Data enc = expand_hrp(hrp);
    append(enc, values);
    enc.resize(enc.size() + checksumLength);
    uint64_t mod = polymod(enc);
    Data ret;
    ret.resize(8);
    for (size_t i = 0; i < 8; i++) {
        ret[i] = (mod >> (5 * (checksumLength - i - 1))) & 31;
    }
    return ret;
}

} // namespace

/** Encode a Bech32 string. */
std::string encode(const std::string& hrp, const Data& values, ChecksumVariant variant) {
    Data checksum = create_checksum(hrp, values);
    Data combined = values;
    append(combined, checksum);
    std::string ret = hrp + ':';
    ret.reserve(ret.size() + combined.size());
    for (const auto& value : combined) {
        ret += charset[value];
    }
    return ret;
}

/** Decode a Bech32 string. */
std::tuple<std::string, Data, ChecksumVariant> decode(const std::string& str) {
    if (str.length() > 90 || str.length() < 2) {
        // too long or too short
        return std::make_tuple(std::string(), Data(), None);
    }
    bool lower = false, upper = false;
    bool ok = true;
    for (size_t i = 0; ok && i < str.size(); ++i) {
        unsigned char c = str[i];
        if (c < 33 || c > 126) {
            ok = false;
        }
        if (c >= 'a' && c <= 'z') {
            lower = true;
        }
        if (c >= 'A' && c <= 'Z') {
            upper = true;
        }
    }
    if (lower && upper) {
        ok = false;
    }
    size_t pos = str.rfind(':');
    if (ok && pos != std::string::npos && pos >= 1 && pos + 7 <= str.size()) {
        Data values;
        values.resize(str.size() - 1 - pos);
        for (size_t i = 0; i < str.size() - 1 - pos; ++i) {
            unsigned char c = str[i + pos + 1];
            if (charset_rev[c] == -1) {
                ok = false;
            }
            values[i] = charset_rev[c];
        }
        if (ok) {
            std::string hrp;
            for (size_t i = 0; i < pos; ++i) {
                hrp += lc(str[i]);
            }
            auto variant = verify_checksum(hrp, values);
            if (variant != None) {
                return std::make_tuple(hrp, Data(values.begin(), values.end() - checksumLength), variant);
            }
        }
    }
    return std::make_tuple(std::string(), Data(), None);
}

} // namespace TW::Bech32

