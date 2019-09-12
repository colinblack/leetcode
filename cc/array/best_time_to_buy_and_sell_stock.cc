#include <iostream>	
#include <vector>
using std::vector;
//�������˼�����ҳ�����Ԫ��֮�����Ĳ�ֵ
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
				min = prices[i]; //����min
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