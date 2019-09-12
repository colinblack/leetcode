/*
Given two binary strings, return their sum (also a binary string).
For example,
a ="11"
b ="1"
Return"100"
*/

#include <iostream>
#include <string>
using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
    	int x = 0;
    	int y = 0;
    	int carry = 0;
    	int value = 0;
    	string sum;

    	for(int i = a.length()-1, j = b.length()-1; i >=0  || j >= 0 ; --i, --j)
    	{

     	 	x = (i < 0 ? 0 : a.at(i)- '0');
        	y = (j < 0 ? 0 : b.at(j) -'0');
        	value = (x+y+carry) % 2;
        //	std::cout << "x: " << x << "y: " << y << "carry: " << carry;
        	carry = (x+y+carry) / 2;
        	sum.insert(0, string(1, value + '0'));
       // 	std::cout << "sum: " << sum <<std::endl;
    	}

		if(carry != 0)
		{
			sum.insert(0, string(1, carry + '0'));
		//	std::cout << sum <<std::endl;
		}

		return sum;
    
    }
};


int main()
{
	Solution s;
	string res;
	res = s.addBinary("1010", "1011");
/*	for(auto i : res)
	{
		std::cout << i ;
	}
	std::cout << std::endl;
*/
	return 0;
}


