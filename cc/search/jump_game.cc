#include <iostream>
#include <algorithm>


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = 1;
		for(int i = 0; i < step && i < nums.size(); ++i)
		{
			step = max(step, i+1+ nums[i]);			
		}

		return step >= nums.size();
    }
};


int main()
{
	
	if 
		break;
		
	int step = 1;
	int i = 0;
	for(; i < step && i < nums.size(); ++i)
	{
		if(i + nums[i] + 1 >= nums.size())
		{
			break;
		}
		else
		{
			step = max(step, nums[i]);
		}
	}
		
	
	
	
	return i;
}