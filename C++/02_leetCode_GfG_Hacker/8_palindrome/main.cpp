
// Babak Poursartip
// 10/13/2020

#include <iostream>

using std::cout;
using std::endl;

/* Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  bool compareLinkedLists(ListNode *head1, ListNode *head2) {
    ListNode *p1 = head1;
    ListNode *p2 = head2;
    while (p1 && p2) {
      if (p1->val == p2->val) {
        p1 = p1->next;
        p2 = p2->next;
      } else
        return 0;
    }

    // if both nodes are null (having the same sizes)
    if (p1 == nullptr && p2 == nullptr)
      return 1;

    // if one node is null and the other one is not
    return 0;
  }

  ListNode *reverse(ListNode *head) {
    ListNode *pre = nullptr, *cur = head, *next = nullptr;
    while (cur != nullptr) {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    // head = pre;
    return pre;
  }

  bool isPalindrome(ListNode *head) {

    ListNode *preslow = nullptr;     // This is needed if the linked list is odd
    ListNode *head_second = nullptr; // head of the second half
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *midNode = nullptr; // to handle linked list with odd no. of nodes.

    bool palindrome = true; // if linked list is null of has only one node.
    if (head != nullptr && head->next != nullptr) {
      /* find the middle node:
      The slow pointer moves by 1 and the fast moves by 2. slow pointer will
      have the middle node once the fast one reaches the end.
      */
      while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        preslow = slow;
        slow = slow->next;
      }

      /* if the no. of nodes in the linked list is even, fast ptr become
       * nullptr, and the process halts, but if the list is odd, fast->next
       * becomes nullptr. For the odd cases, we skip the middle node, but we
       * need to keep to restore the original linked list.*/
      if (fast != nullptr) {
        midNode = slow;
        slow = slow->next; // this node is the beginning of the secod half
      }

      // reverse the second half of the list
      preslow->next = nullptr; // to disconnect the second half from the first
      // head_second = slow;
      head_second = reverse(slow);

      // compare the two lists
      palindrome = compareLinkedLists(head, head_second);

      // reverse the second half and attach two parts.
      head_second = reverse(head_second);

      if (midNode != nullptr) { // odd nodes in the linked list
        preslow->next = midNode;
        midNode->next = head_second;
      } else
        preslow->next = head_second;
    }
    return palindrome;
  }

  void printLinkedList(ListNode *head) {
    while (head != nullptr) {
      cout << head->val << " ";
      head = head->next;
    }
    cout << " null\n";
  }
};

// ===============================================
int main() {

  cout << " starts ... \n";

  // ListNode *head = nullptr;

  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next->next->next->next->next->next =
      new ListNode(3);
  head->next->next->next->next->next->next->next->next->next->next->next =
      new ListNode(2);
  head->next->next->next->next->next->next->next->next->next->next->next->next =
      new ListNode(1);

  Solution obj;
  obj.printLinkedList(head);
  cout << " Is the linked list palindrome? " << std::boolalpha
       << obj.isPalindrome(head) << endl;
  obj.printLinkedList(head);
  return 0;
}