
/*

Babak Poursartip
11/13/2020

Delete a node in a linked list, without having the head, or access to the
previous node.

*/

#include <iostream>
#include <vector>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int val) : val(val), next(nullptr) {}
};
/*
class Solution {
public:
  void deleteNode(ListNode *node) {
    while (node->next->next != nullptr) {
      node->val = node->next->val;
      node = node->next;
    }
    node->val = node->next->val;
    ListNode *temp = node->next;
    node->next = nullptr;
    delete temp;
  }
};
*/

class Solution
{
 public:
  void deleteNode(ListNode *node)
  {
    node->val = node->next->val;
    ListNode *temp = node->next;
    node->next = node->next->next;
    delete temp;
  }
};

int main()
{
  std::cout << " starts ... \n";
  std::vector<int> val{4, 5, 1, 9};

  ListNode *head = new ListNode(val[0]);
  ListNode *temp = head;
  for (std::vector<int>::const_iterator it = val.begin() + 1; it != val.end(); ++it)
  {
    ListNode *temp1(new ListNode(*it));
    temp->next = temp1;
    temp = temp->next;
  }

  std::cout << " here is the linked list: \n";
  temp = head;
  while (temp != nullptr)
  {
    std::cout << temp->val << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
  Solution obj;
  obj.deleteNode(head->next);

  std::cout << " here is the linked list after deletion: \n";
  temp = head;
  while (temp != nullptr)
  {
    std::cout << temp->val << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
  std::cout << " finished \n";
  return 0;
}
