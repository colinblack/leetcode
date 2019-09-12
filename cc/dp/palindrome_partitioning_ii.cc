class Solution {
public:
    int minCut(string s) {
        //����һ����������
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
			//����
			x = y = k;
			while(x >= 0 && y < n && (s[x] == s[y]))
			{
				isPalin[x][y] = true;
				--x;
				++y
			}
			
			//ż��
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