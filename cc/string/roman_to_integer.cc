#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        const char* p = s.c_str();
		int res = 0;
		int size = 0;
		for(int i = 3; i >= 0; --i)
		{
			for(int j = 8; j >= 0; --j)
			{
				
				if( (size = roman[i][j].size())!= 0 
					&& 0 == strncmp(roman[i][j].c_str(), p, size))
				{
					//cout << i << "  " << j << endl;
					//cout << roman[i][j].c_str() << "  " << p << endl;
					p += roman[i][j].size();
					res += (j+1)* pow(10, i);
					break;
				}				
			}
			
		}
		
		return res;
			
    }
	
private:
	/*c++11b不支持静态成员类内初始化？*/
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
	std::cout << s.romanToInt("MMMCMXCIX") << std::endl;
	

	return 0;
}