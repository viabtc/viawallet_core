// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

import Foundation

/// Represents an address in C++ for almost any blockchain.
public final class AnyAddress: Address {

    /// Compares two addresses for equality.
    ///
    /// - Parameter lhs: The first address to compare.
    /// - Parameter rhs: The second address to compare.
    /// - Returns: bool indicating the addresses are equal.
    public static func == (lhs: AnyAddress, rhs: AnyAddress) -> Bool {
        return TWAnyAddressEqual(lhs.rawValue, rhs.rawValue)
    }

    /// Determines if the string is a valid Any address.
    ///
    /// - Parameter string: address to validate.
    /// - Parameter coin: coin type of the address.
    /// - Returns: bool indicating if the address is valid.
    public static func isValid(string: String, coin: CoinType) -> Bool {
        let stringString = TWStringCreateWithNSString(string)
        defer {
            TWStringDelete(stringString)
        }
        return TWAnyAddressIsValid(stringString, TWCoinType(rawValue: coin.rawValue))
    }

    /// Returns the address string representation.
    ///
    /// - Parameter address: address to get the string representation of.
    public var description: String {
        return TWStringNSString(TWAnyAddressDescription(rawValue))
    }

    /// Returns coin type of address.
    ///
    /// - Parameter address: address to get the coin type of.
    public var coin: CoinType {
        return CoinType(rawValue: TWAnyAddressCoin(rawValue).rawValue)!
    }

    /// Returns underlaying data (public key or key hash)
    ///
    /// - Parameter address: address to get the data of.
    public var data: Data {
        return TWDataNSData(TWAnyAddressData(rawValue))
    }

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init?(string: String, coin: CoinType) {
        let stringString = TWStringCreateWithNSString(string)
        defer {
            TWStringDelete(stringString)
        }
        guard let rawValue = TWAnyAddressCreateWithString(stringString, TWCoinType(rawValue: coin.rawValue)) else {
            return nil
        }
        self.rawValue = rawValue
    }

    public init(publicKey: PublicKey, coin: CoinType) {
        rawValue = TWAnyAddressCreateWithPublicKey(publicKey.rawValue, TWCoinType(rawValue: coin.rawValue))
    }

    deinit {
        TWAnyAddressDelete(rawValue)
    }

}
