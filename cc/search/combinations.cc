#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		execute(res, visited);
		return res;
    }
	
	void execute(vector<vector<int>>& res, list<int>& l, int& capacity, int& size, int index)
	{
		for(int i = index; i < capacity; ++i)
		{
			l.push_back(i+1);
			if(l.size() >= size)
			{
				res.push_back(vector<int>(l.begin(), l.end()));
			}
			else
			{
				execute(res, q, capacity, size, i);	
			}
			q.pop_back();			
		}
	}
	
};

int main()
{
	
	
	
	
	return 0;
}