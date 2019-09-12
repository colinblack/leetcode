#include <iostream>
#include <climits>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		int dp[amount+1] = {0};
		for(int i = 1; i <= amount; ++i)
		{
			dp[i] = INT_MAX;
			for(int j = 0; j < coins.size(); ++j)
			{
				if(i >= coins[j] && dp[i-coins[j]] != INT_MAX && dp[i] > dp[i-coins[j]] +1)
				{
					dp[i] = dp[i-coins[j]] +1;
				}
			}
						
		}
		
		if(dp[amount+1] != INT_MAX)
			return dp[amount+1];
		
		return -1;
						
    }
};




int main()
{

    return 0;
}
