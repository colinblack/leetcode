#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int index_a = m - 1;
		int index_b = n - 1;
		int cur = m + n - 1;
		for (; index_a >= 0 && index_b >= 0;)
		{
			A[cur--] = A[index_a] > B[index_b] ? A[index_a--] : B[index_b--];
		}
		while (index_b >= 0)
		{
			A[cur--] = B[index_b--];
		}
	}
};

int main()
{
	
	return 0;
}