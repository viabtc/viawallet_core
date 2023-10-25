// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.trustwallet.core.app.blockchains.kaspa

import com.trustwallet.core.app.utils.toHex
import com.trustwallet.core.app.utils.toHexByteArray
import org.junit.Assert.assertEquals
import org.junit.Test
import wallet.core.jni.*

class TestKaspaAddress {

    init {
        System.loadLibrary("TrustWalletCore")
    }

    @Test
    fun testAddress() {
        val key = PrivateKey("4a08d405f8db0f11010c41b7a51debb2baacb62b1ee0bdf23e0ec35973559de9".toHexByteArray())
        val publickey = key.getPublicKeySecp256k1(true);
        val address = AnyAddress(publickey, CoinType.KASPA)
        val expected = AnyAddress("kaspa:qypu7vn4dkvv4pzhwy9gp5r6n80ym3c6wdfgpum5zpg6de8gznl9xnghhscjnpt", CoinType.KASPA)
        assertEquals(publickey.data().toHex(), "03cf32756d98ca8457710a80d07a99de4dc71a735280f3741051a6e4e814fe534d")
        assertEquals(address.description(), expected.description())
    }
}
