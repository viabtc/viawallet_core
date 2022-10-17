// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "Polkadot/Address.h"
#include "PublicKey.h"
#include "PrivateKey.h"
#include "HDWallet.h"
#include <gtest/gtest.h>
#include <vector>

namespace TW::Polkadot::tests {

TEST(PolkadotAddress, Validation) {
    // Substrate ed25519
    ASSERT_FALSE(Address::isValid("5FqqU2rytGPhcwQosKRtW1E3ha6BJKAjHgtcodh71dSyXhoZ"));
    // Bitcoin
    ASSERT_FALSE(Address::isValid("1ES14c7qLb5CYhLMUekctxLgc1FV2Ti9DA"));
    // Kusama ed25519
    ASSERT_FALSE(Address::isValid("FHKAe66mnbk8ke8zVWE9hFVFrJN1mprFPVmD5rrevotkcDZ"));
    // Kusama secp256k1
    ASSERT_FALSE(Address::isValid("FxQFyTorsjVsjjMyjdgq8w5vGx8LiA1qhWbRYcFijxKKchx"));
    // Kusama sr25519
    ASSERT_FALSE(Address::isValid("EJ5UJ12GShfh7EWrcNZFLiYU79oogdtXFUuDDZzk7Wb2vCe"));

    // Polkadot ed25519
    ASSERT_TRUE(Address::isValid("15KRsCq9LLNmCxNFhGk55s5bEyazKefunDxUH24GFZwsTxyu"));
    // Polkadot sr25519
    ASSERT_TRUE(Address::isValid("15AeCjMpcSt3Fwa47jJBd7JzQ395Kr2cuyF5Zp4UBf1g9ony"));
}

TEST(PolkadotAddress, FromPrivateKey) {
    // subkey phrase `chief menu kingdom stereo hope hazard into island bag trick egg route`
    auto privateKey = PrivateKey(parse_hex("0x612d82bc053d1b4729057688ecb1ebf62745d817ddd9b595bc822f5f2ba0e41a"));
    auto address = Address(privateKey.getPublicKey(TWPublicKeyTypeED25519));
    ASSERT_EQ(address.string(), "15KRsCq9LLNmCxNFhGk55s5bEyazKefunDxUH24GFZwsTxyu");
}

TEST(PolkadotAddress, FromPublicKey) {
    auto publicKey = PublicKey(parse_hex("0xbeff0e5d6f6e6e6d573d3044f3e2bfb353400375dc281da3337468d4aa527908"), TWPublicKeyTypeED25519);
    auto address = Address(publicKey);
    ASSERT_EQ(address.string(), "15KRsCq9LLNmCxNFhGk55s5bEyazKefunDxUH24GFZwsTxyu");
}

TEST(PolkadotAddress, FromString) {
    auto address = Address("15KRsCq9LLNmCxNFhGk55s5bEyazKefunDxUH24GFZwsTxyu");
    ASSERT_EQ(address.string(), "15KRsCq9LLNmCxNFhGk55s5bEyazKefunDxUH24GFZwsTxyu");
}

TEST(PolkadotAddress, FromPhrase) {
    const auto wallet = HDWallet("need dune cherry fantasy undo mail pole dolphin update shine ticket office", "");
    const auto privateKey = wallet.getKey(TWCoinTypePolkadot, TWDerivationDefault);
    const auto publicKey = privateKey.getPublicKey(TWPublicKeyTypeSR25519);
    auto address = Address(publicKey);
    ASSERT_EQ(address.string(), "1prdJetA3vjFhMV2ERU7DCNxP9Lj5qvNPtwAfbZ7y4FWQtS");
}

TEST(PolkadotAddress, FromSR25519Key) {
    const auto privateKeyData = PrivateKey::transform(parse_hex("9d61b19deffd5a60ba844af492ec2cc44449c5697b326919703bac031cae7f60"), TWCurveSR25519);
    const auto privateKey = PrivateKey(privateKeyData);
    const auto publicKey = privateKey.getPublicKey(TWPublicKeyTypeSR25519);
    auto address = Address(publicKey);
    ASSERT_EQ(address.string(), "12Z2dohKGejugkCsD1VFgamLQJyDoUnksenbQNp7NnjeZ8a6");
}

TEST(PolkadotAddress, FromSR25519Key1) {
    const auto privateKeyData = PrivateKey::transform(parse_hex("0x4646464646464646464646464646464646464646464646464646464646464646"), TWCurveSR25519);
    const auto privateKey = PrivateKey(privateKeyData);
    const auto publicKey = privateKey.getPublicKey(TWPublicKeyTypeSR25519);
    auto address = Address(publicKey);
    ASSERT_EQ(address.string(), "1k3eSQ9W6uJbgamWJE73FSrGhQKLehn2szCHs6jDg6Gd9tD");
}

} // namespace TW::Polkadot::tests
