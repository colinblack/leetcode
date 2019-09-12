#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
    string convert(string s, int numRows) {
		if(s.size() <= 1 || numRows <= 1)
			return s;
		
		string s_array[numRows];
		int i = 0;
		int j = 0;
		int inc = -1;
		while(i < s.size())
		{
			if(j == numRows-1 || j == 0)
			{
				inc *= -1;				
			}	
			s_array[j].push_back(s[i]);
			j += inc;		
			++i;
		}
		
		string res;
		
		for(int i = 0; i < numRows; ++i)
		{
			res += s_array[i];
		}
		
		return res;		
    }
};


    string convert(string s, int nRows) {
				if(s.size() <= nRows || nRows == 0)
			return s;
		
		string s_array[nRows];
		int i = 0;
		int j = 0;
		int inc = -1;
		while(i < s.size())
		{
			if(j == nRows-1 || j == 0)
			{
				inc *= -1;				
			}	
			s_array[j].push_back(s[i]);
			j += inc;		
			++i;
		}
		
		string res;
		
		for(int i = 0; i < nRows; ++i)
		{
			res += s_array[i];
		}
		
		return res;		
    }



int main()
{
	Solution s;
	cout << s.convert("PAYPALISHIRING", 4) << endl;

	return 0;
}