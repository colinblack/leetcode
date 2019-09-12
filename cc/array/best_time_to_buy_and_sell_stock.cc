#include <iostream>	
#include <vector>
using std::vector;
//该题的意思就是找出两个元素之间最大的差值
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() < 2) return 0;
		int min = prices[0];
		int profit = 0;
		for (unsigned int i = 1; i < prices.size(); ++i)
		{
			if (min > prices[i])
			{
				min = prices[i]; //更新min
			}
			else
			{
				if (prices[i] - min > profit)
				{
					profit = prices[i] - min;
				}
			}
			
		}
		return profit;
	}
};


int main()
{
		
	return 0;
}