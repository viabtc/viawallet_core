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

/// Cardano helper functions
public class Cardano {
    private byte[] bytes;

    private Cardano() {
    }

    static Cardano createFromNative(byte[] bytes) {
        Cardano instance = new Cardano();
        instance.bytes = bytes;
        return instance;
    }
    /// Calculates the minimum ADA amount needed for a UTXO.
    ///
    /// \see reference https://docs.cardano.org/native-tokens/minimum-ada-value-requirement
    /// \param tokenBundle serialized data of TW.Cardano.Proto.TokenBundle.
    /// \return the minimum ADA amount.
    public static native long minAdaAmount(byte[] tokenBundle);
    /// Return the staking address associated to (contained in) this address. Must be a Base address.
    /// Empty string is returned on error. Result must be freed.
    /// \param baseAddress A valid base address, as string.
    /// \return the associated staking (reward) address, as string, or empty string on error.
    public static native String getStakingAddress(String baseAddress);
}
