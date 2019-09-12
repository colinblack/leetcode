#include <iostream>
#include <string>


using namespace std;


class Solution {
public:


	char* itoa(int val, int base){
		
		static char buf[32] = {0};
		
		int i = 30;
		
		for(; val && i ; --i, val /= base)
		
			buf[i] = "0123456789abcdef"[val % base];
		
		return &buf[i+1];
		
	}
	
    string countAndSay(int n) {
			
		string value("1");
		char num;
		int count = 1 ;
		
		for(int i = 0; i < n-1; ++i)
		{
		//	std::cout << value << std::endl;
			string tmp;
			const char* p = value.c_str();
			while((num = *p++) != '\0')
			{
				if(num == *p)
				{
					++count;
				}	
				else
				{
					tmp.append(itoa(count, 10));
					tmp.push_back(num);
					count = 1;					
				}	
			}	
			value = tmp;
		}
	
		return value;
    }
};





int main()
{
	Solution s;
	std::cout << s.countAndSay(5) << std::endl;
	// s.countAndSay(5);
	
	
	return 0;
}