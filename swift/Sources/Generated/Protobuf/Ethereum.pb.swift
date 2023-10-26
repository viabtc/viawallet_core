// DO NOT EDIT.
// swift-format-ignore-file
//
// Generated by the Swift generator plugin for the protocol buffer compiler.
// Source: Ethereum.proto
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

/// Transaction type
public enum TW_Ethereum_Proto_TransactionMode: SwiftProtobuf.Enum {
  public typealias RawValue = Int

  /// Legacy transaction, pre-EIP2718/EIP1559; for fee gasPrice/gasLimit is used
  case legacy // = 0

  /// Enveloped transaction EIP2718 (with type 0x2), fee is according to EIP1559 (base fee, inclusion fee, ...) 
  case enveloped // = 1
  case UNRECOGNIZED(Int)

  public init() {
    self = .legacy
  }

  public init?(rawValue: Int) {
    switch rawValue {
    case 0: self = .legacy
    case 1: self = .enveloped
    default: self = .UNRECOGNIZED(rawValue)
    }
  }

  public var rawValue: Int {
    switch self {
    case .legacy: return 0
    case .enveloped: return 1
    case .UNRECOGNIZED(let i): return i
    }
  }

}

#if swift(>=4.2)

extension TW_Ethereum_Proto_TransactionMode: CaseIterable {
  // The compiler won't synthesize support with the UNRECOGNIZED case.
  public static var allCases: [TW_Ethereum_Proto_TransactionMode] = [
    .legacy,
    .enveloped,
  ]
}

#endif  // swift(>=4.2)

/// Transaction (transfer, smart contract call, ...)
public struct TW_Ethereum_Proto_Transaction {
  // SwiftProtobuf.Message conformance is added in an extension below. See the
  // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
  // methods supported on all messages.

  /// Payload transfer
  public var transactionOneof: TW_Ethereum_Proto_Transaction.OneOf_TransactionOneof? = nil

  public var transfer: TW_Ethereum_Proto_Transaction.Transfer {
    get {
      if case .transfer(let v)? = transactionOneof {return v}
      return TW_Ethereum_Proto_Transaction.Transfer()
    }
    set {transactionOneof = .transfer(newValue)}
  }

  public var erc20Transfer: TW_Ethereum_Proto_Transaction.ERC20Transfer {
    get {
      if case .erc20Transfer(let v)? = transactionOneof {return v}
      return TW_Ethereum_Proto_Transaction.ERC20Transfer()
    }
    set {transactionOneof = .erc20Transfer(newValue)}
  }

  public var erc20Approve: TW_Ethereum_Proto_Transaction.ERC20Approve {
    get {
      if case .erc20Approve(let v)? = transactionOneof {return v}
      return TW_Ethereum_Proto_Transaction.ERC20Approve()
    }
    set {transactionOneof = .erc20Approve(newValue)}
  }

  public var erc721Transfer: TW_Ethereum_Proto_Transaction.ERC721Transfer {
    get {
      if case .erc721Transfer(let v)? = transactionOneof {return v}
      return TW_Ethereum_Proto_Transaction.ERC721Transfer()
    }
    set {transactionOneof = .erc721Transfer(newValue)}
  }

  public var erc1155Transfer: TW_Ethereum_Proto_Transaction.ERC1155Transfer {
    get {
      if case .erc1155Transfer(let v)? = transactionOneof {return v}
      return TW_Ethereum_Proto_Transaction.ERC1155Transfer()
    }
    set {transactionOneof = .erc1155Transfer(newValue)}
  }

  public var contractGeneric: TW_Ethereum_Proto_Transaction.ContractGeneric {
    get {
      if case .contractGeneric(let v)? = transactionOneof {return v}
      return TW_Ethereum_Proto_Transaction.ContractGeneric()
    }
    set {transactionOneof = .contractGeneric(newValue)}
  }

  public var unknownFields = SwiftProtobuf.UnknownStorage()

  /// Payload transfer
  public enum OneOf_TransactionOneof: Equatable {
    case transfer(TW_Ethereum_Proto_Transaction.Transfer)
    case erc20Transfer(TW_Ethereum_Proto_Transaction.ERC20Transfer)
    case erc20Approve(TW_Ethereum_Proto_Transaction.ERC20Approve)
    case erc721Transfer(TW_Ethereum_Proto_Transaction.ERC721Transfer)
    case erc1155Transfer(TW_Ethereum_Proto_Transaction.ERC1155Transfer)
    case contractGeneric(TW_Ethereum_Proto_Transaction.ContractGeneric)

