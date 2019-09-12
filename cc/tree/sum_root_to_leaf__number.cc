#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	int sumNumbers(TreeNode *root) {
		return dfs(root, 0);

	}

	int dfs(TreeNode *root, int sum)
	{
		if (root == nullptr)
		{
			return 0;
		}

		if (root->left == nullptr && root->right == nullptr)
		{
			return sum * 10 + root->val;
		}
		
		return dfs(root->left, sum * 10+ root->val) + dfs(root->right, sum * 10 + root->val);
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

void pre(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	std::cout << node->val << std::endl;
	pre(node->left);
	pre(node->right);
}


int main()
{
	TreeNode* b_tree = nullptr;
	int array[3] = { 1,2,3 };
	for (auto i : array)
	{
		b_tree = InsertNodeI(b_tree, i);
	}

	Solution test;
	//test.sumNumbers(b_tree);
	//pre(b_tree);
	std::cout << test.sumNumbers(b_tree) << std::endl;

}