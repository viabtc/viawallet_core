// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import WalletCore
import XCTest

class PolkadotTests: XCTestCase {

    let genesisHash = Data(hexString: "0x91b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3")!

    func testAddressValidation() {
        let polkadot = CoinType.polkadot
        // cosmos
        XCTAssertFalse(polkadot.validate(address: "cosmos1l4f4max9w06gqrvsxf74hhyzuqhu2l3zyf0480"))
        // Bitcoin p2sh
        XCTAssertFalse(polkadot.validate(address: "3317oFJC9FvxU2fwrKVsvgnMGCDzTZ5nyf"))
        // Kusama
        XCTAssertFalse(polkadot.validate(address: "ELmaX1aPkyEF7TSmYbbyCjmSgrBpGHv9EtpwR2tk1kmpwvG"))
        // polkadot sr25519
        XCTAssertTrue(polkadot.validate(address: "14PhJGbzPxhQbiq7k9uFjDQx3MNiYxnjFRSiVBvBBBfnkAoM"))
    }

    func testAddress() {
        let key = PrivateKey(data: Data(hexString: "0xd65ed4c1a742699b2e20c0c1f1fe780878b1b9f7d387f934fe0a7dc36f1f9008")!)!
        let pubkey = key.getPublicKeyEd25519()
        let address = AnyAddress(publicKey: pubkey, coin: .polkadot)
        let addressFromString = AnyAddress(string: "12twBQPiG5yVSf3jQSBkTAKBKqCShQ5fm33KQhH3Hf6VDoKW", coin: .polkadot)!

        XCTAssertEqual(pubkey.data.hexString, "53d82211c4aadb8c67e1930caef2058a93bc29d7af86bf587fba4aa3b1515037")
        XCTAssertEqual(address.description, addressFromString.description)
        XCTAssertEqual(address.data, pubkey.data)
    }

    func testSignTransfer() {
        
        let input = PolkadotSigningInput.with {
            $0.genesisHash = genesisHash
            $0.blockHash = Data(hexString: "0x343a3f4258fd92f5ca6ca5abdf473d86a78b0bcd0dc09c568ca594245cc8c642")!
            $0.nonce = 0
            $0.specVersion = 17
            $0.network = .polkadot
            $0.transactionVersion = 3
            $0.privateKey = Data(hexString: "0xabf8e5bdbe30c65656c0a3cbd181ff8a56294a69dfedd27982aace4a76909115")!
            $0.era = PolkadotEra.with {
                $0.blockNumber = 927699
                $0.period = 8
            }
            $0.balanceCall.transfer = PolkadotBalance.Transfer.with {
                $0.toAddress = "14E5nqKAp3oAJcmzgZhUD2RcptBeUBScxKHgJKU4HPNcKVf3"
                $0.value = Data(hexString: "0x3039")!
            }
        }
        let output: PolkadotSigningOutput = AnySigner.sign(input: input, coin: .polkadot)

        XCTAssertEqual(output.encoded.hexString, "29028488dc3417d5058ec4b4503e0c12ea1a0a89be200fe98922423d4334014fa6b0ee003d91a06263956d8ce3ce5c55455baefff299d9cb2bb3f76866b6828ee4083770b6c03b05d7b6eb510ac78d047002c1fe5c6ee4b37c9c5a8b09ea07677f12e50d3200000005008eaf04151687736326c9fea17e25fc5287613693c912909cb226aa4794f26a48e5c0")
    }

    func testSigningBond() {
        let input = PolkadotSigningInput.with {
            $0.genesisHash = genesisHash
            $0.blockHash = Data(hexString: "0xf1eee612825f29abd3299b486e401299df2faa55b7ce1e34bf2243bd591905fc")!
            $0.nonce = 0
            $0.specVersion = 26
            $0.network = .polkadot
            $0.transactionVersion = 5
            $0.privateKey = Data(hexString: "70a794d4f1019c3ce002f33062f45029c4f930a56b3d20ec477f7668c6bbc37f")!
            $0.era = PolkadotEra.with {
                $0.blockNumber = 3540912
                $0.period = 64
            }
            $0.stakingCall.bond = PolkadotStaking.Bond.with {
                $0.controller = "14Ztd3KJDaB9xyJtRkREtSZDdhLSbm7UUKt8Z7AwSv7q85G2"
                $0.rewardDestination = .stash
                $0.value = Data(hexString: "0x028fa6ae00")!
            }
        }
        let output: PolkadotSigningOutput = AnySigner.sign(input: input, coin: .polkadot)

        // https://polkadot.subscan.io/extrinsic/985084-3
        XCTAssertEqual(output.encoded.hexString, "3d02849dca538b7a925b8ea979cc546464a3c5f81d2398a3a272f6f93bdf4803f2f783009025843bc49c1c4fbc99dbbd290c92f9879665d55b02f110abfb4800f0e7630877d2cffd853deae7466c22fbc8616a609e1b92615bb365ea8adccba5ef7624050503000007009dca538b7a925b8ea979cc546464a3c5f81d2398a3a272f6f93bdf4803f2f7830700aea68f0201")
    }

