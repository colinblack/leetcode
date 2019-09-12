#include <iostream>

 struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}	
};


 class Solution {
 public:
	 RandomListNode *copyRandomList(RandomListNode *head) {
		 if (head == nullptr)
		 {
			 return head;
		 }

		 RandomListNode dummy(0);
		 RandomListNode* tmp = nullptr;


		 for (auto node = head; node != nullptr; node = tmp)
		 {
			 RandomListNode* new_node = new RandomListNode(node->label);
			 tmp = node->next;
			 node->next = new_node;
			 new_node->next = tmp;
		 }

		 for (auto node = head, p = &dummy; node != nullptr; node = node->next->next)
		 {
			 if (node->random)
			 {
				 node->next->random = node->random->next;
			 }
			 p->next = node->next;
			 p = node->next;
		 }

	
		 return dummy.next;
	 }
 };


 int main()
 {
	 RandomListNode* head = new RandomListNode(1);
	 Solution test;
	 test.copyRandomList(head);
 
	 return 0;
 }