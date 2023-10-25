// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import WalletCore
import XCTest

class KaspaTests: XCTestCase {

    func testAddress() {
        let key = PrivateKey(data: Data(hexString: "4a08d405f8db0f11010c41b7a51debb2baacb62b1ee0bdf23e0ec35973559de9")!)!
        let pubkey = key.getPublicKeySecp256k1(compressed: true)
        let address = AnyAddress(publicKey: pubkey, coin: .kaspa)
        let addressFromString = AnyAddress(string: "kaspa:qypu7vn4dkvv4pzhwy9gp5r6n80ym3c6wdfgpum5zpg6de8gznl9xnghhscjnpt", coin: .kaspa)!
        
        XCTAssertEqual(pubkey.data.hexString, "03cf32756d98ca8457710a80d07a99de4dc71a735280f3741051a6e4e814fe534d")
        XCTAssertEqual(address.description, addressFromString.description)
    }

    func testGetPublicKeyFromXpub() {
        let xpub = "xpub6CcaLRjB6Et5iGtzopUHhL9CRA93odegp9ykEzbaiBN6tBGthmw6NKpY3xoxcXCXDAcT69a4f5WZJGL4esZj5aq4kSzL7ZR9GJKne1LhnHa"
        let coin = CoinType.kaspa
        
        let xpubAddr1 = HDWallet.getPublicKeyFromExtended(
            extended: xpub,
            coin: coin,
            derivationPath: DerivationPath(purpose: .bip44, coin: coin.slip44Id, account: 0, change: 0, address: 1).description
        )!

        let xpubAddr2 = HDWallet.getPublicKeyFromExtended(
            extended: xpub,
            coin: coin,
            derivationPath: DerivationPath(purpose: .bip44, coin: coin.slip44Id, account: 0, change: 0, address: 2).description
        )!
        
        XCTAssertEqual(coin.deriveAddressFromPublicKey(publicKey: xpubAddr1), "kaspa:qypqecdp89797te5tvwa2gx8uglwt5pyfnmp44e8qdym42ltz5qv7yqfpa36k26")
        XCTAssertEqual(coin.deriveAddressFromPublicKey(publicKey: xpubAddr2), "kaspa:qypynplcurlnr0va2wap7ywqnx9e4aktemcj27d742wkqc0uyywe24sngvn9ly6")
    }
    
    func testSign() {
        let input = KaspaSigningInput.with {
            $0.transfer = KaspaTransferMessage.with {
                $0.privateKey = [
                    Data(hexString: "4a08d405f8db0f11010c41b7a51debb2baacb62b1ee0bdf23e0ec35973559de9")!,
                    Data(hexString: "fdcb07a2dfe68f34e68ecc4c170b48df431626d3a6d2b43c17a87c1482c1be1c")!,
                    Data(hexString: "0ddc6c6b255c89add0b05926d82e29494336467fb757ccf1dac4c34acfb5e689")!
                ]
                $0.amount = 800000
                $0.fee = 30000
                $0.byteFee = 10000
                $0.to = "kaspa:qypu7vn4dkvv4pzhwy9gp5r6n80ym3c6wdfgpum5zpg6de8gznl9xnghhscjnpt"
                $0.unspentOutput = [
                    KaspaBitcoinUnspentOutput.with {
                        $0.amount = 599110000
                        $0.outputIndex = 1
                        $0.outputScript = "21024987f8e0ff31bd9d53ba1f11c0998b9af6cbcef12579beaa9d6061fc211d9556ab"
                        $0.transactionHash = "cf2d5c06becedd51488b812766c03e332f890ae140791a67ad5d51aae3953f23"
                        $0.address = "kaspa:qypynplcurlnr0va2wap7ywqnx9e4aktemcj27d742wkqc0uyywe24sngvn9ly6"
                    },
                    KaspaBitcoinUnspentOutput.with {
                        $0.amount = 800000
                        $0.outputIndex = 0
                        $0.outputScript = "2103cf32756d98ca8457710a80d07a99de4dc71a735280f3741051a6e4e814fe534dab"
                        $0.transactionHash = "cf2d5c06becedd51488b812766c03e332f890ae140791a67ad5d51aae3953f23"
                        $0.address = "kaspa:qypu7vn4dkvv4pzhwy9gp5r6n80ym3c6wdfgpum5zpg6de8gznl9xnghhscjnpt"
                    }
                ]
                $0.changeAddress = "kaspa:qyp6vqamd8gyy0v570wzfk9p5lvhysvt0w9zxg0ypgarrmmv6cx4llgnngkk9s6"
            }
        }
        let plan: KaspaTransactionPlan = AnySigner.plan(input: input, coin: .kaspa)
        XCTAssertEqual(plan.transfer.amount, 800000)
        XCTAssertEqual(plan.transfer.fee, 20000)
        XCTAssertEqual(plan.transfer.change, 599090000)
        
        let output: KaspaSigningOutput = AnySigner.sign(input: input, coin: .kaspa)
        XCTAssertEqual(output.json, "{\"inputs\":[{\"previousOutpoint\":{\"index\":1,\"transactionId\":\"cf2d5c06becedd51488b812766c03e332f890ae140791a67ad5d51aae3953f23\"},\"sequence\":0,\"sigOpCount\":1,\"signatureScript\":\"4120e46b159511efb9caf60f06e5f3a4e45f03665ab1ce12126b0b7691561740bf6061ee258404b489fc0fba3ec3548da11b1f4983932e325ea047132693b54b2f01\"},{\"previousOutpoint\":{\"index\":0,\"transactionId\":\"cf2d5c06becedd51488b812766c03e332f890ae140791a67ad5d51aae3953f23\"},\"sequence\":0,\"sigOpCount\":1,\"signatureScript\":\"41edda5ab14f448be142334375800bd8cb5374ce08f78d65bc6bfffba32d8de9bb0314c4109e71e03952dfaf4ccb53061e00170c5934289016898e264c04fb47e901\"}],\"lockTime\":0,\"outputs\":[{\"amount\":800000,\"scriptPublicKey\":{\"script\":\"2103cf32756d98ca8457710a80d07a99de4dc71a735280f3741051a6e4e814fe534dab\",\"version\":0}},{\"amount\":599080000,\"scriptPublicKey\":{\"script\":\"2103a603bb69d0423d94f3dc24d8a1a7d972418b7b8a2321e40a3a31ef6cd60d5ffdab\",\"version\":0}}],\"subnetworkId\":\"0000000000000000000000000000000000000000\",\"version\":0}")
    }
}
