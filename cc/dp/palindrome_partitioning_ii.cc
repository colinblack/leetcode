class Solution {
public:
    int minCut(string s) {
        //生成一个回文数组
		int n = s.size();
		bool  isPalin[n][n];
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				isPalin = false;
			}
		}
		
		int x = 0;
		int y = 0;
		for(int k = 0; k < n; ++k)
		{
			//奇数
			x = y = k;
			while(x >= 0 && y < n && (s[x] == s[y]))
			{
				isPalin[x][y] = true;
				--x;
				++y
			}
			
			//偶数
			x = k;
			y = k + 1;
						
			while(x >= 0 && y < n && (s[x] == s[y]))
			{
				isPalin[x][y] = true;
				--x;
				++y
			}			
		}
		
		int dp[n+1] = {0};
		
		for(int i = 1; i <= n; ++i)
		{
			dp[i] = INT_MAX;
			for(int j = 0; j <= i-1; ++j)
			{
				if(isPalin[j][i-1])
				{
					dp[i] = min(dp[j]+1, dp[i]);
				}
			}
		}
		
		return dp[n]-1;
		
    }
};