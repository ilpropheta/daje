// Classical recursive version - O(n)
int fact_recursive(int n)
{
  return (n==0 || n==1) ? 1 : (n * fact(n-1));
}

// Classical iterative version- O(n)
int fact_iterative(int n)
{
  if (!n) return 1;
  auto f = 1;
  while (f *= n, --n);
  return f;
}

// unsigned long long (assuming 64bit) bounded version - O(1)
unsigned long long fact_bounded(unsigned long long i)
{
  static const unsigned long long table[] = {
    1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880,
    3628800, 39916800, 479001600, 6227020800, 87178291200,
    1307674368000, 20922789888000, 355687428096000, 6402373705728000,
    121645100408832000, 2432902008176640000 // last = 20!
  };
  return i < (sizeof(table) / sizeof(unsigned long long)) ? table[i] : 0ull;
}

#include <vector>
#include <numeric>

// Generating factorials from '0' to 'upTo' by using the power of standard algorithms - O(n)
// (max value for upTo is 20)
std::vector<unsigned long long> fact_generate(size_t upTo)
{
  vector<unsigned long long> vals(upTo, 1); // [1,1,...1] - O(n)
  iota(begin(vals) + 1, end(vals), 1); // [1,1,2,3,4,...,upTo] - O(n)
  partial_sum(begin(vals), end(vals), begin(vals), multiplies<>()); // [1, 1*1, 1*1*2, 1*1*2*3, ...] - O(n)
  return vals;
}
