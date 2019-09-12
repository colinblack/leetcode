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
	vector<int> preorderTraversal(TreeNode *root) {
		proc(root);
		return _value;
	}
	void proc(TreeNode *root)
	{
		if (root == nullptr) return;
		_value.push_back(root->val);
		proc(root->left);
		proc(root->right);
	}

private:
	vector<int> _value;
};
