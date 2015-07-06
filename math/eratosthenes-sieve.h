/*
   Taken from the book "From Mathematics to Generic Programming" by Stepanov/Rose
*/

#include <algorithm>
#include <vector>

// utility for marking all the nonprimes for a given factor
template <typename I>
void mark_sieve(I first, I last, int factor) 
{
   *first = false;
   while (last - first > factor) 
   {
      first = first + factor;
      *first = false;
   }
}

template <typename I>
void sift(I first, int n) 
{
   I last = first + n;
   std::fill(first, last, true);
   auto i=0;
   auto index_square=3;
   auto factor=3;
   while (index_square < n) 
   {
      // invariant: index_square = 2i^2 + 6i + 3,
      // factor = 2i + 3
      if (first[i]) 
      {
         mark_sieve(first + index_square, last, factor);
      }
      ++i;
      index_square += factor;
      factor += 2;
      index_square += factor;
      index_square += factor;
   }
}

/* The first value is 3 and each successive value is 2 more than the previous one, 
   so the ith value is 2i + 3.
*/
void print_primes(const std::vector<bool>& sieve)
{
   for (auto i = 0u; i < sieve.size(); ++i)
   {     
	if (sieve[i])
          cout << i * 2 + 3 << ", ";
   }
}
