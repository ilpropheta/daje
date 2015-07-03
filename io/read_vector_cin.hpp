#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<int> read_vector_from_stdin(int n)
{
	vector<int> vec; vec.reserve(n);
	copy_n(istream_iterator<int>(is), n, back_inserter(v));
	return vec;
}

vector<int> read_vector_from_stdin()
{
	int n; cin >> n;
	vector<int> vec; vec.reserve(n);
	copy_n(istream_iterator<int>(is), n, back_inserter(v));
	return vec;
}

template<typename ElemType, typename SizeType>
vector<ElemType> read_vector_from_stdin(SizeType n)
{
	vector<ElemType> vec; vec.reserve(n);
	copy_n(istream_iterator<ElemType>(is), n, back_inserter(v));
	return vec;
}

template<typename ElemType>
vector<ElemType> read_vector_from_stdin()
{
	size_t n; cin >> n;
	vector<ElemType> vec; vec.reserve(n);
	copy_n(istream_iterator<ElemType>(is), n, back_inserter(v));
	return vec;
}
