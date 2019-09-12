#include <iostream>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    void reorderList(ListNode *head) {
      if(head == nullptr || head->next == nullptr)
          return;

       ListNode* mid = head;
       for(ListNode* fast = head; fast != nullptr && fast->next != nullptr; mid = mid->next, fast = fast->next->next)
                      ;
    }

    ListNode* Tail(ListNode* head, ListNode* tail)
    {
      if(tail->next == nullptr)    
         return head; 
      auto tmp = Tail(head, tail->next);
      tail->next = tmp->next;
      tmp->next = tail;
     
      return tail->next; 
    }
};


int main()
{


  return 0;
}
