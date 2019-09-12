#include <iostream>


struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	
};

class Solution {
public:
	void connect(TreeLinkNode *root) {	
		while (root)
		{
			TreeLinkNode dummy(-1);
			for (TreeLinkNode *pre = &dummy; root; root = root->next)
			{
				if (root->left)
				{
					if (pre) pre->next = root->left;
					pre = root->left;
				}
				if (root->right)
				{
					if (pre) pre->next = root->right;
					pre = root->right;
				}		
			}
	
			root = dummy.next;
		}
	}
};
