// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

import Foundation

/// Represents a Nervos address.
public final class NervosCKBAddress: Address {

    /// Compares two addresses for equality.
    ///
    /// - Parameter lhs: The first address to compare.
    /// - Parameter rhs: The second address to compare.
    /// - Returns: bool indicating the addresses are equal.
    public static func == (lhs: NervosCKBAddress, rhs: NervosCKBAddress) -> Bool {
        return TWNervosCKBAddressEqual(lhs.rawValue, rhs.rawValue)
    }

    /// Determines if the string is a valid Nervos address.
    ///
    /// - Parameter string: string to validate.
    /// - Returns: bool indicating if the address is valid.
    public static func isValidString(string: String) -> Bool {
        let stringString = TWStringCreateWithNSString(string)
        defer {
            TWStringDelete(stringString)
        }
        return TWNervosCKBAddressIsValidString(stringString)
    }

    /// Convert an address to Bech32mFullAddress.
    public static func convertToBech32mFullAddress(address: String) -> String {
        let addressString = TWStringCreateWithNSString(address)
        defer {
            TWStringDelete(addressString)
        }
        return TWStringNSString(TWNervosCKBAddressConvertToBech32mFullAddress(addressString))
    }

    /// Returns the address string representation.
    ///
    /// - Parameter address: Address to get the string representation of.
    public var description: String {
        return TWStringNSString(TWNervosCKBAddressDescription(rawValue))
    }

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init?(string: String) {
        let stringString = TWStringCreateWithNSString(string)
        defer {
            TWStringDelete(stringString)
        }
        guard let rawValue = TWNervosCKBAddressCreateWithString(stringString) else {
            return nil
        }
        self.rawValue = rawValue
    }

    deinit {
        TWNervosCKBAddressDelete(rawValue)
    }

}
