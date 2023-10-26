// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

package wallet.core.jni;

import java.security.InvalidParameterException;

/// THORChain swap functions
public class THORChainSwap {
    private byte[] bytes;

    private THORChainSwap() {
    }

    static THORChainSwap createFromNative(byte[] bytes) {
        THORChainSwap instance = new THORChainSwap();
        instance.bytes = bytes;
        return instance;
    }
    /// Builds a THORChainSwap transaction input.
    ///
    /// \param input The serialized data of SwapInput.
    /// \return The serialized data of SwapOutput.
    public static native byte[] buildSwap(byte[] input);
}
