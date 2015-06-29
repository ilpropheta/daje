/*
 "Ah Ce', er popolo chiede sesterzi..
  No, vado dritto"
  (Roman joke)
*/

#include <string>
#include <vector>
#include <algorithm>

/* Julius Caesar used to encrypt messages by rotating every letter in the message by a fixed number K.
   K is considered to be the encryption key.
   The Caesar Cipher is the simplest symmetric encryption scheme.
   m may contain only the following chars "abcdefghijklmnopqrstuvwxyz" 
*/
string encrypt_as_caesar(const string& m, int K)
{
	static const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	static const auto len = sizeof(alphabet) - 1;
	string encrypted; encrypted.reserve(m.size());
	transform(begin(m), end(m), back_inserter(encrypted), [=](char c){
		return alphabet[(c - alphabet[0] + K) % len];
	});
	return encrypted;
}

void encrypt_as_caesar_inplace(string& m, int K)
{
	static const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	static const auto len = sizeof(alphabet) - 1;
	for (auto& c : m)
	{
		c = alphabet[(c - alphabet[0] + K) % len];
	}
}

// alphabet must be sorted in ascending order
void encrypt_as_caesar_inplace(string& m, int K, const vector<char>& alphabet)
{
	const auto alphabetLen = alphabet.size();
	for (auto& c : m)
	{
		auto it = lower_bound(begin(alphabet), end(alphabet), c);
		if (it != end(alphabet) && *it == c)
		{
			auto pos = (distance(begin(alphabet), it) + K) % alphabetLen;
			c = alphabet[pos];
		}
	}
}

// decrypt_as_caesar(encrypt_as_caesar(m, K), K) == m
/* simple variation here: to left-shift, we reverse the alphabet
   and add K. 
*/
std::string decrypt_as_caesar(const string& m, int K)
{
	static const char alphabet[] = "zyxwvutsrqponmlkjihgfedcba";
	static const auto len = sizeof(alphabet) - 1;
	string decrypted; decrypted.reserve(m.size());
	transform(begin(m), end(m), back_inserter(decrypted), [=](char c){
		return alphabet[(alphabet[0] - c + K) % len];
	});
	return decrypted;
}

void decrypt_as_caesar_inplace(string& m, int K, const vector<char>& alphabet)
{
	const auto alphabetLen = alphabet.size();
	for (auto& c : m)
	{
		auto it = lower_bound(begin(alphabet), end(alphabet), c);
		if (it != end(alphabet) && *it == c)
		{
			auto pos = (distance(it, end(alphabet)-1) + K) % alphabetLen;
			c = alphabet[alphabetLen-1-pos];
		}
	}
}
