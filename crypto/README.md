## crypto
Trivial functions and snippets regarding cryptography.

## Current contents

* basics.hpp
  * __shift_by__ : given a string containing only {0,1,...,9}, returns the cyclic-right-shifted string by e positions
  * __shift_by_inplace__ : as above, this time the shift is in-place

* caesar.hpp
  * __encrypt_as_caesar__ : given a string containing english lowercase letters, returns the Caesar-encoded string (that is, the letters of the originary string are rotated by K positions to the right)
  * __shift_by_inplace__ : as above, except for the the encryption that happens in-place
  * __encrypt_as_caesar_inplace__ : as above, except for the alphabet that is provided by the user
  * __decrypt_as_caesar__ : inverse function of __encrypt_as_caesar__
  * __decrypt_as_caesar_inplace__ : inverse function of __encrypt_as_caesar_inplace__ (alphabet provided by the user)

* xor.hpp
  * __xor_encrypt__ : encrypts/decrypts a message given a key by using the XOR Cipher
  * __xor_encrypt_inplace__ : encrypts/decrypts in-place a message given a key by using the XOR Cipher

## This is NOT a library
.hpp files in this folder are not intended to be included somewhere. They contain snippets, easy to copy-and-paste into the challenge editor.

__However__ .h files can be used as header-only.
