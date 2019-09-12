#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::reverse;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		levelOrder(root, 1);
		return level_set;
	}

	void levelOrder(TreeNode *root, int level)
	{
		if (root == nullptr)	return;
		if (level > level_set.size()) level_set.push_back(vector<int>());

		level_set[level - 1].push_back(root->val);
		levelOrder(root->left, level+1);
		levelOrder(root->right, level+1);
	}
private:
	vector<vector<int>> level_set;
};