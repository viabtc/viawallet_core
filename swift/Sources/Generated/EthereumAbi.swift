// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

import Foundation

/// Wrapper class for Ethereum ABI encoding & decoding.
public struct EthereumAbi {

    /// Encode function to Eth ABI binary
    ///
    /// - Parameter fn: Non-null Eth abi function
    /// - Returns: Non-null encoded block of data
    public static func encode(fn: EthereumAbiFunction) -> Data {
        return TWDataNSData(TWEthereumAbiEncode(fn.rawValue))
    }

    /// Decode function output from Eth ABI binary, fill output parameters
    ///
    /// \param[in] fn Non-null Eth abi function
    /// \param[out] encoded Non-null block of data
    /// - Returns: true if encoded have been filled correctly, false otherwise
    public static func decodeOutput(fn: EthereumAbiFunction, encoded: Data) -> Bool {
        let encodedData = TWDataCreateWithNSData(encoded)
        defer {
            TWDataDelete(encodedData)
        }
        return TWEthereumAbiDecodeOutput(fn.rawValue, encodedData)
    }

    /// Decode function call data to human readable json format, according to input abi json
    ///
    /// - Parameter data: Non-null block of data
    /// - Parameter abi: Non-null string
    /// - Returns: Non-null json string function call data
    public static func decodeCall(data: Data, abi: String) -> String? {
        let dataData = TWDataCreateWithNSData(data)
        defer {
            TWDataDelete(dataData)
        }
        let abiString = TWStringCreateWithNSString(abi)
        defer {
            TWStringDelete(abiString)
        }
        guard let result = TWEthereumAbiDecodeCall(dataData, abiString) else {
            return nil
        }
        return TWStringNSString(result)
    }

    /// Compute the hash of a struct, used for signing, according to EIP712 ("v4").
    /// Input is a Json object (as string), with following fields:
    /// - types: map of used struct types (see makeTypes())
    /// - primaryType: the type of the message (string)
    /// - domain: EIP712 domain specifier values
    /// - message: the message (object).
    /// Throws on error.
    /// Example input:
    ///  R"({
    ///     "types": {
    ///         "EIP712Domain": [
    ///             {"name": "name", "type": "string"},
    ///             {"name": "version", "type": "string"},
    ///             {"name": "chainId", "type": "uint256"},
    ///             {"name": "verifyingContract", "type": "address"}
    ///         ],
    ///         "Person": [
    ///             {"name": "name", "type": "string"},
    ///             {"name": "wallet", "type": "address"}
    ///         ]
    ///     },
    ///     "primaryType": "Person",
    ///     "domain": {
    ///         "name": "Ether Person",
    ///         "version": "1",
    ///         "chainId": 1,
    ///         "verifyingContract": "0xCcCCccccCCCCcCCCCCCcCcCccCcCCCcCcccccccC"
    ///     },
    ///     "message": {
    ///         "name": "Cow",
    ///         "wallet": "CD2a3d9F938E13CD947Ec05AbC7FE734Df8DD826"
    ///     }
    ///  })");
    /// On error, empty Data is returned.
    /// Returned data must be deleted (hint: use WRAPD() macro).
    ///
    /// - Parameter messageJson: Non-null json abi input
    /// - Returns: Non-null block of data, encoded abi input
    public static func encodeTyped(messageJson: String) -> Data {
        let messageJsonString = TWStringCreateWithNSString(messageJson)
        defer {
            TWStringDelete(messageJsonString)
        }
        return TWDataNSData(TWEthereumAbiEncodeTyped(messageJsonString))
    }


    init() {
    }


}
