#include <iostream>


 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


 //”–Œ Ã‚
 //class Solution {
 //public:
	// ListNode *rotateRight(ListNode *head, int k) {
	//	 if (head == nullptr)
	//	 {
	//		 return nullptr;
	//	 }
	//	 if (k <= 0)
	//	 {
	//		 return head;
	//	 }
	//	 ListNode dummy(-1);
	//	 dummy.next = head;
	//	 int key = k, len = 0;
	//	 rotate(&dummy, &dummy, k, len);
	//	 return dummy.next;
	// }

	// void rotate(ListNode* dummy, ListNode* right, int& k, int& len) {
	//	 if (right->next == nullptr)
	//	 {
	//		 k %= len;
	//	     right->next = dummy->next;
	//		 --k;
	//		 --len;
	//		 return;
	//	 }
	//	 ++len;
	//	 rotate(dummy, right->next, k, len);
	//	 if (k == 0 && len > 0)
	//	 {
	//		 dummy->next = right->next;
	//		 right->next = nullptr;
	//	 }
	//	 --k;
	//	 --len;
	// }
 //};

 class Solution {
 public:
	 ListNode *rotateRight(ListNode *head, int k) {
		 if (head == nullptr)
		 {
			 return nullptr;
		 }
		 if (k < 0)
		 {
			 return head;
		 }

		 int len = 1;
		 ListNode *tail = head;
		 while (tail->next != nullptr)
		 {
			 tail = tail->next;
			 ++len;
		 }
		 k %= len;
		 int step = len - k;
		 if (step == len)
		 {
			 return head;
		 }
		 tail->next = head;
		 while (step--)
		 {
			 tail = tail->next;
		 }

		 head = tail->next;
		 tail->next = nullptr;

		 return head;
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
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	Solution A;
	ListNode* p = A.rotateRight(nullptr, 13);
	printList(p);

	return 0;
}