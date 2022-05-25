// Copyright © 2017-2021 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.trustwallet.core.app.blockchains.simpleledger

import com.trustwallet.core.app.utils.toHex
import com.trustwallet.core.app.utils.toHexByteArray
import org.junit.Assert.assertEquals
import org.junit.Test
import wallet.core.jni.*

class TestSimpleLedgerAddress {

    init {
        System.loadLibrary("TrustWalletCore")
    }

    @Test
    fun testAddress() {

        val key = PrivateKey("28071bf4e2b0340db41b807ed8a5514139e5d6427ff9d58dbd22b7ed187103a4".toHexByteArray())
        val pubkey = key.getPublicKeySecp256k1(true)
        val address = AnyAddress(pubkey, CoinType.SIMPLELEDGER)
        val expected = AnyAddress("simpleledger:qruxj7zq6yzpdx8dld0e9hfvt7u47zrw9g9clv30jf", CoinType.SIMPLELEDGER)

        assertEquals(pubkey.data().toHex(), "0x0240ebf906b948281289405317a5eb9a98045af8a8ab5311b2e3060cfb66c507a1")
        assertEquals(address.description(), expected.description())
    }
}
