#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {		
	    Sudoku(board);	
    }
	bool Sudoku(vector<vector<char>>& board)
	{
		for(int i = 0; i < 9; ++i)
		{
			for(int j = 0; j < 9; ++j)
			{
				if(board[i][j] == '.')
				{
					for(int k = 0; k < 9; ++k)
					{
						board[i][j] = k + '1';
						if(isValid(board, i, j) && Sudoku(board))
							return true;
						board[i][j] = '.';
					}
					
					return false;
				}	
			}
		}
				
		return true;
	}
	
	bool isValid(vector<vector<char>>&board, int x, int y)
	{
		//行
		for(int i = 0; i < 9; ++i)
		{
			if(y != i && board[x][y] == board[x][i]) return false;
		}
		
		//列
		for(int j = 0; j < 9; ++j)
		{
			if(x != j && board[x][y] == board[j][y]) return false;
		}
		
		for(int i = (x/3) * 3;  i < (x/3) * 3 + 3; ++i)
		{
			for(int j = (y/3) * 3; j < (y/3) * 3 + 3; ++j)
			{
				
				if((x != i || y != j) && board[x][y] == board[i][j])
					return false;
			}
			
		}
		
		return true;
	}
};

int main()
{
	
	
	return 0;
}