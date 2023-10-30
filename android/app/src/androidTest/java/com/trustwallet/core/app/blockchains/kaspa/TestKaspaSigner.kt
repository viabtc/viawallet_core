// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.trustwallet.core.app.blockchains.kaspa

import com.google.protobuf.ByteString
import com.trustwallet.core.app.utils.Numeric
import com.trustwallet.core.app.utils.toHexByteArray
import com.trustwallet.core.app.utils.toHexBytes
import com.trustwallet.core.app.utils.toHexBytesInByteString
import org.junit.Assert.assertEquals
import org.junit.Test
import wallet.core.java.AnySigner
import wallet.core.jni.CoinType
import wallet.core.jni.proto.Kaspa
import wallet.core.jni.proto.Kaspa.SigningOutput

class TestKaspaSigner {

    init {
        System.loadLibrary("TrustWalletCore")
    }

    @Test
    fun KaspaTransactionSigning() {

        val private1Key = Numeric.hexStringToByteArray("0ddc6c6b255c89add0b05926d82e29494336467fb757ccf1dac4c34acfb5e689")
        val private2Key = Numeric.hexStringToByteArray("4a08d405f8db0f11010c41b7a51debb2baacb62b1ee0bdf23e0ec35973559de9")

        val transfer = Kaspa.TransferMessage.newBuilder()
            .setTo("kaspa:qypu7vn4dkvv4pzhwy9gp5r6n80ym3c6wdfgpum5zpg6de8gznl9xnghhscjnpt")
            .setFee(30000)
            .setAmount(800000)
            .setPrivateKey(0, ByteString.copyFrom(private1Key))
            .setPrivateKey(1, ByteString.copyFrom(private2Key))
            .setChangeAddress("kaspa:qyp6vqamd8gyy0v570wzfk9p5lvhysvt0w9zxg0ypgarrmmv6cx4llgnngkk9s6")
            .build()
        val signingInput = Kaspa.SigningInput.newBuilder()
            .setTransfer(transfer)
            .build()
        val output: Kaspa.SigningOutput = AnySigner.sign(signingInput, CoinType.KASPA, SigningOutput.parser())
        assertEquals(
            output.json,
            "{\"inputs\":[{\"previousOutpoint\":{\"index\":1,\"transactionId\":\"cf2d5c06becedd51488b812766c03e332f890ae140791a67ad5d51aae3953f23\"},\"sequence\":0,\"sigOpCount\":1,\"signatureScript\":\"4120e46b159511efb9caf60f06e5f3a4e45f03665ab1ce12126b0b7691561740bf6061ee258404b489fc0fba3ec3548da11b1f4983932e325ea047132693b54b2f01\"},{\"previousOutpoint\":{\"index\":0,\"transactionId\":\"cf2d5c06becedd51488b812766c03e332f890ae140791a67ad5d51aae3953f23\"},\"sequence\":0,\"sigOpCount\":1,\"signatureScript\":\"41edda5ab14f448be142334375800bd8cb5374ce08f78d65bc6bfffba32d8de9bb0314c4109e71e03952dfaf4ccb53061e00170c5934289016898e264c04fb47e901\"}],\"lockTime\":0,\"outputs\":[{\"amount\":800000,\"scriptPublicKey\":{\"script\":\"2103cf32756d98ca8457710a80d07a99de4dc71a735280f3741051a6e4e814fe534dab\",\"version\":0}},{\"amount\":599080000,\"scriptPublicKey\":{\"script\":\"2103a603bb69d0423d94f3dc24d8a1a7d972418b7b8a2321e40a3a31ef6cd60d5ffdab\",\"version\":0}}],\"subnetworkId\":\"0000000000000000000000000000000000000000\",\"version\":0}"
        )
    }
}
