// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Cardano/Signer.h"
#include "Cardano/AddressV3.h"
#include "proto/Cardano.pb.h"
#include <TrustWalletCore/TWCardano.h>

#include "PrivateKey.h"
#include "HexCoding.h"
#include "Cbor.h"
#include "uint256.h"
#include <TrustWalletCore/TWAnySigner.h>
#include "../interface/TWTestUtilities.h"

#include <gtest/gtest.h>
#include <vector>


using namespace TW::Cardano;
using namespace TW;
using namespace std;

const auto privateKeyTest1 = "089b68e458861be0c44bf9f7967f05cc91e51ede86dc679448a3566990b7785bd48c330875b1e0d03caaed0e67cecc42075dce1c7a13b1c49240508848ac82f603391c68824881ae3fc23a56a1a75ada3b96382db502e37564e84a5413cfaf1290dbd508e5ec71afaea98da2df1533c22ef02a26bb87b31907d0b2738fb7785b38d53aa68fc01230784c9209b2b2a2faf28491b3b1f1d221e63e704bbd0403c4154425dfbb01a2c5c042da411703603f89af89e57faae2946e2a5c18b1c5ca0e";
const auto ownAddress1 = "addr1q8043m5heeaydnvtmmkyuhe6qv5havvhsf0d26q3jygsspxlyfpyk6yqkw0yhtyvtr0flekj84u64az82cufmqn65zdsylzk23";

Proto::SigningInput createSampleInput(uint64_t amount, int utxoCount = 10,
    const std::string& alternateToAddress = "", bool omitPrivateKey = false
) {
    const std::string toAddress = (alternateToAddress.length() > 0) ? alternateToAddress :
        "addr1q92cmkgzv9h4e5q7mnrzsuxtgayvg4qr7y3gyx97ukmz3dfx7r9fu73vqn25377ke6r0xk97zw07dqr9y5myxlgadl2s0dgke5";

    Proto::SigningInput input;
    if (utxoCount >= 1) {
        auto* utxo1 = input.add_utxos();
        const auto txHash1 = parse_hex("f074134aabbfb13b8aec7cf5465b1e5a862bde5cb88532cc7e64619179b3e767");
        utxo1->mutable_out_point()->set_tx_hash(txHash1.data(), txHash1.size());
        utxo1->mutable_out_point()->set_output_index(1);
        utxo1->set_address(ownAddress1);
        utxo1->set_amount(1500000);
    }
    if (utxoCount >= 2) {
        auto* utxo2 = input.add_utxos();
        const auto txHash2 = parse_hex("554f2fd942a23d06835d26bbd78f0106fa94c8a551114a0bef81927f66467af0");
        utxo2->mutable_out_point()->set_tx_hash(txHash2.data(), txHash2.size());
        utxo2->mutable_out_point()->set_output_index(0);
        utxo2->set_address(ownAddress1);
        utxo2->set_amount(6500000);
    }

    if (!omitPrivateKey) {
        const auto privateKeyData = parse_hex(privateKeyTest1);
        input.add_private_key(privateKeyData.data(), privateKeyData.size());
    }
    input.mutable_transfer_message()->set_to_address(toAddress);
    input.mutable_transfer_message()->set_change_address(ownAddress1);
    input.mutable_transfer_message()->set_amount(amount);
    input.mutable_transfer_message()->set_use_max_amount(false);
    input.set_ttl(53333333);
    return input;
}

TEST(CardanoSigning, Plan) {
    auto input = createSampleInput(7000000);

    {
        auto signer = Signer(input);
        const auto plan = signer.doPlan();
        EXPECT_EQ(plan.utxos.size(), 2);
        EXPECT_EQ(plan.availableAmount, 8000000);
        EXPECT_EQ(plan.amount, 7000000);
        EXPECT_EQ(plan.fee, 1000000);
        EXPECT_EQ(plan.change, 0);
        EXPECT_EQ(plan.amount + plan.change + plan.fee, plan.availableAmount);
        EXPECT_EQ(plan.error, Common::Proto::OK);
    }
    {   // very small target amount
        input.mutable_transfer_message()->set_amount(1);
        auto signer = Signer(input);
        const auto plan = signer.doPlan();
        EXPECT_EQ(plan.utxos.size(), 1);
        EXPECT_EQ(plan.availableAmount, 6500000);
        EXPECT_EQ(plan.amount, 1);
        EXPECT_EQ(plan.fee, 168405);
        EXPECT_EQ(plan.amount + plan.change + plan.fee, plan.availableAmount);
    }
    {   // small target amount
        input.mutable_transfer_message()->set_amount(2000000);
        auto signer = Signer(input);
        const auto plan = signer.doPlan();
        EXPECT_EQ(plan.utxos.size(), 1);
        EXPECT_EQ(plan.availableAmount, 6500000);
        EXPECT_EQ(plan.amount, 2000000);
        EXPECT_EQ(plan.fee, 168581);
        EXPECT_EQ(plan.amount + plan.change + plan.fee, plan.availableAmount);
    }
    {   // small target amount requested, but max amount
        input.mutable_transfer_message()->set_amount(2000000);
        input.mutable_transfer_message()->set_use_max_amount(true);
        auto signer = Signer(input);
        const auto plan = signer.doPlan();
        EXPECT_EQ(plan.utxos.size(), 2);
        EXPECT_EQ(plan.availableAmount, 8000000);
        EXPECT_EQ(plan.amount, 7828251);
        EXPECT_EQ(plan.fee, 171749);
        EXPECT_EQ(plan.amount + plan.change + plan.fee, plan.availableAmount);
    }
}

