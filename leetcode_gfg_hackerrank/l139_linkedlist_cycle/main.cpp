
#include <iostream>
#include <list>

using namespace std;

struct ListNode
{
  int val;
  ListNode* next;
  ListNode(int val) : val{val}, next{nullptr} {}
};

class Solution
{
 public:
  bool hasCycle(ListNode* head)
  {
    if (!head) return false;

    ListNode *slow = head, *fast = head->next;
    // cout <<" starts-slow: " << slow->val << " fast: "<< fast->val << endl;

    while (fast && fast->next)
    {
      // cout <<"slow: " << slow->val << " fast: "<< fast->val << endl;
      if (slow == fast) return true;
      slow = slow->next;
      fast = fast->next->next;
    }
    return false;
  }
};

int main(int argc, char* argv[])
{
  ListNode* head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next;

  Solution sol;
  bool out = sol.hasCycle(head);
  cout << boolalpha << out << endl;
  cout << "end\n";
  return 0;
}
