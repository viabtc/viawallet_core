// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"
#include "Address.h"
#include "Messages.h"

#include "../Base64.h"

using namespace TW;
using namespace std::chrono;

namespace TW::Everscale {

Proto::SigningOutput Signer::sign(const Proto::SigningInput& input) noexcept {
    auto key = PrivateKey(input.private_key());
    auto publicKey = key.getPublicKey(TWPublicKeyTypeED25519);

    auto protoOutput = Proto::SigningOutput();

    switch (input.action_oneof_case()) {
    case Proto::SigningInput::ActionOneofCase::kTransfer: {
        const auto& transfer = input.transfer();

        uint8_t flags;
        switch (transfer.behavior()) {
        case Proto::MessageBehavior::SendAllBalance: {
            flags = Wallet::sendAllBalanceFlags;
            break;
        }
        default: {
            flags = Wallet::simpleTransferFlags;
            break;
        }
        }

        Cell::Ref contractData{};
        switch (transfer.account_state_oneof_case()) {
        case Proto::Transfer::AccountStateOneofCase::kEncodedContractData: {
            contractData = Cell::fromBase64(transfer.encoded_contract_data());
            break;
        }
        default:
            break;
        }

        auto signedMessage = createSignedMessage(
            publicKey,
            key,
            transfer.bounce(),
            flags,
            transfer.amount(),
            transfer.expired_at(),
            Address(transfer.to()),
            contractData);
        protoOutput.set_encoded(TW::Base64::encode(signedMessage));
        break;
    }
    default:
        break;
    }

    return protoOutput;
}

} // namespace TW::Everscale
