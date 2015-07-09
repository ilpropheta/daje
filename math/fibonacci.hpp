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

// Recursive Fibonacci - O(2^n)
int recursive_fibo(int n)
{
  if (n == 0 || n == 1)
    return 1;
  return recursive_fibo(n - 1) + recursive_fibo(n - 2);
}

// Dynamic Programming - O(n)
int dp_fibo(int n)
{
  // inner object to store the support vector during recursion
  // I don't like recursive std::function (*might* result in slower code)
  struct dp_fibonacci_recurse_t
  {
    vector<int> dp;

    dp_fibonacci_recurse_t(int n)
      : dp(n+1, -1)
    {

    }

    int dp_fibo(int n)
    {
      if (dp[n] != -1)
        return dp[n];
      if (n == 0)
        dp[n] = 0;
      else if (n == 1)
        dp[n] = 1;
      else
        dp[n] = dp_fibonacci_recurse(dp, n - 1) + dp_fibonacci_recurse(dp, n - 2);
      return dp[n];
    }
  };

  return dp_fibonacci_recurse_t(n).dp_fibo(n);
}

// Elegant version which uses the standard algorithm 'adjacent_difference' - O(n)
#include <numeric>
int std_fibo(int n)
{
   vector<int> v (n, 1);
   std::adjacent_difference(v.begin(), v.end() - 1, v.begin() + 1, std::plus<int>());
   return v.back();
}
