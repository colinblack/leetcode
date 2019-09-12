//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST

#include <iostream>


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 struct TreeNode {
     int val;
   TreeNode *left;
   TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		if (head == nullptr)
		{
			return nullptr;
		}
		if (head->next == nullptr)
		{
			return new TreeNode(head->val);
		}
	
		ListNode *mid = findMid(head);
		TreeNode *tree = new TreeNode(mid->val);
		tree->left =  sortedListToBST(head);
		tree->right = sortedListToBST(mid->next);

		return tree;
	}

	ListNode *findMid(ListNode *head) {
		if (head == nullptr)
		{
			return nullptr;
		}

		ListNode *fast = head;
		ListNode *slow = head;
		ListNode *pre_slow = head;
		
		for (; fast != nullptr && fast->next != nullptr; 
			   pre_slow = slow, slow = slow->next, fast = fast->next->next)
			         ;
		pre_slow->next = nullptr;

		return slow;
	}

};

int main()
{
	Solution a;
	a.sortedListToBST(nullptr);
	return 0;
}