// DO NOT EDIT.
// swift-format-ignore-file
//
// Generated by the Swift generator plugin for the protocol buffer compiler.
// Source: Kaspa.proto
//
// For information on using the generated types, please see the documentation:
//   https://github.com/apple/swift-protobuf/

// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

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

public enum TW_Kaspa_Proto_TransferError: SwiftProtobuf.Enum {
  public typealias RawValue = Int
  case none // = 0
  case insufficientBalance // = 1
  case invalidUtxoamount // = 2
  case transferAmountLessThanMinCapacity // = 3
  case UNRECOGNIZED(Int)

  public init() {
    self = .none
  }

  public init?(rawValue: Int) {
    switch rawValue {
    case 0: self = .none
    case 1: self = .insufficientBalance
    case 2: self = .invalidUtxoamount
    case 3: self = .transferAmountLessThanMinCapacity
    default: self = .UNRECOGNIZED(rawValue)
    }
  }

  public var rawValue: Int {
    switch self {
    case .none: return 0
    case .insufficientBalance: return 1
    case .invalidUtxoamount: return 2
    case .transferAmountLessThanMinCapacity: return 3
    case .UNRECOGNIZED(let i): return i
    }
  }

}

#if swift(>=4.2)

extension TW_Kaspa_Proto_TransferError: CaseIterable {
  // The compiler won't synthesize support with the UNRECOGNIZED case.
  public static var allCases: [TW_Kaspa_Proto_TransferError] = [
    .none,
    .insufficientBalance,
    .invalidUtxoamount,
    .transferAmountLessThanMinCapacity,
  ]
}

#endif  // swift(>=4.2)

public struct TW_Kaspa_Proto_TransferMessage {
  // SwiftProtobuf.Message conformance is added in an extension below. See the
  // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
  // methods supported on all messages.

  public var privateKey: [Data] = []

  public var amount: Int64 = 0

  public var fee: Int64 = 0

  public var to: String = String()

  public var unspentOutput: [TW_Kaspa_Proto_BitcoinUnspentOutput] = []

  public var changeAddress: String = String()

  public var useMaxAmount: Bool = false

  public var byteFee: Int64 = 0

  public var unknownFields = SwiftProtobuf.UnknownStorage()

  public init() {}
}

public struct TW_Kaspa_Proto_SigningInput {
  // SwiftProtobuf.Message conformance is added in an extension below. See the
  // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
  // methods supported on all messages.

  public var messageOneof: TW_Kaspa_Proto_SigningInput.OneOf_MessageOneof? = nil

  public var transfer: TW_Kaspa_Proto_TransferMessage {
    get {
      if case .transfer(let v)? = messageOneof {return v}
      return TW_Kaspa_Proto_TransferMessage()
    }
    set {messageOneof = .transfer(newValue)}
  }

  public var unknownFields = SwiftProtobuf.UnknownStorage()

  public enum OneOf_MessageOneof: Equatable {
    case transfer(TW_Kaspa_Proto_TransferMessage)

  #if !swift(>=4.1)
    public static func ==(lhs: TW_Kaspa_Proto_SigningInput.OneOf_MessageOneof, rhs: TW_Kaspa_Proto_SigningInput.OneOf_MessageOneof) -> Bool {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch (lhs, rhs) {
      case (.transfer, .transfer): return {
        guard case .transfer(let l) = lhs, case .transfer(let r) = rhs else { preconditionFailure() }
        return l == r
      }()
      }
    }
  #endif
  }

  public init() {}
}

/// Transaction signing output.
public struct TW_Kaspa_Proto_SigningOutput {
  // SwiftProtobuf.Message conformance is added in an extension below. See the
  // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
  // methods supported on all messages.

  /// Signed and encoded transaction bytes.
  public var json: String = String()

  public var unknownFields = SwiftProtobuf.UnknownStorage()

  public init() {}
}

