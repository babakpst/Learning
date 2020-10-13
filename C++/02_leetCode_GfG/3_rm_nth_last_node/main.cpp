/**
 * Definition for singly-linked list.
 */

#include <iostream>

using std::cout;
using std::endl;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head == nullptr)
      return head;
    ListNode *cur = head;

    for (int i = 0; i < n; ++i) {
      cur = cur->next;
      if (cur == nullptr && i != n - 1)
        return head;
    }

    if (cur == nullptr) {
      cur = head;
      head = head->next;
      delete cur;
      return head;
    }

    ListNode *pre = head;
    cout << " here1: " << cur->val << endl;

    while (cur->next != nullptr) {
      cur = cur->next;
      pre = pre->next;
    }
    cout << " here2: " << cur->val << endl;
    cur = pre->next;
    cout << " here3: " << pre->val << endl;
    pre->next = pre->next->next;
    delete cur;
    return head;
  }
};

int main() {
  cout << " starts ... \n";

  ListNode *head = new ListNode(1);
  /*
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  */
  cout << " before\n";
  ListNode *cur = head;
  while (cur) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << "\n";

  Solution obj;
  head = obj.removeNthFromEnd(head, 1);

  cout << " after\n";
  cur = head;
  while (cur) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << "\n";
  return 0;
}
