

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
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

    return second;
  }
};
