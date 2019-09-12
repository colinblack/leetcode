#include <iostream>


 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		return root ? isSymmetric(root->left, root->right) : 0;
	}

	bool isSymmetric(TreeNode *left, TreeNode *right)
	{
		if (!left && !right) return false;
		if (!left || !right) return false;

		return left->val == right->val &&
			isSymmetric(left->left, right->right) &&
			isSymmetric(left->right, right->left);
	}
};
