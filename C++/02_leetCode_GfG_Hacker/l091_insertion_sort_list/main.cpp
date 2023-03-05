
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
      ListNode *temp = head->next;
      while (temp)
      {
        ListNode *temp2 = head;
        while(temp2 != temp) 
          if (temp->val < temp2->val)
          {
            int tmp = temp2->val;
            temp2->val = temp->val;
            temp->val = tmp;
          }
          else
            temp2 = temp2->next;
        temp = temp->next;
      }    
      
      return head;      
    }
};


int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  ListNode* root = new ListNode(4);
  root->next = new ListNode(2);
  root->next->next = new ListNode(1);
  root->next->next->next = new ListNode(3);
  root->next->next->next->next = new ListNode(10);
  root->next->next->next->next->next = new ListNode(0);
 
 
  Solution t;

  ListNode* out = t.insertionSortList(root);
  
  
  cout << " answer: "<< endl;
  while (out)
  {
    cout << out->val << " ";
    out = out->next;
  }
  cout << endl;
  
  std::cout << " done \n";
  return 0;
}