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
import java.util.HashSet;

/// Represents a private key.
public class PrivateKey {
    private long nativeHandle;

    static PrivateKey createFromNative(long nativeHandle) {
        PrivateKey instance = new PrivateKey();
        instance.nativeHandle = nativeHandle;
        PrivateKeyPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Create a random private key
    ///
    /// \note Should be deleted with \TWPrivateKeyDelete
    /// \return Non-null Private key
    static native long nativeCreate();
    /// Create a private key with the given block of data
    ///
    /// \param data a block of data
    /// \note Should be deleted with \TWPrivateKeyDelete
    /// \return Nullable pointer to Private Key
    static native long nativeCreateWithData(byte[] data);
    /// Deep copy a given private key
    ///
    /// \param key Non-null private key to be copied
    /// \note Should be deleted with \TWPrivateKeyDelete
    /// \return Deep copy, Nullable pointer to Private key
    static native long nativeCreateCopy(PrivateKey key);
    static native void nativeDelete(long handle);
    /// Determines if the given private key is valid or not.
    ///
    /// \param data block of data (private key bytes)
    /// \param curve Eliptic curve of the private key
    /// \return true if the private key is valid, false otherwise
    public static native boolean isValid(byte[] data, Curve curve);

    public static native byte[] transform(byte[] data, Curve curve);
    /// Convert the given private key to raw-bytes block of data
    ///
    /// \param pk Non-null pointer to the private key
    /// \return Non-null block of data (raw bytes) of the given private key
    public native byte[] data();
    /// Returns the Secp256k1 public key associated with the given private key
    ///
    /// \param pk Non-null pointer to the private key
    /// \param compressed if the given private key is compressed or not
    /// \return Non-null pointer to the corresponding public key
    public native PublicKey getPublicKeySecp256k1(boolean compressed);
    /// Returns the Nist256p1 public key associated with the given private key
    ///
    /// \param pk Non-null pointer to the private key
    /// \return Non-null pointer to the corresponding public key
    public native PublicKey getPublicKeyNist256p1();
    /// Returns the Ed25519 public key associated with the given private key
    ///
    /// \param pk Non-null pointer to the private key
    /// \return Non-null pointer to the corresponding public key
    public native PublicKey getPublicKeyEd25519();
    /// Returns the Ed25519Blake2b public key associated with the given private key
    ///
    /// \param pk Non-null pointer to the private key
    /// \return Non-null pointer to the corresponding public key
    public native PublicKey getPublicKeyEd25519Blake2b();
    /// Returns the Ed25519Cardano public key associated with the given private key
    ///
    /// \param pk Non-null pointer to the private key
    /// \return Non-null pointer to the corresponding public key
    public native PublicKey getPublicKeyEd25519Cardano();
    /// Returns the Curve25519 public key associated with the given private key
    ///
    /// \param pk Non-null pointer to the private key
    /// \return Non-null pointer to the corresponding public key
    /// Returns the public key associated with this private key.
    public native PublicKey getPublicKeySr25519();
    /// Returns the public key associated with this private key.
    public native PublicKey getPublicKeyMina();
    /// Returns the public key associated with this private key.
    public native PublicKey getPublicKeyKadena();
    /// Returns the public key associated with this private key.
    public native PublicKey getPublicKeyCurve25519();
    /// Computes an EC Diffie-Hellman secret in constant time
    /// Supported curves: secp256k1
    ///
    /// \param pk Non-null pointer to a Private key
    /// \param publicKey Non-null pointer to the corresponding public key
    /// \param curve Eliptic curve
    /// \return The corresponding shared key as a non-null block of data
    public native byte[] getSharedKey(PublicKey publicKey, Curve curve);
    /// Signs a digest using ECDSA and given curve.
    ///
    /// \param pk  Non-null pointer to a Private key
    /// \param digest Non-null digest block of data
    /// \param curve Eliptic curve
    /// \return Signature as a Non-null block of data
    public native byte[] sign(byte[] digest, Curve curve);
    /// Signs a digest using ECDSA. The result is encoded with DER.
    ///
    /// \param pk  Non-null pointer to a Private key
    /// \param digest Non-null digest block of data
    /// \return Signature as a Non-null block of data
    public native byte[] signAsDER(byte[] digest);
    /// Signs a digest using ECDSA and Zilliqa schnorr signature scheme.
    ///
    /// \param pk Non-null pointer to a Private key
    /// \param message Non-null message
    /// \return Signature as a Non-null block of data
    public native byte[] signZilliqaSchnorr(byte[] message);
    /// Create a random private key
    ///
    /// \note Should be deleted with \TWPrivateKeyDelete
    /// \return Non-null Private key
    public PrivateKey() {
        nativeHandle = nativeCreate();
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        PrivateKeyPhantomReference.register(this, nativeHandle);
    }

    /// Create a private key with the given block of data
    ///
    /// \param data a block of data
    /// \note Should be deleted with \TWPrivateKeyDelete
    /// \return Nullable pointer to Private Key
    public PrivateKey(byte[] data) {
        nativeHandle = nativeCreateWithData(data);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        PrivateKeyPhantomReference.register(this, nativeHandle);
    }

    /// Deep copy a given private key
    ///
    /// \param key Non-null private key to be copied
    /// \note Should be deleted with \TWPrivateKeyDelete
    /// \return Deep copy, Nullable pointer to Private key
    public PrivateKey(PrivateKey key) {
        nativeHandle = nativeCreateCopy(key);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        PrivateKeyPhantomReference.register(this, nativeHandle);
    }

}
class PrivateKeyPhantomReference extends java.lang.ref.PhantomReference<PrivateKey> {
    private static java.util.Set<PrivateKeyPhantomReference> references = new HashSet<PrivateKeyPhantomReference>();
    private static java.lang.ref.ReferenceQueue<PrivateKey> queue = new java.lang.ref.ReferenceQueue<PrivateKey>();
    private long nativeHandle;

    private PrivateKeyPhantomReference(PrivateKey referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(PrivateKey referent, long nativeHandle) {
        references.add(new PrivateKeyPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        PrivateKeyPhantomReference ref = (PrivateKeyPhantomReference) queue.poll();
        for (; ref != null; ref = (PrivateKeyPhantomReference) queue.poll()) {
            PrivateKey.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