TEST(CardanoSigning, PlanForceFee) {
    auto requestedAmount = 6500000;
    auto availableAmount = 8000000;
    auto input = createSampleInput(requestedAmount);

    {
        auto fee = 174609;
        input.mutable_transfer_message()->set_force_fee(fee);
        auto signer = Signer(input);
        const auto plan = signer.doPlan();
        EXPECT_EQ(plan.availableAmount, availableAmount);
        EXPECT_EQ(plan.amount, requestedAmount);
        EXPECT_EQ(plan.fee, fee);
        EXPECT_EQ(plan.change, availableAmount - requestedAmount - fee);
        EXPECT_EQ(plan.amount + plan.change + plan.fee, plan.availableAmount);
        EXPECT_EQ(plan.error, Common::Proto::OK);
    }
    {   // tiny fee
        auto fee = 174609;
        input.mutable_transfer_message()->set_force_fee(fee);
        auto signer = Signer(input);
        const auto plan = signer.doPlan();
        EXPECT_EQ(plan.availableAmount, availableAmount);
        EXPECT_EQ(plan.amount, requestedAmount);
        EXPECT_EQ(plan.fee, fee);
        EXPECT_EQ(plan.change, availableAmount - requestedAmount - fee);
        EXPECT_EQ(plan.amount + plan.change + plan.fee, plan.availableAmount);
    }
    {   // large fee
        auto fee = 174609;
        input.mutable_transfer_message()->set_force_fee(fee);
        auto signer = Signer(input);
        const auto plan = signer.doPlan();
        EXPECT_EQ(plan.availableAmount, availableAmount);
        EXPECT_EQ(plan.amount, requestedAmount);
        EXPECT_EQ(plan.fee, fee);
        EXPECT_EQ(plan.change, availableAmount - requestedAmount - fee);
        EXPECT_EQ(plan.amount + plan.change + plan.fee, plan.availableAmount);
    }
    {   // very large fee, larger than possible, truncated
        auto fee = 174609;
        input.mutable_transfer_message()->set_force_fee(fee);
        auto signer = Signer(input);
        const auto plan = signer.doPlan();
        EXPECT_EQ(plan.availableAmount, availableAmount);
        EXPECT_EQ(plan.amount, requestedAmount);
        EXPECT_EQ(plan.fee, 174609);
        EXPECT_EQ(plan.change, 1325391);
        EXPECT_EQ(plan.amount + plan.change + plan.fee, plan.availableAmount);
    }
    {   // force fee and max amount: fee is used, amount is max, change 0
        auto fee = 171749;
        input.mutable_transfer_message()->set_force_fee(fee);
        input.mutable_transfer_message()->set_use_max_amount(true);
        auto signer = Signer(input);
        const auto plan = signer.doPlan();
        EXPECT_EQ(plan.availableAmount, availableAmount);
        EXPECT_EQ(plan.amount, 7828251);
        EXPECT_EQ(plan.fee, fee);
        EXPECT_EQ(plan.change, 0);
        EXPECT_EQ(plan.amount + plan.change + plan.fee, plan.availableAmount);
    }
}

TEST(CardanoSigning, PlanMissingPrivateKey) {
    auto input = createSampleInput(7000000, 10, "", true);

    auto signer = Signer(input);
    const auto plan = signer.doPlan();

    EXPECT_EQ(plan.utxos.size(), 2);
    EXPECT_EQ(plan.availableAmount, 8000000);
    EXPECT_EQ(plan.amount, 7000000);
    EXPECT_EQ(plan.fee, 1000000);
    EXPECT_EQ(plan.change, 0);
    EXPECT_EQ(plan.amount + plan.change + plan.fee, plan.availableAmount);
    EXPECT_EQ(plan.error, Common::Proto::OK);
}