    func testSigningBondAndNominate() {
        let input = PolkadotSigningInput.with {
            $0.genesisHash = genesisHash
            $0.blockHash = genesisHash
            $0.nonce = 4
            $0.specVersion = 30
            $0.network = .polkadot
            $0.transactionVersion = 7
            $0.privateKey = Data(hexString: "0x7f44b19b391a8015ca4c7d94097b3695867a448d1391e7f3243f06987bdb6858")!
            $0.stakingCall.bondAndNominate = PolkadotStaking.BondAndNominate.with {
                $0.controller = "13ZLCqJNPsRZYEbwjtZZFpWt9GyFzg5WahXCVWKpWdUJqrQ5"
                $0.value = Data(hexString: "0x02540be400")! // 1 DOT
                $0.rewardDestination = .stash
                $0.nominators = [
                    "1zugcavYA9yCuYwiEYeMHNJm9gXznYjNfXQjZsZukF1Mpow", // Zug Capital / 12
                    "15oKi7HoBQbwwdQc47k71q4sJJWnu5opn1pqoGx4NAEYZSHs" // P2P Validator
                ]
            }
        }
        let output: PolkadotSigningOutput = AnySigner.sign(input: input, coin: .polkadot)

        // https://polkadot.subscan.io/extrinsic/4955314-2
        XCTAssertEqual(output.encoded.hexString, "6103840036092fac541e0e5feda19e537c679b487566d7101141c203ac8322c27e5f076a00a8b1f859d788f11a958e98b731358f89cf3fdd41a667ea992522e8d4f46915f4c03a1896f2ac54bdc5f16e2ce8a2a3bf233d02aad8192332afd2113ed6688e0d0010001a02080700007120f76076bcb0efdf94c7219e116899d0163ea61cb428183d71324eb33b2bce0700e40b540201070508002c2a55b5ffdca266bd0207df97565b03255f70783ca1a349be5ed9f44589c36000d44533a4d21fd9d6f5d57c8cd05c61a6f23f9131cec8ae386b6b437db399ec3d")
    }

    func testSigningBondExtra() {
        let input = PolkadotSigningInput.with {
            $0.genesisHash = genesisHash
            $0.blockHash = genesisHash
            $0.nonce = 5
            $0.specVersion = 30
            $0.network = .polkadot
            $0.transactionVersion = 7
            $0.privateKey = Data(hexString: "0x7f44b19b391a8015ca4c7d94097b3695867a448d1391e7f3243f06987bdb6858")!
            $0.stakingCall.bondExtra = PolkadotStaking.BondExtra.with {
                $0.value = Data(hexString: "0x77359400")! // 0.2 DOT
            }
        }
        let output: PolkadotSigningOutput = AnySigner.sign(input: input, coin: .polkadot)

        // https://polkadot.subscan.io/extrinsic/4999416-1
        XCTAssertEqual("0x" + output.encoded.hexString, "0xb501840036092fac541e0e5feda19e537c679b487566d7101141c203ac8322c27e5f076a00c8268c2dfd4074f41d225e12e62e5975ff8debf0f828d31ddbfed6f7593e067fb860298eb12f50294f7ba0f82795809c84fc5cce6fcb36cde4cb1c07edbbb60900140007010300943577")
    }

    func testChillAndUnbond() {
        // real key in 1p test
        let key = PrivateKey(data: Data(hexString: "298fcced2b497ed48367261d8340f647b3fca2d9415d57c2e3c5ef90482a2266")!)!

        let input = PolkadotSigningInput.with {
            $0.genesisHash = genesisHash
            $0.blockHash = Data(hexString: "0x35ba668bb19453e8da6334cadcef2a27c8d4141bfc8b49e78e853c3d73e1ecd0")!
            $0.era = PolkadotEra.with {
                $0.blockNumber = 10541373
                $0.period = 64
            }
            $0.nonce = 6
            $0.specVersion = 9200
            $0.network = .polkadot
            $0.transactionVersion = 12
            $0.privateKey = key.data
            $0.stakingCall.chillAndUnbond = PolkadotStaking.ChillAndUnbond.with {
                $0.value = Data(hexString: "0x1766444D00")! // 10.05 DOT
            }
        }
        let output: PolkadotSigningOutput = AnySigner.sign(input: input, coin: .polkadot)

        // https://polkadot.subscan.io/extrinsic/10541383-2
        XCTAssertEqual("0x" + output.encoded.hexString, "0xd10184008361bd08ddca5fda28b5e2aa84dc2621de566e23e089e555a42194c3eaf2da7900c891ba102db672e378945d74cf7f399226a76b43cab502436971599255451597fc2599902e4b62c7ce85ecc3f653c693fef3232be620984b5bb5bcecbbd7b209d50318001a02080706070207004d446617")
    }
}
