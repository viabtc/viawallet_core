// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "../interface/TWTestUtilities.h"
#include "SimpleLedger/Signer.h"
#include "HexCoding.h"
#include "PrivateKey.h"
#include "Bitcoin/OutPoint.h"

#include <gtest/gtest.h>

using namespace TW;
using namespace TW::SimpleLedger;

auto transactionOutPoint = Bitcoin::OutPoint(std::vector<uint8_t>(32), 0);

inline auto buildUTXO(const Bitcoin::OutPoint& outPoint, int64_t amount, int64_t slpAmount) {
    Proto::UnspentTransaction utxo;
    utxo.set_amount(amount);
    utxo.set_simple_ledger_amount(slpAmount);
    utxo.mutable_out_point()->set_hash(outPoint.hash.data(), outPoint.hash.size());
    utxo.mutable_out_point()->set_index(outPoint.index);
    return utxo;
}

TEST(SimpleLedgerSigner, SelectUnpsents1) {
    auto utxos = std::vector<Proto::UnspentTransaction>();
    utxos.push_back(buildUTXO(transactionOutPoint, 4000, 4000));
    utxos.push_back(buildUTXO(transactionOutPoint, 2000, 2000));
    utxos.push_back(buildUTXO(transactionOutPoint, 6000, 6000));
    utxos.push_back(buildUTXO(transactionOutPoint, 1000, 1000));
    utxos.push_back(buildUTXO(transactionOutPoint, 11000, 11000));
    utxos.push_back(buildUTXO(transactionOutPoint, 12000, 12000));
    auto selected = UnspentSelector::select(utxos, 5000);
    ASSERT_EQ(UnspentSelector::sum(selected), 11000);
}

TEST(SimpleLedgerSigner, SelectUnpsents2) {
    auto utxos = std::vector<Proto::UnspentTransaction>();
    utxos.push_back(buildUTXO(transactionOutPoint, 4000, 4000));
    utxos.push_back(buildUTXO(transactionOutPoint, 2000, 2000));
    utxos.push_back(buildUTXO(transactionOutPoint, 6000, 6000));
    utxos.push_back(buildUTXO(transactionOutPoint, 1000, 1000));
    utxos.push_back(buildUTXO(transactionOutPoint, 50000, 50000));
    utxos.push_back(buildUTXO(transactionOutPoint, 120000, 120000));

    auto selected = UnspentSelector::select(utxos, 10000);

    ASSERT_EQ(UnspentSelector::sum(selected), 50000);
}

TEST(SimpleLedgerSigner, SelectUnpsents3) {
    auto utxos = std::vector<Proto::UnspentTransaction>();
    utxos.push_back(buildUTXO(transactionOutPoint, 4000, 4000));
    utxos.push_back(buildUTXO(transactionOutPoint, 2000, 2000));
    utxos.push_back(buildUTXO(transactionOutPoint, 5000, 5000));

    auto selected = UnspentSelector::select(utxos, 6000);

    ASSERT_EQ(UnspentSelector::sum(selected), 9000);
}

TEST(SimpleLedgerSigner, SelectUnpsents4) {
    auto utxos = std::vector<Proto::UnspentTransaction>();
    utxos.push_back(buildUTXO(transactionOutPoint, 40000, 40000));
    utxos.push_back(buildUTXO(transactionOutPoint, 30000, 30000));
    utxos.push_back(buildUTXO(transactionOutPoint, 30000, 30000));

    auto selected = UnspentSelector::select(utxos, 50000);

    ASSERT_EQ(UnspentSelector::sum(selected), 70000);
}

TEST(SimpleLedgerSigner, SelectUnpsents5) {
    auto utxos = std::vector<Proto::UnspentTransaction>();
    utxos.push_back(buildUTXO(transactionOutPoint, 1000, 1000));
    utxos.push_back(buildUTXO(transactionOutPoint, 2000, 2000));
    utxos.push_back(buildUTXO(transactionOutPoint, 3000, 3000));
    utxos.push_back(buildUTXO(transactionOutPoint, 4000, 4000));
    utxos.push_back(buildUTXO(transactionOutPoint, 5000, 5000));
    utxos.push_back(buildUTXO(transactionOutPoint, 6000, 6000));
    utxos.push_back(buildUTXO(transactionOutPoint, 7000, 7000));
    utxos.push_back(buildUTXO(transactionOutPoint, 8000, 8000));
    utxos.push_back(buildUTXO(transactionOutPoint, 9000, 9000));

    auto selected = UnspentSelector::select(utxos, 28000);

    ASSERT_EQ(UnspentSelector::sum(selected), 30000);
}

TEST(SimpleLedgerSigner, SelectUnpsentsInsufficient) {
    auto utxos = std::vector<Proto::UnspentTransaction>();
    utxos.push_back(buildUTXO(transactionOutPoint, 4000, 4000));
    utxos.push_back(buildUTXO(transactionOutPoint, 4000, 4000));
    utxos.push_back(buildUTXO(transactionOutPoint, 4000, 4000));

    auto selected = UnspentSelector::select(utxos, 15000);

    ASSERT_TRUE(selected.empty());
}

TEST(SimpleLedgerSigner, SelectMaxCase) {
    auto utxos = std::vector<Proto::UnspentTransaction>();
    utxos.push_back(buildUTXO(transactionOutPoint, 10189534, 10189534));

    auto selected = UnspentSelector::select(utxos, 10189342);

    ASSERT_EQ(UnspentSelector::sum(selected), 10189534);
    ASSERT_TRUE(selected.size() > 0);
}