TEST(CardanoSigning, SignTransfer1) {
    const auto input = createSampleInput(7000000);

    auto signer = Signer(input);
    const auto output = signer.sign();

    EXPECT_EQ(output.error(), Common::Proto::OK);

    const auto encoded = data(output.encoded());
    EXPECT_EQ(hex(encoded), "83a40082825820554f2fd942a23d06835d26bbd78f0106fa94c8a551114a0bef81927f66467af000825820f074134aabbfb13b8aec7cf5465b1e5a862bde5cb88532cc7e64619179b3e76701018182583901558dd902616f5cd01edcc62870cb4748c45403f1228218bee5b628b526f0ca9e7a2c04d548fbd6ce86f358be139fe680652536437d1d6fd51a006acfc0021a000f4240031a032dcd55a100828258206d8a0b425bd2ec9692af39b1c0cf0e51caa07a603550e22f54091e872c7df29058407519e5e7391f8a47f58c8ded1ce532dc80910ef25b108b1092cb58e86a318964956d00af763087fddabf631d00508d1e9c206eaf762176f538042f5c52f6d9028258206d8a0b425bd2ec9692af39b1c0cf0e51caa07a603550e22f54091e872c7df29058407519e5e7391f8a47f58c8ded1ce532dc80910ef25b108b1092cb58e86a318964956d00af763087fddabf631d00508d1e9c206eaf762176f538042f5c52f6d902f6");
    const auto txid = data(output.tx_id());
    EXPECT_EQ(hex(txid), "92859ce37002afc9185c5a918e6596b90258dd3b59ea686ec625bf1b15a5c101");

    {
        const auto decode = Cbor::Decode(encoded);
        ASSERT_TRUE(decode.isValid());
        EXPECT_EQ(decode.dumpToString(), "[{0: [[h\"554f2fd942a23d06835d26bbd78f0106fa94c8a551114a0bef81927f66467af0\", 0], [h\"f074134aabbfb13b8aec7cf5465b1e5a862bde5cb88532cc7e64619179b3e767\", 1]], 1: [[h\"01558dd902616f5cd01edcc62870cb4748c45403f1228218bee5b628b526f0ca9e7a2c04d548fbd6ce86f358be139fe680652536437d1d6fd5\", 7000000]], 2: 1000000, 3: 53333333}, {0: [[h\"6d8a0b425bd2ec9692af39b1c0cf0e51caa07a603550e22f54091e872c7df290\", h\"7519e5e7391f8a47f58c8ded1ce532dc80910ef25b108b1092cb58e86a318964956d00af763087fddabf631d00508d1e9c206eaf762176f538042f5c52f6d902\"], [h\"6d8a0b425bd2ec9692af39b1c0cf0e51caa07a603550e22f54091e872c7df290\", h\"7519e5e7391f8a47f58c8ded1ce532dc80910ef25b108b1092cb58e86a318964956d00af763087fddabf631d00508d1e9c206eaf762176f538042f5c52f6d902\"]]}, null]");
        EXPECT_EQ(decode.getArrayElements().size(), 3);
    }
}

TEST(CardanoSigning, PlanAndSignTransfer1) {
    uint amount = 6000000;
    auto input = createSampleInput(amount);

    {
        // run plan and check result
        auto signer = Signer(input);
        const auto plan = signer.doPlan();

        EXPECT_EQ(plan.availableAmount, 8000000);
        EXPECT_EQ(plan.amount, amount);
        EXPECT_EQ(plan.fee, 174609);
        EXPECT_EQ(plan.change, 8000000 - amount - 174609);
        ASSERT_EQ(plan.utxos.size(), 2);
        EXPECT_EQ(plan.utxos[0].amount, 6500000);
        EXPECT_EQ(plan.utxos[1].amount, 1500000);

        // perform sign with default plan
        const auto output = signer.sign();

        EXPECT_EQ(output.error(), Common::Proto::OK);

        const auto encoded = data(output.encoded());
        EXPECT_EQ(hex(encoded), "83a40082825820554f2fd942a23d06835d26bbd78f0106fa94c8a551114a0bef81927f66467af000825820f074134aabbfb13b8aec7cf5465b1e5a862bde5cb88532cc7e64619179b3e76701018282583901558dd902616f5cd01edcc62870cb4748c45403f1228218bee5b628b526f0ca9e7a2c04d548fbd6ce86f358be139fe680652536437d1d6fd51a005b8d8082583901df58ee97ce7a46cd8bdeec4e5f3a03297eb197825ed5681191110804df22424b6880b39e4bac8c58de9fe6d23d79aaf44756389d827aa09b1a001bda6f021a0002aa11031a032dcd55a100828258206d8a0b425bd2ec9692af39b1c0cf0e51caa07a603550e22f54091e872c7df2905840b721510bab7560882e467ddd76f5ca2faaf8e0ac4e9c51bb8bc171446f14aaf765d05260854d509165f33dbe31d09b30a2cee7213ab6e06aac31e64ec0f0c40b8258206d8a0b425bd2ec9692af39b1c0cf0e51caa07a603550e22f54091e872c7df2905840b721510bab7560882e467ddd76f5ca2faaf8e0ac4e9c51bb8bc171446f14aaf765d05260854d509165f33dbe31d09b30a2cee7213ab6e06aac31e64ec0f0c40bf6");
        const auto txid = data(output.tx_id());
        EXPECT_EQ(hex(txid), "2fda7c264c242e02979f2010e5c65d4f0b7e5c242701478d2b5a2500817435ac");
    }

    // set different plan, with one input only
    input.mutable_plan()->set_amount(amount);
    input.mutable_plan()->set_available_amount(6500000);
    input.mutable_plan()->set_fee(165489);
    input.mutable_plan()->set_change(17191988);
    *(input.mutable_plan()->add_utxos()) = input.utxos(0);
    input.mutable_plan()->set_error(Common::Proto::OK);

    auto signer = Signer(input);
    const auto output = signer.sign();

    EXPECT_EQ(output.error(), Common::Proto::OK);

    const auto encoded = data(output.encoded());
    EXPECT_EQ(hex(encoded), "83a40081825820f074134aabbfb13b8aec7cf5465b1e5a862bde5cb88532cc7e64619179b3e76701018282583901558dd902616f5cd01edcc62870cb4748c45403f1228218bee5b628b526f0ca9e7a2c04d548fbd6ce86f358be139fe680652536437d1d6fd51a005b8d8082583901df58ee97ce7a46cd8bdeec4e5f3a03297eb197825ed5681191110804df22424b6880b39e4bac8c58de9fe6d23d79aaf44756389d827aa09b1a01065434021a00028671031a032dcd55a100818258206d8a0b425bd2ec9692af39b1c0cf0e51caa07a603550e22f54091e872c7df29058408311a058035d75545a47b844fea401aa9c23e99fe7bc8136b554396eef135d4cd93062c5df38e613185c21bb1c98b881d1e0fd1024d3539b163c8e14d1a6e40df6");
    const auto txid = data(output.tx_id());
    EXPECT_EQ(hex(txid), "e319c0bfc99cdb79d64f00b7e8fb8bfbf29fa70554c84f101e92b7dfed172448");
}


