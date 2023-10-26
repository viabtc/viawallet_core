// DO NOT EDIT.
// swift-format-ignore-file
//
// Generated by the Swift generator plugin for the protocol buffer compiler.
// Source: VeChain.proto
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

/// A clause, between a sender and destination
public struct TW_VeChain_Proto_Clause {
  // SwiftProtobuf.Message conformance is added in an extension below. See the
  // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
  // methods supported on all messages.

  //// Recipient address.
  public var to: String = String()

  //// Transaction amount (uint256, serialized little endian)
  public var value: Data = Data()

  //// Payload data.
  public var data: Data = Data()

  public var unknownFields = SwiftProtobuf.UnknownStorage()

  public init() {}
}

/// Input data necessary to create a signed transaction.
public struct TW_VeChain_Proto_SigningInput {
  // SwiftProtobuf.Message conformance is added in an extension below. See the
  // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
  // methods supported on all messages.

  //// Last byte of the genesis block ID which is used to identify a blockchain to prevent the cross-chain replay attack.
  public var chainTag: UInt32 = 0

  //// Reference to a specific block.
  public var blockRef: UInt64 = 0

  //// How long, in terms of the number of blocks, the transaction will be allowed to be mined in VeChainThor.
  public var expiration: UInt32 = 0

  //// An array of Clause objects.
  ////
  //// Each clause contains fields To, Value and Data to enable a single transaction to carry multiple tasks issued
  //// by the transaction sender.
  public var clauses: [TW_VeChain_Proto_Clause] = []

  //// Coefficient used to calculate the gas price for the transaction.
  public var gasPriceCoef: UInt32 = 0

  //// Maximum amount of gas allowed to pay for the transaction.
  public var gas: UInt64 = 0

  //// ID of the transaction on which the current transaction depends.
  public var dependsOn: Data = Data()

  //// Number set by user.
  public var nonce: UInt64 = 0

  //// The secret private key used for signing (32 bytes).
  public var privateKey: Data = Data()

  public var unknownFields = SwiftProtobuf.UnknownStorage()

  public init() {}
}

/// Result containing the signed and encoded transaction.
public struct TW_VeChain_Proto_SigningOutput {
  // SwiftProtobuf.Message conformance is added in an extension below. See the
  // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
  // methods supported on all messages.

  /// Signed and encoded transaction bytes.
  public var encoded: Data = Data()

  /// Signature.
  public var signature: Data = Data()

  public var unknownFields = SwiftProtobuf.UnknownStorage()

  public init() {}
}

// MARK: - Code below here is support for the SwiftProtobuf runtime.

fileprivate let _protobuf_package = "TW.VeChain.Proto"

extension TW_VeChain_Proto_Clause: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = _protobuf_package + ".Clause"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "to"),
    2: .same(proto: "value"),
    3: .same(proto: "data"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeSingularStringField(value: &self.to) }()
      case 2: try { try decoder.decodeSingularBytesField(value: &self.value) }()
      case 3: try { try decoder.decodeSingularBytesField(value: &self.data) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    if !self.to.isEmpty {
      try visitor.visitSingularStringField(value: self.to, fieldNumber: 1)
    }
    if !self.value.isEmpty {
      try visitor.visitSingularBytesField(value: self.value, fieldNumber: 2)
    }
    if !self.data.isEmpty {
      try visitor.visitSingularBytesField(value: self.data, fieldNumber: 3)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_VeChain_Proto_Clause, rhs: TW_VeChain_Proto_Clause) -> Bool {
    if lhs.to != rhs.to {return false}
    if lhs.value != rhs.value {return false}
    if lhs.data != rhs.data {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_VeChain_Proto_SigningInput: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = _protobuf_package + ".SigningInput"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .standard(proto: "chain_tag"),
    2: .standard(proto: "block_ref"),
    3: .same(proto: "expiration"),
    4: .same(proto: "clauses"),
    5: .standard(proto: "gas_price_coef"),
    6: .same(proto: "gas"),
    7: .standard(proto: "depends_on"),
    8: .same(proto: "nonce"),
    9: .standard(proto: "private_key"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeSingularUInt32Field(value: &self.chainTag) }()
      case 2: try { try decoder.decodeSingularUInt64Field(value: &self.blockRef) }()
      case 3: try { try decoder.decodeSingularUInt32Field(value: &self.expiration) }()
      case 4: try { try decoder.decodeRepeatedMessageField(value: &self.clauses) }()
      case 5: try { try decoder.decodeSingularUInt32Field(value: &self.gasPriceCoef) }()
      case 6: try { try decoder.decodeSingularUInt64Field(value: &self.gas) }()
      case 7: try { try decoder.decodeSingularBytesField(value: &self.dependsOn) }()
      case 8: try { try decoder.decodeSingularUInt64Field(value: &self.nonce) }()
      case 9: try { try decoder.decodeSingularBytesField(value: &self.privateKey) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    if self.chainTag != 0 {
      try visitor.visitSingularUInt32Field(value: self.chainTag, fieldNumber: 1)
    }
    if self.blockRef != 0 {
      try visitor.visitSingularUInt64Field(value: self.blockRef, fieldNumber: 2)
    }
    if self.expiration != 0 {
      try visitor.visitSingularUInt32Field(value: self.expiration, fieldNumber: 3)
    }
    if !self.clauses.isEmpty {
      try visitor.visitRepeatedMessageField(value: self.clauses, fieldNumber: 4)
    }
    if self.gasPriceCoef != 0 {
      try visitor.visitSingularUInt32Field(value: self.gasPriceCoef, fieldNumber: 5)
    }
    if self.gas != 0 {
      try visitor.visitSingularUInt64Field(value: self.gas, fieldNumber: 6)
    }
    if !self.dependsOn.isEmpty {
      try visitor.visitSingularBytesField(value: self.dependsOn, fieldNumber: 7)
    }
    if self.nonce != 0 {
      try visitor.visitSingularUInt64Field(value: self.nonce, fieldNumber: 8)
    }
    if !self.privateKey.isEmpty {
      try visitor.visitSingularBytesField(value: self.privateKey, fieldNumber: 9)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_VeChain_Proto_SigningInput, rhs: TW_VeChain_Proto_SigningInput) -> Bool {
    if lhs.chainTag != rhs.chainTag {return false}
    if lhs.blockRef != rhs.blockRef {return false}
    if lhs.expiration != rhs.expiration {return false}
    if lhs.clauses != rhs.clauses {return false}
    if lhs.gasPriceCoef != rhs.gasPriceCoef {return false}
    if lhs.gas != rhs.gas {return false}
    if lhs.dependsOn != rhs.dependsOn {return false}
    if lhs.nonce != rhs.nonce {return false}
    if lhs.privateKey != rhs.privateKey {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_VeChain_Proto_SigningOutput: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = _protobuf_package + ".SigningOutput"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "encoded"),
    2: .same(proto: "signature"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeSingularBytesField(value: &self.encoded) }()
      case 2: try { try decoder.decodeSingularBytesField(value: &self.signature) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    if !self.encoded.isEmpty {
      try visitor.visitSingularBytesField(value: self.encoded, fieldNumber: 1)
    }
    if !self.signature.isEmpty {
      try visitor.visitSingularBytesField(value: self.signature, fieldNumber: 2)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_VeChain_Proto_SigningOutput, rhs: TW_VeChain_Proto_SigningOutput) -> Bool {
    if lhs.encoded != rhs.encoded {return false}
    if lhs.signature != rhs.signature {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}
