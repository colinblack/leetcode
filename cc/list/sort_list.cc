//¡¥ ΩøÏ≈≈
//http://blog.csdn.net/otuhacker/article/details/10366563
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	void sortList(ListNode *head, ListNode* tail) {
		if (head == nullptr || head->next == nullptr || head == tail)
		{
			return;
		}

		ListNode* p_min = head;
		ListNode* p_cur = head->next;

		while (p_cur != tail)
		{
			if (p_cur->val < head->val)
			{
				p_min = p_min->next;
				if (p_min != p_cur)
				{
					swap(p_min, p_cur);
				}
			}
			p_cur = p_cur->next;
		}

		if (p_min != head)
		{
			swap(head, p_min);
			sortList(head, p_min);
		}
		
		sortList(p_min->next, tail);
	}

	void swap(ListNode* node1, ListNode* node2)
	{
		int tmp = node1->val;
		node1->val = node2->val;
		node2->val = tmp;
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

	ListNode n1(2);
	ListNode n2(4);
	ListNode n3(6);
	ListNode n4(0);
	ListNode n5(1);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	Solution A;
	A.sortList(&n1, NULL);
//	printList(&n1);
	return 0;
}