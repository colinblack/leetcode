#include <iostream>

template  <class T>
class listNode{
public:
	listNode<T>*  next;
	T data;
};


template <class T>
void  listAdd(listNode<T>* add1, listNode<T>* add2, listNode<T>** result)
{
	int src1 = 0;
	int src2 = 0;
	int resultNum = 0;
	listNode<T>** listTemp = result;

	for (listNode<T>* curr = add1; curr != nullptr; curr = curr->next)
	{
		src1 *= 10;
		src1 += curr->data;
	}

	for (listNode<T>* curr = add2; curr != nullptr; curr = curr->next)
	{
		src2 *= 10;
		src2 += curr->data;
	}

	result = src1 + src2;

	listNode<T>* listTemp = nullptr;
	while (resultNum)
	{
		*listTemp = new listNode<T>;
		(*listTemp)->data = resultNum % 10;
		listTemp = &((*listTemp)->next);
		resultNum = resultNum / 10;
	}

}


int main()
{



	return 0;
}