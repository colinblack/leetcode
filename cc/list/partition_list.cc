/*
*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
*You should preserve the original relative order of the nodes in each of the two partitions.
*For example,
*Given1->4->3->2->5->2and x = 3,
*return1->2->2->4->3->5.
*/

#include <iostream>

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


 //题意理解有误
//class Solution {
//public:
//	ListNode *partition(ListNode *head, int x) {
//		if (head == nullptr)
//		{
//			return nullptr;
//		}
//
//		ListNode dummy(-1);
//		dummy.next = head;
//		ListNode *cur = dummy.next;
//
//		for (; cur != nullptr && cur->val != x; cur = cur->next)
//								;
//		if (cur == nullptr)
//		{
//			return head;
//		}
//
//		for (ListNode *left = &dummy, *right = cur->next, *next = cur->next; right != nullptr;)
//		{
//
//			if (right->val < cur->val)
//			{
//				next = right->next;
//				if (left->next->val >= right->val)
//				{
//					right->next = left->next;
//					left->next = right;
//					left = right;
//				}
//				else
//				{
//					right->next = left->next->next;
//					left->next->next = right;
//				}
//				right = next;
//			}
//			else
//			{
//				right = right->next;
//			}
//
//		}
//
//		return dummy.next;
//	}
//};

 class Solution {
 public:
	 ListNode *partition(ListNode *head, int x) {
		 if (head == nullptr)
		 {
			 return nullptr;
		 }

		 ListNode left_list(-1), *left = &left_list;
		 ListNode right_list(-1), *right = &right_list;

		 for (ListNode* cur = head; cur; cur = cur->next)
		 {
			 if (cur->val < x)
			 {
				 left->next = cur;
				 left = cur;
			 }
			 else
			 {
				 right->next = cur;
				 right = cur;
			 }		 
		 }
		 left->next = right_list.next;
		 right->next = nullptr;  //此句别忘了加

		 return left_list.next;
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
	ListNode n2(4);
	ListNode n3(3);
	ListNode n4(2);
	ListNode n5(5);
	ListNode n6(2);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	Solution A;

	ListNode *p = A.partition(&n1, 3);
	printList(p);

	return 0;
}