
// Jul 23, 2022

// * Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

#include <iostream>
#include <memory>
using namespace std;

void printList(ListNode* list)
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

class Solution
{
 public:
  ListNode* rotateRight(ListNode* head, int k)
  {
    // edge case
    if (!head || head->next == nullptr || k == 0) return head;

    ListNode *temp1 = head, *temp2, *temp3;

    // find number of elements
    int numNodes = 1;
    while (head->next != nullptr)
    {
      numNodes++;
      head = head->next;
    }

    head = temp1;
    temp2 = head;

    k = k % numNodes;

    if (k == 0) return head;

    for (int i = 0; i < numNodes - k - 1; i++)
    {
      head = head->next;
    }
    // cout << " after moving " << numNodes << endl;
    // printList(head);
    temp1 = head->next;
    // printList(temp1);

    temp3 = head;
    // printList(temp3);
    head = head->next;
    temp3->next = nullptr;
    for (int i = 0; i < k - 1; i++)
    {
      head = head->next;
    }
    head->next = temp2;
    return temp1;
  }
};

class Solution2
{
 public:
  ListNode* rotateRight(ListNode* head, int k)
  {
    // edge case
    if (!head || head->next == nullptr) return head;

    ListNode *temp1 = head, *temp2;
    for (int i = 1; i < k; i++)
    {
      head = temp1;
      temp2 = head;
      while (head->next->next != nullptr)
      {
        head = head->next;
      }
      temp1 = head->next;
      head->next = nullptr;
      temp1->next = temp2;
    }
    return temp1;
  }
};

int main(int argc, char* argv[])
{
  cout << " starts ... \n";

  int num = 6;

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

  Solution t;
  ListNode* out = t.rotateRight(h1.get(), num);

  cout << " output: \n";
  printList(out);

  cout << " done.  \n";
  return 0;
}
