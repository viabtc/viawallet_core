#pragma once

#include "Amount.h"
#include "../proto/Bitcoin.pb.h"

#include <vector>

namespace TW::Bitcoin {

class Transfer {
public:
    /// Transfer value
    Amount value;

    /// Recipient's address
    std::string to_address;

public:
    Transfer() = default;

    Transfer(const Proto::Transfer& transfer)
        : value(transfer.value())
        , to_address(transfer.to_address())
        {}

    Proto::Transfer proto() const {
        auto transfer = Proto::Transfer();
        transfer.set_value(value);
        transfer.set_to_address(to_address);
        return transfer;
    }
};

/// A list of Transfer
class Transfers: public std::vector<Transfer> {
public:
    Transfers() = default;
    Transfers(const std::vector<Transfer>& vector): std::vector<Transfer>(vector) {}
    Transfers(Transfer utxo): std::vector<Transfer>({utxo}) {}
};

} // namespace TW::Bitcoin
