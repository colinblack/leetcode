//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.
//You may not alter the values in the nodes, only nodes itself may be changed.
//Only constant memory is allowed
//For example,
//Given this linked list : 1->2->3->4->5
//For k = 2, you should return : 2->1->4->3->5
//For k = 3, you should return : 3->2->1->4->5


#include <iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};


class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == nullptr || k <= 1)
		{
			return head;
		}
		int len = 0;
		ListNode *cur = head;
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *pre = &dummy;
		while (cur)
		{
			++len;
			if (len % k == 0)
			{
				 pre = reverse(pre, cur->next);
				 cur = pre->next;
			}
			else
			{
				cur = cur->next;
			}
		
		}
		return dummy.next;
	}

	ListNode* reverse(ListNode *head, ListNode *tail){
		ListNode *first = head->next;
		ListNode *last = first->next;
		ListNode *tmp = nullptr;
		while (last != tail)
		{
			first->next = last->next;
			last->next = head->next;
			head->next = last;
			last = first->next;
		}
		
		return first;
	}
};