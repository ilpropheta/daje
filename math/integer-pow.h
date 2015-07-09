/* 
   Exponentiation by squaring - O(exp*log(base))
*/
int ipow(int base, int exp)
{
  auto res = 1;
  while (exp)
  {
    if (exp & 1)
      res *= base;
    exp >>= 1;
    base *= base; 
  }
  return res;
}
