#include <iostream>


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode* p2 = nullptr;
		if (!hasCycle(head, p2))
		{
			return nullptr;
		}

		ListNode* p1 = head;
		for (; p1 != p2; p1 = p1->next, p2 = p2->next)
			;
		return p1;
	}

	bool hasCycle(ListNode *head, ListNode* & node) {
		ListNode *slow = head;
		ListNode *fast = head;

		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				node = fast;
				return true;
			}
		}
		return false;
	}
};