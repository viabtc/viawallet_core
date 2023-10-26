// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

/// Preset encryption parameter with different security strength, for key store
public enum StoredKeyEncryptionLevel: UInt32, CaseIterable {
    case `default` = 0
    case minimal = 1
    case weak = 2
    case standard = 3
}
