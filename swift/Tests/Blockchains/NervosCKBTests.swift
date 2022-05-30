// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import WalletCore
import XCTest

class NervosCKBTests: XCTestCase {
    
    func testAddress() {
        let key = PrivateKey(data: Data(hexString: "7e8a39f523548d1c9485dfa076b2e30e2021a8cf69092707ec7f62bac2a8b1e2")!)!
        let pubkey = key.getPublicKeySecp256k1(compressed: true)
        let address = AnyAddress(publicKey: pubkey, coin: .nervosCKB)
        let addressFromString = AnyAddress(string: "ckb1qyq0zvxuq8d09xv9cxmq0jc2z5e7pv7lcy8skquj6s", coin: .nervosCKB)!

        XCTAssertEqual(pubkey.data.hexString, "0313405bd91c33f5a34664f67d79ab1a5cf914743ab6964fd5a7f7611a1ab679dc")
        XCTAssertEqual(address.description, addressFromString.description)
    }

    func testSign() {
        let input = NervosCKBSigningInput.with {
            $0.transfer = NervosCKBTransferMessage.with {
                $0.amount = 6200000000
                $0.feeRate = 1000
                $0.to = "ckb1qyq2tatnjz8585dr4j94any9gymm03w2uprsq23unj"
                $0.useMaxAmount = false
                $0.privateKey = Data(hexString: "7e8a39f523548d1c9485dfa076b2e30e2021a8cf69092707ec7f62bac2a8b1e2")!
                $0.cells = [
                    NervosCKBCellInput.with {
                        $0.capacity = 19000000000
                        $0.since = 0
                        $0.previousOutput = NervosCKBOutPoint.with {
                            $0.index = 0
                            $0.txHash = Data(hexString: "14dead518c172b8f90d36ea45d6712dc833c04044179f39704119d31c1cbfee6")!
                        }
                    }
                ]
            }
        }
        
        let output: NervosCKBSigningOutput = AnySigner.sign(input: input, coin: .nervosCKB)
        XCTAssertEqual(output.json, "{\"cell_deps\":[{\"dep_type\":\"dep_group\",\"out_point\":{\"index\":\"0x0\",\"tx_hash\":\"0x71a7ba8fc96349fea0ed3a5c47992e3b4084b031a42264a018e0072e8172e46c\"}}],\"header_deps\":[],\"inputs\":[{\"previous_output\":{\"index\":\"0x0\",\"tx_hash\":\"0x14dead518c172b8f90d36ea45d6712dc833c04044179f39704119d31c1cbfee6\"},\"since\":\"0x0\"}],\"outputs\":[{\"capacity\":\"0x1718c7e00\",\"lock\":{\"args\":\"0xa5f573908f43d1a3ac8b5ecc854137b7c5cae047\",\"code_hash\":\"0x9bd7e06f3ecf4be0f2fcd2188b23f1b9fcc88e5d4b65a8637b17723bbda3cce8\",\"hash_type\":\"type\"},\"type\":null},{\"capacity\":\"0x2faf07e30\",\"lock\":{\"args\":\"0xf130dc01daf29985c1b607cb0a1533e0b3dfc10f\",\"code_hash\":\"0x9bd7e06f3ecf4be0f2fcd2188b23f1b9fcc88e5d4b65a8637b17723bbda3cce8\",\"hash_type\":\"type\"},\"type\":null}],\"outputs_data\":[\"0x\",\"0x\"],\"version\":\"0x0\",\"witnesses\":[\"0x55000000100000005500000055000000410000002194b89bb157e8edd597a2e1793c0791e8b675fbe7258db87b23ba18bfe9ca7f7b14f88219582b41653e51a4ff8d5ac9be45342902d12ecdc240e77b29459a6000\"]}")
    }
}
