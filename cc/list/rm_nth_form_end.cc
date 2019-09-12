//从链表为删除第n个元素
#include <iostream>

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (n <= 0)
		{
			return head;
		}
		ListNode* first = head;
		int count = n;
		for (; first && count > 0; --count, first = first->next)
			;
		if (count != 0)
		{
			return head;
		}
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *pre = &dummy;
		ListNode* second = head;
		for (; first; second = second->next, first = first->next)
		{
			pre = second;
		}

		pre->next = second->next;
		delete second;

		return dummy.next;
	}
};

int main()
{
	ListNode* list = new ListNode(1);
	list->next = new ListNode(2);
	list->next->next = new ListNode(3);
	list->next->next->next = new ListNode(4);
	list->next->next->next->next = new ListNode(5);
	list->next->next->next->next->next = new ListNode(6);

	Solution test;
	list = test.removeNthFromEnd(list, 7);


	for (ListNode* tail = list; tail != nullptr; tail = tail->next)
	{
		std::cout << tail->val << std::endl;
	}

}