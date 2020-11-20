
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
  ListNode *oddEvenList(ListNode *head) {

    if (head == nullptr)
      return head;

    ListNode *p1 = head;
    ListNode *p2 = head->next;
    ListNode *evenHead = p2;

    while (p2 != nullptr && p2->next != nullptr) {
      p1->next = p2->next;
      p1 = p1->next;
      p2->next = p1->next;
      p2 = p2->next;
    }
    p1->next = evenHead;
    return head;
  }

  void printLinkedList(ListNode *head) {
    cout << " linked list: \n";
    if (head == nullptr)
      cout << " null pointer\n";
    while (head != nullptr) {
      cout << head->val << " ";
      head = head->next;
    }
    cout << endl;
  }
};

int main() {
  cout << " start ... \n";

  // ListNode *head = nullptr;

  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  Solution obj;
  obj.printLinkedList(head);
  head = obj.oddEvenList(head);
  obj.printLinkedList(head);

  return 0;
}