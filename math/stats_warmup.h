/*
  Inspired by "Basic Statistics Warmup" challenge on HackerRank (https://www.hackerrank.com/challenges/stat-warmup).
  This file contains some fundamental statistics algorithms.
*/

#include <numeric>
#include <utility>
#include <algorithm>
#include <cmath>
#include <vector>

// O(n)
inline float mean(const std::vector<int>& v)
{
   return std::accumulate(begin(v), end(v), 0)/float(v.size());
}

// O(n) - changes the vector
float median(std::vector<int> &v)
{
  const auto n = v.size() / 2;
  std::nth_element(v.begin(), v.begin()+n, v.end());
  auto med = v[n];
  if(v.size()%2) // when size is odd
  {
     return med;
  }
  std::nth_element(v.begin(), v.begin()+n-1, v.end()); // when size is even
  return 0.5f*(med+v[n-1]);
}

// O(n) - makes assumption on the problem
int mode(const std::vector<int>& v)
{
   std::vector<short> histogram(100000+1); // we know i is within [0, 10^5]
   for (auto i : v)
      histogram[i]++;
   auto maxElem = std::max_element(begin(histogram), end(histogram));
   return std::distance(begin(histogram), maxElem);
}

// O(n) - takes the mean as an input (otherwise just pay O(n) for calculating it)
float std_dev(const std::vector<int>& v, float mean)
{
   std::vector<float> diff(v.size());
   std::transform(v.begin(), v.end(), diff.begin(), [=](int i) { return float(i) - mean;});
   double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0f);
   return std::sqrt(sq_sum / v.size());
}

// O(1) - just two numbers derived from previous data
std::pair<float, float> confidence_bounds(float mean, float stddev, size_t n)
{
   const auto commonTem = 1.96f * (stddev)/sqrt(float(n));
   return std::make_pair(mean - commonTem, mean + commonTem);
}
