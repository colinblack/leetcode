//给定一个链表，交换每两个相邻节点并返回它的头部

#include <iostream>

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
		{
			return nullptr;
		}
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *pre = &dummy, *cur = pre->next, *next = cur->next;

		for (; cur && next; next = cur->next)
		{
			pre->next = next;
			cur->next = next->next;
			next->next = cur;
			pre = cur;
			if ((cur = pre->next) == nullptr)
			{
				break;
			}
		}

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
	list = test.swapPairs(list);

	for (ListNode* tail = list; tail != nullptr; tail = tail->next)
	{
		std::cout << tail->val << std::endl;
	}

	return 0;
}