#include <iostream>


template <class T>
class ListNode{
	ListNode<T>* next;
	T data;

};


template <class T>
ListNode<T>*  groupRevertList(ListNode<T>* node, ListNode<T>* tail)
{
	ListNode<T>* last = node->next;
	ListNode<T>* curr = last->next;

	while (curr != tail)
	{
		
		last->next = curr->next;
		curr->next = node->next;
		node->next = curr;
		curr = last->next;
	
	}

	return last;
}

int main()
{



	return 0;
}