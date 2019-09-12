#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if(0 == wordList.size()) return 0;
		map<string, bool> word;
		for(int i = 0; i < wordList.size(); ++i)
		{
			word[wordList[i]] = false;
		}
		
		return ladder(beginWord, endWord, 0, word);
    }

	int ladder(string beginWord, string endWord, int deep, map<string, bool> wordList)
	{
		int len = 0;

		for(int i = 0; i < beginWord.size(); ++i)
		{
			for(map<string, bool>::iterator it = wordList.begin(); it != wordList.end(); ++it)
			{
				if(isMatch(beginWord, it->first, i) && (it->second == false))
				{
					cout << "1" << "beginword= " << beginWord << " words = " << it->first << " deep= " << deep << endl;
					wordList[it->first] = true;
					if(endWord == it->first)
					{
						cout << "2" << "beginword= " << beginWord << " endwords = " <<endWord << " deep= " << deep << endl;
						return deep;
					}	
					int tmp = ladder(it->first, endWord, deep + 1, wordList);
					if(0 != tmp)
					{
						len = (len == 0? tmp : min(len, tmp));
					}
					if(len <= deep )
					{
						cout << "3" << "beginword= " << beginWord << " words = " << it->first << " deep= " << deep << endl;
						return len;
					}
				}
			}	
		
		}

		return len;
	}
	
private:
	bool isMatch(const string & str1, const string &str2, int pos)
	{
		if(str1.size() != str2.size()) return false;
		if(str1 == str2) return false;
		
		for(int i = 0; i < str1.size(); ++i)
		{
			if(i == pos) continue;
			if(str1[i] != str2[i]) return false;
		}
		return true;
	}
	
};

//"hit" -> "hot" -> "dot" -> "dog" -> "cog",

int main()
{
	string a = "hit";
	string b = "cog";
	const string array[] = {"hot","dot","dog","lot","log", "cog"};
	vector<string> words(array, array+6);
	
	Solution s;
	cout << s.ladderLength(a, b, words) << endl;
	
	return 0;
}