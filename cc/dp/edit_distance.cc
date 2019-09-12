//最小编辑距离算法


#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();

       // int dp[size1+1][size2+1] = {0};
		vector<vector<int>> dp;
		dp.resize(size1+1);
		for(auto& e : dp)
		{
			e.resize(size2+1);
		}
        //初始化
        for(int i = 0; i <= size1; ++i)
        {
          dp[i][0] = i;
        }

        for(int i = 0; i <= size2; ++i)
        {
          dp[0][i] = i;
        }

        int min = 0;
        for(int i = 1; i <= size1; ++i)
        {
          for(int j = 1; j <= size2; ++j)
          {
            if(word1[i-1] == word2[j-1])
            {
              dp[i][j] = dp[i-1][j-1];
            }
            else
            {
              min = std::min(dp[i-1][j], dp[i][j-1]);
              dp[i][j] = std::min(dp[i-1][j-1], min) +1;
            }
          }
        }

        return dp[size1][size2];
    }
};


int main()
{
    Solution s;
    s.minDistance("abdeg", "ekgie");

  return 0;
}
