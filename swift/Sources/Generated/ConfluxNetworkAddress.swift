// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

import Foundation

/// Represents a legacy Conflux address.
public final class ConfluxNetworkAddress: Address {

    /// Compares two addresses for equality.
    public static func == (lhs: ConfluxNetworkAddress, rhs: ConfluxNetworkAddress) -> Bool {
        return TWConfluxNetworkAddressEqual(lhs.rawValue, rhs.rawValue)
    }

    /// Determines if the string is a valid Conflux address.
    public static func isValidString(string: String) -> Bool {
        let stringString = TWStringCreateWithNSString(string)
        defer {
            TWStringDelete(stringString)
        }
        return TWConfluxNetworkAddressIsValidString(stringString)
    }


    public static func encode(string: String) -> String {
        let stringString = TWStringCreateWithNSString(string)
        defer {
            TWStringDelete(stringString)
        }
        return TWStringNSString(TWConfluxNetworkAddressEncode(stringString))
    }

    /// Returns the address string representation.
    public var description: String {
        return TWStringNSString(TWConfluxNetworkAddressDescription(rawValue))
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
        guard let rawValue = TWConfluxNetworkAddressCreateWithString(stringString) else {
            return nil
        }
        self.rawValue = rawValue
    }

    public init(publicKey: PublicKey) {
        rawValue = TWConfluxNetworkAddressCreateWithPublicKey(publicKey.rawValue)
    }

    deinit {
        TWConfluxNetworkAddressDelete(rawValue)
    }

}
