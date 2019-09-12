#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		if(nums.size() == 0)
		{
			return 0;			
		}
		
		int b = 0;
		int e = nums.size();
		
		while(b != e)
		{
			int m = b + (e-b)/2;
			if(nums[m] == target)
			{
				return m;
			}
			else if(target < nums[m])
			{
				e = m;				
			}	
			else
			{
				b = m+1;	
			}
		}

		return b;
	
    }
};


int main()
{
	Solution s;
	vector<int> vec({1,3,5,6});
	cout << s.searchInsert(vec, 0) << endl;
	
	return 0;
}