## bit
Bit operations.

## Current contents

* conversions.hpp
  * __binary_to_decimal__ : converts a binary number to decimal
  * __decimal_to_binary__ : converts a decimal number to binary
  * __decimal_to_bitset__ : converts a decimal number given as a compile-time constant to a properly-sized bitset

* flags.hpp
  * __is_active__ : checks if the ith bit of 32bit int is set to 1
  * __set_active__ : sets to 1 the ith bit of 32bit int
  * __set_inactive__ : sets to 0 the ith bit of 32bit int
  * __set_flip__ : fips the ith bit of 32bit int
  
* misc.hpp
  * __xor_swap__ : classical xor-swap idiom

* power_of_2.hpp
  * __pow_of_2__ : returns the ith power of two (0-based)
  * __mult_by_pow_2__ : multiplies a number by the ith power of two (0-based)
  * __div_by_pow_2__ : divides a number by the ith power of two (0-based)
  * __is_pow_2__ : returns true if a number is a power of two, false otherwise

## This is NOT a library
.hpp files in this folder are not intended to be included somewhere. They contain snippets, easy to copy-and-paste into the challenge editor.

__However__ .h files can be used as header-only.
