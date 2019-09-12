#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int len = s.size();
		if(len <= 1)	return s;
		
		bool dp[len][len];
		
		for(int i = 0; i < len; ++i)
		{
			for(int j = 0; j < len; ++j)
			{
				if(i == j)
				{
					dp[i][j] = true;
				}
				else
				{
					dp[i][j] = false;
				}				
			}
					
		}
		
		int max = 1;
		for(int j = 0; j < len; ++j)
		{
			for(int i = 0; i < j; ++i)
			{
				if()
				{
					
					
				}
				
			}
			
			
		}
		
		
		
		
		
		
		
		
    }
};


int main()
{
	
	
	
	teturn 0;
}