TEST(CardanoSigning, PlanAndSignMaxAmount) {
    auto input = createSampleInput(7000000);
    input.mutable_transfer_message()->set_use_max_amount(true);

    {
        // run plan and check result
        auto signer = Signer(input);
        const auto plan = signer.doPlan();

        EXPECT_EQ(plan.availableAmount, 8000000);
        EXPECT_EQ(plan.amount, 8000000 - 171749);
        EXPECT_EQ(plan.fee, 171749);
        EXPECT_EQ(plan.change, 0);
        ASSERT_EQ(plan.utxos.size(), 2);
        EXPECT_EQ(plan.utxos[0].amount, 1500000);
        EXPECT_EQ(plan.utxos[1].amount, 6500000);
    }

    auto signer = Signer(input);
    const auto output = signer.sign();

    EXPECT_EQ(output.error(), Common::Proto::OK);

    const auto encoded = data(output.encoded());
    EXPECT_EQ(hex(encoded), "83a40082825820f074134aabbfb13b8aec7cf5465b1e5a862bde5cb88532cc7e64619179b3e76701825820554f2fd942a23d06835d26bbd78f0106fa94c8a551114a0bef81927f66467af000018182583901558dd902616f5cd01edcc62870cb4748c45403f1228218bee5b628b526f0ca9e7a2c04d548fbd6ce86f358be139fe680652536437d1d6fd51a0077731b021a00029ee5031a032dcd55a100828258206d8a0b425bd2ec9692af39b1c0cf0e51caa07a603550e22f54091e872c7df2905840f54eb9ffc7c7d9b7d77a763c50327cc7f392110cd9449c3c9614f9eedda7d79e2576267233009fbe1dc7ab530ae4c00fe1f941cbd9621f4a327a61a84f9d20098258206d8a0b425bd2ec9692af39b1c0cf0e51caa07a603550e22f54091e872c7df2905840f54eb9ffc7c7d9b7d77a763c50327cc7f392110cd9449c3c9614f9eedda7d79e2576267233009fbe1dc7ab530ae4c00fe1f941cbd9621f4a327a61a84f9d2009f6");
    const auto txid = data(output.tx_id());
    EXPECT_EQ(hex(txid), "9655a39d233d409b11b8bf56895ec84f9b362fbce9333d7596e43eb7b724f3a5");
}

TEST(CardanoSigning, SignNegative) {
    {   // plan with error
        auto input = createSampleInput(7000000);
        const auto error = Common::Proto::Error_invalid_memo;
        input.mutable_plan()->set_error(error);
        auto signer = Signer(input);
        const auto output = signer.sign();
        EXPECT_EQ(output.error(), error);
    }
    {   // zero requested amount
        auto input = createSampleInput(0);
        auto signer = Signer(input);
        const auto output = signer.sign();
        EXPECT_EQ(output.error(), Common::Proto::Error_zero_amount_requested);
    }
    {   // no utxo
        auto input = createSampleInput(7000000, 0);
        auto signer = Signer(input);
        const auto output = signer.sign();
        EXPECT_EQ(output.error(), Common::Proto::Error_missing_input_utxos);
    }
    {   // low balance
        auto input = createSampleInput(7000000000);
        auto signer = Signer(input);
        const auto output = signer.sign();
        EXPECT_EQ(output.error(), Common::Proto::OK);
    }
    {   // missing private key
        auto input = createSampleInput(7000000, 10, "", true);
        auto signer = Signer(input);
        const auto output = signer.sign();
        EXPECT_EQ(output.error(), Common::Proto::Error_missing_private_key);
    }
}

