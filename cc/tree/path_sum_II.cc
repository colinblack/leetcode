#include <iostream>
#include <vector>


using  std::vector;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<int> path;
		proc(root, sum, path);
		return _path_sum;
	}

	void proc(TreeNode *root, int sum, vector<int>& path)
	{
		if (root == nullptr) return;
		path.push_back(root->val);
		if (root->left == nullptr && root->right == nullptr)
		{
//		std::cout << sum << "  " << root->val << std::endl;
			if (root->val == sum)
			{
				_path_sum.push_back(path);
			}
		}
		

		proc(root->left, sum - root->val, path);
	//	path.pop_back();

	//	path.push_back(root->val);
		proc(root->right, sum - root->val, path);
		path.pop_back();
	}
private:
	vector<vector<int>> _path_sum;
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
	int array[7] = { 5, 5, 5,5,5,5,5};
	for (auto i : array)
	{
		b_tree = InsertNodeI(b_tree, i);
	}
//	pre(b_tree);
	Solution test;
	vector<vector<int>>&& pathSum = test.pathSum(b_tree, 15);

	/*for (auto i : pathSum)
	{
	for (auto j : i)
	{
	std::cout << j << " " << std::endl;
	}
	std::cout << std::endl;
	}*/

	return 0;
}