#include <iostream>

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
	void reorderList(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
		{
			return ;
		}

		ListNode *right = findOrignalRightNode(head);
		ListNode *left = ReorderList(head, right);
		left->next = nullptr;
	}

	ListNode *findOrignalRightNode(ListNode *head){
		ListNode *slow = head->next;
		ListNode *fast = head;
		for (; fast->next != nullptr && fast->next->next != nullptr; slow = slow->next, fast = fast->next->next)
		      	;
		return slow;
	}

	ListNode *ReorderList(ListNode *left, ListNode *right){
		if (right == nullptr)
		{
			return left;
		}
	
		left = ReorderList(left, right->next);
		ListNode *tmp = left->next;
		left->next = right;
		right->next = tmp;
		return tmp;
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
	//ListNode n6(0);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	//n5.next = &n6;
	Solution A;
	A.reorderList(&n1);
	printList(&n1);
	return 0;
}



