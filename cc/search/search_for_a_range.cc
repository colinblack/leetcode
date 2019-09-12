#include <iostream>
#include <vector>

using namespace std;
//用两次二分

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
        {
            return vector<int>{-1, -1};
        }
		int l = lower(nums, target);
		int r = upper(nums, l , target);
		
		if(l == nums.size() || nums[l] != target)
		{
			return vector<int>{-1, -1};
		}
		else
		{
			return vector<int>{l, r-1};
		}
	
		
    }
	
	int lower(vector<int>& nums, int target)
	{
		int b = 0;
		int e = nums.size();
		while(b != e)
		{
			int m = b + (e-b) / 2;
			if(nums[m] < target)
			{
				b = m+1;
			}
			else
			{
				e = m;		
			}
		}
		
		return b;
	}
	
	int upper(vector<int>& nums, int b, int target)
	{
		int e = nums.size();
		while(b != e)
		{
			int m = b + (e -b) / 2;
			if(nums[m] <= target)
			{
				b = m+1;
			}
			else
			{
				e = m;
			}
		}
		
		return b;
	}
	
};


int main()
{
	Solution s;
	vector<int> v= {-1};
	auto r = s.searchRange(v, 0);
	cout << r[0] << r[1] << endl;
	
	
	return 0;
}