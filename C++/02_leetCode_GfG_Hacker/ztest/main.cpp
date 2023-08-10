

#include <iostream>
#include <memory>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *list)
{
  // cout << " checkpoint Print 001 \n";
  if (!list)
    cout << " null \n";
  else
  {
    // ListNode *list = this;
    while (list != nullptr)
    {
      cout << list->val << " ";
      list = list->next;
    }
    cout << endl;
  }
};

// Definition for singly-linked list.

class Solution
{
 public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    if (!list1)
      return list2;
    else if (!list2)
      return list1;

    ListNode *head = nullptr;
    if (list1->val < list2->val)
    {
      head = list1;
      list1 = list1->next;
    }
    else
    {
      head = list2;
      list2 = list2->next;
    }

    ListNode *tmp = head;
    while (list1 && list2)
    {
      if (list1->val < list2->val)
      {
        tmp->next = list1;
        list1 = list1->next;
      }
      else
      {
        tmp->next = list2;
        list2 = list2->next;
      }
      tmp = tmp->next;
    }
    if (!list1)
      tmp->next = list2;
    else if (!list2)
      tmp->next = list1;

    return head;
  }
};

int main(int argc, char *argv[])
{
  cout << " starts ... \n";

  std::unique_ptr<ListNode> h1 = nullptr, h2 = nullptr;

  h1 = std::make_unique<ListNode>(1);
  h1->next = new ListNode(2);
  h1->next->next = new ListNode(4);
  h1->next->next->next = new ListNode(5);
  h1->next->next->next->next = new ListNode(12);
  // h1=nullptr;
  cout << " list 1: \n";
  // h1->printList();
  printList(h1.get());

  h2 = std::make_unique<ListNode>(1);
  h2->next = new ListNode(3);
  h2->next->next = new ListNode(4);
  // h2=nullptr;
  cout << " list 2: \n";
  // h2->printList();
  printList(h2.get());

  // create two sorted lists
  // merging
  Solution t;
  ListNode *merged = t.mergeTwoLists(h1.get(), h2.get());

  // output
  cout << " out: \n";
  // merged->printList();
  printList(merged);

  cout << " done. \n";
  return 0;
}
