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
	int maxPathSum(TreeNode *root) {
		_sum = root->val;
		 dfs(root);
		 return _sum;
	}
	int dfs(TreeNode *root) {
		if (root == nullptr)
		{
			return 0;
		}
		int l = dfs(root->left);
		int r = dfs(root->right);
		int sum = root->val;
		if (l > 0) sum += l;
		if (r > 0) sum += r;
	//	std::cout << "sum: " << sum << " _sum: " << _sum << std::endl;
		_sum = max(_sum, sum);

		std::cout << "l: " << l << " r: " << r << " _sum" << _sum <<  std::endl;
		return max(l, r) > 0 ? max(l, r) + root->val : root->val;
	}
private:
	int _sum;
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


void end(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	end(node->left);
	end(node->right);
	std::cout << node->val << std::endl;
}

void show(TreeNode *root)
{
	static int level = 0;
	int i = 0;

	if (root == NULL)
		return;
	level++;
	show(root->right);
	level--;
	for (i = 0; i < level; i++)
	{
		printf("\t");
	}
	printf("%d\n", root->val);
	level++;
	show(root->left);
	level--;
}

int main()
{
	TreeNode* b_tree = nullptr;
	int array[10] = {4, 2,-1, 1, 3, 6, 7, 5, 20, 7};
	for (auto i : array)
	{
		b_tree = InsertNodeI(b_tree, i);
	}

	Solution test;
	//test.maxPathSum(b_tree);
	//end(b_tree);
//	std::cout << test.maxPathSum(b_tree) << std::endl;
	show(b_tree);
	return 0;
}