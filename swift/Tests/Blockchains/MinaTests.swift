// Copyright © 2017-2021 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import WalletCore
import XCTest

class MinaTests: XCTestCase {

    func testAddress() {


        let key = PrivateKey(data: Data(hexString: "0x1f8a33418070dce124003b3b287853969d5f21f869091c8d881e0cac8073064a")!)!
        let pubkey = key.getPublicKeyMina()
        let address = AnyAddress(publicKey: pubkey, coin: .mina)
        let addressFromString = AnyAddress(string: "B62qng4Q3NBfiwKRDctBrdQ6iAKTLFCEoXHz9wdTzG6kBh48p5Mf5EU", coin: .mina)!

        XCTAssertEqual(pubkey.data.hexString, "cb01017de6897948db6afdf6efba13ad694d329f33f6d6a54b7be3cd2571ffda68fa2f01")
        XCTAssertEqual(address.description, addressFromString.description)
    }

    func testSign() {
        let input = MinaSigningInput.with {
            $0.privateKey = Data(hexString: "1f8a33418070dce124003b3b287853969d5f21f869091c8d881e0cac8073064a")!
            $0.to = "B62qng4Q3NBfiwKRDctBrdQ6iAKTLFCEoXHz9wdTzG6kBh48p5Mf5EU"
            $0.from = "B62qng4Q3NBfiwKRDctBrdQ6iAKTLFCEoXHz9wdTzG6kBh48p5Mf5EU"
            $0.amount = 10000000
            $0.fee = 20000000
            $0.nonce = 1
            $0.validUntil = 4294967295
            $0.memo = ""
            $0.delegation = false
        }
        let output: MinaSigningOutput = AnySigner.sign(input: input, coin: .mina)
        XCTAssertEqual(output.signature, "3d6ea210c8b93eca7fe9fe2040b2c0dab31b230aee424c2deb8b17be7c5096970f1e630d1a47f3a1a3c6754d47f0b04916c36d1aa5cf0cf8f73cfd5901232b8e")
    }
}