TEST(CardanoSigning, SignTransfer_0db1ea) {
    const auto amount = 1100000;

    Proto::SigningInput input;
    auto* utxo1 = input.add_utxos();
    const auto txHash1 = parse_hex("81b935447bb994567f041d181b628a0afbcd747d0199c9ff4cd895686bbee8c6");
    utxo1->mutable_out_point()->set_tx_hash(std::string(txHash1.begin(), txHash1.end()));
    utxo1->mutable_out_point()->set_output_index(0);
    utxo1->set_address(ownAddress1);
    utxo1->set_amount(1000000);
    auto* utxo2 = input.add_utxos();
    const auto txHash2 = parse_hex("3a9068a273cc2af59b45593b78973841d972d01802abe992c55dbeecdffc561b");
    utxo2->mutable_out_point()->set_tx_hash(std::string(txHash2.begin(), txHash2.end()));
    utxo2->mutable_out_point()->set_output_index(0);
    utxo2->set_address(ownAddress1);
    utxo2->set_amount(1800000);

    const auto privateKeyData1 = parse_hex(privateKeyTest1);
    input.add_private_key(privateKeyData1.data(), privateKeyData1.size());
    input.mutable_transfer_message()->set_to_address("addr1qxxe304qg9py8hyyqu8evfj4wln7dnms943wsugpdzzsxnkvvjljtzuwxvx0pnwelkcruy95ujkq3aw6rl0vvg32x35qc92xkq");
    input.mutable_transfer_message()->set_change_address(ownAddress1);
    input.mutable_transfer_message()->set_amount(amount);
    auto fee = 174609;
    input.mutable_transfer_message()->set_use_max_amount(false);
    input.mutable_transfer_message()->set_force_fee(fee); // use force fee feature here
    input.set_ttl(54675589);

    {
        // run plan and check result
        auto signer = Signer(input);
        const auto plan = signer.doPlan();

        EXPECT_EQ(plan.availableAmount, 2800000);
        EXPECT_EQ(plan.amount, amount);
        EXPECT_EQ(plan.fee, fee);
        EXPECT_EQ(plan.change, 2800000 - amount - fee);
        EXPECT_EQ(plan.utxos.size(), 2);
    }

    // set plan with specific fee, to match the real transaction
    input.mutable_plan()->set_amount(amount);
    input.mutable_plan()->set_available_amount(2800000);
    input.mutable_plan()->set_fee(fee);
    input.mutable_plan()->set_change(2800000 - amount - fee);
    *(input.mutable_plan()->add_utxos()) = input.utxos(0);
    *(input.mutable_plan()->add_utxos()) = input.utxos(1);
    input.mutable_plan()->set_error(Common::Proto::OK);

    auto signer = Signer(input);
    const auto output = signer.sign();

    // curl -d '{"txHash":"0db1ea..44fa","txBody":"83a400..06f6"}' -H "Content-Type: application/json" https://<cardano-node>/api/txs/submit
    EXPECT_EQ(output.error(), Common::Proto::OK);
    const auto encoded = data(output.encoded());
    EXPECT_EQ(hex(encoded), "83a4008282582081b935447bb994567f041d181b628a0afbcd747d0199c9ff4cd895686bbee8c6008258203a9068a273cc2af59b45593b78973841d972d01802abe992c55dbeecdffc561b000182825839018d98bea0414243dc84070f96265577e7e6cf702d62e871016885034ecc64bf258b8e330cf0cdd9fdb03e10b4e4ac08f5da1fdec6222a34681a0010c8e082583901df58ee97ce7a46cd8bdeec4e5f3a03297eb197825ed5681191110804df22424b6880b39e4bac8c58de9fe6d23d79aaf44756389d827aa09b1a0017468f021a0002aa11031a03424885a100828258206d8a0b425bd2ec9692af39b1c0cf0e51caa07a603550e22f54091e872c7df2905840082fd586cec18d4c41d56741fdfde7c1ec02f88c6bc2783d03fa5144c0fd093ea89b9345e8c336c6a702a30eadc9792e0af04bc1e115897bef98a3e8460ebe008258206d8a0b425bd2ec9692af39b1c0cf0e51caa07a603550e22f54091e872c7df2905840082fd586cec18d4c41d56741fdfde7c1ec02f88c6bc2783d03fa5144c0fd093ea89b9345e8c336c6a702a30eadc9792e0af04bc1e115897bef98a3e8460ebe00f6");
    const auto txid = data(output.tx_id());
    EXPECT_EQ(hex(txid), "03fefd4b99831073680dc53421198134074ef6342ba59dff2fe88f160fe099a8");
}

