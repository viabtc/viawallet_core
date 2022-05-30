// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Data.h"

#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>

namespace TW {

using int1024_t = boost::multiprecision::int1024_t;
using uint1024_t = boost::multiprecision::uint1024_t;

/// Loads a `uint1024_t` from a collection of bytes.
/// The rightmost bytes are taken from data
inline uint1024_t load(const Data& data) {
    using boost::multiprecision::cpp_int;
    if (data.empty()) {
        return uint1024_t(0);
    }
    uint1024_t result;
    import_bits(result, data.begin(), data.end());
    return result;
}

/// Loads a `uint1024_t` from a collection of bytes.
/// The leftmost offset bytes are skipped, and the next 32 bytes are taken.  At least 32 (+offset)
/// bytes are needed.
inline uint1024_t loadWithOffset(const Data& data, size_t offset) {
    using boost::multiprecision::cpp_int;
    if (data.empty() || (data.size() < (1024 / 8 + offset))) {
        // not enough bytes in data
        return uint1024_t(0);
    }
    uint1024_t result;
    import_bits(result, data.begin() + offset, data.begin() + offset + 1024 / 8);
    return result;
}

/// Loads a `uint1024_t` from Protobuf bytes (which are wrongly represented as
/// std::string).
inline uint1024_t load(const std::string& data) {
    using boost::multiprecision::cpp_int;
    if (data.empty()) {
        return uint1024_t(0);
    }
    uint1024_t result;
    import_bits(result, reinterpret_cast<const byte*>(data.data()),
                reinterpret_cast<const byte*>(data.data() + data.size()));
    return result;
}

/// Stores a `uint1024_t` as a collection of bytes.
inline Data store(const uint1024_t& v) {
    using boost::multiprecision::cpp_int;
    Data bytes;
    bytes.reserve(128);
    export_bits(v, std::back_inserter(bytes), 8);
    return bytes;
}

// Append a uint1024_t value as a big-endian byte array into the provided buffer, and limit
// the array size by digit/8.
inline void encode1024BE(Data& data, const uint1024_t& value, uint32_t digit) {
    Data bytes = store(value);
    Data buff(digit);

    for (int i = 0; i < (int)bytes.size(); ++i) {
        int start = (int)buff.size() - (int)bytes.size() + i;
        if (start >= 0) {
            buff[start] = bytes[i];
        }
    }
    data.insert(data.end(), buff.begin(), buff.end());
}

/// Return string representation of uint1024_t
inline std::string toString(uint1024_t value) {
    return boost::lexical_cast<std::string>(value);
}

} // namespace TW
