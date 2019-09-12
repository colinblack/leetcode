#include <iostream>

 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };


class Solution {
public:
	void connect(TreeLinkNode *root) {
		connect(root, nullptr);
	}
	void connect(TreeLinkNode *root, TreeLinkNode* sibling){
		if (root == nullptr)
		{
			return;
		}
		else
		{
			root->next = sibling;
		}

		connect(root->left, root->right);   //同一节点下同一层元素相连
		if (sibling)
		{
			connect(root->right, sibling->left);
		}
		else
		{
			connect(root->right, nullptr);
		}

	}
};




int main()
{

	return 0;
}