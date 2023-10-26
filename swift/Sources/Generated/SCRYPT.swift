// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

import Foundation

/// SCRYPT Derivation Function
public struct SCRYPT {

    /// Derives a key from a password and a salt using scrypt.
    ///
    /// - Parameter password: is the master password from which a derived key is generated
    /// - Parameter salt: is a sequence of bits, known as a cryptographic salt
    /// - Parameter N: is the number of iterations desired
    /// - Parameter r: is block size
    /// - Parameter p: is parallelization parameter
    /// - Parameter dkLen: is the desired byte-length of the derived key
    /// - Returns: the derived key data.
    public static func scrypt(password: Data, salt: Data, N: UInt64, r: UInt32, p: UInt32, dkLen: UInt32) -> Data? {
        let passwordData = TWDataCreateWithNSData(password)
        defer {
            TWDataDelete(passwordData)
        }
        let saltData = TWDataCreateWithNSData(salt)
        defer {
            TWDataDelete(saltData)
        }
        guard let result = TWSCRYPTScrypt(passwordData, saltData, N, r, p, dkLen) else {
            return nil
        }
        return TWDataNSData(result)
    }


    init() {
    }


}
