#include <cmath>
#include <utility>

// first -> true if n is a perfect square, false otherwise
// second -> sqrt of n (as int)
std::pair<bool, int> is_perfect_square(int n)
{ 
    const auto root = std::sqrt(n);
    return std::make_pair(root == std::floor(root), root);
}

// it's also a solution of https://www.hackerrank.com/challenges/sherlock-and-squares
// [a, b] both inclusive
unsigned int count_perfect_squares_in_range(int a, int b)
{
    std::pair<bool, int> pfs = {false, 0};
    while (a<=b && !(pfs=is_perfect_square(a)).first) // find the first perfect square (if any)
        ++a;

    unsigned int count = pfs.first; // pfs.first = false means: no perfect squares in that range
    auto root = pfs.second+1; // start iterating only on perfect squares (no more sqrt involved)
    a = root*root;
    while (a<=b)
    {
        ++root;
        ++count;
        a = root*root; // next perfect square
    }
    return count;
}

// simple receiver-style version of perfect_squares_in_range
template<typename F>
void for_each_perfect_square_in_range(int a, int b, F receiver)
{
    std::pair<bool, int> pfs = {false, 0};
    while (a<=b && !(pfs=is_perfect_square(a)).first) // find the first perfect square (if any)
        ++a;

    if (pfs.first)
    {
    	receiver(a, pfs.second);
    }	
    auto root = pfs.second+1; // start iterating only on perfect squares (no more sqrt involved)
    a = root*root;
    while (a<=b)
    {
        receiver(a, root);
        ++root;
        a = root*root; // next perfect square
    }
}

// keeps on computing sqrt(a) even if I find the first perfect square 
// passed all HackerRank test cases but it's such a poorer solution
unsigned int count_perfect_squares_in_range_naive(int a, int b)
{
    unsigned int count = 0;
    while (a<=b)
    {
        auto root = std::sqrt(a);
        if (root == std::floor(root))
        {
            ++count;
            a = (root+1)*(root+1);
        }
        else
        {
            ++a;
        }
    }
}
