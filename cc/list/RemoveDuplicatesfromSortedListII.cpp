#include <iostream>

struct ListNode{
	ListNode* next;
	int data;
};

class RemoveDuplicatII{
public:
	ListNode*  RemoveDuplicatFromSortedList(ListNode* list);
	void  DeletDuplicatElem(ListNode* prev, ListNode* curr);
};


ListNode* RemoveDuplicatII::RemoveDuplicatFromSortedList(ListNode* list)
{
	if (!list)
	{
		return list;
	}

	ListNode dummy{list, list->data + 1};
	DeletDuplicatElem(&dummy, dummy.next);

	return dummy.next;
}


void RemoveDuplicatII::DeletDuplicatElem(ListNode* prev, ListNode* curr)
{
	if (!curr)
	{
		return;
	}

	if (prev->data == curr->data)
	{

		DeletDuplicatElem();
	}
	else
	{
	
	
	}
}



int main()
{

	return 0;
}