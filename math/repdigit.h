/*  A 'repdigit' (repeated digit) is a natural number composed of repeated instances of the same digit 
    in a positional number system.
    
    For example: 1, 111, 1111, 222, 3333
    
    Classical problems like the "triangle of numbers" can be solved by using repdigits:
    
    1
    22
    333
    4444
    ....
    
    The n-times repeated digit x in the positional system with base B is:
    repdigit = x * (B^n - 1) / (B - 1)
    
    For example, repeating 4 times the number 3 in base 10 results in:
    3 * (10^4 - 1) / (10 - 1) = 3 * 1111 = 3333
*/

#include "integer-pow.h"

int repdigit(int x, int n, int base)
{
   return x * (ipow(base, n) - 1)/(base - 1);
}

int repdigit_base10(int x, int n)
{
   return x * (ipow(10, n) - 1)/9;
}
