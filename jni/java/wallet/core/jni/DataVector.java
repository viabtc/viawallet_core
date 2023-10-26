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

/// A vector of TWData byte arrays
public class DataVector {
    private long nativeHandle;

    static DataVector createFromNative(long nativeHandle) {
        DataVector instance = new DataVector();
        instance.nativeHandle = nativeHandle;
        DataVectorPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Creates a Vector of Data.
    ///
    /// \note Must be deleted with \TWDataVectorDelete
    /// \return a non-null Vector of Data.
    static native long nativeCreate();
    /// Creates a Vector of Data with the given element
    ///
    /// \param data A non-null valid block of data
    /// \return A Vector of data with a single given element
    static native long nativeCreateWithData(byte[] data);
    static native void nativeDelete(long handle);
    /// Retrieve the number of elements
    ///
    /// \param dataVector A non-null Vector of data
    /// \return the size of the given vector.
    public native int size();
    /// Add an element to a Vector of Data. Element is cloned
    ///
    /// \param dataVector A non-null Vector of data
    /// \param data A non-null valid block of data
    /// \note data input parameter must be deleted on its own
    public native void add(byte[] data);
    /// Retrieve the n-th element.
    ///
    /// \param dataVector A non-null Vector of data
    /// \param index index element of the vector to be retrieved, need to be < TWDataVectorSize
    /// \note Returned element must be freed with \TWDataDelete
    /// \return A non-null block of data
    public native byte[] get(int index);
    /// Creates a Vector of Data.
    ///
    /// \note Must be deleted with \TWDataVectorDelete
    /// \return a non-null Vector of Data.
    public DataVector() {
        nativeHandle = nativeCreate();
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        DataVectorPhantomReference.register(this, nativeHandle);
    }

    /// Creates a Vector of Data with the given element
    ///
    /// \param data A non-null valid block of data
    /// \return A Vector of data with a single given element
    public DataVector(byte[] data) {
        nativeHandle = nativeCreateWithData(data);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        DataVectorPhantomReference.register(this, nativeHandle);
    }

}
class DataVectorPhantomReference extends java.lang.ref.PhantomReference<DataVector> {
    private static java.util.Set<DataVectorPhantomReference> references = new HashSet<DataVectorPhantomReference>();
    private static java.lang.ref.ReferenceQueue<DataVector> queue = new java.lang.ref.ReferenceQueue<DataVector>();
    private long nativeHandle;

    private DataVectorPhantomReference(DataVector referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(DataVector referent, long nativeHandle) {
        references.add(new DataVectorPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        DataVectorPhantomReference ref = (DataVectorPhantomReference) queue.poll();
        for (; ref != null; ref = (DataVectorPhantomReference) queue.poll()) {
            DataVector.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