TEST(CardanoSigning, SignTransferFromLegacy) {
    Proto::SigningInput input;
    auto* utxo1 = input.add_utxos();
    const auto txHash1 = parse_hex("f074134aabbfb13b8aec7cf5465b1e5a862bde5cb88532cc7e64619179b3e767");
    utxo1->mutable_out_point()->set_tx_hash(txHash1.data(), txHash1.size());
    utxo1->mutable_out_point()->set_output_index(1);
    utxo1->set_address("Ae2tdPwUPEZMRgecV9jV2e9RdbrmnWu7YgRie4de16xLdkWhy6q7ypmRhgn");
    utxo1->set_amount(1500000);
    auto* utxo2 = input.add_utxos();
    const auto txHash2 = parse_hex("554f2fd942a23d06835d26bbd78f0106fa94c8a551114a0bef81927f66467af0");
    utxo2->mutable_out_point()->set_tx_hash(txHash2.data(), txHash2.size());
    utxo2->mutable_out_point()->set_output_index(0);
    utxo2->set_address("Ae2tdPwUPEZMRgecV9jV2e9RdbrmnWu7YgRie4de16xLdkWhy6q7ypmRhgn");
    utxo2->set_amount(6500000);

    const auto privateKeyData = parse_hex("c031e942f6bf2b2864700e7da20964ee6bb6d716345ce2e24d8c00e6500b574411111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
    {
        const auto privKey = PrivateKey(privateKeyData);
        const auto pubKey = privKey.getPublicKey(TWPublicKeyTypeED25519Extended);
        const auto addr = AddressV2(pubKey);
        EXPECT_EQ(addr.string(), "Ae2tdPwUPEZMRgecV9jV2e9RdbrmnWu7YgRie4de16xLdkWhy6q7ypmRhgn");
    }
    input.add_private_key(privateKeyData.data(), privateKeyData.size());
    input.mutable_transfer_message()->set_to_address("addr1q92cmkgzv9h4e5q7mnrzsuxtgayvg4qr7y3gyx97ukmz3dfx7r9fu73vqn25377ke6r0xk97zw07dqr9y5myxlgadl2s0dgke5");
    input.mutable_transfer_message()->set_change_address(ownAddress1);
    input.mutable_transfer_message()->set_amount(7000000);
    input.mutable_transfer_message()->set_use_max_amount(false);
    input.set_ttl(53333333);

    auto signer = Signer(input);
    const auto output = signer.sign();

    EXPECT_EQ(output.error(), Common::Proto::Error_invalid_address);
    EXPECT_EQ(hex(output.encoded()), "");
}

TEST(CardanoSigning, SignTransferToLegacy) {
    const auto toAddressLegacy = "DdzFFzCqrhssmYoG5Eca1bKZFdGS8d6iag1mU4wbLeYcSPVvBNF2wRG8yhjzQqErbg63N6KJA4DHqha113tjKDpGEwS5x1dT2KfLSbSJ";
    EXPECT_FALSE(AddressV3::isValid(toAddressLegacy)); // not V3
    EXPECT_TRUE(AddressV3::isValidLegacy(toAddressLegacy));

    const auto input = createSampleInput(7000000, 10, toAddressLegacy);

    auto signer = Signer(input);
    const auto output = signer.sign();

    EXPECT_EQ(output.error(), Common::Proto::OK);
    EXPECT_EQ(hex(output.encoded()), "83a40082825820554f2fd942a23d06835d26bbd78f0106fa94c8a551114a0bef81927f66467af000825820f074134aabbfb13b8aec7cf5465b1e5a862bde5cb88532cc7e64619179b3e76701018182584c82d818584283581c6aebd89cf88271c3ee76339930d8956b03f018b2f4871522f88eb8f9a101581e581c692a37dae3bc63dfc3e1463f12011f26655ab1d1e0f4ed4b8fc63708001ad8a9555b1a006acfc0021a000f4240031a032dcd55a100828258206d8a0b425bd2ec9692af39b1c0cf0e51caa07a603550e22f54091e872c7df29058402d7e3d3247eeddec4265bbe110b2f1cd8ff5561805de807747a88a921146120ad49b2e93d4c7d70e3e54117d6ac6848907087c6c1a76b028c5a499adb57bbe0f8258206d8a0b425bd2ec9692af39b1c0cf0e51caa07a603550e22f54091e872c7df29058402d7e3d3247eeddec4265bbe110b2f1cd8ff5561805de807747a88a921146120ad49b2e93d4c7d70e3e54117d6ac6848907087c6c1a76b028c5a499adb57bbe0ff6");
    EXPECT_EQ(hex(data(output.tx_id())), "d6837816e0d5e1fcc61d713bc8f6f963a53f406607a1ed0bb88bbcf22592cf16");
}

TEST(CardanoSigning, SignTransferToInvalid) {
    const auto input = createSampleInput(7000000, 10, "__INVALID_ADDRESS__");

    auto signer = Signer(input);
    const auto output = signer.sign();

    EXPECT_EQ(output.error(), Common::Proto::Error_invalid_address);
    EXPECT_EQ(hex(output.encoded()), "");
}

TEST(CardanoSigning, SignMessageWithKey) {
    // test case from cardano-crypto.js

    const auto privateKey = PrivateKey(parse_hex(
        "d809b1b4b4c74734037f76aace501730a3fe2fca30b5102df99ad3f7c0103e48"
        "d54cde47e9041b31f3e6873d700d83f7a937bea746dadfa2c5b0a6a92502356c"
        "69272d81c376382b8a87c21370a7ae9618df8da708d1a9490939ec54ebe43000"
        "1111111111111111111111111111111111111111111111111111111111111111"
        "1111111111111111111111111111111111111111111111111111111111111111"
        "1111111111111111111111111111111111111111111111111111111111111111"
    ));

    const auto publicKey = privateKey.getPublicKey(TWPublicKeyTypeED25519Extended);
    EXPECT_EQ(hex(publicKey.bytes), 
        "e6f04522f875c1563682ca876ddb04c2e2e3ae718e3ff9f11c03dd9f9dccf698"
        "69272d81c376382b8a87c21370a7ae9618df8da708d1a9490939ec54ebe43000"
        "857eed804ff087b97f87848f6493e87257a8c5203cb9f422f6e7a7d8a4d299f3"
        "1111111111111111111111111111111111111111111111111111111111111111"
    );

    const auto sampleMessageStr = "Hello world";
    const auto sampleMessage = data(sampleMessageStr);

    const auto signature = privateKey.sign(sampleMessage, TWCurveED25519Extended);

    const auto sampleRightSignature = "1096ddcfb2ad21a4c0d861ef3fabe18841e8de88105b0d8e36430d7992c588634ead4100c32b2800b31b65e014d54a8238bdda63118d829bf0bcf1b631e86f0e";
    EXPECT_EQ(hex(signature), sampleRightSignature);
}

TEST(CardanoSigning, AnySignTransfer1) {
    const auto input = createSampleInput(7000000);

    Proto::SigningOutput output;
    ANY_SIGN(input, TWCoinTypeCardano);

    EXPECT_EQ(output.error(), Common::Proto::OK);

    const auto encoded = data(output.encoded());
    EXPECT_EQ(hex(encoded), "83a40082825820554f2fd942a23d06835d26bbd78f0106fa94c8a551114a0bef81927f66467af000825820f074134aabbfb13b8aec7cf5465b1e5a862bde5cb88532cc7e64619179b3e76701018182583901558dd902616f5cd01edcc62870cb4748c45403f1228218bee5b628b526f0ca9e7a2c04d548fbd6ce86f358be139fe680652536437d1d6fd51a006acfc0021a000f4240031a032dcd55a100828258206d8a0b425bd2ec9692af39b1c0cf0e51caa07a603550e22f54091e872c7df29058407519e5e7391f8a47f58c8ded1ce532dc80910ef25b108b1092cb58e86a318964956d00af763087fddabf631d00508d1e9c206eaf762176f538042f5c52f6d9028258206d8a0b425bd2ec9692af39b1c0cf0e51caa07a603550e22f54091e872c7df29058407519e5e7391f8a47f58c8ded1ce532dc80910ef25b108b1092cb58e86a318964956d00af763087fddabf631d00508d1e9c206eaf762176f538042f5c52f6d902f6");
    const auto txid = data(output.tx_id());
    EXPECT_EQ(hex(txid), "92859ce37002afc9185c5a918e6596b90258dd3b59ea686ec625bf1b15a5c101");
}

TEST(CardanoSigning, AnyPlan1) {
    const auto input = createSampleInput(7000000);

    Proto::TransactionPlan plan;
    ANY_PLAN(input, plan, TWCoinTypeCardano);

    EXPECT_EQ(plan.error(), Common::Proto::OK);
    EXPECT_EQ(plan.amount(), 7000000);
    EXPECT_EQ(plan.available_amount(), 8000000);
    EXPECT_EQ(plan.fee(), 1000000);
    EXPECT_EQ(plan.change(), 0);
    ASSERT_EQ(plan.utxos_size(), 2);
    EXPECT_EQ(plan.utxos(0).amount(), 6500000);
    EXPECT_EQ(plan.utxos(1).amount(), 1500000);

    EXPECT_EQ(hex(plan.SerializeAsString()), "0880a4e80310c09fab0318c0843d4292010a220a20554f2fd942a23d06835d26bbd78f0106fa94c8a551114a0bef81927f66467af01267616464723171383034336d356865656179646e76746d6d6b7975686536717635686176766873663064323671336a7967737370786c796670796b3679716b77307968747976747230666c656b6a3834753634617a38326375666d716e36357a6473796c7a6b323318a0dd8c034293010a240a20f074134aabbfb13b8aec7cf5465b1e5a862bde5cb88532cc7e64619179b3e76710011267616464723171383034336d356865656179646e76746d6d6b7975686536717635686176766873663064323671336a7967737370786c796670796b3679716b77307968747976747230666c656b6a3834753634617a38326375666d716e36357a6473796c7a6b323318e0c65b");

    {
        // also test fromProto
        const auto plan2 = TransactionPlan::fromProto(plan);
        EXPECT_EQ(plan2.amount, plan.amount());
        EXPECT_EQ(plan2.change, plan.change());
    }
}

TEST(CardanoSigning, AnyPlan2) {

    Proto::SigningInput input;

    auto* utxo1 = input.add_utxos();
    const auto txHash0 = parse_hex("660dee35fc4462ea9ac6d651090fdce153681458f4e720798cc3c051bb51b17f");
    utxo1->mutable_out_point()->set_tx_hash(txHash0.data(), txHash0.size());
    utxo1->mutable_out_point()->set_output_index(1);
    utxo1->set_address("addr1qxuwk4yhufrrry7lmke3pmktugsme0448kcj9qt7fj3axy9g8tehtqgqtef7wszrrrtl9ncx55v4gpnskf89f28ljr5qezg0nj");
    utxo1->set_amount(1340279);

    auto* utxo2 = input.add_utxos();
    const auto txHash1 = parse_hex("660dee35fc4462ea9ac6d651090fdce153681458f4e720798cc3c051bb51b17f");
    utxo2->mutable_out_point()->set_tx_hash(txHash1.data(), txHash1.size());
    utxo2->mutable_out_point()->set_output_index(1);
    utxo2->set_address("addr1qy6xwh77ej2q6l5cufg94uyfu9y4and5ttkxrnr83v3mepag8tehtqgqtef7wszrrrtl9ncx55v4gpnskf89f28ljr5qhqd9uj");
    utxo2->set_amount(1000000);

    auto* utxo3 = input.add_utxos();
    const auto txHash2 = parse_hex("8cef893898fea03f0738a5e158b911319a7b9c1cd21238deb0d9bcb29a705944");
    utxo3->mutable_out_point()->set_tx_hash(txHash2.data(), txHash2.size());
    utxo3->mutable_out_point()->set_output_index(0);
    utxo3->set_address("addr1qy6xwh77ej2q6l5cufg94uyfu9y4and5ttkxrnr83v3mepag8tehtqgqtef7wszrrrtl9ncx55v4gpnskf89f28ljr5qhqd9uj");
    utxo3->set_amount(1000000);

    auto* utxo4 = input.add_utxos();
    const auto txHash3 = parse_hex("93d6d410cfa61796a07a6c29b01ed0458daec47bb76ed2dbfa587ddf233aebe2");
    utxo4->mutable_out_point()->set_tx_hash(txHash3.data(), txHash3.size());
    utxo4->mutable_out_point()->set_output_index(1);
    utxo4->set_address("addr1qxuwk4yhufrrry7lmke3pmktugsme0448kcj9qt7fj3axy9g8tehtqgqtef7wszrrrtl9ncx55v4gpnskf89f28ljr5qezg0nj");
    utxo4->set_amount(2034611);

    const auto privateKeyData0 = parse_hex("108c9ad46184b2a882c6c473f06f4a0e8998d025d4e74fbe77df84a2774fc356834171c6dead27f23986b991e8178693cade4a1c2124c80c9e1b543c05c7083645b2402c8a1e53de23060377c670e2bafccf1d91968cfe33b4ca5c91342d517df07028b041a3e83c7a7dc3a27a9af936d23ae74197f33f4f628676a5774fc356ce6a494ad8f6c170300e98d3ee20606d972b6ecc27c2218c2968bdeadf352421fdfdddc66e97a32c896f9f3dcb4eb61ce82f01ad1de5c601fe1a13d05561272a");
    input.add_private_key(privateKeyData0.data(), privateKeyData0.size());

    const auto privateKeyData1 = parse_hex("003d225ee9dba5ec25ab7fe8bda5979e4d3f6878bcd3815a7c67685b7a4fc356f2feab0f2be1d4de72f16b00d2f946b49efce76d568a9362148ab16a6c5e3b552adb4833d3c2ffb6e8262a5a010a756cab45a58dc29ec107620bc11e010ba3c7f07028b041a3e83c7a7dc3a27a9af936d23ae74197f33f4f628676a5774fc356ce6a494ad8f6c170300e98d3ee20606d972b6ecc27c2218c2968bdeadf352421fdfdddc66e97a32c896f9f3dcb4eb61ce82f01ad1de5c601fe1a13d05561272a");
    input.add_private_key(privateKeyData1.data(), privateKeyData1.size());

    const auto privateKeyData2 = parse_hex("003d225ee9dba5ec25ab7fe8bda5979e4d3f6878bcd3815a7c67685b7a4fc356f2feab0f2be1d4de72f16b00d2f946b49efce76d568a9362148ab16a6c5e3b552adb4833d3c2ffb6e8262a5a010a756cab45a58dc29ec107620bc11e010ba3c7f07028b041a3e83c7a7dc3a27a9af936d23ae74197f33f4f628676a5774fc356ce6a494ad8f6c170300e98d3ee20606d972b6ecc27c2218c2968bdeadf352421fdfdddc66e97a32c896f9f3dcb4eb61ce82f01ad1de5c601fe1a13d05561272a");
    input.add_private_key(privateKeyData2.data(), privateKeyData2.size());

    const auto privateKeyData3 = parse_hex("108c9ad46184b2a882c6c473f06f4a0e8998d025d4e74fbe77df84a2774fc356834171c6dead27f23986b991e8178693cade4a1c2124c80c9e1b543c05c7083645b2402c8a1e53de23060377c670e2bafccf1d91968cfe33b4ca5c91342d517df07028b041a3e83c7a7dc3a27a9af936d23ae74197f33f4f628676a5774fc356ce6a494ad8f6c170300e98d3ee20606d972b6ecc27c2218c2968bdeadf352421fdfdddc66e97a32c896f9f3dcb4eb61ce82f01ad1de5c601fe1a13d05561272a");
    input.add_private_key(privateKeyData3.data(), privateKeyData3.size());


    input.mutable_transfer_message()->set_to_address("addr1qy6xwh77ej2q6l5cufg94uyfu9y4and5ttkxrnr83v3mepag8tehtqgqtef7wszrrrtl9ncx55v4gpnskf89f28ljr5qhqd9uj");
    input.mutable_transfer_message()->set_change_address("addr1qy6xwh77ej2q6l5cufg94uyfu9y4and5ttkxrnr83v3mepag8tehtqgqtef7wszrrrtl9ncx55v4gpnskf89f28ljr5qhqd9uj");
    input.mutable_transfer_message()->set_amount(1000000);
    input.mutable_transfer_message()->set_use_max_amount(false);
    input.set_ttl(63796153);

    Proto::TransactionPlan plan;
    ANY_PLAN(input, plan, TWCoinTypeCardano);

    EXPECT_EQ(plan.error(), Common::Proto::OK);
    EXPECT_EQ(plan.amount(), 1000000);
    EXPECT_EQ(plan.available_amount(), 3374890);
    EXPECT_EQ(plan.fee(), 174609);
    EXPECT_EQ(plan.change(), 2200281);
    ASSERT_EQ(plan.utxos_size(), 2);
    EXPECT_EQ(plan.utxos(0).amount(), 2034611);
    EXPECT_EQ(plan.utxos(1).amount(), 1340279);
    EXPECT_EQ(hex(plan.SerializeAsString()), "08aafecd0110c0843d1891d40a20d9a586014293010a240a2093d6d410cfa61796a07a6c29b01ed0458daec47bb76ed2dbfa587ddf233aebe2100112676164647231717875776b347968756672727279376c6d6b6533706d6b747567736d65303434386b636a39717437666a33617879396738746568747167717465663777737a727272746c396e63783535763467706e736b6638396632386c6a723571657a67306e6a18b3977c4293010a240a20660dee35fc4462ea9ac6d651090fdce153681458f4e720798cc3c051bb51b17f100112676164647231717875776b347968756672727279376c6d6b6533706d6b747567736d65303434386b636a39717437666a33617879396738746568747167717465663777737a727272746c396e63783535763467706e736b6638396632386c6a723571657a67306e6a18f7e651");
}
