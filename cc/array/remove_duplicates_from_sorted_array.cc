#include <iostream>

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n <= 1) return n;
		int index = 1;
		for (int i = 1; i < n; ++i)
		{
			if (A[index - 1] != A[i]) A[index++] = A[i];
		}

		return index;
	}
};


int main()
{
	int A[3] = { 1, 1, 2 };
	Solution s;
	std::cout << s.removeDuplicates(A, 3) << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << A[i] << " ";
	}

}