public struct TW_Kaspa_Proto_BitcoinUnspentOutput {
  // SwiftProtobuf.Message conformance is added in an extension below. See the
  // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
  // methods supported on all messages.

  public var transactionHash: String = String()

  public var outputIndex: Int32 = 0

  public var amount: Int64 = 0

  public var outputScript: String = String()

  public var address: String = String()

  public var unknownFields = SwiftProtobuf.UnknownStorage()

  public init() {}
}

public struct TW_Kaspa_Proto_TransferPlan {
  // SwiftProtobuf.Message conformance is added in an extension below. See the
  // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
  // methods supported on all messages.

  public var amount: Int64 = 0

  public var availableAmount: Int64 = 0

  public var fee: Int64 = 0

  public var change: Int64 = 0

  public var error: TW_Kaspa_Proto_TransferError = .none

  public var unknownFields = SwiftProtobuf.UnknownStorage()

  public init() {}
}

public struct TW_Kaspa_Proto_TransactionPlan {
  // SwiftProtobuf.Message conformance is added in an extension below. See the
  // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
  // methods supported on all messages.

  public var messageOneof: TW_Kaspa_Proto_TransactionPlan.OneOf_MessageOneof? = nil

  public var transfer: TW_Kaspa_Proto_TransferPlan {
    get {
      if case .transfer(let v)? = messageOneof {return v}
      return TW_Kaspa_Proto_TransferPlan()
    }
    set {messageOneof = .transfer(newValue)}
  }

  public var unknownFields = SwiftProtobuf.UnknownStorage()

  public enum OneOf_MessageOneof: Equatable {
    case transfer(TW_Kaspa_Proto_TransferPlan)

  #if !swift(>=4.1)
    public static func ==(lhs: TW_Kaspa_Proto_TransactionPlan.OneOf_MessageOneof, rhs: TW_Kaspa_Proto_TransactionPlan.OneOf_MessageOneof) -> Bool {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch (lhs, rhs) {
      case (.transfer, .transfer): return {
        guard case .transfer(let l) = lhs, case .transfer(let r) = rhs else { preconditionFailure() }
        return l == r
      }()
      }
    }
  #endif
  }

  public init() {}
}

// MARK: - Code below here is support for the SwiftProtobuf runtime.

fileprivate let _protobuf_package = "TW.Kaspa.Proto"

extension TW_Kaspa_Proto_TransferError: SwiftProtobuf._ProtoNameProviding {
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    0: .same(proto: "NONE"),
    1: .same(proto: "InsufficientBalance"),
    2: .same(proto: "InvalidUTXOAmount"),
    3: .same(proto: "TransferAmountLessThanMinCapacity"),
  ]
}

