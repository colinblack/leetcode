#include <iostream>	
#include <vector>
#include <algorithm>
using std::vector;
using std::max;
using std::min;
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() < 2)	return 0;
		int size = prices.size();
		vector<int> f1(size, 0);
		vector<int> f2(size, 0);
		
		int min_price = prices[0];
		for (int i = 1; i < size; ++i)
		{
			min_price = min(prices[i], min_price);
			f1[i] = max(f1[i-1], prices[i] - min_price);
		}
		
		int max_price = prices[size - 1];
		for (int i = size - 2; i >= 0; --i)
		{
			max_price = max(prices[i], max_price);
			f2[i] = max(f2[i+1], max_price - prices[i]);
		}
		int profit = 0;
		for (int i = 0; i < size; ++i)
		{
			profit = max(profit, f1[i] + f2[i]);
		}
		
		return profit;
	}
};

int main()
{
	

	return 0;
}