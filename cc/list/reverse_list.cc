#include <iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution{
public:
	ListNode* reverse(ListNode* head)
	{
		if (nullptr == head || head->next == nullptr) return head;
		
		ListNode* p1 = nullptr, *p2 = head;
		for (; p2 != nullptr;)
		{
			ListNode* tmp = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = tmp;
		}
		
		return p1;
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
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	ListNode n6(6);
	ListNode n7(7);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
//	printList(&n1);
	Solution A;
	ListNode*p = A.reverse(&n1);
	printList(p);

	return 0;
}