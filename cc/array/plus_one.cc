#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		add(digits, 1);
		return digits;
	}

	void add(vector<int>& digits, int num)
	{
		int carry = num;

		for (auto it = digits.rbegin(); it != digits.rend(); ++it)
		{
			*it += carry;
			carry = *it / 10;
			*it %= 10;
		}
		if (carry > 0) digits.insert(digits.begin(), carry);
	}
};

