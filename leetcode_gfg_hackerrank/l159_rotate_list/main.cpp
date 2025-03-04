
#include <iostream>
#include <list>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution0
{
 public:
  void printList(ListNode *head)
  {
    cout << " here is the list: \n";
    while (head)
    {
      cout << head->val << " ";
      head = head->next;
    }
    cout << endl;
  }

  void replace(ListNode *head)
  {
    if (!head->next) return;

    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur->next)
    {
      pre = cur;
      cur = cur->next;
    }
    pre->next = nullptr;
    cur->next = head->next;
    head->next = cur;
  };

  void reorderList(ListNode *head)
  {
    if (!head->next) return;

    // printList(head);

    ListNode *tmp = head;
    while (tmp->next && tmp->next->next)
    {
      replace(tmp);
      if (tmp->next->next) tmp = tmp->next->next;
      // printList(head);
    }
  }
};

class Solution
{
 public:
  void reorderList(ListNode *head)
  {
    if (!head->next) return;

    // printList(head);
    // find middle node
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    // cout<< " middle: " << slow->val << endl;

    // reverse the second half
    ListNode *pre = slow;
    ListNode *cur = slow->next;
    pre->next = nullptr;
    while (cur)
    {
      ListNode *tmp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = tmp;
    }

    // printList(pre);

    ListNode *start = head;
    ListNode *end = pre;
    while (start->next && end->next)
    {
      // cout<< start->val << endl;
      ListNode *tmp1 = end->next;
      end->next = start->next;
      start->next = end;
      start = end->next;
      end = tmp1;
    }
  }

  void printList(ListNode *head)
  {
    while (head)
    {
      cout << head->val << " ";
      head = head->next;
    }
    cout << endl;
  }
};

int main()
{
  // ex1
  // ListNode *head = new ListNode{0};

  // ex2
  ListNode *head = new ListNode{1};
  head->next = new ListNode{2};
  head->next->next = new ListNode{3};
  head->next->next->next = new ListNode{4};
  head->next->next->next->next = new ListNode{5};
  head->next->next->next->next->next = new ListNode{6};
  head->next->next->next->next->next->next = new ListNode{7};

  Solution t;

  t.printList(head);
  t.reorderList(head);

  t.printList(head);
  // printList(head);
  cout << " end\n";
  return 0;
}
