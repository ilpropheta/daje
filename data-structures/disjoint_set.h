#include <vector>
#include <numeric>

/*
	Union-Find data structure. It's used for set partitioning problems
	(e.g. I used that to solve "Merging Communities" challenge: https://www.hackerrank.com/challenges/merging-communities)
	Basically, each subset is a "backwards" tree (stored as vector)
	merge/find in O(log N)
	No bound-check is performed
*/
class disjoint_set
{
public:
	disjoint_set(size_t size)
		: parents(size), sizes(size, 1)
	{
		std::iota(begin(parents), end(parents), 0); // each node is parent of itself
	}

	size_t size() const
	{
		return parents.size();
	}

	int find(int x) const
	{
		// parent==node -> node is the "root" of the subset
		while (parents[x] != x) 
		{
			x = parents[x];
		}
		return x;
	}

	int size_of(int x) const
	{
		return sizes[find(x)];
	}

	void merge(int x, int y)
	{
		int r1=find(x), r2=find(y);
		if (r1 == r2) // already merged
			return;

		if (sizes[r1] >= sizes[r2])
		{
			sizes[r1] += sizes[r2];
			parents[r2] = r1;
		}
		else
		{
			sizes[r2] += sizes[r1];
			parents[r1] = r2;
		}
	}
	
private:
	std::vector<int> parents; // parent node of subset i
	std::vector<int> sizes; // size of subset i
};
