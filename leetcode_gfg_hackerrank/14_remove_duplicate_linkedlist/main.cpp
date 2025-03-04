

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Node
{
 public:
  int data;
  Node *next;
  Node(int d)
  {
    data = d;
    next = NULL;
  }
};

class Solution
{
 public:
  Node *removeDuplicates(Node *head)
  {
    if (head == NULL) return head;
    Node *h = head;
    while (h != NULL && h->next != NULL)
    {
      while (h->next != 0 && h->data == h->next->data)
      {
        Node *tmp = h->next;
        h->next = h->next->next;
        delete tmp;
      }
      h = h->next;
    }
    return head;
  }

  Node *insert(Node *head, int data)
  {
    Node *p = new Node(data);
    if (head == NULL)
    {
      head = p;
    }
    else if (head->next == NULL)
    {
      head->next = p;
    }
    else
    {
      Node *start = head;
      while (start->next != NULL)
      {
        start = start->next;
      }
      start->next = p;
    }
    return head;
  }
  void display(Node *head)
  {
    Node *start = head;
    while (start)
    {
      cout << start->data << " ";
      start = start->next;
    }
  }
};

int main()
{
  Node *head = NULL;
  Solution mylist;
  int T = 7, data;
  while (T-- > 0)
  {
    // int data[] = {4, 3, 3, 2, 2, 2, 1};
    int data[] = {1, 1, 1, 1, 1, 1, 1};
    head = mylist.insert(head, data[T]);
  }
  head = mylist.removeDuplicates(head);

  mylist.display(head);
}
