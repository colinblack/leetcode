/************************************************************************/
/*Reverse a linked list from position m to n.Do it in - place and in one - pass.
 For example :
 Given1->2->3->4->5->NULL, m = 2 and n = 4,
 return1->4->3->2->5->NULL.
 Note :
 Given m, n satisfy the following condition :
 1 ¡Ü m ¡Ü n ¡Ü length of list.            */                                                         
/************************************************************************/
#include <iostream>



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		if (head == nullptr || n < m || m < 1)
		{
			return head;
		}

		ListNode dummy(-1);
		dummy.next = head;
		ListNode* cur = dummy.next;
		ListNode* pre_m = cur;
		ListNode* next_n = cur;
		ListNode* p_m = nullptr;
		ListNode* p_n = nullptr;
		int len = 0;
		for (ListNode* pre = &dummy; cur != nullptr; pre = cur, cur = cur->next)
		{
			++len;
			if (len == m)
			{
				pre_m = pre;
				p_m = cur;
			}

			if (len == n)
			{	
				next_n = cur->next;
				p_n = cur;
			}
		}

		if (len < m || len < n)
		{
			return head;
		}

		for (ListNode* cur = p_m->next, *next = nullptr; cur != next_n;)
		{
			next = cur->next;
			cur->next = pre_m->next;
			pre_m->next = cur;
			cur = next;
		}
		p_m->next = next_n;
	
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
	ListNode n1(5);
	ListNode n2(4);
	ListNode n3(3);
	ListNode n4(2);
	ListNode n5(1);
	ListNode n6(0);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	Solution A;
	ListNode* p = A.reverseBetween(&n1, 2, 5);
	printList(p);

	return 0;
}