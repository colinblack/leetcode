#include <iostream>
#include <algorithm>

using std::max;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	int run(TreeNode *root) {
		return maxDepth(root);
	}

	int maxDepth(TreeNode *root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		return  1 + max(maxDepth(root->left), maxDepth(root->right));
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
	int array[9] = { 2, 1, 0, -1, 3, 4, 5, 6, 7 };
	for (auto i : array)
	{
		b_tree = InsertNodeI(b_tree, i);
	}

	Solution test;
	//test.run(b_tree);
	std::cout << test.run(b_tree) << std::endl;


	return 0;
}