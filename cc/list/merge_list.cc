#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == nullptr)
		{
			return l2;
		}
		else  if (l2 == nullptr)
		{
			return l1;
		}

		if (l2->val < l1->val)
		{
			l2->next =  mergeTwoLists(l1, l2->next);
			return l2;
		}
		else
		{
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}

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
		ListNode n2(3);
		ListNode n3(5);
		ListNode n4(7);
		n1.next = &n2;
		n2.next = &n3;
		n3.next = &n4;


		ListNode n7(2);
		ListNode n8(4);

		n7.next = &n8;


		Solution A;
		ListNode* p = A.mergeTwoLists(&n1, &n7);
		printList(p);

		return 0;
	}