  #if !swift(>=4.1)
    public static func ==(lhs: TW_Ethereum_Proto_Transaction.OneOf_TransactionOneof, rhs: TW_Ethereum_Proto_Transaction.OneOf_TransactionOneof) -> Bool {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch (lhs, rhs) {
      case (.transfer, .transfer): return {
        guard case .transfer(let l) = lhs, case .transfer(let r) = rhs else { preconditionFailure() }
        return l == r
      }()
      case (.erc20Transfer, .erc20Transfer): return {
        guard case .erc20Transfer(let l) = lhs, case .erc20Transfer(let r) = rhs else { preconditionFailure() }
        return l == r
      }()
      case (.erc20Approve, .erc20Approve): return {
        guard case .erc20Approve(let l) = lhs, case .erc20Approve(let r) = rhs else { preconditionFailure() }
        return l == r
      }()
      case (.erc721Transfer, .erc721Transfer): return {
        guard case .erc721Transfer(let l) = lhs, case .erc721Transfer(let r) = rhs else { preconditionFailure() }
        return l == r
      }()
      case (.erc1155Transfer, .erc1155Transfer): return {
        guard case .erc1155Transfer(let l) = lhs, case .erc1155Transfer(let r) = rhs else { preconditionFailure() }
        return l == r
      }()
      case (.contractGeneric, .contractGeneric): return {
        guard case .contractGeneric(let l) = lhs, case .contractGeneric(let r) = rhs else { preconditionFailure() }
        return l == r
      }()
      default: return false
      }
    }
  #endif
  }

  /// Native coin transfer transaction
  public struct Transfer {
    // SwiftProtobuf.Message conformance is added in an extension below. See the
    // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
    // methods supported on all messages.

    /// Amount to send in wei (uint256, serialized little endian)
    public var amount: Data = Data()

    /// Optional payload data
    public var data: Data = Data()

    public var unknownFields = SwiftProtobuf.UnknownStorage()

    public init() {}
  }

  /// ERC20 token transfer transaction
  public struct ERC20Transfer {
    // SwiftProtobuf.Message conformance is added in an extension below. See the
    // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
    // methods supported on all messages.

    /// destination address (string)
    public var to: String = String()

    /// Amount to send (uint256, serialized little endian)
    public var amount: Data = Data()

    public var unknownFields = SwiftProtobuf.UnknownStorage()

    public init() {}
  }

  /// ERC20 approve transaction
  public struct ERC20Approve {
    // SwiftProtobuf.Message conformance is added in an extension below. See the
    // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
    // methods supported on all messages.

    /// Target of the approval
    public var spender: String = String()

    /// Amount to send (uint256, serialized little endian)
    public var amount: Data = Data()

    public var unknownFields = SwiftProtobuf.UnknownStorage()

    public init() {}
  }

  /// ERC721 NFT transfer transaction
  public struct ERC721Transfer {
    // SwiftProtobuf.Message conformance is added in an extension below. See the
    // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
    // methods supported on all messages.

    /// Source address
    public var from: String = String()

    /// Destination address
    public var to: String = String()

    /// ID of the token (uint256, serialized little endian)
    public var tokenID: Data = Data()

    public var unknownFields = SwiftProtobuf.UnknownStorage()

    public init() {}
  }

  /// ERC1155 NFT transfer transaction
  public struct ERC1155Transfer {
    // SwiftProtobuf.Message conformance is added in an extension below. See the
    // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
    // methods supported on all messages.

    /// Source address
    public var from: String = String()

    /// Destination address
    public var to: String = String()

    /// ID of the token (uint256, serialized little endian)
    public var tokenID: Data = Data()

    /// The amount of tokens being transferred (uint256, serialized little endian)
    public var value: Data = Data()

    public var data: Data = Data()

    public var unknownFields = SwiftProtobuf.UnknownStorage()

    public init() {}
  }

