#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        string& s1 = s;
		string& p1 = p;
		size_t s_pos_h = 0;
		size_t s_pos_e = 0;
		size_t p_pos_h = 0;
		size_t p_pos_e = 0;
		do
		{
			if(string::npos != (p_pos_e = p1.find_first_of("?*", p_pos_h)))
			{
				if(0 == s1.compare(s_pos_h, p_pos_e - p_pos_h, p1, p_pos_h, p_pos_e - p_pos_h))
				{
                    //s_pos_e = s_pos_h + p_pos_e - p_pos_h;
                    std::cout <<"1 " << s1.substr(s_pos_h, p_pos_e - p_pos_h) << " " << p1.substr(p_pos_h, p_pos_e - p_pos_h) << std::endl;
					if(string::npos == (p_pos_h = p1.find_first_not_of("*?", p_pos_e)))
					{
						break;
					}
					s_pos_h = p_pos_e;
					if(string::npos == (s_pos_h = s1.find_first_of(p1[p_pos_h], s_pos_h)))
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
            std::cout << "2 " << s1.substr(s_pos_h, s_pos_e) << " " << p1.substr(p_pos_h, p_pos_e) << std::endl;
				size_t ls = s1.size() - s_pos_h;
				size_t lp = p1.size() - p_pos_h;
				if(0 != s1.compare(s_pos_h, ls, p1, p_pos_h, lp) || ls != lp)
				{
					return false;
				}
			}
		}while(p_pos_e != string::npos);

		return true;
    }
};


int main()
{
    Solution s;
    std::cout << s.isMatch("abefcdgiescdfimde", "ab*cd?i*de") << std::endl;


    return 0;
}
