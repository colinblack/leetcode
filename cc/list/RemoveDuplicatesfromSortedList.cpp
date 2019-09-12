#include <iostream>


struct ListNode
{
	ListNode* next;
	int data;
};

class RemoveDuplicat
{
public:
	ListNode* RemoveDuplicatFromSortedList(ListNode* list);
	void DeletDuplicatElem(ListNode* prev, ListNode* curr);
};


void DeletDuplicatElem(ListNode* prev, ListNode* curr)
{
	if (prev->data == curr->data)
	{
		prev->next = curr->next;
		delete curr;
		DeletDuplicatElem(prev, prev->next);
	}
	else
	{
		DeletDuplicatElem(curr, curr->next);
	}
}


ListNode* RemoveDuplicatFromSortedList(ListNode* list)
{
	if (list == nullptr)
	{
		return nullptr;
	}

	ListNode dummy;
	dummy.next = list;

	DeletDuplicatElem(dummy.next, dummy.next->next);
}


int main()
{
	return 0;
}
