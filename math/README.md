## math
Common math functions and snippets.

## Current contents

* digit-operations.hpp
  * __sum_of_digits__ : calculates the sum of the digits of a number 
  
* eratosthenes-sieve.h
  * __sift__ : implementation of the Sieve of Eatosthenes taken from "From Mathematics to Generic Programming"

* fibonacci.hpp
  * __nth_fibo__ : returns the nth Fibonacci number by using Binet's formula
  * __is_fibo__ : returns true if an int is a Fibonacci number, false otherwise
  * __recursive_fibo__ : returns the nth Fibonacci number by using naive recursion - O(2^n)
  * __dp_fibo__ : returns the nth Fibonacci number by using Dynamic Programming - O(n)
  * __std_fibo__ : returns the nth Fibonacci number by using 'adjacent_difference' - O(n)

* perfect-squares.h
  * __is_perfect_square__ : returns if an int number is a square of another (and its root, eventually)
  * __perfect_squares_in_range__ : returns the number of perfect squares in a range [a, b]
  * __perfect_squares_in_range__ : calls a function for each perfect square in a range [a, b] 

* prime-factors.h
  * __prime_factors_of__ : returns all the prime factors of a number
  * __sum_of_prime_factors__ : calculates the sum of all the prime factors of a number

## This is NOT a library
.hpp files in this folder are not intended to be included somewhere. They contain snippets, easy to copy-and-paste into the challenge editor.

__However__ .h files can be used as header-only.
