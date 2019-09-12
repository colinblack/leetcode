/*
* Given a sorted linked list, delete all nodes that have duplicate 
* numbers, leaving only distinct numbers from the original list.
* For example,
* Given1->2->3->3->4->4->5, return1->2->5.
* Given1->1->1->2->3, return2->3.
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//class Solution {
//public:
//	ListNode *deleteDuplicates(ListNode *head) {
//		if (head == nullptr)
//		{
//			return nullptr;
//		}
//
//		ListNode dummy(-1);
//		dummy.next = head;
//		ListNode *list = &dummy;
//		
//
//		for (ListNode *pre = list->next, *cur = pre->next; cur; pre = cur, cur = cur->next)
//		{
//			if (pre->val == cur->val)
//			{
//				while (cur && pre->val == cur->val)
//				{
//				  //  delete pre;
//					pre = cur;
//					cur = cur->next;
//				}
//				//delete pre;
//				list->next = cur;
//				list = cur;		
//			}
//			else
//			{
//				list->next = pre;			
//				list = pre;
//			}
//
//			if (cur == nullptr)
//			{
//				break;
//			}
//					
//		}
//
//		return dummy.next;
//	}
//};

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == nullptr)
		{
			return nullptr;
		}
		ListNode dummy(-1);
		dummy.next = head;
		bool is_duplicates = false;
		ListNode* pre = &dummy, *cur = pre->next ;
		for (;cur;)
		{
			for (ListNode *tmp = cur; cur->next && cur->val == cur->next->val;)
			{
				tmp = cur->next;
				delete cur;
				cur = tmp;
				is_duplicates = true;
			}

			if (is_duplicates)
			{
				pre->next = cur->next;
				delete cur;
				cur = pre->next;
				is_duplicates = false;
			}
			else
			{
				pre = cur;
				cur = cur->next;
			}
		}
		pre->next = cur;
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
	ListNode n4(1);
	ListNode n5(1);
	ListNode n6(1);
	ListNode n7(1);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	Solution A;
	ListNode *p = A.deleteDuplicates(&n1);
	printList(p);

	return 0;
}