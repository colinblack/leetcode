#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        bool isScramble(string s1, string s2) {
            int size1 = s1.size();
            int size2 = s2.size();
            int N = size1;
            if(size1 != size2)
                return false;

            bool dp[size1][size2][N] = {false};

            for(int k = 1; k <= N; ++k)
            {
                for(int l = 1; l <= k; ++l)
                {
                    for(int i = 0; i < size1; ++i)
                    {
                        for(int j = 0; j < size2; ++j)
                        {
                            if(k == 1)
                                dp[i][j][k] = true;
                            else
                            {
                                dp[i][j][k] = (dp[i][j][l] && dp[i+l][j+l][k-l]) || (dp[i][j+k-l][l] && dp[i+l][j][k-l]);
                            }

                        }

                    }
                }
            }
            return dp[0][0][N-1];
};


int main()
{


    return 0;
}
