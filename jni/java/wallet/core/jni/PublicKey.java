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

/// Represents a public key.
public class PublicKey {
    private long nativeHandle;

    private PublicKey() {
        nativeHandle = 0;
    }

    static PublicKey createFromNative(long nativeHandle) {
        PublicKey instance = new PublicKey();
        instance.nativeHandle = nativeHandle;
        PublicKeyPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Create a public key from a block of data
    ///
    /// \param data Non-null block of data representing the public key
    /// \param type type of the public key
    /// \note Should be deleted with \TWPublicKeyDelete
    /// \return Nullable pointer to the public key
    static native long nativeCreateWithData(byte[] data, PublicKeyType type);
    static native void nativeDelete(long handle);
    /// Determines if the given public key is valid or not
    ///
    /// \param data Non-null block of data representing the public key
    /// \param type type of the public key
    /// \return true if the block of data is a valid public key, false otherwise
    public static native boolean isValid(byte[] data, PublicKeyType type);
    /// Try to get a public key from a given signature and a message
    ///
    /// \param signature Non-null pointer to a block of data corresponding to the signature
    /// \param message Non-null pointer to a block of data corresponding to the message
    /// \return Null pointer if the public key can't be recover from the given signature and message,
    /// pointer to the public key otherwise
    public static native PublicKey recover(byte[] signature, byte[] message);
    /// Determines if the given public key is compressed or not
    ///
    /// \param pk Non-null pointer to a public key
    /// \return true if the public key is compressed, false otherwise
    public native boolean isCompressed();
    /// Give the compressed public key of the given non-compressed public key
    ///
    /// \param from Non-null pointer to a non-compressed public key
    /// \return Non-null pointer to the corresponding compressed public-key
    public native PublicKey compressed();
    /// Give the non-compressed public key of a corresponding compressed public key
    ///
    /// \param from Non-null pointer to the corresponding compressed public key
    /// \return Non-null pointer to the corresponding non-compressed public key
    public native PublicKey uncompressed();
    /// Gives the raw data of a given public-key
    ///
    /// \param pk Non-null pointer to a public key
    /// \return Non-null pointer to the raw block of data of the given public key
    public native byte[] data();
    /// Give the public key type (eliptic) of a given public key
    ///
    /// \param publicKey Non-null pointer to a public key
    /// \return The public key type of the given public key (eliptic)
    public native PublicKeyType keyType();
    /// Get the public key description from a given public key
    ///
    /// \param publicKey Non-null pointer to a public key
    /// \return Non-null pointer to a string representing the description of the public key
    public native String description();
    /// Verify the validity of a signature and a message using the given public key
    ///
    /// \param pk Non-null pointer to a public key
    /// \param signature Non-null pointer to a block of data corresponding to the signature
    /// \param message Non-null pointer to a block of data corresponding to the message
    /// \return true if the signature and the message belongs to the given public key, false otherwise
    public native boolean verify(byte[] signature, byte[] message);
    /// Verify the validity as DER of a signature and a message using the given public key
    ///
    /// \param pk Non-null pointer to a public key
    /// \param signature Non-null pointer to a block of data corresponding to the signature
    /// \param message Non-null pointer to a block of data corresponding to the message
    /// \return true if the signature and the message belongs to the given public key, false otherwise
    public native boolean verifyAsDER(byte[] signature, byte[] message);
    /// Verify a Zilliqa schnorr signature with a signature and message.
    ///
    /// \param pk Non-null pointer to a public key
    /// \param signature Non-null pointer to a block of data corresponding to the signature
    /// \param message Non-null pointer to a block of data corresponding to the message
    /// \return true if the signature and the message belongs to the given public key, false otherwise
    public native boolean verifyZilliqaSchnorr(byte[] signature, byte[] message);
    /// Create a public key from a block of data
    ///
    /// \param data Non-null block of data representing the public key
    /// \param type type of the public key
    /// \note Should be deleted with \TWPublicKeyDelete
    /// \return Nullable pointer to the public key
    public PublicKey(byte[] data, PublicKeyType type) {
        nativeHandle = nativeCreateWithData(data, type);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        PublicKeyPhantomReference.register(this, nativeHandle);
    }

}
class PublicKeyPhantomReference extends java.lang.ref.PhantomReference<PublicKey> {
    private static java.util.Set<PublicKeyPhantomReference> references = new HashSet<PublicKeyPhantomReference>();
    private static java.lang.ref.ReferenceQueue<PublicKey> queue = new java.lang.ref.ReferenceQueue<PublicKey>();
    private long nativeHandle;

    private PublicKeyPhantomReference(PublicKey referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(PublicKey referent, long nativeHandle) {
        references.add(new PublicKeyPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        PublicKeyPhantomReference ref = (PublicKeyPhantomReference) queue.poll();
        for (; ref != null; ref = (PublicKeyPhantomReference) queue.poll()) {
            PublicKey.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
