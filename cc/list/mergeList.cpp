#include <iostream>

struct  listNode{
	int  element;
	listNode *next;
};

class List{
public:
	 List();
	 ~List();
	static  int  InserElement(listNode*);
	 List* Sort(listNode*, listNode*);
	 static List* MergeList(List*,  List*);
	 static void MergeList_2(List*, List*);
	 static void Position(listNode**, listNode**);
private:
	 static listNode *head ;
};

 listNode* List::head = nullptr;

int List::InserElement(listNode*  listHead)
{
	int ret = 0;
	listNode** node  = &head;
	while (*node)
	{
		(*node) = (*node)->next;
	}

	*node = listHead;
	(*node)->next = nullptr;

	return 0;
};

List*  List::MergeList(List*  dest,  List*  src)
{
	List* list = src;
	listNode** desPre = &dest->head;
	listNode** destNode = &dest->head;
	listNode** srcNode = &src->head;

	for (; *destNode != nullptr; destNode = desPre)
	{
		Position(destNode, srcNode);
		 if (*srcNode == src->head)
		{
			(*destNode)->next = src->head;
			desPre = &(*destNode)->next;
			list = dest;
		}
		 else if (*srcNode == nullptr)
		{
			*srcNode = *destNode;
			return list;
		}
		else
		{
			desPre = &(*destNode)->next;
			(*destNode)->next = (*srcNode)->next;
			(*srcNode)->next = *destNode;
		}
	}
	return list;
}

void  List::MergeList_2(List*  dest, List*  src)
{
}


void List::Position(listNode**  destNode, listNode**  srcNode)
{
	for (; *srcNode != nullptr; srcNode = &((*srcNode)->next))
		{
		if ((*srcNode)->element > (*destNode)->element)
			{
				return ;
			}
		}
}


List::List(){}

List::~List(){ delete  head; }

int main()
{
	return 0;
}