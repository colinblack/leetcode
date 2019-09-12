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
	vector<int> postorderTraversal(TreeNode *root) {
		proc(root);
		return _value;
	}
	void proc(TreeNode *root)
	{
		if (root == nullptr) return;
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		_value.push_back(root->val);
	}

private:
	vector<int> _value;
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

	Solution test;
	vector<int>&& value =  test.postorderTraversal(b_tree);
	for (auto i : value)
	{
		std::cout << i << std::endl;
	}


	return 0;
}