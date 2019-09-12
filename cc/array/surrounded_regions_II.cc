//BFS ”–Œ Ã‚°£°£

#include <iostream>
#include <vector>
#include <utility>
#include <queue>


using std::vector;
using std::pair;
using std::queue;



class Solution {
public:
	void solve(vector<vector<char>> &board) {
		int max_row = board.size();
		int max_col = board[0].size();
		
		for (int i = 0; i < max_col; ++i)
		{
			BFS(board, 0, i);
			BFS(board, max_row-1, i);
		}
		for (int i = 0; i < max_row; ++i)
		{
			BFS(board, i, 0);
			BFS(board,i, max_col - 1 );
		}
		
		for (int i = 0; i < max_row; ++i)
		{
			for (int j = 0; j < max_col; ++j)
			{
				if (board[i][j] == '+')
				{
					board[i][j] = 'O';
				}
				else if (board[i][j] == 'O')
				{
					board[i][j] = 'X';
				}
			}
		
		}

	}
	void BFS(vector<vector<char>> &board, int x, int y)
	{
		queue<pair<int, int>> elem;
		visit(board, x, y, elem);
		while (!elem.empty())
		{
			auto point = elem.front();
			elem.pop();
			int row = point.first;
			int col = point.second;
			visit(board, row - 1, col, elem);
			visit(board, row, col - 1, elem);
			visit(board, row + 1, col, elem);
			visit(board, row, col + 1, elem);	
		}

	}

	void visit(vector<vector<char>> &board, int x, int y, queue<pair<int, int>>& elem)
	{
		if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'O')
		{
			return;
		}
		board[x][y] = '+';
		elem.push(std::make_pair(x, y));
	}
};


int main()
{
	char array[4][6] = { 'X', 'O', 'X', 'O', 'X', 'O',
		'O', 'X', 'O', 'X', 'O', 'X',
		'X', 'O', 'X', 'O', 'X', 'O', 
		'O', 'X', 'O', 'X', 'O', 'X',
	};

	vector<vector<char>> board;
	for (int i = 0; i < 4; ++i)
	{
		vector<char> tmp;
		for (int j = 0; j < 6; ++j)
		{

			tmp.push_back(array[i][j]);
		}
		board.push_back(tmp);
	}

	for (auto i : board)
	{
		for (auto j : i)
		{
			printf("%c ", j);
		}
		std::cout << std::endl;
	}


	Solution s;
	s.solve(board);

	std::cout << "============================================================" << std::endl;

	for (auto i : board)
	{
		for (auto j : i)
		{
			printf("%c ", j);
		}
		std::cout << std::endl;
	}


	return 0;
}



