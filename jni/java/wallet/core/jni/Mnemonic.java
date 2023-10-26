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

/// Mnemonic validate / lookup functions
public class Mnemonic {
    private byte[] bytes;

    private Mnemonic() {
    }

    static Mnemonic createFromNative(byte[] bytes) {
        Mnemonic instance = new Mnemonic();
        instance.bytes = bytes;
        return instance;
    }
    /// Determines whether a BIP39 English mnemonic phrase is valid.
    ///
    /// \param mnemonic Non-null BIP39 english mnemonic
    /// \return true if the mnemonic is valid, false otherwise
    public static native boolean isValid(String mnemonic);
    /// Determines whether word is a valid BIP39 English mnemonic word.
    ///
    /// \param word Non-null BIP39 English mnemonic word
    /// \return true if the word is a valid BIP39 English mnemonic word, false otherwise
    public static native boolean isValidWord(String word);
    /// Return BIP39 English words that match the given prefix. A single string is returned, with space-separated list of words.
    ///
    /// \param prefix Non-null string prefix
    /// \return Single non-null string, space-separated list of words containing BIP39 words that match the given prefix.
    public static native String suggest(String prefix);
    /// Return all mnemonic word
    public static native String wordList();
}
