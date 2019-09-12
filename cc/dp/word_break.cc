#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            int size = s.size();
            bool dp[size+1];
            dp[0] = true;
            for(int i = 1; i <= size; ++i)
            {
                for(int j = i-1; j >= 0; --j)
                {
                   if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end())
                   {
                        dp[i] = true;
                        break;
                   }
                }

            }

            return dp[size];

        }
};

int main()
{



    return 0;
}

