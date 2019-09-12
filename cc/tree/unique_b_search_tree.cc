#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
	int numTrees(int n) {
		vector<int> f(n + 1, 0);
		f[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				f[i] += f[j - 1] * f[i - j];
				std::cout << i << " " << j << std::endl;
			}
		}
		return f[n];
	}
};



int main()
{
	Solution test;
    test.numTrees(3);

	return 0;
}