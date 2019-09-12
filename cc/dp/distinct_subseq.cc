#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        int numDistinct(string s, string t) {
            vector<int> dp;
            dp.resize(s.size(), 0);
            vector<string> ss;
            int cnt = 0;
            for(int i = 0; i < dp.size(); ++i)
            {
                if(i == 0)
                {
                    dp[i] = 1;
                    ss.push_back(string(1, s[0]));
                }
                if(i > 0)
                {
                    dp[i] += (dp[i-1] * 2 + 1);
                    for(int j = 0; j < ss.size(); ++j)
                        ss.push_back(ss[j] + s[i]);
                    ss.push_back(string(1, s[i]));
                }
            }
            for(int i = 0; i < dp.size(); ++i)
            {
                cout << dp[i] << endl;
            }
            for(int i = 0; i < ss.size(); ++i)
            {
                cout << ss[i] << endl;
                if(ss[i] == t)
                    cnt++;
            }


            return cnt;
        }

};



int main()
{
    Solution s;
    std::cout << s.numDistinct("rabbbit", "rabbit") << std::endl;
    return 0;
}


