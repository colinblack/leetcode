#include <iostream>
#include <vector>
#include <algorithm>

using std::find;
using std::distance;
using std::next;
using std::begin;
using std::end;
using std::prev;

using std::vector;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return buildBTree(begin(postorder), end(postorder), begin(inorder), end(inorder));
	}

	template <class InputIterator>
	TreeNode *buildBTree(InputIterator b_post, InputIterator e_post, InputIterator b_in, InputIterator e_in){
		if (b_post == e_post)  return nullptr;
		if (b_in == e_in)  return nullptr;

		auto root_value = *prev(e_post);
		TreeNode *root = new TreeNode(root_value);

		auto it_root = find(b_in, e_in, root_value);
		auto child_dis = distance(b_in, it_root);

		root->left = buildBTree(b_post, next(b_post, child_dis), b_in, next(b_in, child_dis));
		root->right = buildBTree(next(b_post, child_dis), prev(e_post), next(it_root), e_in);

		return root;
	}

};
int main()
{
	return 0;
}