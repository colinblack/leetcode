#include <iostream>
#include <vector>
#include <algorithm>

using std::find;
using std::distance;
using std::next;
using std::begin;
using std::end;


using std::vector;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return buildBTree(begin(preorder), end(preorder), begin(inorder), end(inorder));
	}

	template <class InputIterator>
	TreeNode *buildBTree(InputIterator b_pre, InputIterator e_pre, InputIterator b_in, InputIterator e_in){
		if (b_pre == e_pre)  return nullptr;
		if (b_in == e_in)  return nullptr;

		TreeNode *root = new TreeNode(*b_pre);

		auto it_root = find(b_in, e_in, *b_pre);
		auto child_dis = distance(b_in, it_root);

		root->left = buildBTree(next(b_pre), next(b_pre, child_dis + 1), b_in, next(b_in, child_dis));
		root->right = buildBTree(next(b_pre, child_dis + 1), e_pre, next(it_root), e_in);

			return root;
	}

};
int main()
{



	return 0;
}