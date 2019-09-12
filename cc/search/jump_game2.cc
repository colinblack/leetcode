#include <iostream>


class Solution {
public:
    int jump(vector<int>& nums) {
		if(nums.size() == 1) return 0; 	
		
		int left = 0;
		int right = 0;
		int cnt = 0;
		int old_right = 0;
		while(left <= right)
		{
			++cnt;
			old_right = right;
			for(int i = left; i <= old_right; ++i)
			{
				if(nums[i] + i > nums.size()-1) return cnt;	
				if(nums[i] + i > right) right = nums[i] + i;
			}
			
			left = old_right + 1;
		}
		
		return 0;	
    }
};


int main()
{


	return 0;
}


1 2 3 4 