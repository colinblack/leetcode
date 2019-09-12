#include <iostream>

 struct TreeNode {
    int val;
	TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (p == nullptr || q == nullptr)	return false;
		if (p == nullptr && q == nullptr) return true;

		return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
	int array[10] = { 4, 2, -1, 1, 3, 6, 7, 5, 20, 8 };
	for (auto i : array)
	{
		b_tree = InsertNodeI(b_tree, i);
	}

	TreeNode* b_tree_1 = nullptr;
	int array_1[10] = { 2,5,1,3,7,6,8,9,0,4 };
	for (auto i : array)
	{
		b_tree_1 = InsertNodeI(b_tree_1, i);
	}

	Solution test;
	std::cout << test.isSameTree(b_tree, b_tree_1) << std::endl;

	return 0;
}