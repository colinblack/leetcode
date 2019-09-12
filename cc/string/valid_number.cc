/**
 *输入一段字符串，判断是不是数字
 *"0"=>true
 *" 0.1 "=>true
 *"abc"=>false
 *"1 a"=>false
 *"2e10"=>true 
 */

#include <iostream>

class Solution {
public:
	enum type_s{
		INVALID,
		SPACE,
		DOT,
		SIGN,
		DIGIT,
		EXPONENT,
	};

	bool status_table[][6] ={
		-1,0,1,2,3,-1，
        

	};
    bool isNumber(const char *s) 
    {
    	int status = 0; 
    	int index = INVALID;
    	while(*s++ != '\0')
    	{
   			if(isspace(*s))
   			{
   				index = SPACE;
   			}
   			else if(*s == '.')
   			{
   				index = DOT;
   			}
   			else if(*s == '+' || *s == '-')
   			{
   				index = SIGN; 
   			}
   			else if(isdigit(*s))
   			{
   				index = DIGIT;
   			}
   			else if(*s == 'e' || *s == 'E')
   			{
   				index = EXPONENT;
   			}

   			status =  
   			if（-1 == status） return false;
    	}


    }
};



int main()
{



	return 0;
}