//
// Created by cp on 2019/1/26.
//

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == nullptr || k == 0)
            return head;
        ListNode* p = head;
        int count = 1;
        while(p->next)
        {
            p = p->next;
            ++count;
        }

        int pos = count - k % count;
        p->next = head;
        for(int i = 0; i < pos; ++i)
            p = p->next;

        ListNode* next = p->next;
        p->next = nullptr;
        return next;
    };
};


void printList(ListNode *head)
{
    while (head != NULL){
        std::cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    Solution A;
    ListNode* p = A.rotateRight(&n1, 13);
    printList(p);

    return 0;
}

