/*
* You are given two linked lists representing two non - negative numbers.
* The digits are stored in reverse order and each of their nodes contain a single digit.
* Add the two numbers and return it as a linked list.
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output : 7 -> 0 -> 8
*/
#include <iostream>

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

 class Solution {
 public:
	 ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		 ListNode dummy(-1);
		 int carry = 0, tmp = 0;
		 ListNode *cur = nullptr;
		 for ( cur = &dummy; l1 != nullptr || l2 != nullptr; 
			 l1 = l1 == nullptr ? nullptr : l1->next, l2 = l2 == nullptr ? nullptr : l2->next) //注意循环条件
		 {
			 const int a = l1 == nullptr ? 0 : l1->val;  
			 const int b = l2 == nullptr ? 0 : l2->val;
			 tmp = a + b + carry;
			 cur->next = new ListNode(tmp % 10);
			 carry = tmp / 10;
			 cur = cur->next;
		 }
		 if (carry)
		 {
			 cur->next = new  ListNode(carry);
		 }

		 return dummy.next;
	 }
 };

int main()
{


	return 0;
}
