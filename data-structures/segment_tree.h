#include <vector>
#include <algorithm>

/*
	Given a sequence of values, this structure is able to efficiently - O(logN) - answer to these queries:
	* modify an element of the sequence
	* return the sum of the elements in a (sub-)interval
	
	Reference: http://codeforces.com/blog/entry/18051
*/
class segment_tree
{
	size_t m_size;
	std::vector<int> m_elements;

	void build() 
	{  
		for (auto i = m_size - 1; i > 0; --i) 
			m_elements[i] = m_elements[i << 1] + m_elements[i << 1 | 1]; // v[i] = v[2i]+v[2i+1]
	}

public:
	explicit segment_tree(size_t size)
		: segment_tree(std::vector<int>(size))
	{
	}

	explicit segment_tree(std::vector<int> values)
		: m_size(values.size()), m_elements(std::move(values))
	{
		m_elements.resize(m_size * 2);
		std::rotate(begin(m_elements), next(begin(m_elements), m_elements.size() / 2), end(m_elements));
 		build();
	}
	
	void modify(size_t index, int newValue)
	{
		for (m_elements[index += m_size] = newValue; index > 1; index >>= 1)
			m_elements[index >> 1] = m_elements[index] + m_elements[index ^ 1];
	}

	int query(size_t l, size_t r)
	{
		int res = 0;
		for (l += m_size, r += m_size; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1) res += m_elements[l++];
			if (r & 1) res += m_elements[--r];
		}
		return res;
	}
};
