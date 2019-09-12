#include <iostream>

template <class T>
class ListNode{
public:
    ListNode<T>* next;
	T data;
};

//template <class T>
//void revertList(ListNode<T>*& src)
//{
//	//ListNode<T>** pNode = &src;
//	ListNode<T>* pNode = src->next;
//	ListNode<T>* nextNode = pNode->next;
//	ListNode<T>* pThird = nullptr;
//
//	while(pNode)
//	{
//		//nextNode = pNode->next;
//		pThird = nextNode->next;
//		nextNode->next = pNode;
//		pNode = nextNode;
//		nextNode = pThird;
//		//std::cout << pNode << std::endl;
//	}
//	//src->next = nullptr;
//}



template <class T>
void revertList(ListNode<T>*& src, const int num, int gap)
{
	const int buffSize = 255;
	ListNode<T>* pCurr = src;
	ListNode<T>* pTemp = nullptr;
	ListNode<T>* pNext = nullptr;
	ListNode<T>* pHead[buffSize] = { nullptr };
	ListNode<T>* pTail[buffSize] = { nullptr };

	int cnt = 0;
	int groupNum = 0;

	while (pCurr != nullptr)
	{
		if (groupNum == num)
		{
			pHead[groupNum] = pCurr;
			break;		
		}

		pTail[groupNum] = pCurr;
		while (cnt < gap)
		{
		//	std::cout << pCurr << std::endl;
			pNext = pCurr->next;
			pCurr->next = pTemp;
			pTemp = pCurr;
			pCurr = pNext;
			++cnt;
		}
		cnt = 0;
		pHead[groupNum] = pTemp;
		pTail[groupNum + 1] = pCurr;		
		++groupNum;
	}

	for (int i = 0; i <= num - 1; ++i)
	{
		pTail[i]->next = pHead[i + 1];
	}

	src = pHead[0];

}


int main()
{
	ListNode<int>* list = new ListNode<int>;
	list->data = 1;
	list->next = new ListNode<int>;
	list->next->data = 2;

	list->next->next = new ListNode<int>;
	list->next->next->data = 3;
	list->next->next->next = nullptr;

	list->next->next->next = new ListNode<int>;
	list->next->next->next->data = 4;
	list->next->next->next->next = nullptr;

	list->next->next->next->next = new ListNode<int>;
	list->next->next->next->next->data = 5;
	list->next->next->next->next->next = nullptr;

	//revertList(list);
	revertList(list, 2, 2);

	std::cout << std::endl; 
	std::cout << std::endl;

	for (ListNode<int>* tail = list; tail != nullptr; tail = tail->next)
	{
		std::cout << tail->data << std::endl;
	}

	return 0;
}