TEST(SimpleLedgerSigner, Sign) {
    const int64_t amount = 1200000;
    const int64_t fee = 100;
    auto tokenId = DATA("dcfda580f8a80ad6e020bb3ef6e6e1a6d4c449c459fb28015df566579ac7ed81");

    auto slpInput = Proto::SimpleLedgerInput();
    slpInput.set_token_id(TWDataBytes(tokenId.get()), TWDataSize(tokenId.get()));
    slpInput.set_amount(amount);
    slpInput.set_to_address("simpleledger:qrjl0aszcdnq5zprjngtyvsz66zhrjyw8ufvsjnguj");
    slpInput.set_change_address("simpleledger:qr2m5chhu3mr8d5exphs5jzcldm2295dag5m0cmgku");
    // Add slp utxo
    auto hash0 = DATA("ee4f1ae627863903462c6906d44936c6541564224bd1c122261e624be6fd4f24");
    auto utxo0 = slpInput.add_utxo();
    utxo0->mutable_out_point()->set_hash(TWDataBytes(hash0.get()), TWDataSize(hash0.get()));
    utxo0->mutable_out_point()->set_index(1);
    utxo0->mutable_out_point()->set_sequence(UINT32_MAX);
    utxo0->set_amount(546);
    utxo0->set_simple_ledger_amount(1200000);
    auto script0 = parse_hex("76a914d5ba62f7e47633b699306f0a4858fb76a5168dea88ac");
    utxo0->set_script(script0.data(), script0.size());
    // Add slp private key
    auto utxoKey0 = parse_hex("c974d42f3926acbae0952429587a803ed9ba4e212e5565dd6081079991308c51");
    slpInput.add_private_key(utxoKey0.data(), utxoKey0.size());

    auto bchInput = Proto::BitcoinCashInput();
    bchInput.set_change_address("bitcoincash:qpt0nwg9wl7yl9prp074afk92splyufvmu6704vsg9");
    // Add bch utxo
    auto bch_hash_0 = DATA("a0f41cbc3afa3e6716b95807adcc449b52eb1d17ecfe269e488804123c9b4336");
    auto bch_utxo_0 = bchInput.add_utxo();
    bch_utxo_0->mutable_out_point()->set_hash(TWDataBytes(bch_hash_0.get()), TWDataSize(bch_hash_0.get()));
    bch_utxo_0->mutable_out_point()->set_index(0);
    bch_utxo_0->mutable_out_point()->set_sequence(UINT32_MAX);
    bch_utxo_0->set_amount(3140);
    auto bch_script_0 = parse_hex("76a91456f9b90577fc4f94230bfd5ea6c55403f2712cdf88ac");
    bch_utxo_0->set_script(bch_script_0.data(), bch_script_0.size());

    auto bch_hash_1 = DATA("ba9665e893d5b71a81e38e56a5fc18921bed8fff1d7d56483125507716f70147");
    auto bch_utxo_1 = bchInput.add_utxo();
    bch_utxo_1->mutable_out_point()->set_hash(TWDataBytes(bch_hash_1.get()), TWDataSize(bch_hash_1.get()));
    bch_utxo_1->mutable_out_point()->set_index(0);
    bch_utxo_1->mutable_out_point()->set_sequence(UINT32_MAX);
    bch_utxo_1->set_amount(1000000);
    auto bch_script_1 = parse_hex("76a91456f9b90577fc4f94230bfd5ea6c55403f2712cdf88ac");
    bch_utxo_1->set_script(bch_script_1.data(), bch_script_1.size());
    // Add private key
    auto utxoKey1 = parse_hex("b6b36bdb66314eb5d027ad9b36a909191cd9e3f390d91a43bb5642282060ebf6");
    bchInput.add_private_key(utxoKey1.data(), utxoKey1.size());

    auto input = Proto::SigningInput();
    input.set_byte_fee(fee);
    *input.mutable_simple_ledger_input() = slpInput;
    *input.mutable_bitcoin_cash_input() = bchInput;

    // Sign
    auto plan = Signer::plan(input);
    auto output = Signer::sign(input);


    ASSERT_EQ(43900, plan.fee());

    ASSERT_EQ(hex(output.encoded()),
              "0100000002ee4f1ae627863903462c6906d44936c6541564224bd1c122261e624be6fd4f24010000006a47304402202d62fff4edab54bb3e7fbfd051c5506e21a7b75303cb83a2489cc3b7c72b01110220673ad27d402c5ff43ea8f3905055039907eaade3b9b5d0625dcb10dc899cac8c412102cdb05a92c866fbb56063ff2433d89feee1df2b5a4cebc3e0b74ea4b285b30ebaffffffffba9665e893d5b71a81e38e56a5fc18921bed8fff1d7d56483125507716f70147000000006b483045022100a25fb694044835771532dcd7e81cd2a6ff5152f08ff3144735bb6e0ad02a6be7022044baf3493f27f1b430a5768f8de6758a7b05196a2edd1f2a343abaab527168f2412102c59234267298a6fedd0449451f65b74100062e257ae5001e01b6624448c9dc8dffffffff030000000000000000376a04534c500001010453454e4420dcfda580f8a80ad6e020bb3ef6e6e1a6d4c449c459fb28015df566579ac7ed81080000000000124f8022020000000000001976a914e5f7f602c3660a082394d0b23202d68571c88e3f88acc4960e00000000001976a91456f9b90577fc4f94230bfd5ea6c55403f2712cdf88ac00000000");
}
