#include <iostream>
#include <vector>
#include <cmath>

using namesapce std;

class Solution {
public:
    vector<int> grayCode(int n) {
      vector<int> res;
      int pre = 0;
      int now = 0;
      int size = pow(2, n);
      int a[size] = {0};
      while(res.size() != size)      
      {
        for(int i = 0; i < n; ++i) 
        {
            now = a[pre] | pow(2, i);
            if(a[now] == 0)
            {
              pre = now;
              a[now] = 1;
              res.push_back(now);
            }
        
        }
      
      }
      return res;

    }
};



int main()
{
  Solution s;
  vector<int> res = s.grayCode(3);
  for(auto& e: res)
  {
    cout << e << endl; 
  }

  return 0;
}
