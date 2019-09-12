/*此题难点是解决
*1. 递归： 1 for n-1
*2. 解决重复元素问题
*
*/


#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
		vector<int> path;
        vector<vector<int> > res;
		combination(candidates, res, path, 0, target);
		return res;
    }
	
	void combination(vector<int>& candidates, vector<vector<int> >& res, vector<int>&path, int index, int target)
	{
		if(target == 0)
		{
			res.push_back(path);
			return;
		}
		
		for(int i = index; i < candidates.size(); ++i)
		{
			if(target < candidates[i])	return;
			path.push_back(candidates[i]);
			combination(candidates, res, path, i, target - candidates[i]);
			path.pop_back();			
		}
	}
};




int main()
{
	
	
	
	return 0;
}