

// Babak Poursartip
// reverse linked list
#include <iostream>
using std::cout;
using std::endl;

struct node
{
  int val;
  node *next;
  node(int val) : val{val}, next{nullptr} {}
};

class reverseLinkedList
{
 public:
  node *reverse(node *head)
  {
    node *pre = nullptr, *cur = head, *next = nullptr;
    while (cur != nullptr)
    {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    head = pre;
    return head;
  }
};

//==========================
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// without recursion
class Solution0
{
 public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *first = nullptr;
    ListNode *second = head;
    while (second)
    {
      ListNode *tmp = second->next;
      second->next = first;
      first = second;
      second = tmp;
    }
    return first;
  }
};

// without recursion
class Solution1
{
 public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *newhead = head;
    while (head->next)
    {
      ListNode *tmp = head->next;
      head->next = head->next->next;
      tmp->next = newhead;
      newhead = tmp;
    }
    return newhead;
  }
};

// recursion
class Solution
{
 public:
  ListNode *cur = nullptr;
  ListNode *reverseList(ListNode *head)
  {
    if (!head) return cur;
    cout << head->val << endl;
    ListNode *tmp = head->next;
    head->next = cur;
    cur = head;
    return reverseList(tmp);
  }
};

int main()
{
  cout << " starts ...   \n ";

  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  ListNode *cur = head;
  while (cur != nullptr)
  {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << "\n";

  Solution obj;
  // Solution1 obj;
  head = obj.reverseList(head);

  cur = head;
  while (cur != nullptr)
  {
    cout << cur->val << " ";
    cur = cur->next;
  }

  cout << "\n";

  return 0;
}
