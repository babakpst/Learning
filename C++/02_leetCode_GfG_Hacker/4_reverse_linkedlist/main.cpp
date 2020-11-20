

// Babak Poursartip
// reverse linked list
#include <iostream>
using std::cout;
using std::endl;

struct node {
  int val;
  node *next;
  node(int val) : val{val}, next{nullptr} {}
};

class reverseLinkedList {
public:
  node *reverse(node *head) {
    node *pre = nullptr, *cur = head, *next = nullptr;
    while (cur != nullptr) {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    head = pre;
    return head;
  }
};

int main() {

  cout << " starts ...   \n ";

  node *head = new node(1);
  head->next = new node(2);
  head->next->next = new node(3);
  head->next->next->next = new node(4);
  head->next->next->next->next = new node(5);
  head->next->next->next->next->next = new node(6);

  node *cur = head;
  while (cur != nullptr) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << "\n";
  reverseLinkedList obj;
  head = obj.reverse(head);

  cur = head;
  while (cur != nullptr) {
    cout << cur->val << " ";
    cur = cur->next;
  }

  cout << "\n";

  return 0;
}