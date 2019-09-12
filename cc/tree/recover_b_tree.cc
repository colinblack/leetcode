#include <iostream>
#include <algorithm>

using std::swap;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	void recoverTree(TreeNode *root) {
		memset(node, 0, sizeof(node));
		//	std::cout << node[0] << node[1] << std::endl;
		pre = nullptr;
		recoverTree1(root);
		if (node[0] && node[1])
			swap(node[0]->val, node[1]->val);
	}
	TreeNode*  recoverTree1(TreeNode *root){
		if (root == nullptr)  return pre;
		recoverTree1(root->left);
		//		std::cout << pre << " "<< root << std::endl;

		if (pre && pre->val > root->val)
		{
			//	std::cout << pre->val << root->val << std::endl;
			node[0] = node[0] == nullptr ? pre : node[0];
			node[1] = root;
		}
		pre = root;
		recoverTree1(root->right);
		return pre;
	}
private:
	TreeNode* node[2];
	TreeNode* pre;
};


void mid(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	mid(node->left);
	std::cout << node->val << std::endl;
	mid(node->right);
}

int main()
{
	TreeNode *tree = new TreeNode(0);
    tree->left = new TreeNode(1);

	/*TreeNode *tree = new TreeNode(4);
	tree->left = new TreeNode(5);
	tree->right = new TreeNode(2);
	tree->left->left = new TreeNode(1);
	tree->left->right = new TreeNode(3);*/

	mid(tree);

	std::cout << "---------------------------" << std::endl;
	Solution test;
	test.recoverTree(tree);

	mid(tree);
	return 0;
}