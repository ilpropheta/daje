#include <cmath>
#include <vector>

std::vector<int> prime_factors_of(int n)
{
    std::vector<int> factors;
    while (n%2 == 0) // while n is even
    {
        factors.push_back(2);
        n = n/2;
    }
 
    for (auto i=3; i <= std::sqrt(n); i+=2) // i is odd here (skip 2 numbers)
    {
        while (n%i == 0)
        {
            factors.push_back(i);
            n = n/i;
        }
    }
 
    if (n > 2)
        factors.push_back(n);
    
    return factors;
}

int sum_of_prime_factors(int n)
{
    auto sum = 0;
    while (n%2 == 0) // while n is even
    {
        sum += 2;
        n = n/2;
    }
 
    for (auto i=3; i <= std::sqrt(n); i+=2) // i is odd here (skip 2 numbers)
    {
        while (n%i == 0)
        {
            sum += i;
            n = n/i;
        }
    }
 
    if (n > 2)
        sum += n;
    
    return sum;
}
