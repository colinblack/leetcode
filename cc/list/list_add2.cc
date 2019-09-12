#include <iostream>

template <class T>
class ListNode{
public:
	ListNode(T n) : data(n){};
	ListNode<T>* next = nullptr;
	T data;
};

template <class T>
using LISTNODE = ListNode<T>*;


template <class T>
LISTNODE<T> listAdd(LISTNODE<T> list1, LISTNODE<T> list2)
{
	ListNode<int> dummy(-1);
	int num1 = 0;
	int num2 = 0;
	int carry = 0;

	for (LISTNODE<T> curr1 = list1, curr2 = list2, curr = &dummy.next;
		curr1 != nullptr || curr2 != nullptr;
		curr1 = curr1 == nullptr ? nullptr : curr1->next, 
		curr2 = curr2 == nullptr ? nullptr : curr2->next)
	{
		num1 = curr1->data;
		num2 = curr2->data;

		carry = (num1 + num2 + carry) / 10;
		curr = new ListNode<T>((num1 + num2 + carry)%10);
		curr = curr->next;
	}

	if (carry> 0)
	{
		curr = new ListNode<T>(carry);
	}

	return dummy.next;
}


int main()
{



	return 0;
}