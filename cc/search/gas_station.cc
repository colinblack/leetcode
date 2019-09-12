#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int left = 0;
		int size = gas.size();
		for(int i = 0; i < size; ++i)
		{
			left = gas[i];
			int j = (i+1) % size;
			left -= cost[i];
			for(; j != i; j = (j+1) % size)
			{
				if(left < 0) 
				{
					left = 0;
					break;
				}	
				left = left + gas[j] - cost[j];
		//		cout << j << " " <<i << " "<< left << endl;
			}
			if(j == i && left >= 0) return i;
						
		}
			
		return -1;
    }
};


int main()
{
	Solution s;
	vector<int> gas = {1,2,3,4,5};
	vector<int> cost = {3,4,5,1,2};
	
	cout << s.canCompleteCircuit(gas, cost) << endl;
	
	
	return 0;
}