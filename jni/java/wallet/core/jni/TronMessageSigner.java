// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

package wallet.core.jni;

import java.security.InvalidParameterException;

/// Tron message signing and verification.
///
/// Tron and some other wallets support a message signing & verification format, to create a proof (a signature)
/// that someone has access to the private keys of a specific address.
public class TronMessageSigner {
    private byte[] bytes;

    private TronMessageSigner() {
    }

    static TronMessageSigner createFromNative(byte[] bytes) {
        TronMessageSigner instance = new TronMessageSigner();
        instance.bytes = bytes;
        return instance;
    }
    /// Sign a message.
    ///
    /// \param privateKey: the private key used for signing
    /// \param message: A custom message which is input to the signing.
    /// \returns the signature, Hex-encoded. On invalid input empty string is returned. Returned object needs to be deleted after use.
    public static native String signMessage(PrivateKey privateKey, String message);
    /// Verify signature for a message.
    ///
    /// \param pubKey: pubKey that will verify and recover the message from the signature
    /// \param message: the message signed (without prefix)
    /// \param signature: in Hex-encoded form.
    /// \returns false on any invalid input (does not throw), true if the message can be recovered from the signature
    public static native boolean verifyMessage(PublicKey pubKey, String message, String signature);
}
