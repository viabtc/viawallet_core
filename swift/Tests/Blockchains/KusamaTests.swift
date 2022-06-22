// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import WalletCore
import XCTest

class KusamaTests: XCTestCase {

    func testAddressValidation() {
        let kusama = CoinType.kusama
        // polkadot sr25519
        XCTAssertFalse(kusama.validate(address: "14PhJGbzPxhQbiq7k9uFjDQx3MNiYxnjFRSiVBvBBBfnkAoM"))
        // cosmos
        XCTAssertFalse(kusama.validate(address: "cosmos1l4f4max9w06gqrvsxf74hhyzuqhu2l3zyf0480"))
        // Bitcoin p2sh
        XCTAssertFalse(kusama.validate(address: "3317oFJC9FvxU2fwrKVsvgnMGCDzTZ5nyf"))

        XCTAssertTrue(kusama.validate(address: "ELmaX1aPkyEF7TSmYbbyCjmSgrBpGHv9EtpwR2tk1kmpwvG"))
    }

    func testAddress() {
        let key = PrivateKey(data: Data(hexString: "0x85fca134b3fe3fd523d8b528608d803890e26c93c86dc3d97b8d59c7b3540c97")!)!
        let pubkey = key.getPublicKeyEd25519()
        let address = AnyAddress(publicKey: pubkey, coin: .kusama)
        let addressFromString = AnyAddress(string: "HewiDTQv92L2bVtkziZC8ASxrFUxr6ajQ62RXAnwQ8FDVmg", coin: .kusama)!

        XCTAssertEqual(pubkey.data.hexString, "e0b3fcccfe0283cc0f8c105c68b5690aab8c5c1692a868e55eaca836c8779085")
        XCTAssertEqual(address.description, addressFromString.description)
        XCTAssertEqual(address.data.hexString, pubkey.data.hexString)
    }

    func testSigningTransfer() {
        let input = PolkadotSigningInput.with {
            $0.blockHash = Data(hexString: "0x4955dd4813f3e91ef3fd5a825b928af2fc50a71380085f753ccef00bb1582891")!
            $0.genesisHash = Data(hexString: "0xb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe")!
            $0.nonce = 0
            $0.specVersion = 2019
            $0.network = .kusama
            $0.transactionVersion = 2
            $0.privateKey = Data(hexString: "0xabf8e5bdbe30c65656c0a3cbd181ff8a56294a69dfedd27982aace4a76909115")!
            $0.balanceCall = PolkadotBalance.with {
                $0.transfer = PolkadotBalance.Transfer.with {
                    $0.toAddress = "FoQJpPyadYccjavVdTWxpxU7rUEaYhfLCPwXgkfD6Zat9QP"
                    // 10000000000 ~ 0.01 KSM
                    $0.value = Data(hexString: "0x3039")!
                }
            }
        }
        let output: PolkadotSigningOutput = AnySigner.sign(input: input, coin: .kusama)

        XCTAssertEqual(output.encoded.hexString, "25028488dc3417d5058ec4b4503e0c12ea1a0a89be200fe98922423d4334014fa6b0ee000765cfa76cfe19499f4f19ef7dc4527652ec5b2e6b5ecfaf68725dafd48ae2694ad52e61f44152a544784e847de10ddb2c56bee4406574dcbcfdb5e5d35b6d0300000004008eaf04151687736326c9fea17e25fc5287613693c912909cb226aa4794f26a48e5c0")
    }
}
