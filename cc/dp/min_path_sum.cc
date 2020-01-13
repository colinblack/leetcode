#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <functional>

using namespace std;

#if  0
func minPathSum(grid [][]int) int {
	l := len(grid)
	if l == 0 {
		return 0
	}
	copy := make([][]int, l)
	c := len(grid[0])
	for i := 0; i < len(copy); i++ {
		copy[i] = make([]int, c)
		//	note[i] = make([]int, i+1)
	}
	for _, v := range copy{
		for i := 0; i < len(v); i++{
			v[i] = -1
		}
	}

	var helper func(int, int) int
	helper = func(i int, j int) int{
/*  	if i == 0 || j == 0 {
		if i == 0 && j > 0 {
			return grid[i][j] + helper(i, j-1)
		} else if i > 0 && j == 0 {
			return grid[i][j] + helper(i-1, j)
		} else {
			return grid[i][j]
		}
	}  */
	if i < 0 || j < 0{
		return math.MaxInt64
	}
	if i == 0 && j == 0{
		return grid[i][j]
	}

	if copy[i][j] == -1{
		copy[i][j] = grid[i][j] + min(helper(i, j-1), help
                       
#endif 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
           auto l  = grid.size();
           auto c = grid[0].size();
           vector<vector<int>> copy(l, vector<int>(c, -1));

            std::function<int(int, int)>  helper;
            helper  =  [&] (int  i, int j)->int{
               if  (i  <  0  ||  j  <  0){
                   return  INT_MAX; 
               } 
               if  (i==0 && j == 0){
                    return grid[i][j];
               }
              
              if( copy[i][j] == -1){
		            copy[i][j] = grid[i][j] + std::min(helper(i, j-1), helper(i-1, j));
              }
              return copy[i][j] ;
            };
            
            return helper(l-1, c-1);
    }
};

int main(){
    return 0;
}