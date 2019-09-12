#include  <iostream>
#include <cstdlib>
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
	bool isBalanced(TreeNode *root) {
		_is_balanced = true;
		hight(root);
		return _is_balanced;
	}
	int hight(TreeNode * root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int hight_l = hight(root->left);
		int hight_r = hight(root->right);
		if (abs(hight_l - hight_r) >1)
		{
			_is_balanced = false;
		}
		else
		{
			_is_balanced = true;
		}

		return max(hight_l, hight_r)+ 1;

	}

private:
	bool _is_balanced;
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
	int array[5] = {4, 1, 2, 3, 5};
	for (auto i : array)
	{
		b_tree = InsertNodeI(b_tree, i);
	}

	Solution test;
	std::cout << test.isBalanced(b_tree) << std::endl;

	return 0;
}