#include <string>

// encryption/decription xor
string xor_encrypt(const string& m, const string& key)
{
	string encrypted; encrypted.reserve(m.size());
	size_t i=0u, j=0u;
	for (; i < m.size(); ++i, j=(j+1)%key.size())
	{
		encrypted.push_back(m[i]^key[j]);
	}
	return encrypted;
}

void xor_encrypt_inplace(string& m, const string& key)
{
	size_t i = 0u, j = 0u;
	for (; i < m.size(); ++i, j = (j + 1) % key.size())
	{
		m[i] ^= key[j];
	}
}
