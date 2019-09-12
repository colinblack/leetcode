#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using std::vector;
using std::unordered_map;
class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_map<int, bool> hash_table;
		for (auto i : num)
		{
			hash_table[i] = false;
		}
		int length = 0;
		for (auto i : num)
		{
			if (hash_table[i])	continue;
			int len = 1;
			hash_table[i] = true;
			for (int j = i + 1; hash_table.find(j) != hash_table.end(); ++j)
			{
				hash_table[j] = true;
				++len;
			}

			for (int j = i - 1; hash_table.find(j) != hash_table.end(); --j)
			{
				hash_table[j] = true;
				++len;
			}
			length = std::max(length, len);
		}
		return length;
	}
};

int main()
{
	

	return 0;
}