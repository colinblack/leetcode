#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
public:	
    vector<string> anagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> words;
        for(auto& sub : strs)
        {
            string tmp = sub;
            sort(tmp.begin(), tmp.end());
            words[tmp].push_back(sub);
        }

        vector<string> res;
        for(auto &e: words)
        {
            res.insert(res.end(), e.second.begin(), e.second.end());
        }
        return res;
    }

};


int main()
{





    return 0;
}
