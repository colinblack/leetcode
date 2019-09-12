#include <iostream>
#include <vector>	
using std::vector;
//此题可理解为两两元素之间的最大距离之和
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() < 2)	return 0;
		int min = prices[0];
		int max = prices[0];
		int profit = 0;
		for (int i = 1; i < prices.size(); ++i)
		{
			if (prices[i] > max)
			{
				max = prices[i];
				if (i == prices.size() - 1)
				{
					profit += max - min;
				}
			}
			else
			{
				profit += max - min;
				min = prices[i];
				max = min;
			}
		}
		return profit;
	}
};

int main()
{
	

	return 0;
}