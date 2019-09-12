/*
*Given a sorted linked list, delete all duplicates such that each element appear only once.
*For example,
*Given1->1->2, return1->2.
*Given1->1->2->3->3, return1->2->3.
*
*/

#include <iostream>


 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

 class Solution {
 public:
	 ListNode *deleteDuplicates(ListNode *head) {
		 if (head == nullptr)
		 {
			 return nullptr;
		 }

		 ListNode dummy(-1);
		 dummy.next = head;

		 for (ListNode *pre = &dummy, *cur = dummy.next; cur->next != nullptr; cur = cur->next) //clangÏÂ¶Î´íÎó
		 {
			 if (cur->val == cur->next->val)
			 {
				 pre->next = cur->next;
				 delete cur;
			 }
			 else
			 {
				 pre = cur;
			 }
		 }

		 return dummy.next;
	 }
 };



void printList(ListNode *head)
{
	while (head != NULL){
		std::cout << head->val << " ";
		head = head->next;
	}
}

int main()
{
	ListNode n1(1);
	ListNode n2(1);
	ListNode n3(1);
	ListNode n4(2);
	ListNode n5(3);
	ListNode n6(3);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	Solution A;

	ListNode *p = A.deleteDuplicates(&n1);
	printList(p);
	return 0;
}