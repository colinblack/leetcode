
#include <iostream>
#include <string>

using namespace std;


class Solution {
	public:
		string multiply(string num1, string num2) {

		string sum1;
		int i = 0;
		for(string::reverse_iterator iter = num2.rbegin(); iter != num2.rend(); ++iter, ++i)
		{
			sum1 = sum(sigMultiply(num1, *iter) + string(i, '0'), sum1);
			//std::cout << sigMultiply(num1, *iter)+ string(i, '0')  << std::endl;
		//	std::cout << sum1 << std::endl;
		}

        if(sum1.find_first_not_of('0') == string::npos)
        {
            return string(1, '0');
        }
		
		return sum1;

    }
	string sum(string num1, string num2)
	{
		string sum;
		int a = 0;
		int b = 0;
		int carry = 0;

		int tmp = 0;
		string::reverse_iterator iter1 = num1.rbegin();
		string::reverse_iterator iter2 = num2.rbegin();
		for(; iter1 != num1.rend() || iter2 != num2.rend();
			iter1 = (iter1 == num1.rend() ?  num1.rend() : iter1 + 1),
			iter2 = (iter2 == num2.rend() ?  num2.rend() : iter2 + 1))
		{
			a =  (iter1 == num1.rend() ? 0 : *iter1 - '0');
			b =  (iter2 == num2.rend() ? 0 : *iter2 - '0');

			tmp = a + b + carry;
			//std::cout << "a = " << a << " b = " << b << " carry = " << carry << std::endl;
			sum.insert(sum.begin(),  tmp % 10  + '0');

			carry = tmp /10;
			
		}

		if(0 != carry)
		{
			sum.insert(sum.begin(), carry + '0');

		}

		return sum;
	}

	string sigMultiply(string num1, char num2)
	{
		int carry = 0;
		int product = 0;
		string mul;

		for(string::reverse_iterator iter = num1.rbegin(); iter != num1.rend(); ++iter)
		{
			int tmp = (*iter - '0') * (num2 - '0') + carry;

			product = tmp % 10;

			mul.insert(mul.begin(), product + '0');
			carry = tmp /10;
		}

		if(0 != carry)
		{
			mul.insert(mul.begin(), carry + '0');
		}

		return mul;
	}

};


int main()
{
    Solution s;
   std::cout << s.multiply("140", "721") << std::endl;
	//std::cout <<  s.sum("2940", "98000") << std::endl;
    return 0;
}
