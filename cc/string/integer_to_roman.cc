#include <iostream>
#include <string>
#include <cmath>


using namespace std;

class Solution {
public:
    string intToRoman(int num) {
		int number = num;
		int index = 0;
		int pows = 1;
		string res;
		
		for(int i = 3; i >= 0; --i)
		{
			pows = pow(10, i);
			index = number / pows;
			
			if(0 != index)
			{
				res += roman[i][index-1];				
				number %= pows;
			}
 		}
			
		return res;
    }
	
private:	
	const string roman[4][9] = 
	{
		{"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
		{"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
		{"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
		{"M", "MM", "MMM"}
	};
};


int main()
{
	Solution s;
	cout << s.intToRoman(10) << endl;
	
	
	return 0;
}