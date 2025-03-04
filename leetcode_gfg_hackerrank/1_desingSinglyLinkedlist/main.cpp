// Babak Poursartip
// 10/12/2020

// design linkedlist

#include <iostream>
using std::cout;
using std::endl;

struct node
{
  int val;
  node *next;
  node(int val) : val{val}, next{nullptr} {}
};

class MyLinkedList
{
 public:
  node *head;
  /** Initialize your data structure here. */
  MyLinkedList() { head = nullptr; }

  /** Get the value of the index-th node in the linked list. If the index is
   * invalid, return -1. */
  int get(int index)
  {
    node *cur = head;
    for (int i = 0; i < index; i++)
      if (cur->next)
        cur = cur->next;
      else
        return -1;
    return cur->val;
  }

  /** Add a node of value val before the first element of the linked list. After
   * the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val)
  {
    if (!head)
      head = new node(val);
    else
    {
      node *n = new node(val);
      n->next = head;
      head = n;
    }
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val)
  {
    if (head == nullptr)
    {
      addAtHead(val);
      return;
    }
    node *cur = head;
    node *n = new node(val);
    while (cur->next) cur = cur->next;
    cur->next = n;
  }

  /** Add a node of value val before the index-th node in the linked list. If
   * index equals to the length of linked list, the node will be appended to
   * the end of linked list. If index is greater than the length, the node
   * will not be inserted. */
  void addAtIndex(int index, int val)
  {
    if (index == 0)
    {
      addAtHead(val);
      return;
    }
    node *n = new node(val);
    node *cur = head;
    for (int i = 0; i < index - 1; i++)
      if (cur->next)
        cur = cur->next;
      else
        return;
    n->next = cur->next;
    cur->next = n;
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index)
  {
    node *cur = head;

    if (index == 0)
    {
      head = head->next;
      delete cur;
    }
    else
    {
      node *pre = nullptr;
      for (int i = 0; i < index; i++)
      {
        pre = cur;
        if (cur->next)
          cur = cur->next;
        else
          return;
      }
      pre->next = cur->next;
      delete cur;
    }
  }

  static int count;
  void printList()
  {
    count++;
    if (!head)
    {
      cout << "count: " << count << " "
           << "null\n";
      return;
    }
    node *n = head;
    cout << "count: " << count << "\n";
    cout << n->val << " ";
    while (n->next)
    {
      n = n->next;
      cout << n->val << " ";
    }
    cout << "\n";
  }
};

int MyLinkedList::count = 0;
int main()
{
  /**
   * Your MyLinkedList object will be instantiated and called as such:
   * MyLinkedList* obj = new MyLinkedList();
   * int param_1 = obj->get(index);
   * obj->addAtHead(val);
   * obj->addAtTail(val);
   * obj->addAtIndex(index,val);
   * obj->deleteAtIndex(index);
   */

  std::cout << "starts ... \n";

  MyLinkedList *obj = new MyLinkedList();

  obj->printList();
  obj->addAtTail(3);
  cout << "get: " << obj->get(0) << endl;
  obj->printList();
  obj->addAtIndex(0, 20);
  obj->printList();
  obj->addAtHead(1);
  obj->printList();

  obj->printList();
  obj->addAtIndex(1, 2);
  obj->printList();
  obj->get(1);
  obj->deleteAtIndex(0);
  obj->printList();
  obj->get(0);
  /*
  obj->addAtHead(6);
  obj->printList();

  cout << " index: " << 1 << ": " << obj->get(1) << endl;

  obj->addAtTail(7);
  obj->printList();
  obj->addAtTail(8);
  obj->printList();

  obj->addAtIndex(2, 9);
  obj->printList();

  obj->printList();
  */
  return 0;
}
