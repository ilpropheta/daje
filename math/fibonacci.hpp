/* Fibonacci numbers snippets and utilities.
   [1,1,2,3,5,8,13,...]
*/

#include <cmath>
#include "perfect-squares.h" // daje/math

// Binet's formula (http://mathworld.wolfram.com/BinetsFibonacciNumberFormula.html)
int nth_fibo(int i)
{
  const auto sqrt5 = sqrt(5);
  const auto phi = (1 + sqrt5) / 2;
  return static_cast<int>( (pow(phi, i) - (-pow(phi, -i))) / sqrt5);
}

/* Solving Binet's formula for n gives:
   n = log_phi[(nth_fibo(n)*sqrt5 + sqrt(5*nth_fibo(n)^2 +- 4))/2]
   n must be integer, that is the expression under the radical MUST be an integer (otherwise the
   logarithm does not even return a rational number).
   For this reason, x is a Fibonacci number if either 5*n^2+4 OR 5*n^2-4 is a perfect square.
*/
bool is_fibo(int i)
{
  const auto x = 5 * i * i;
	return is_perfect_square(x + 4).first || is_perfect_square(x - 4).first;
}
