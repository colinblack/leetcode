#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <set>

using namespace  std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		wordList.push_back(beginWord);
		map<string, vector<string>> word_map;
		
		construct(wordList, word_map);
		queue<pair<string, int>> Q;
		set<string> repeat;
		
		repeat.insert(beginWord);
		Q.push(make_pair(beginWord, 1));
		
		while(!Q.empty())
		{
			string str = Q.front().first;
			int cnt = Q.front().second;
			Q.pop();
			
			if(str == endWord)
				return cnt;
			
			const vector<string>& vec = word_map[str];
			for(int i = 0; i < vec.size(); ++i)
			{
				if(repeat.find(vec[i]) == repeat.end())
				{
					Q.push(make_pair(vec[i], cnt+1));	
					repeat.insert(vec[i]);
				}
				
			}
		}
		
		return 0;
    }

	
	void construct(vector<string>& wordList, map<string, vector<string>>& word_map)
	{
		for(int i =0; i < wordList.size(); ++i)
		{
			for(int j = i; j < wordList.size(); ++j)
			{
				if(isMatch(wordList[i], wordList[j]))
				{
					word_map[wordList[i]].push_back(wordList[j]);
					word_map[wordList[j]].push_back(wordList[i]);
				}				
			}
		}
	}
	
	bool isMatch(string& a, string& b)
	{
		if(a.size() != b.size()
			|| a == b)
		{
			return false;			
		}		
		int cnt = 0;
		for(int i = 0; i < a.size(); ++i)
		{
			if(a[i] != b[i])
				cnt++;
		}
		
		return cnt == 1;		
	}
	
	
};







int main()
{
	
	
	
	return 0;
}