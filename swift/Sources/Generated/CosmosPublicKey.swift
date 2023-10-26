// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

import Foundation

/// Represents a Cosmos public key.
public final class CosmosPublicKey {

    /// Compares two public key for equality.
    public static func == (lhs: CosmosPublicKey, rhs: CosmosPublicKey) -> Bool {
        return TWCosmosPublicKeyEqual(lhs.rawValue, rhs.rawValue)
    }

    /// Returns the public key string representation.
    public var description: String {
        return TWStringNSString(TWCosmosPublicKeyDescription(rawValue))
    }

    /// Returns the public key data.
    public var data: Data {
        return TWDataNSData(TWCosmosPublicKeyData(rawValue))
    }

    /// Returns the public key human-readable part.
    public var hrp: String {
        return TWStringNSString(TWCosmosPublicKeyHrp(rawValue))
    }

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init?(hrp: String, data: Data) {
        let hrpString = TWStringCreateWithNSString(hrp)
        defer {
            TWStringDelete(hrpString)
        }
        let dataData = TWDataCreateWithNSData(data)
        defer {
            TWDataDelete(dataData)
        }
        guard let rawValue = TWCosmosPublicKeyCreateWithData(hrpString, dataData) else {
            return nil
        }
        self.rawValue = rawValue
    }

    deinit {
        TWCosmosPublicKeyDelete(rawValue)
    }

}
