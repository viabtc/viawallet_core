// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

import Foundation

/// Represents a CashAddress in C++.
public final class CashAddress: Address {

    /// Compares two addresses for equality.
    ///
    /// - Parameter lhs: The first address to compare.
    /// - Parameter rhs: The second address to compare.
    /// - Returns: bool indicating the addresses are equal.
    public static func == (lhs: CashAddress, rhs: CashAddress) -> Bool {
        return TWCashAddressEqual(lhs.rawValue, rhs.rawValue)
    }

    /// Determines if the data is a valid CashAddress.
    ///
    /// - Parameter data: data to validate.
    /// - Returns: bool indicating if the address data is valid.
    public static func isValid(data: Data) -> Bool {
        let dataData = TWDataCreateWithNSData(data)
        defer {
            TWDataDelete(dataData)
        }
        return TWCashAddressIsValid(dataData)
    }

    /// Determines if the string is a valid CashAddress.
    ///
    /// - Parameter hrp: hrp to validate.
    /// - Parameter string: string to validate.
    /// - Returns: bool indicating if the address string is valid.
    public static func isValidString(hrp: String, string: String) -> Bool {
        let hrpString = TWStringCreateWithNSString(hrp)
        defer {
            TWStringDelete(hrpString)
        }
        let stringString = TWStringCreateWithNSString(string)
        defer {
            TWStringDelete(stringString)
        }
        return TWCashAddressIsValidString(hrpString, stringString)
    }

    /// Returns the address in cash encode string representation.
    ///
    /// - Parameter address: CashAddress to get the string representation of.
    public var description: String {
        return TWStringNSString(TWCashAddressDescription(rawValue))
    }

    /// Returns the key hash data.
    ///
    /// - Parameter address: CashAddress to get the keyhash data of.
    public var keyhash: Data {
        return TWDataNSData(TWCashAddressKeyhash(rawValue))
    }

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init?(hrp: String, string: String) {
        let hrpString = TWStringCreateWithNSString(hrp)
        defer {
            TWStringDelete(hrpString)
        }
        let stringString = TWStringCreateWithNSString(string)
        defer {
            TWStringDelete(stringString)
        }
        guard let rawValue = TWCashAddressCreateWithString(hrpString, stringString) else {
            return nil
        }
        self.rawValue = rawValue
    }

    public init?(hrp: String, publicKey: PublicKey) {
        let hrpString = TWStringCreateWithNSString(hrp)
        defer {
            TWStringDelete(hrpString)
        }
        guard let rawValue = TWCashAddressCreateWithPublicKey(hrpString, publicKey.rawValue) else {
            return nil
        }
        self.rawValue = rawValue
    }

    deinit {
        TWCashAddressDelete(rawValue)
    }

}
