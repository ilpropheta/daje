/* Conversion snippets from/to binary numbers. 
   Use bitset if possible. This functions are as divulgative as possible (e.g. they are not intended to be optimized).
*/
#include <bitset>

constexpr unsigned int binary_to_decimal(unsigned int n)
{
  unsigned dec = 0;
  for (auto i = 0u; n > 0; ++i)
  {
    if ((n % 10) == 1)
      dec += (1 << i);
    n /= 10;
  }
  return dec;
}

unsigned int binary_to_decimal(const string& n)
{
  unsigned dec = 0;
  auto i = 0;
  for (auto j=n.size(); j>0; --j)
  {
    dec += (n[j-1]=='1' ? (1<<i) : 0);
    ++i;
  }
  return dec;
}

std::string decimal_to_binary(unsigned int n)
{
  if (!n)
    return "0";
  auto len = unsigned(log2(n)) + 1;
  string res; res.resize(len);
  auto i = len-1;
  while (n != 0) 
  { 
    res[i--] = n % 2 == 0 ? '0' : '1';
    n /= 2; 
  }
  return res;
}

// simple way to obtain the number of bits needed to represent n (e.g. log2(n)+1)
// (here we don't have log2 at compile-time)
constexpr int nbit(unsigned n)
{   
   if (n<=1)
      return 1;
   auto res = 0;
   while (n >>= 1) 
      ++res;
   return res+1;
}

// gets a bitset as big as nbit(n)
// e.g. cout << decimal_to_bitset<30>().to_string(); // 11110
template<unsigned n>
auto decimal_to_bitset()
{
   return bitset<nbit(n)>(n);
}

// gets a string representing the binary conversion of a number (drops the leading zeros).
// This function is kind of the dynamic equivalent of the previous decimal_to_bitset()
// E.g.: cout << to_binary_str(30) << endl; // 11110
template<typename Num>
string to_binary_str(Num n)
{
   auto binStr = bitset<sizeof(Num)*8>(n).to_string();
   binStr.erase(0, min(binStr.find_first_not_of('0'), binStr.size()-1));
   return binStr;
}
