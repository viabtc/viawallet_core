// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

import Foundation

/// Cardano helper functions
public struct Cardano {

    /// Calculates the minimum ADA amount needed for a UTXO.
    ///
    /// - SeeAlso: reference https://docs.cardano.org/native-tokens/minimum-ada-value-requirement
    /// - Parameter tokenBundle: serialized data of TW.Cardano.Proto.TokenBundle.
    /// - Returns: the minimum ADA amount.
    public static func minAdaAmount(tokenBundle: Data) -> UInt64 {
        let tokenBundleData = TWDataCreateWithNSData(tokenBundle)
        defer {
            TWDataDelete(tokenBundleData)
        }
        return TWCardanoMinAdaAmount(tokenBundleData)
    }

    /// Return the staking address associated to (contained in) this address. Must be a Base address.
    /// Empty string is returned on error. Result must be freed.
    /// - Parameter baseAddress: A valid base address, as string.
    /// - Returns: the associated staking (reward) address, as string, or empty string on error.
    public static func getStakingAddress(baseAddress: String) -> String {
        let baseAddressString = TWStringCreateWithNSString(baseAddress)
        defer {
            TWStringDelete(baseAddressString)
        }
        return TWStringNSString(TWCardanoGetStakingAddress(baseAddressString))
    }


    init() {
    }


}
