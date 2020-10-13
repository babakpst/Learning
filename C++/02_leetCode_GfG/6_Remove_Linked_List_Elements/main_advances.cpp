
// Babak Poursartip
// 10/13/2020
#include <iostream>

using std::cout;
using std::endl;

// ==============================
/* Definition for singly-linked list.  */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {

    // edge cases
    if (!head)
      return head;

    ListNode *cur = new ListNode(-1);
    cur->next = head;
    head = cur;
    while (cur->next != nullptr) {
      if (cur->next->val == val) {
        delete cur->next;
        cur->next = cur->next->next;
      } else
        cur = cur->next;
    }
    return head->next;
  }

  void printLinkedList(ListNode *head) {
    cout << " the Linked List: \n";
    if (head == nullptr)
      cout << "null\n";
    else {
      ListNode *cur = head;
      while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
      }
      cout << endl;
    }
  }
};

int main() {

  cout << "\n starts ... \n";

  // ListNode *head = nullptr;

  // Linked List: 1->2->6->3->4->5->6
  ListNode *head = new ListNode(1);
  // head->next = new ListNode(2);
  // head->next->next = new ListNode(2);
  // head->next->next->next = new ListNode(1);

  //*
  head->next = new ListNode(2);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next->next = new ListNode(6);
  //*/
  Solution obj;
  obj.printLinkedList(head);
  head = obj.removeElements(head, 6);
  obj.printLinkedList(head);

  cout << "\n finished \n";

  return 0;
}