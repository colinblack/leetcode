#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> res;
		zigzagLevelOrder(root, res, 1, true);
		return res;
	}
	void zigzagLevelOrder(TreeNode *root, vector<vector<int>>& res, int level, bool seq)
	{
		if (root == nullptr)	return;
		if (res.size() < level)
		{
			res.push_back(vector<int>());
		}

		if (seq)
		{
			res[level-1].push_back(root->val);

		}
		else
		{
			res[level-1].insert(res[level-1].begin(), root->val);
		}

		zigzagLevelOrder(root->left, res, level + 1, !seq);
		zigzagLevelOrder(root->right, res, level + 1, !seq);
	}
};



int main()
{


	return 0;
}