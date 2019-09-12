#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;
//map遍历
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
      //  sort(candidates.begin(), candidates.end());
        map<int, int> m;
        vector<int> path;
        vector<vector<int> > res;
        for(int i = 0; i < candidates.size(); ++i)
        {
            m[candidates[i]]++;
        }
        
		combination(m, res, path, m.begin(), target);
		return res;
    }
	void combination(map<int, int>& m, vector<vector<int> >& res, vector<int>&path, map<int, int>::iterator itb, int target)
	{
		if(target == 0)
		{
			res.push_back(path);
			return;
		}
		//cout << "first " << itb->first << " second " << itb->second << endl;
		if(itb->second == 0)
		{
			++itb;
		}
	
        for(map<int, int>::iterator it = itb; it != m.end(); ++it)
        {
            if(target < it->first)	return;
            path.push_back(it->first);
			it->second--;
			/*
				map不能有这样的操作 it+1 
			*/
            combination(m, res, path, it, target - it->first);
            it->second++;
			path.pop_back();
        }
    }
};


int main()
{
    Solution s;
    int array[] = {2, 5, 2, 1, 2};//{10,1,2,7,6,1,5};
    vector<vector<int> > res;
    vector<int> c(array, array+5);
    res = s.combinationSum2(c, 5);
    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j)
        {
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }
    
    return 0;
}