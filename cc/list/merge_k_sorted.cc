#include <iostream>
#include <vector>

using std::vector;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if (lists.size() == 0)
		{
			return nullptr;
		}
		ListNode* totalList = nullptr;
		for (int i = 0; i < lists.size(); ++i)
		{
			totalList = mergeTwoList(totalList, lists[i]);
		}

		return totalList;
	}

	ListNode *mergeTwoList(ListNode* l1, ListNode* l2){
		if (l1 == nullptr)
		{
			return l2;
		}
		if (l2 == nullptr)
		{
			return l1;
		}

		ListNode *tmp = nullptr;
		if (l1->val < l2->val)
		{
			l1->next = mergeTwoList(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = mergeTwoList(l1, l2->next);
			return l2;
		}

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

	ListNode* list1 = new ListNode(7);
	list1->next = new ListNode(10);
	list1->next->next = new ListNode(20);
	list1->next->next->next = new ListNode(31);
	
	ListNode* list2 = new ListNode(8);
	list2->next = new ListNode(12);
	list2->next->next = new ListNode(21);
	list2->next->next->next = new ListNode(32);


	vector<ListNode *> v;
	v.push_back(list);
	v.push_back(list1);
	v.push_back(list2);

	Solution test;
	list = test.mergeKLists(v);

	for (ListNode* tail = list; tail != nullptr; tail = tail->next)
	{
		std::cout << tail->val << std::endl;
	}




	return 0;
}