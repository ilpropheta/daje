#include <string>

/* Alphabet of m = {0,1,2,...,9}
   Cyclic right shift by e
   Can be a solution of https://www.hackerrank.com/challenges/security-message-space-and-ciphertext-space
*/
string shift_by(const string& m, int e)
{
	string shifted; shifted.reserve(m.size());
	transform(begin(m), end(m), back_inserter(shifted), [=](char c){
		return (c - '0' + e) % 10 + '0';
	});
	return shifted;
}
/*
  Simple explanation:
  1. c - '0' -> c as int (e.g. '1' is 1)
  2. + e -> increment c as int by e
  3. % 10 -> shift should be cyclic, that is modulo 10 (size of the alphabet)
  4. + '0' -> turn the result back to char
*/

void shift_by_inplace(string& m, int e)
{
	for (auto& c : m)
	{
	  c = (c - '0' + e) % 10 + '0';
	}
}
