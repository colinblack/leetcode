#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;


#if 1
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
		//构造一个n*n矩形
		vector<vector<string>> res;
		vector<string> board(n, string(n, '.'));
		
		Queens(res, board, 0, n);
		return res;
    }
	bool Queens(vector<vector<string>>& res, vector<string> board, int cnt, int &n)
	{				
		if(cnt == n)
		{
			for(auto i : board)
			{
				cout << i << endl;
				
			}
			cout << endl;
			sleep(2);
			
			res.push_back(board);
			return true;
		}
		
		for(int i = 0; i < board.size(); ++i)
		{
			for(int j = 0; j < board[i].size(); ++j)
			{
				if(board[i][j] == '.')
				{
					board[i][j] = 'Q';
					fill(board, i, j, n, '-');
					if(Queens(res, board, cnt+1, n))
					{
						board[i][j] = '.';
						fill(board, i, j, n, '.');
					}

				}				
			}		
		}
	
		return false;
	}
	
	void fill(vector<string>& board, int x, int y, int& n, char c)
	{

		for(int j = 0; j < board[x].size(); ++j)
		{
			if(j != y) board[x][j] = c;		
		}
		
		for(int i = 0; i < n; ++i)
		{
			if(i != x) board[i][y] = c;		
		}
		
		for(int i = x+1, j = y+1; i < board[x].size() && j < n; ++i, ++j)
		{
			board[i][j] = c;
			
		}
		
		for(int i = x-1, j = y-1; i >= 0 && j >= 0; --i, --j)
		{
			board[i][j] = c;
			
		}
		
		for(int i = x+1, j = y-1; i < n && j >= 0; ++i, --j)
		{
			board[i][j] = c;
			
		}
		
		for(int i = x-1, j = y+1; i >= 0 && j < board[x].size(); --i, ++j)
		{
			board[i][j] = c;
			
		}
			
	}
		
};

#endif 

int main()
{
	Solution s;
	auto res = s.solveNQueens(4);
	
	/*
	vector<string> board(4, string(4, 'x'));
	int n = 4;
	s.fill(board, 1, 1, n, '-');
	
	for(auto i : board)
	{
		cout << i << endl;
		
	}
	*/
	
	return 0;
}