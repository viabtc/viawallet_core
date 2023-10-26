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

/// CoinTypeConfiguration functions
public class CoinTypeConfiguration {
    private byte[] bytes;

    private CoinTypeConfiguration() {
    }

    static CoinTypeConfiguration createFromNative(byte[] bytes) {
        CoinTypeConfiguration instance = new CoinTypeConfiguration();
        instance.bytes = bytes;
        return instance;
    }
    /// Returns stock symbol of coin
    ///
    /// \param type A coin type
    /// \return A non-null TWString stock symbol of coin
    /// \note Caller must free returned object
    public static native String getSymbol(CoinType type);
    /// Returns max count decimal places for minimal coin unit
    ///
    /// \param type A coin type
    /// \return Returns max count decimal places for minimal coin unit
    public static native int getDecimals(CoinType type);
    /// Returns transaction url in blockchain explorer
    ///
    /// \param type A coin type
    /// \param transactionID A transaction identifier
    /// \return Returns a non-null TWString transaction url in blockchain explorer
    public static native String getTransactionURL(CoinType type, String transactionID);
    /// Returns account url in blockchain explorer
    ///
    /// \param type A coin type
    /// \param accountID an Account identifier
    /// \return Returns a non-null TWString account url in blockchain explorer
    public static native String getAccountURL(CoinType type, String accountID);
    /// Returns full name of coin in lower case
    ///
    /// \param type A coin type
    /// \return Returns a non-null TWString, full name of coin in lower case
    public static native String getID(CoinType type);
    /// Returns full name of coin
    ///
    /// \param type A coin type
    /// \return Returns a non-null TWString, full name of coin
    public static native String getName(CoinType type);
    /// Returns full name of coin
    ///
    /// \param type A coin type
    /// \return Returns a non-null TWString, full name of coin
    public static native String getFullName(CoinType type);
}
