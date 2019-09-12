#include <iostream>

class Solution {
public:
    bool search(vector<int>& nums, int target) {
		int b = 0;
		int e = nums.size()-1;
		if(e == 0) return target == nums[0];
		
		int m = 0;
		while(b != e)
		{
			m =  (b+e)/2;
			if(nums[m] == target) return true;
			if(nums[b] < nums[m])
			{
				if(nums[b] <= target && target < nums[m])
				{
					e = m;	
				}
				else
				{
					b = m + 1;					
				}	
			}
			else if(nums[b] > nums[m])
			{
				if(nums[m] < target && target <= nums[e])
				{
					b = m + 1;		
				}
				else
				{
					e = m;
				}
				
			}
			else
			{
				++b;
			}
			
		}
				
        return false;
    }
};






int main()
{
	
		
	return 0;
}