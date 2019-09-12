#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
		if(board.size() == 0) return false;
		
		int n = board[0].size();
		vector<vector<bool>>  mark(board.size(), vector<bool>(n, false));
		
		
		for(int i = 0; i < board.size(); ++i)
		{
			for(int j = 0; j < board[i].size(); ++j)
			{
				if(search(mark, board, word, 0 ,i, j)) return true;	
			}
		}
		return 	false;
    }
	
	
	bool search(vector<vector<bool>>& mark, vector<vector<char>>& board, string& word, int index, int i, int j)
	{
		
		if(i >= board.size() || i < 0 || j >= board[i].size() || j < 0)
		{
			return false;
		}
		
		if(index == word.size()) return  true;
		if(mark[i][j]) return false;
		
		if(board[i][j] != word[index]) return false;
		
		mark[i][j] = true;
		bool ret = (search(mark, board, word, index + 1, i, j+1) || 
				   search(mark, board, word,  index + 1, i+1, j) ||
				   search(mark, board, word,  index + 1, i, j-1) ||
				   search(mark, board, word,  index + 1, i-1, j));

		mark[i][j] = false;
		//if(str.size() > 0) str.erase(str.end()-1);
		return ret;
		
	}
};


int main()
{
	
	char array[][4]= {
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}
	};
	vector<vector<char>> board;
	
	for(int i = 0; i < 3; ++i)
	{
		board.push_back(vector<char>(array[i], array[i]+4));
	}
	

	
	Solution s;
	string word= "ABCCED";
	cout << s.exist(board, word) << endl;
	
	
	
	return 0;
}