// DO NOT EDIT.
// swift-format-ignore-file
//
// Generated by the Swift generator plugin for the protocol buffer compiler.
// Source: ConfluxNetwork.proto
//
// For information on using the generated types, please see the documentation:
//   https://github.com/apple/swift-protobuf/

import Foundation
import SwiftProtobuf

// If the compiler emits an error on this type, it is because this file
// was generated by a version of the `protoc` Swift plug-in that is
// incompatible with the version of SwiftProtobuf to which you are linking.
// Please ensure that you are building against the same version of the API
// that was used to generate this file.
fileprivate struct _GeneratedWithProtocGenSwiftVersion: SwiftProtobuf.ProtobufAPIVersionCheck {
  struct _2: SwiftProtobuf.ProtobufAPIVersion_2 {}
  typealias Version = _2
}

/// Input data necessary to create a signed transaction.
public struct TW_ConfluxNetwork_Proto_SigningInput {
  // SwiftProtobuf.Message conformance is added in an extension below. See the
  // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
  // methods supported on all messages.

  /// Chain identifier (256-bit number)
  public var chainID: Data = Data()

  /// Nonce (256-bit number)
  public var nonce: Data = Data()

  /// Gas price (256-bit number)
  public var gasPrice: Data = Data()

  /// Gas limit (256-bit number)
  public var gasLimit: Data = Data()

  /// Recipient's address.
  public var toAddress: String = String()

  /// Amount to send in wei (256-bit number)
  public var amount: Data = Data()

  /// Optional payload
  public var payload: Data = Data()

  /// Private key.
  public var privateKey: Data = Data()

  public var storageLimit: Data = Data()

  public var epochHeight: Data = Data()

  public var unknownFields = SwiftProtobuf.UnknownStorage()

  public init() {}
}

/// Transaction signing output.
public struct TW_ConfluxNetwork_Proto_SigningOutput {
  // SwiftProtobuf.Message conformance is added in an extension below. See the
  // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
  // methods supported on all messages.

  /// Signed and encoded transaction bytes.
  public var encoded: Data = Data()

  public var v: Data = Data()

  public var r: Data = Data()

  public var s: Data = Data()

  public var unknownFields = SwiftProtobuf.UnknownStorage()

  public init() {}
}

// MARK: - Code below here is support for the SwiftProtobuf runtime.

fileprivate let _protobuf_package = "TW.ConfluxNetwork.Proto"

extension TW_ConfluxNetwork_Proto_SigningInput: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = _protobuf_package + ".SigningInput"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .standard(proto: "chain_id"),
    2: .same(proto: "nonce"),
    3: .standard(proto: "gas_price"),
    4: .standard(proto: "gas_limit"),
    5: .standard(proto: "to_address"),
    6: .same(proto: "amount"),
    7: .same(proto: "payload"),
    8: .standard(proto: "private_key"),
    9: .standard(proto: "storage_limit"),
    10: .standard(proto: "epoch_height"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeSingularBytesField(value: &self.chainID) }()
      case 2: try { try decoder.decodeSingularBytesField(value: &self.nonce) }()
      case 3: try { try decoder.decodeSingularBytesField(value: &self.gasPrice) }()
      case 4: try { try decoder.decodeSingularBytesField(value: &self.gasLimit) }()
      case 5: try { try decoder.decodeSingularStringField(value: &self.toAddress) }()
      case 6: try { try decoder.decodeSingularBytesField(value: &self.amount) }()
      case 7: try { try decoder.decodeSingularBytesField(value: &self.payload) }()
      case 8: try { try decoder.decodeSingularBytesField(value: &self.privateKey) }()
      case 9: try { try decoder.decodeSingularBytesField(value: &self.storageLimit) }()
      case 10: try { try decoder.decodeSingularBytesField(value: &self.epochHeight) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    if !self.chainID.isEmpty {
      try visitor.visitSingularBytesField(value: self.chainID, fieldNumber: 1)
    }
    if !self.nonce.isEmpty {
      try visitor.visitSingularBytesField(value: self.nonce, fieldNumber: 2)
    }
    if !self.gasPrice.isEmpty {
      try visitor.visitSingularBytesField(value: self.gasPrice, fieldNumber: 3)
    }
    if !self.gasLimit.isEmpty {
      try visitor.visitSingularBytesField(value: self.gasLimit, fieldNumber: 4)
    }
    if !self.toAddress.isEmpty {
      try visitor.visitSingularStringField(value: self.toAddress, fieldNumber: 5)
    }
    if !self.amount.isEmpty {
      try visitor.visitSingularBytesField(value: self.amount, fieldNumber: 6)
    }
    if !self.payload.isEmpty {
      try visitor.visitSingularBytesField(value: self.payload, fieldNumber: 7)
    }
    if !self.privateKey.isEmpty {
      try visitor.visitSingularBytesField(value: self.privateKey, fieldNumber: 8)
    }
    if !self.storageLimit.isEmpty {
      try visitor.visitSingularBytesField(value: self.storageLimit, fieldNumber: 9)
    }
    if !self.epochHeight.isEmpty {
      try visitor.visitSingularBytesField(value: self.epochHeight, fieldNumber: 10)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_ConfluxNetwork_Proto_SigningInput, rhs: TW_ConfluxNetwork_Proto_SigningInput) -> Bool {
    if lhs.chainID != rhs.chainID {return false}
    if lhs.nonce != rhs.nonce {return false}
    if lhs.gasPrice != rhs.gasPrice {return false}
    if lhs.gasLimit != rhs.gasLimit {return false}
    if lhs.toAddress != rhs.toAddress {return false}
    if lhs.amount != rhs.amount {return false}
    if lhs.payload != rhs.payload {return false}
    if lhs.privateKey != rhs.privateKey {return false}
    if lhs.storageLimit != rhs.storageLimit {return false}
    if lhs.epochHeight != rhs.epochHeight {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_ConfluxNetwork_Proto_SigningOutput: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = _protobuf_package + ".SigningOutput"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "encoded"),
    2: .same(proto: "v"),
    3: .same(proto: "r"),
    4: .same(proto: "s"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeSingularBytesField(value: &self.encoded) }()
      case 2: try { try decoder.decodeSingularBytesField(value: &self.v) }()
      case 3: try { try decoder.decodeSingularBytesField(value: &self.r) }()
      case 4: try { try decoder.decodeSingularBytesField(value: &self.s) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    if !self.encoded.isEmpty {
      try visitor.visitSingularBytesField(value: self.encoded, fieldNumber: 1)
    }
    if !self.v.isEmpty {
      try visitor.visitSingularBytesField(value: self.v, fieldNumber: 2)
    }
    if !self.r.isEmpty {
      try visitor.visitSingularBytesField(value: self.r, fieldNumber: 3)
    }
    if !self.s.isEmpty {
      try visitor.visitSingularBytesField(value: self.s, fieldNumber: 4)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_ConfluxNetwork_Proto_SigningOutput, rhs: TW_ConfluxNetwork_Proto_SigningOutput) -> Bool {
    if lhs.encoded != rhs.encoded {return false}
    if lhs.v != rhs.v {return false}
    if lhs.r != rhs.r {return false}
    if lhs.s != rhs.s {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}
