#include <iostream>

 struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool isValidBST(TreeNode *root) {

		return isValidBST(root, INT_MIN, INT_MAX);

	}
	bool isValidBST(TreeNode *root, int min, int max)
	{
		if (root == nullptr)
		{
			return true;
		}
	
		return (root->val > min && root->val < max) 
				&& isValidBST(root->left, min, root->val) 
				&& isValidBST(root->right, root->val, max);
	}
};



TreeNode* InsertNodeI(TreeNode* node, int value)
{
	TreeNode* bak = node;
	TreeNode** child_node = nullptr;
	TreeNode* new_node = new TreeNode(value);

	if (node == nullptr)
	{
		return new_node;
	}

	while (node != nullptr)
	{
		if (node->val > value)
		{
			child_node = &node->left;
			node = node->left;
		}
		else
		{
			child_node = &node->right;
			node = node->right;
		}
	}

	*child_node = new_node;

	return bak;
}

int main()
{
	TreeNode* b_tree = nullptr;
	int array[3] = { 1, 2, 3 };
	for (auto i : array)
	{
		b_tree = InsertNodeI(b_tree, i);
	}

	Solution test;
	std::cout << test.isValidBST(b_tree) << std::endl;

	return 0;
}