extension TW_Kaspa_Proto_TransferMessage: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = _protobuf_package + ".TransferMessage"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .standard(proto: "private_key"),
    2: .same(proto: "amount"),
    3: .same(proto: "fee"),
    4: .same(proto: "to"),
    5: .same(proto: "unspentOutput"),
    6: .same(proto: "changeAddress"),
    7: .same(proto: "useMaxAmount"),
    8: .same(proto: "byteFee"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeRepeatedBytesField(value: &self.privateKey) }()
      case 2: try { try decoder.decodeSingularInt64Field(value: &self.amount) }()
      case 3: try { try decoder.decodeSingularInt64Field(value: &self.fee) }()
      case 4: try { try decoder.decodeSingularStringField(value: &self.to) }()
      case 5: try { try decoder.decodeRepeatedMessageField(value: &self.unspentOutput) }()
      case 6: try { try decoder.decodeSingularStringField(value: &self.changeAddress) }()
      case 7: try { try decoder.decodeSingularBoolField(value: &self.useMaxAmount) }()
      case 8: try { try decoder.decodeSingularInt64Field(value: &self.byteFee) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    if !self.privateKey.isEmpty {
      try visitor.visitRepeatedBytesField(value: self.privateKey, fieldNumber: 1)
    }
    if self.amount != 0 {
      try visitor.visitSingularInt64Field(value: self.amount, fieldNumber: 2)
    }
    if self.fee != 0 {
      try visitor.visitSingularInt64Field(value: self.fee, fieldNumber: 3)
    }
    if !self.to.isEmpty {
      try visitor.visitSingularStringField(value: self.to, fieldNumber: 4)
    }
    if !self.unspentOutput.isEmpty {
      try visitor.visitRepeatedMessageField(value: self.unspentOutput, fieldNumber: 5)
    }
    if !self.changeAddress.isEmpty {
      try visitor.visitSingularStringField(value: self.changeAddress, fieldNumber: 6)
    }
    if self.useMaxAmount != false {
      try visitor.visitSingularBoolField(value: self.useMaxAmount, fieldNumber: 7)
    }
    if self.byteFee != 0 {
      try visitor.visitSingularInt64Field(value: self.byteFee, fieldNumber: 8)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_Kaspa_Proto_TransferMessage, rhs: TW_Kaspa_Proto_TransferMessage) -> Bool {
    if lhs.privateKey != rhs.privateKey {return false}
    if lhs.amount != rhs.amount {return false}
    if lhs.fee != rhs.fee {return false}
    if lhs.to != rhs.to {return false}
    if lhs.unspentOutput != rhs.unspentOutput {return false}
    if lhs.changeAddress != rhs.changeAddress {return false}
    if lhs.useMaxAmount != rhs.useMaxAmount {return false}
    if lhs.byteFee != rhs.byteFee {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_Kaspa_Proto_SigningInput: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = _protobuf_package + ".SigningInput"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "transfer"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try {
        var v: TW_Kaspa_Proto_TransferMessage?
        var hadOneofValue = false
        if let current = self.messageOneof {
          hadOneofValue = true
          if case .transfer(let m) = current {v = m}
        }
        try decoder.decodeSingularMessageField(value: &v)
        if let v = v {
          if hadOneofValue {try decoder.handleConflictingOneOf()}
          self.messageOneof = .transfer(v)
        }
      }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    // The use of inline closures is to circumvent an issue where the compiler
    // allocates stack space for every if/case branch local when no optimizations
    // are enabled. https://github.com/apple/swift-protobuf/issues/1034 and
    // https://github.com/apple/swift-protobuf/issues/1182
    try { if case .transfer(let v)? = self.messageOneof {
      try visitor.visitSingularMessageField(value: v, fieldNumber: 1)
    } }()
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_Kaspa_Proto_SigningInput, rhs: TW_Kaspa_Proto_SigningInput) -> Bool {
    if lhs.messageOneof != rhs.messageOneof {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_Kaspa_Proto_SigningOutput: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = _protobuf_package + ".SigningOutput"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "json"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeSingularStringField(value: &self.json) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    if !self.json.isEmpty {
      try visitor.visitSingularStringField(value: self.json, fieldNumber: 1)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_Kaspa_Proto_SigningOutput, rhs: TW_Kaspa_Proto_SigningOutput) -> Bool {
    if lhs.json != rhs.json {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_Kaspa_Proto_BitcoinUnspentOutput: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = _protobuf_package + ".BitcoinUnspentOutput"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "transactionHash"),
    2: .same(proto: "outputIndex"),
    3: .same(proto: "amount"),
    4: .same(proto: "outputScript"),
    5: .same(proto: "address"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeSingularStringField(value: &self.transactionHash) }()
      case 2: try { try decoder.decodeSingularInt32Field(value: &self.outputIndex) }()
      case 3: try { try decoder.decodeSingularInt64Field(value: &self.amount) }()
      case 4: try { try decoder.decodeSingularStringField(value: &self.outputScript) }()
      case 5: try { try decoder.decodeSingularStringField(value: &self.address) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    if !self.transactionHash.isEmpty {
      try visitor.visitSingularStringField(value: self.transactionHash, fieldNumber: 1)
    }
    if self.outputIndex != 0 {
      try visitor.visitSingularInt32Field(value: self.outputIndex, fieldNumber: 2)
    }
    if self.amount != 0 {
      try visitor.visitSingularInt64Field(value: self.amount, fieldNumber: 3)
    }
    if !self.outputScript.isEmpty {
      try visitor.visitSingularStringField(value: self.outputScript, fieldNumber: 4)
    }
    if !self.address.isEmpty {
      try visitor.visitSingularStringField(value: self.address, fieldNumber: 5)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_Kaspa_Proto_BitcoinUnspentOutput, rhs: TW_Kaspa_Proto_BitcoinUnspentOutput) -> Bool {
    if lhs.transactionHash != rhs.transactionHash {return false}
    if lhs.outputIndex != rhs.outputIndex {return false}
    if lhs.amount != rhs.amount {return false}
    if lhs.outputScript != rhs.outputScript {return false}
    if lhs.address != rhs.address {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_Kaspa_Proto_TransferPlan: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = _protobuf_package + ".TransferPlan"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "amount"),
    2: .same(proto: "availableAmount"),
    3: .same(proto: "fee"),
    4: .same(proto: "change"),
    5: .same(proto: "error"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeSingularInt64Field(value: &self.amount) }()
      case 2: try { try decoder.decodeSingularInt64Field(value: &self.availableAmount) }()
      case 3: try { try decoder.decodeSingularInt64Field(value: &self.fee) }()
      case 4: try { try decoder.decodeSingularInt64Field(value: &self.change) }()
      case 5: try { try decoder.decodeSingularEnumField(value: &self.error) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    if self.amount != 0 {
      try visitor.visitSingularInt64Field(value: self.amount, fieldNumber: 1)
    }
    if self.availableAmount != 0 {
      try visitor.visitSingularInt64Field(value: self.availableAmount, fieldNumber: 2)
    }
    if self.fee != 0 {
      try visitor.visitSingularInt64Field(value: self.fee, fieldNumber: 3)
    }
    if self.change != 0 {
      try visitor.visitSingularInt64Field(value: self.change, fieldNumber: 4)
    }
    if self.error != .none {
      try visitor.visitSingularEnumField(value: self.error, fieldNumber: 5)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_Kaspa_Proto_TransferPlan, rhs: TW_Kaspa_Proto_TransferPlan) -> Bool {
    if lhs.amount != rhs.amount {return false}
    if lhs.availableAmount != rhs.availableAmount {return false}
    if lhs.fee != rhs.fee {return false}
    if lhs.change != rhs.change {return false}
    if lhs.error != rhs.error {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_Kaspa_Proto_TransactionPlan: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = _protobuf_package + ".TransactionPlan"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "transfer"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try {
        var v: TW_Kaspa_Proto_TransferPlan?
        var hadOneofValue = false
        if let current = self.messageOneof {
          hadOneofValue = true
          if case .transfer(let m) = current {v = m}
        }
        try decoder.decodeSingularMessageField(value: &v)
        if let v = v {
          if hadOneofValue {try decoder.handleConflictingOneOf()}
          self.messageOneof = .transfer(v)
        }
      }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    // The use of inline closures is to circumvent an issue where the compiler
    // allocates stack space for every if/case branch local when no optimizations
    // are enabled. https://github.com/apple/swift-protobuf/issues/1034 and
    // https://github.com/apple/swift-protobuf/issues/1182
    try { if case .transfer(let v)? = self.messageOneof {
      try visitor.visitSingularMessageField(value: v, fieldNumber: 1)
    } }()
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_Kaspa_Proto_TransactionPlan, rhs: TW_Kaspa_Proto_TransactionPlan) -> Bool {
    if lhs.messageOneof != rhs.messageOneof {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}