  /// Generic smart contract transaction
  public struct ContractGeneric {
    // SwiftProtobuf.Message conformance is added in an extension below. See the
    // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
    // methods supported on all messages.

    /// Amount to send in wei (uint256, serialized little endian)
    public var amount: Data = Data()

    /// Contract call payload data
    public var data: Data = Data()

    public var unknownFields = SwiftProtobuf.UnknownStorage()

    public init() {}
  }

  public init() {}
}

/// Input data necessary to create a signed transaction.
/// Legacy and EIP2718/EIP1559 transactions supported, see TransactionMode.
public struct TW_Ethereum_Proto_SigningInput {
  // SwiftProtobuf.Message conformance is added in an extension below. See the
  // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
  // methods supported on all messages.

  /// Chain identifier (uint256, serialized little endian)
  public var chainID: Data = Data()

  /// Nonce (uint256, serialized little endian)
  public var nonce: Data = Data()

  /// Transaction version selector: Legacy or enveloped, has impact on fee structure.
  /// Default is Legacy (value 0)
  public var txMode: TW_Ethereum_Proto_TransactionMode = .legacy

  /// Gas price (uint256, serialized little endian)
  /// Relevant for legacy transactions only (disregarded for enveloped/EIP1559)
  public var gasPrice: Data = Data()

  /// Gas limit (uint256, serialized little endian)
  public var gasLimit: Data = Data()

  /// Maximum optional inclusion fee (aka tip) (uint256, serialized little endian)
  /// Relevant for enveloped/EIP1559 transactions only, tx_mode=Enveloped, (disregarded for legacy)
  public var maxInclusionFeePerGas: Data = Data()

  /// Maximum fee (uint256, serialized little endian)
  /// Relevant for enveloped/EIP1559 transactions only, tx_mode=Enveloped, (disregarded for legacy)
  public var maxFeePerGas: Data = Data()

  /// Recipient's address.
  public var toAddress: String = String()

  /// The secret private key used for signing (32 bytes).
  public var privateKey: Data = Data()

  /// The payload transaction
  public var transaction: TW_Ethereum_Proto_Transaction {
    get {return _transaction ?? TW_Ethereum_Proto_Transaction()}
    set {_transaction = newValue}
  }
  /// Returns true if `transaction` has been explicitly set.
  public var hasTransaction: Bool {return self._transaction != nil}
  /// Clears the value of `transaction`. Subsequent reads from it will return its default value.
  public mutating func clearTransaction() {self._transaction = nil}

  public var unknownFields = SwiftProtobuf.UnknownStorage()

  public init() {}

  fileprivate var _transaction: TW_Ethereum_Proto_Transaction? = nil
}

/// Result containing the signed and encoded transaction.
public struct TW_Ethereum_Proto_SigningOutput {
  // SwiftProtobuf.Message conformance is added in an extension below. See the
  // `Message` and `Message+*Additions` files in the SwiftProtobuf library for
  // methods supported on all messages.

  /// Signed and encoded transaction bytes.
  public var encoded: Data = Data()

  /// The V, R, S components of the resulting signature, (each uint256, serialized little endian)
  public var v: Data = Data()

  public var r: Data = Data()

  public var s: Data = Data()

  /// The payload part, supplied in the input or assembled from input parameters
  public var data: Data = Data()

  /// error code, 0 is ok, other codes will be treated as errors
  public var error: TW_Common_Proto_SigningError = .ok

  /// error code description
  public var errorMessage: String = String()

  public var unknownFields = SwiftProtobuf.UnknownStorage()

  public init() {}
}

// MARK: - Code below here is support for the SwiftProtobuf runtime.

fileprivate let _protobuf_package = "TW.Ethereum.Proto"

extension TW_Ethereum_Proto_TransactionMode: SwiftProtobuf._ProtoNameProviding {
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    0: .same(proto: "Legacy"),
    1: .same(proto: "Enveloped"),
  ]
}

