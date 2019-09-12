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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		return consturct(num, 0, num.size());
	}
	TreeNode *consturct(vector<int>& num, int begin, int end)
	{
		if (num.size() <= 0)	return nullptr;
		if (begin >= end)
		{
			return nullptr;
		}
		int mid = (begin + end) / 2;
		TreeNode *tree = new TreeNode(num[mid]);
		tree->left = consturct(num, begin, mid);
		tree->right = consturct(num, mid + 1, end);
		return tree;
	}
};

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
	vector<int> v{ -10, -3, 0, 5, 9 };
	Solution s;
	TreeNode* tree = s.sortedArrayToBST(v);
	show(tree);
	return 0;
}