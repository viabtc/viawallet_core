// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import WalletCore
import XCTest

class SimpleLedgerTests: XCTestCase {

    func testAddress() {

        let key = PrivateKey(data: Data(hexString: "28071bf4e2b0340db41b807ed8a5514139e5d6427ff9d58dbd22b7ed187103a4")!)!
        let pubkey = key.getPublicKeySecp256k1(compressed: true)
        let address = AnyAddress(publicKey: pubkey, coin: .simpleLedger)
        let addressFromString = AnyAddress(string: "simpleledger:qruxj7zq6yzpdx8dld0e9hfvt7u47zrw9g9clv30jf", coin: .simpleLedger)!

        XCTAssertEqual(pubkey.data.hexString, "0240ebf906b948281289405317a5eb9a98045af8a8ab5311b2e3060cfb66c507a1")
        XCTAssertEqual(address.description, addressFromString.description)
    }

    func testSign() {

        let slpInput = SimpleLedgerSimpleLedgerInput.with {
            $0.tokenID = Data(hexString: "dcfda580f8a80ad6e020bb3ef6e6e1a6d4c449c459fb28015df566579ac7ed81")!
            $0.amount = 1200000
            $0.toAddress = "simpleledger:qrjl0aszcdnq5zprjngtyvsz66zhrjyw8ufvsjnguj"
            $0.changeAddress = "simpleledger:qr2m5chhu3mr8d5exphs5jzcldm2295dag5m0cmgku"
            $0.privateKey = [Data(hexString: "c974d42f3926acbae0952429587a803ed9ba4e212e5565dd6081079991308c51")!]
            $0.utxo = [SimpleLedgerUnspentTransaction.with {
                $0.amount = 546
                $0.simpleLedgerAmount = 1200000
                $0.script = Data(hexString: "76a914d5ba62f7e47633b699306f0a4858fb76a5168dea88ac")!
                $0.outPoint = BitcoinOutPoint.with {
                    $0.hash = Data(hexString: "ee4f1ae627863903462c6906d44936c6541564224bd1c122261e624be6fd4f24")!
                    $0.index = 1;
                    $0.sequence = UInt32.max
                }
            }]
        }

        let bchInput = SimpleLedgerBitcoinCashInput.with {
            $0.changeAddress = "bitcoincash:qpt0nwg9wl7yl9prp074afk92splyufvmu6704vsg9"
            $0.privateKey = [Data(hexString: "b6b36bdb66314eb5d027ad9b36a909191cd9e3f390d91a43bb5642282060ebf6")!]
            $0.utxo = [
                BitcoinUnspentTransaction.with {
                    $0.amount = 3140
                    $0.script = Data(hexString: "76a91456f9b90577fc4f94230bfd5ea6c55403f2712cdf88ac")!
                    $0.outPoint = BitcoinOutPoint.with {
                        $0.hash = Data(hexString: "a0f41cbc3afa3e6716b95807adcc449b52eb1d17ecfe269e488804123c9b4336")!;
                        $0.index = 0;
                        $0.sequence = UInt32.max
                    }
                },
                BitcoinUnspentTransaction.with {
                    $0.amount = 1000000
                    $0.script = Data(hexString: "76a91456f9b90577fc4f94230bfd5ea6c55403f2712cdf88ac")!
                    $0.outPoint = BitcoinOutPoint.with {
                        $0.hash = Data(hexString: "ba9665e893d5b71a81e38e56a5fc18921bed8fff1d7d56483125507716f70147")!;
                        $0.index = 0;
                        $0.sequence = UInt32.max
                    }
                }
            ]
        }

        let input = SimpleLedgerSigningInput.with {
            $0.byteFee = 100
            $0.simpleLedgerInput = slpInput
            $0.bitcoinCashInput = bchInput
        }

        let plan: SimpleLedgerTransactionPlan = AnySigner.plan(input: input, coin: .simpleLedger)
        let output: SimpleLedgerSigningOutput = AnySigner.sign(input: input, coin: .simpleLedger)

        XCTAssertEqual(plan.fee, 43900)
        XCTAssertEqual(output.encoded.hexString, "0100000002ee4f1ae627863903462c6906d44936c6541564224bd1c122261e624be6fd4f24010000006a47304402202d62fff4edab54bb3e7fbfd051c5506e21a7b75303cb83a2489cc3b7c72b01110220673ad27d402c5ff43ea8f3905055039907eaade3b9b5d0625dcb10dc899cac8c412102cdb05a92c866fbb56063ff2433d89feee1df2b5a4cebc3e0b74ea4b285b30ebaffffffffba9665e893d5b71a81e38e56a5fc18921bed8fff1d7d56483125507716f70147000000006b483045022100a25fb694044835771532dcd7e81cd2a6ff5152f08ff3144735bb6e0ad02a6be7022044baf3493f27f1b430a5768f8de6758a7b05196a2edd1f2a343abaab527168f2412102c59234267298a6fedd0449451f65b74100062e257ae5001e01b6624448c9dc8dffffffff030000000000000000376a04534c500001010453454e4420dcfda580f8a80ad6e020bb3ef6e6e1a6d4c449c459fb28015df566579ac7ed81080000000000124f8022020000000000001976a914e5f7f602c3660a082394d0b23202d68571c88e3f88acc4960e00000000001976a91456f9b90577fc4f94230bfd5ea6c55403f2712cdf88ac00000000")
    }
}
