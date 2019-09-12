class Solution {
public:
    int lengthOfLastWord(const char *s) {
        std::string str = s;
        std::size_t p1 = str.find_last_not_of(" ");
        if(p1 == std::string::npos)
        {
             return 0;
        }

        std::size_t p2 = str.find_last_of(" ", p1);
        
        return  abs(p1-p2) ;
    }
};