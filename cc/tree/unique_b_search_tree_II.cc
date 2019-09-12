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
	vector<TreeNode *> generateTrees(int n) {
		if (n <= 0)
			return generateTrees(1, 0);
		else 
			return generateTrees(1, n);

	}
	vector<TreeNode*> generateTrees(int start, int end)
	{
		vector<TreeNode*> res;
		if (start > end)
		{
			res.push_back(nullptr);
			return res;
		}
		for (int i = start; i <= end; ++i)
		{
			vector<TreeNode*> sub_l = generateTrees(start, i - 1);
			vector<TreeNode*> sub_r = generateTrees(i + 1, end);
			for (auto j : sub_l)
			{
				for (auto k : sub_r)
				{	
					TreeNode* node = new TreeNode(i);
					node->left = j;
					node->right = k;
					res.push_back(node);
				}
			}
		}
		return res;
	}
};


void pre(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	std::cout << node->val << " ";
	pre(node->left);
	pre(node->right);
}




int main()
{
	Solution test;
	vector<TreeNode*> res = test.generateTrees(3);

	for (auto i : res)
	{
		pre(i);
		std::cout << "\n\n" << std::endl;

	}


	return 0;
}