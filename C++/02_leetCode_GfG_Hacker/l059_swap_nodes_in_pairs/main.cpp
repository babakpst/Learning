
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// without recursion
class Solution0 {
public:
    ListNode* swapPairs(ListNode* head) {

      ListNode *tmp = head;
      while(tmp && tmp->next)
      {
        swap(tmp->val,tmp->next->val);
        if (tmp->next) tmp = tmp->next->next;
      }

      return head;
    }
};

// recursion
class Solution {
public:
  ListNode* swapPairs(ListNode* head) {

    if (!head || !head->next) return head;
    
    cout << head->val;
    ListNode* first = head;
    ListNode* second = head->next;

    first->next = swapPairs(second->next);
    second->next = first;

    return second;
  }
};


int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  /*
  ListNode* head = new ListNode(1);
  head->next     = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  */

  // /*
  ListNode* head = new ListNode(1);
  head->next     = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  // */

  //ListNode* head = new ListNode(1);
  // ListNode* head = nullptr;

  Solution t;

  ListNode* out = t.swapPairs(head);
  cout << " answer: "<< endl;
  
  while (out) {
    cout << out->val << " ";
    out = out->next;  
  }
  cout << endl;
  
  
  
  std::cout << " done \n";
  return 0;
}