#include <iostream>
#include <vector>


using namespace std;

class Solution {
    public:
        int numDistinct(string s, string t) {
            vector <vector<int>>  dp(t.size()+1, vector<int>(t.size()+1, 0));
            int i, j;
            for(i = 0; i <= s.size(); ++i)
            {
                for(j = 0; j <= t.size(); ++j)
                {
                    if(j == 0)
                    {
                        dp[i][j] = 1;
                        continue;
                    }
                    if(i == 0)
                    {
                        dp[i][j]  = 0;
                        continue;
                    }

                    dp[i][j] = dp[i-1][j];
                    if(s[i-1] == t[j-1])
                        dp[i][j] += dp[i-1][j-1];
                }

            }
            return dp[i][j];
        }

};

int main()
{
    Solution s;

    return 0;
}