extension TW_Ethereum_Proto_Transaction: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = _protobuf_package + ".Transaction"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "transfer"),
    2: .standard(proto: "erc20_transfer"),
    3: .standard(proto: "erc20_approve"),
    4: .standard(proto: "erc721_transfer"),
    5: .standard(proto: "erc1155_transfer"),
    6: .standard(proto: "contract_generic"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try {
        var v: TW_Ethereum_Proto_Transaction.Transfer?
        var hadOneofValue = false
        if let current = self.transactionOneof {
          hadOneofValue = true
          if case .transfer(let m) = current {v = m}
        }
        try decoder.decodeSingularMessageField(value: &v)
        if let v = v {
          if hadOneofValue {try decoder.handleConflictingOneOf()}
          self.transactionOneof = .transfer(v)
        }
      }()
      case 2: try {
        var v: TW_Ethereum_Proto_Transaction.ERC20Transfer?
        var hadOneofValue = false
        if let current = self.transactionOneof {
          hadOneofValue = true
          if case .erc20Transfer(let m) = current {v = m}
        }
        try decoder.decodeSingularMessageField(value: &v)
        if let v = v {
          if hadOneofValue {try decoder.handleConflictingOneOf()}
          self.transactionOneof = .erc20Transfer(v)
        }
      }()
      case 3: try {
        var v: TW_Ethereum_Proto_Transaction.ERC20Approve?
        var hadOneofValue = false
        if let current = self.transactionOneof {
          hadOneofValue = true
          if case .erc20Approve(let m) = current {v = m}
        }
        try decoder.decodeSingularMessageField(value: &v)
        if let v = v {
          if hadOneofValue {try decoder.handleConflictingOneOf()}
          self.transactionOneof = .erc20Approve(v)
        }
      }()
      case 4: try {
        var v: TW_Ethereum_Proto_Transaction.ERC721Transfer?
        var hadOneofValue = false
        if let current = self.transactionOneof {
          hadOneofValue = true
          if case .erc721Transfer(let m) = current {v = m}
        }
        try decoder.decodeSingularMessageField(value: &v)
        if let v = v {
          if hadOneofValue {try decoder.handleConflictingOneOf()}
          self.transactionOneof = .erc721Transfer(v)
        }
      }()
      case 5: try {
        var v: TW_Ethereum_Proto_Transaction.ERC1155Transfer?
        var hadOneofValue = false
        if let current = self.transactionOneof {
          hadOneofValue = true
          if case .erc1155Transfer(let m) = current {v = m}
        }
        try decoder.decodeSingularMessageField(value: &v)
        if let v = v {
          if hadOneofValue {try decoder.handleConflictingOneOf()}
          self.transactionOneof = .erc1155Transfer(v)
        }
      }()
      case 6: try {
        var v: TW_Ethereum_Proto_Transaction.ContractGeneric?
        var hadOneofValue = false
        if let current = self.transactionOneof {
          hadOneofValue = true
          if case .contractGeneric(let m) = current {v = m}
        }
        try decoder.decodeSingularMessageField(value: &v)
        if let v = v {
          if hadOneofValue {try decoder.handleConflictingOneOf()}
          self.transactionOneof = .contractGeneric(v)
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
    switch self.transactionOneof {
    case .transfer?: try {
      guard case .transfer(let v)? = self.transactionOneof else { preconditionFailure() }
      try visitor.visitSingularMessageField(value: v, fieldNumber: 1)
    }()
    case .erc20Transfer?: try {
      guard case .erc20Transfer(let v)? = self.transactionOneof else { preconditionFailure() }
      try visitor.visitSingularMessageField(value: v, fieldNumber: 2)
    }()
    case .erc20Approve?: try {
      guard case .erc20Approve(let v)? = self.transactionOneof else { preconditionFailure() }
      try visitor.visitSingularMessageField(value: v, fieldNumber: 3)
    }()
    case .erc721Transfer?: try {
      guard case .erc721Transfer(let v)? = self.transactionOneof else { preconditionFailure() }
      try visitor.visitSingularMessageField(value: v, fieldNumber: 4)
    }()
    case .erc1155Transfer?: try {
      guard case .erc1155Transfer(let v)? = self.transactionOneof else { preconditionFailure() }
      try visitor.visitSingularMessageField(value: v, fieldNumber: 5)
    }()
    case .contractGeneric?: try {
      guard case .contractGeneric(let v)? = self.transactionOneof else { preconditionFailure() }
      try visitor.visitSingularMessageField(value: v, fieldNumber: 6)
    }()
    case nil: break
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_Ethereum_Proto_Transaction, rhs: TW_Ethereum_Proto_Transaction) -> Bool {
    if lhs.transactionOneof != rhs.transactionOneof {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_Ethereum_Proto_Transaction.Transfer: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = TW_Ethereum_Proto_Transaction.protoMessageName + ".Transfer"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "amount"),
    2: .same(proto: "data"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeSingularBytesField(value: &self.amount) }()
      case 2: try { try decoder.decodeSingularBytesField(value: &self.data) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    if !self.amount.isEmpty {
      try visitor.visitSingularBytesField(value: self.amount, fieldNumber: 1)
    }
    if !self.data.isEmpty {
      try visitor.visitSingularBytesField(value: self.data, fieldNumber: 2)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_Ethereum_Proto_Transaction.Transfer, rhs: TW_Ethereum_Proto_Transaction.Transfer) -> Bool {
    if lhs.amount != rhs.amount {return false}
    if lhs.data != rhs.data {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_Ethereum_Proto_Transaction.ERC20Transfer: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = TW_Ethereum_Proto_Transaction.protoMessageName + ".ERC20Transfer"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "to"),
    2: .same(proto: "amount"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeSingularStringField(value: &self.to) }()
      case 2: try { try decoder.decodeSingularBytesField(value: &self.amount) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    if !self.to.isEmpty {
      try visitor.visitSingularStringField(value: self.to, fieldNumber: 1)
    }
    if !self.amount.isEmpty {
      try visitor.visitSingularBytesField(value: self.amount, fieldNumber: 2)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_Ethereum_Proto_Transaction.ERC20Transfer, rhs: TW_Ethereum_Proto_Transaction.ERC20Transfer) -> Bool {
    if lhs.to != rhs.to {return false}
    if lhs.amount != rhs.amount {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_Ethereum_Proto_Transaction.ERC20Approve: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = TW_Ethereum_Proto_Transaction.protoMessageName + ".ERC20Approve"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "spender"),
    2: .same(proto: "amount"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeSingularStringField(value: &self.spender) }()
      case 2: try { try decoder.decodeSingularBytesField(value: &self.amount) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    if !self.spender.isEmpty {
      try visitor.visitSingularStringField(value: self.spender, fieldNumber: 1)
    }
    if !self.amount.isEmpty {
      try visitor.visitSingularBytesField(value: self.amount, fieldNumber: 2)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_Ethereum_Proto_Transaction.ERC20Approve, rhs: TW_Ethereum_Proto_Transaction.ERC20Approve) -> Bool {
    if lhs.spender != rhs.spender {return false}
    if lhs.amount != rhs.amount {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_Ethereum_Proto_Transaction.ERC721Transfer: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = TW_Ethereum_Proto_Transaction.protoMessageName + ".ERC721Transfer"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "from"),
    2: .same(proto: "to"),
    3: .standard(proto: "token_id"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeSingularStringField(value: &self.from) }()
      case 2: try { try decoder.decodeSingularStringField(value: &self.to) }()
      case 3: try { try decoder.decodeSingularBytesField(value: &self.tokenID) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    if !self.from.isEmpty {
      try visitor.visitSingularStringField(value: self.from, fieldNumber: 1)
    }
    if !self.to.isEmpty {
      try visitor.visitSingularStringField(value: self.to, fieldNumber: 2)
    }
    if !self.tokenID.isEmpty {
      try visitor.visitSingularBytesField(value: self.tokenID, fieldNumber: 3)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_Ethereum_Proto_Transaction.ERC721Transfer, rhs: TW_Ethereum_Proto_Transaction.ERC721Transfer) -> Bool {
    if lhs.from != rhs.from {return false}
    if lhs.to != rhs.to {return false}
    if lhs.tokenID != rhs.tokenID {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_Ethereum_Proto_Transaction.ERC1155Transfer: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = TW_Ethereum_Proto_Transaction.protoMessageName + ".ERC1155Transfer"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "from"),
    2: .same(proto: "to"),
    3: .standard(proto: "token_id"),
    4: .same(proto: "value"),
    5: .same(proto: "data"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeSingularStringField(value: &self.from) }()
      case 2: try { try decoder.decodeSingularStringField(value: &self.to) }()
      case 3: try { try decoder.decodeSingularBytesField(value: &self.tokenID) }()
      case 4: try { try decoder.decodeSingularBytesField(value: &self.value) }()
      case 5: try { try decoder.decodeSingularBytesField(value: &self.data) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    if !self.from.isEmpty {
      try visitor.visitSingularStringField(value: self.from, fieldNumber: 1)
    }
    if !self.to.isEmpty {
      try visitor.visitSingularStringField(value: self.to, fieldNumber: 2)
    }
    if !self.tokenID.isEmpty {
      try visitor.visitSingularBytesField(value: self.tokenID, fieldNumber: 3)
    }
    if !self.value.isEmpty {
      try visitor.visitSingularBytesField(value: self.value, fieldNumber: 4)
    }
    if !self.data.isEmpty {
      try visitor.visitSingularBytesField(value: self.data, fieldNumber: 5)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_Ethereum_Proto_Transaction.ERC1155Transfer, rhs: TW_Ethereum_Proto_Transaction.ERC1155Transfer) -> Bool {
    if lhs.from != rhs.from {return false}
    if lhs.to != rhs.to {return false}
    if lhs.tokenID != rhs.tokenID {return false}
    if lhs.value != rhs.value {return false}
    if lhs.data != rhs.data {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_Ethereum_Proto_Transaction.ContractGeneric: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = TW_Ethereum_Proto_Transaction.protoMessageName + ".ContractGeneric"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "amount"),
    2: .same(proto: "data"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeSingularBytesField(value: &self.amount) }()
      case 2: try { try decoder.decodeSingularBytesField(value: &self.data) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    if !self.amount.isEmpty {
      try visitor.visitSingularBytesField(value: self.amount, fieldNumber: 1)
    }
    if !self.data.isEmpty {
      try visitor.visitSingularBytesField(value: self.data, fieldNumber: 2)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_Ethereum_Proto_Transaction.ContractGeneric, rhs: TW_Ethereum_Proto_Transaction.ContractGeneric) -> Bool {
    if lhs.amount != rhs.amount {return false}
    if lhs.data != rhs.data {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_Ethereum_Proto_SigningInput: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = _protobuf_package + ".SigningInput"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .standard(proto: "chain_id"),
    2: .same(proto: "nonce"),
    3: .standard(proto: "tx_mode"),
    4: .standard(proto: "gas_price"),
    5: .standard(proto: "gas_limit"),
    6: .standard(proto: "max_inclusion_fee_per_gas"),
    7: .standard(proto: "max_fee_per_gas"),
    8: .standard(proto: "to_address"),
    9: .standard(proto: "private_key"),
    10: .same(proto: "transaction"),
  ]

  public mutating func decodeMessage<D: SwiftProtobuf.Decoder>(decoder: inout D) throws {
    while let fieldNumber = try decoder.nextFieldNumber() {
      // The use of inline closures is to circumvent an issue where the compiler
      // allocates stack space for every case branch when no optimizations are
      // enabled. https://github.com/apple/swift-protobuf/issues/1034
      switch fieldNumber {
      case 1: try { try decoder.decodeSingularBytesField(value: &self.chainID) }()
      case 2: try { try decoder.decodeSingularBytesField(value: &self.nonce) }()
      case 3: try { try decoder.decodeSingularEnumField(value: &self.txMode) }()
      case 4: try { try decoder.decodeSingularBytesField(value: &self.gasPrice) }()
      case 5: try { try decoder.decodeSingularBytesField(value: &self.gasLimit) }()
      case 6: try { try decoder.decodeSingularBytesField(value: &self.maxInclusionFeePerGas) }()
      case 7: try { try decoder.decodeSingularBytesField(value: &self.maxFeePerGas) }()
      case 8: try { try decoder.decodeSingularStringField(value: &self.toAddress) }()
      case 9: try { try decoder.decodeSingularBytesField(value: &self.privateKey) }()
      case 10: try { try decoder.decodeSingularMessageField(value: &self._transaction) }()
      default: break
      }
    }
  }

  public func traverse<V: SwiftProtobuf.Visitor>(visitor: inout V) throws {
    // The use of inline closures is to circumvent an issue where the compiler
    // allocates stack space for every if/case branch local when no optimizations
    // are enabled. https://github.com/apple/swift-protobuf/issues/1034 and
    // https://github.com/apple/swift-protobuf/issues/1182
    if !self.chainID.isEmpty {
      try visitor.visitSingularBytesField(value: self.chainID, fieldNumber: 1)
    }
    if !self.nonce.isEmpty {
      try visitor.visitSingularBytesField(value: self.nonce, fieldNumber: 2)
    }
    if self.txMode != .legacy {
      try visitor.visitSingularEnumField(value: self.txMode, fieldNumber: 3)
    }
    if !self.gasPrice.isEmpty {
      try visitor.visitSingularBytesField(value: self.gasPrice, fieldNumber: 4)
    }
    if !self.gasLimit.isEmpty {
      try visitor.visitSingularBytesField(value: self.gasLimit, fieldNumber: 5)
    }
    if !self.maxInclusionFeePerGas.isEmpty {
      try visitor.visitSingularBytesField(value: self.maxInclusionFeePerGas, fieldNumber: 6)
    }
    if !self.maxFeePerGas.isEmpty {
      try visitor.visitSingularBytesField(value: self.maxFeePerGas, fieldNumber: 7)
    }
    if !self.toAddress.isEmpty {
      try visitor.visitSingularStringField(value: self.toAddress, fieldNumber: 8)
    }
    if !self.privateKey.isEmpty {
      try visitor.visitSingularBytesField(value: self.privateKey, fieldNumber: 9)
    }
    try { if let v = self._transaction {
      try visitor.visitSingularMessageField(value: v, fieldNumber: 10)
    } }()
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_Ethereum_Proto_SigningInput, rhs: TW_Ethereum_Proto_SigningInput) -> Bool {
    if lhs.chainID != rhs.chainID {return false}
    if lhs.nonce != rhs.nonce {return false}
    if lhs.txMode != rhs.txMode {return false}
    if lhs.gasPrice != rhs.gasPrice {return false}
    if lhs.gasLimit != rhs.gasLimit {return false}
    if lhs.maxInclusionFeePerGas != rhs.maxInclusionFeePerGas {return false}
    if lhs.maxFeePerGas != rhs.maxFeePerGas {return false}
    if lhs.toAddress != rhs.toAddress {return false}
    if lhs.privateKey != rhs.privateKey {return false}
    if lhs._transaction != rhs._transaction {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}

extension TW_Ethereum_Proto_SigningOutput: SwiftProtobuf.Message, SwiftProtobuf._MessageImplementationBase, SwiftProtobuf._ProtoNameProviding {
  public static let protoMessageName: String = _protobuf_package + ".SigningOutput"
  public static let _protobuf_nameMap: SwiftProtobuf._NameMap = [
    1: .same(proto: "encoded"),
    2: .same(proto: "v"),
    3: .same(proto: "r"),
    4: .same(proto: "s"),
    5: .same(proto: "data"),
    6: .same(proto: "error"),
    7: .standard(proto: "error_message"),
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
      case 5: try { try decoder.decodeSingularBytesField(value: &self.data) }()
      case 6: try { try decoder.decodeSingularEnumField(value: &self.error) }()
      case 7: try { try decoder.decodeSingularStringField(value: &self.errorMessage) }()
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
    if !self.data.isEmpty {
      try visitor.visitSingularBytesField(value: self.data, fieldNumber: 5)
    }
    if self.error != .ok {
      try visitor.visitSingularEnumField(value: self.error, fieldNumber: 6)
    }
    if !self.errorMessage.isEmpty {
      try visitor.visitSingularStringField(value: self.errorMessage, fieldNumber: 7)
    }
    try unknownFields.traverse(visitor: &visitor)
  }

  public static func ==(lhs: TW_Ethereum_Proto_SigningOutput, rhs: TW_Ethereum_Proto_SigningOutput) -> Bool {
    if lhs.encoded != rhs.encoded {return false}
    if lhs.v != rhs.v {return false}
    if lhs.r != rhs.r {return false}
    if lhs.s != rhs.s {return false}
    if lhs.data != rhs.data {return false}
    if lhs.error != rhs.error {return false}
    if lhs.errorMessage != rhs.errorMessage {return false}
    if lhs.unknownFields != rhs.unknownFields {return false}
    return true
  }
}
