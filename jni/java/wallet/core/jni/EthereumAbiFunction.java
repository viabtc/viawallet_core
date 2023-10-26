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

/// Represents Ethereum ABI function
public class EthereumAbiFunction {
    private long nativeHandle;

    private EthereumAbiFunction() {
        nativeHandle = 0;
    }

    static EthereumAbiFunction createFromNative(long nativeHandle) {
        EthereumAbiFunction instance = new EthereumAbiFunction();
        instance.nativeHandle = nativeHandle;
        EthereumAbiFunctionPhantomReference.register(instance, nativeHandle);
        return instance;
    }
    /// Creates a function object, with the given name and empty parameter list.  It must be deleted at the end.
    ///
    /// \param name function name
    /// \return Non-null Ethereum abi function
    static native long nativeCreateWithString(String name);
    static native void nativeDelete(long handle);
    /// Return the function type signature, of the form "baz(int32,uint256)"
    ///
    /// \param fn A Non-null eth abi function
    /// \return function type signature as a Non-null string.
    public native String getType();
    /// Methods for adding parameters of the given type (input or output).
    /// For output parameters (isOutput=true) a value has to be specified, although usually not need;
    /// Add a uint8 type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamUInt8(byte val, boolean isOutput);
    /// Add a uint16 type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamUInt16(short val, boolean isOutput);
    /// Add a uint32 type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamUInt32(int val, boolean isOutput);
    /// Add a uint64 type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamUInt64(long val, boolean isOutput);
    /// Add a uint256 type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamUInt256(byte[] val, boolean isOutput);
    /// Add a uint(bits) type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamUIntN(int bits, byte[] val, boolean isOutput);
    /// Add a int8 type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamInt8(byte val, boolean isOutput);
    /// Add a int16 type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamInt16(short val, boolean isOutput);
    /// Add a int32 type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamInt32(int val, boolean isOutput);
    /// Add a int64 type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamInt64(long val, boolean isOutput);
    /// Add a int256 type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified (stored in a block of data)
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamInt256(byte[] val, boolean isOutput);
    /// Add a int(bits) type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param bits Number of bits of the integer parameter
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamIntN(int bits, byte[] val, boolean isOutput);
    /// Add a bool type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamBool(boolean val, boolean isOutput);
    /// Add a string type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamString(String val, boolean isOutput);
    /// Add an address type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamAddress(byte[] val, boolean isOutput);
    /// Add a bytes type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamBytes(byte[] val, boolean isOutput);
    /// Add a bytes[N] type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param size fixed size of the bytes array parameter (val).
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamBytesFix(int size, byte[] val, boolean isOutput);
    /// Add a type[] type parameter
    ///
    /// \param fn A Non-null eth abi function
    /// \param val for output parameters, value has to be specified
    /// \param isOutput determines if the parameter is an input or output
    /// \return the index of the parameter (0-based).
    public native int addParamArray(boolean isOutput);
    /// Methods for accessing the value of an output or input parameter, of different types.
    /// Get a uint8 type parameter at the given index
    ///
    /// \param fn A Non-null eth abi function
    /// \param idx index for the parameter (0-based).
    /// \param isOutput determines if the parameter is an input or output
    /// \return the value of the parameter.
    public native byte getParamUInt8(int idx, boolean isOutput);
    /// Get a uint64 type parameter at the given index
    ///
    /// \param fn A Non-null eth abi function
    /// \param idx index for the parameter (0-based).
    /// \param isOutput determines if the parameter is an input or output
    /// \return the value of the parameter.
    public native long getParamUInt64(int idx, boolean isOutput);
    /// Get a uint256 type parameter at the given index
    ///
    /// \param fn A Non-null eth abi function
    /// \param idx index for the parameter (0-based).
    /// \param isOutput determines if the parameter is an input or output
    /// \return the value of the parameter stored in a block of data.
    public native byte[] getParamUInt256(int idx, boolean isOutput);
    /// Get a bool type parameter at the given index
    ///
    /// \param fn A Non-null eth abi function
    /// \param idx index for the parameter (0-based).
    /// \param isOutput determines if the parameter is an input or output
    /// \return the value of the parameter.
    public native boolean getParamBool(int idx, boolean isOutput);
    /// Get a string type parameter at the given index
    ///
    /// \param fn A Non-null eth abi function
    /// \param idx index for the parameter (0-based).
    /// \param isOutput determines if the parameter is an input or output
    /// \return the value of the parameter.
    public native String getParamString(int idx, boolean isOutput);
    /// Get an address type parameter at the given index
    ///
    /// \param fn A Non-null eth abi function
    /// \param idx index for the parameter (0-based).
    /// \param isOutput determines if the parameter is an input or output
    /// \return the value of the parameter.
    public native byte[] getParamAddress(int idx, boolean isOutput);
    /// Methods for adding a parameter of the given type to a top-level input parameter array.  Returns the index of the parameter (0-based).
    /// Note that nested ParamArrays are not possible through this API, could be done by using index paths like "1/0"
    /// Adding a uint8 type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamUInt8(int arrayIdx, byte val);
    /// Adding a uint16 type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamUInt16(int arrayIdx, short val);
    /// Adding a uint32 type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamUInt32(int arrayIdx, int val);
    /// Adding a uint64 type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamUInt64(int arrayIdx, long val);
    /// Adding a uint256 type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter stored in a block of data
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamUInt256(int arrayIdx, byte[] val);
    /// Adding a uint[N] type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param bits Number of bits of the integer parameter
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter stored in a block of data
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamUIntN(int arrayIdx, int bits, byte[] val);
    /// Adding a int8 type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamInt8(int arrayIdx, byte val);
    /// Adding a int16 type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamInt16(int arrayIdx, short val);
    /// Adding a int32 type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamInt32(int arrayIdx, int val);
    /// Adding a int64 type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamInt64(int arrayIdx, long val);
    /// Adding a int256 type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter stored in a block of data
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamInt256(int arrayIdx, byte[] val);
    /// Adding a int[N] type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param bits Number of bits of the integer parameter
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter stored in a block of data
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamIntN(int arrayIdx, int bits, byte[] val);
    /// Adding a bool type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamBool(int arrayIdx, boolean val);
    /// Adding a string type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamString(int arrayIdx, String val);
    /// Adding an address type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamAddress(int arrayIdx, byte[] val);
    /// Adding a bytes type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param val the value of the parameter
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamBytes(int arrayIdx, byte[] val);
    /// Adding a int64 type parameter of to the top-level input parameter array
    ///
    /// \param fn A Non-null eth abi function
    /// \param arrayIdx array index for the abi function (0-based).
    /// \param size fixed size of the bytes array parameter (val).
    /// \param val the value of the parameter
    /// \return the index of the added parameter (0-based).
    public native int addInArrayParamBytesFix(int arrayIdx, int size, byte[] val);
    /// Creates a function object, with the given name and empty parameter list.  It must be deleted at the end.
    ///
    /// \param name function name
    /// \return Non-null Ethereum abi function
    public EthereumAbiFunction(String name) {
        nativeHandle = nativeCreateWithString(name);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        EthereumAbiFunctionPhantomReference.register(this, nativeHandle);
    }

}
class EthereumAbiFunctionPhantomReference extends java.lang.ref.PhantomReference<EthereumAbiFunction> {
    private static java.util.Set<EthereumAbiFunctionPhantomReference> references = new HashSet<EthereumAbiFunctionPhantomReference>();
    private static java.lang.ref.ReferenceQueue<EthereumAbiFunction> queue = new java.lang.ref.ReferenceQueue<EthereumAbiFunction>();
    private long nativeHandle;

    private EthereumAbiFunctionPhantomReference(EthereumAbiFunction referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(EthereumAbiFunction referent, long nativeHandle) {
        references.add(new EthereumAbiFunctionPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        EthereumAbiFunctionPhantomReference ref = (EthereumAbiFunctionPhantomReference) queue.poll();
        for (; ref != null; ref = (EthereumAbiFunctionPhantomReference) queue.poll()) {
            EthereumAbiFunction.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
