//用DFS好像不合适


#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
	void solve(vector<vector<char>> &board) {	
		vector<vector<char>> marks(board);
		for (unsigned int i = 0; i < board.size(); ++i)
		{
			for (unsigned int j = 0; j < board[i].size(); ++j)
			{
				if (marks[i][j] == 'O')
				{
					search(board, marks, i, j);
				}
			}
		}


	}
	bool search(vector<vector<char>> &board, vector<vector<char>> &marks, int row, int col)
	{
		//边界条件
		if (row == 0 || row == board.size() - 1 || col == 0 || col == board[row].size())
		{
			return board[row][col] == 'O' ? true : false;
		}
		
		if (board[row][col] == 'X')		return false;
	
		//上
		if (search(board, marks, row - 1, col))		marks[row][col] = 'X';
		//下
		else if (search(board, marks, row + 1, col))	marks[row][col] = 'X';
		//左
		else if (search(board, marks, row, col - 1))	marks[row][col] = 'X';
		//右
		else if (search(board, marks, row, col + 1))	marks[row][col] = 'X';
		else	return false;

		return true;
	}

};




int main()
{
	char array[4][4] = { 'X', 'X', 'X', 'X',
						 'X', 'O', 'O', 'X',
						 'X', 'X', 'O', 'X',
						 'X', 'O', 'X', 'X'
					   };

	vector<vector<char>> board;
	for (int i = 0; i < 4; ++i)
	{
		vector<char> tmp; 
		for (int j = 0; j < 4; ++j)
		{
	
			tmp.push_back(array[i][j]);
		}
		board.push_back(tmp);		
	}

	for (auto i:board)
	{
		for (auto j: i)
		{
			printf("%c ", j);
		}
		std::cout << std::endl;
	}


	Solution s;
	s.solve(board);

	std::cout << "============================================================" << std::endl;

	for (auto i:board)
	{
		for (auto j: i)
		{
			printf("%c ", j);
		}
		std::cout << std::endl;
	}


	return 0;
}
