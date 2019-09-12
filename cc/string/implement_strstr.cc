#include <iostream>

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        char* pos = nullptr;
		if(nullptr == needle) return pos;
		for(char *p = haystack, *s = needle, *p1 = p; *p != '\0'; ++p)
		{
			s = needle;
			p1 = p;		
			for(;*p1 == *s && *s != '\0'&& *p1 != '\0'; ++p1, ++s)
				;
			
			if(*s == '\0') 
			{
				pos = p;
				break;
			}
			
		}
		
		return pos;
    }
};


int main()
{
	Solution s;
	char* a = "abcdecd";
	char* b = "cd";
	std::cout << *(s.strStr(a, b)) << std::endl;
	
	return 0;
}