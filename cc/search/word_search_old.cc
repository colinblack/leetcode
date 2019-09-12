#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
		string str;
		
	//	for(int i = 0; i < board.size(); ++i)
	//	{
	//		for(int j = 0; j < board[i].size(); ++j)
			{
				if(search(str, board, word, board[0][0] ,0, 0)) return true;	
			}
	//	}
		return 	false;
    }
	
	
	bool search(string& str, vector<vector<char>>& board, string& word, char c, int i, int j)
	{
		sleep(1);
	  // cout << "1 " << "c1= " << c << " board[i][j]= " <<board[i][j] << " str= " << str <<  " i= " << i << " j= " << j << endl;
		if(i >= board.size() || i < 0 || j >= board[i].size() || j < 0)
		{
//			cout << "1" << endl;
			return false;
		}
//		cout << "1 " << "c1= " << c << " board[i][j]= " <<board[i][j] << " str= " << str <<  " i= " << i << " j= " << j << endl;
		if(board[i][j] < c)
		{
	//		if(str.size() > 0) str.erase(str.end()-1);		
			return false;	
		}
		str.push_back(board[i][j]);
		
//		cout << "str: " <<  str << "word: " << word << endl;
		if(str == word)
		{
		
			return true;
		}
		
		cout << "1" << endl;
		if(search(str, board, word, board[i][j], i, j+1)) return true;
		 cout << "2 " << "c1= " << c << " board[i][j]= " <<board[i][j] << " str= " << str <<  " i= " << i << " j= " << j << endl;
		if(str.size() > 0) str.erase(str.end()-1);
		
		 
		 
		str.push_back(board[i][j]);
		cout << "3" << endl;
		if(search(str, board, word, board[i][j], i+1, j)) return true;
		cout << "4 " << "c1= " << c << " board[i][j]= " <<board[i][j] << " str= " << str <<  " i= " << i << " j= " << j << endl;
		if(str.size() > 0) str.erase(str.end()-1);
	
		 
		str.push_back(board[i][j]);
		cout << "5" << endl;
		if(search(str, board, word, board[i][j], i, j-1)) return true;
		cout << "6 " << "c1= " << c << " board[i][j]= " <<board[i][j] << " str= " << str <<  " i= " << i << " j= " << j << endl;
		if(str.size() > 0) str.erase(str.end()-1);
		
	//	if(search(str, board, word, board[i][j], i-1, j)) return true;

		
		//if(str.size() > 0) str.erase(str.end()-1);
		return false;
		
		
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