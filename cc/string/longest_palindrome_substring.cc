#include <iostream>
#include <string>


using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len == 1) return s;
        
		bool dp[len][len];
		
		for(int i = 0; i < len ;++i)
		{
			for(int j = 0; j < len; ++j)
			{
				if(i == j) 
					dp[i][j] = true;
				else
					dp[i][j] = false;
			}	
			
		}
		
		int h = 0;
		int t = 0;
		int max = 1;
		
		for(int j = 0; j < len; ++j)
		{
			for(int i = 0; i < j; ++i)
			{				
				if(s[j] == s[i])
				{
					if((j -i > 1 && dp[i+1][j-1]) || j-i <= 1)
					{
						dp[i][j] = true;
						if(j-i+1 > max)
						{
							max = j-i+1;
							h = i;
							t = j;
						}
					}	
				}
			}	
		}
	
		
		return s.substr(h, max);
		
    }
};

int main()
{
	Solution s;
	cout << s.longestPalindrome("aaaa") << endl;


    return 0;
}
