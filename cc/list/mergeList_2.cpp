#include <stdio.h>

struct list{
	list *next;
	int  num;
};


void MergeList(list* & hostListNode,  list* firstNode,  list* secondNode)
{
	if (firstNode == nullptr)
	{
		hostListNode = secondNode;
		return;
	}
	else if (secondNode == nullptr)
	{
		hostListNode = firstNode;
		return;
	}

	if (firstNode->num > secondNode->num)
	{
		hostListNode = secondNode;
		MergeList(hostListNode->next, firstNode, secondNode->next);
	}
	else
	{
		hostListNode = firstNode;
		MergeList(hostListNode->next, firstNode->next, secondNode);
	}

}



int  main()
{



	return 0;
}