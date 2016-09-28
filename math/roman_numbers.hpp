#include <string>
#include <map>

using namespace std;

// Classic "if-cascade"-based way to convert an integer into the corresponding Roman representation 
string to_roman_ifcascade(int n)
{
	string roman;
	while (n)
	{
		if (n >= 1000) { roman += "M"; n -= 1000; }
		else if (n >= 900) { roman += "CM"; n -= 900; }
		else if (n >= 500) { roman += "D"; n -= 500; }
		else if (n >= 400) { roman += "CD"; n -= 400; }
		else if (n >= 100) { roman += "C"; n -= 100; }
		else if (n >= 90) { roman += "XC"; n -= 90; }
		else if (n >= 50) { roman += "L"; n -= 50; }
		else if (n >= 40) { roman += "XL"; n -= 40; }
		else if (n >= 10) { roman += "X"; n -= 10; }
		else if (n >= 9) { roman += "IX"; n -= 9; }
		else if (n >= 5) { roman += "V"; n -= 5; }
		else if (n >= 4) { roman += "IV"; n -= 4; }
		else if (n >= 1) { roman += "I"; n -= 1; }
	}
	return roman;
}

// Converts an integer into the corresponding Roman representation
// by using std::map + lower_bound (easily convertible into std::array + std::lower_bound, just more verbose)
string to_roman_lower_bound(int n)
{
  // defines the correspondence between a decimal number and the Roman symbol
	static const map<int, string> m{
		{ 1000, "M" }, { 900, "CM" }, { 500, "D" }, { 400, "CD" }, { 100, "C" },
		{ 90, "XC" }, { 50, "L" }, { 40, "XL" }, { 10, "X" }, { 9, "IX" }, 
		{ 5, "V" }, { 4, "IV" }, { 1, "I" },
	};

	string roman;
	while (n)
	{
	  auto lb = m.lower_bound(n); // find the symbol
		if (lb == end(m) || lb->first != n) // beyond the limit or not exact match?
			lb = prev(lb);
		roman += lb->second;
		n -= lb->first;
	}

	return roman;
}
