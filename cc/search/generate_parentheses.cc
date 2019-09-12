#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> res;
		string path;
		generate(res, path, 0, 0, n, 0);
		return res;
    }

    void generate(vector<string>& res, string& path, int l, int r , int& n, int c)
    {
        if(l == n && r == n && c == 0)
        {
            res.push_back(path);
            return;
        }
		if(c < 0) return;


        if(l < n)
        {
            path.push_back('(');
            generate(res, path, l+1, r, n , c+1);
            path.pop_back();
        }

        if(r < n)
        {
            path.push_back(')');
            generate(res, path, l, r+1, n , c-1);
            path.pop_back();
        }

    }

};



int main()
{
	Solution s;
	vector<string> r = s.generateParenthesis(4);

	for(int i = 0 ; i < r.size(); ++i)
	{
		cout << r[i] << endl;
	}

	return 0;
}

