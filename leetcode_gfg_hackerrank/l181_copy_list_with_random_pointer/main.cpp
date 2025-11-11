
// babak poursartip
// Jan 03, 2023

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any
node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has
its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should
point to new nodes in the copied list such that the pointers in the original list and copied list represent the same
list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two
nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val,
random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not
point to any node. Your code will only be given the head of the original linked list.
*/

class Node
{
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution
{
 public:
  unordered_map<Node*, Node*> mymap;

  Node* copyRandomList(Node* head)
  {
    if (!head) return head;

    Node* newHead = new Node(head->val);
    mymap.insert({head, newHead});

    Node* temp = newHead;

    while (head)
    {
      // cout << "here0 \n";
      if (!head->next)
      {
        // cout << "here2 \n";
        temp->next = nullptr;
      }

      else if (mymap.find(head->next) == mymap.end())
      {
        // cout << "here1 \n";
        temp->next = new Node(head->next->val);
        mymap.insert({head->next, temp->next});
      }
      else
      {
        // cout << "here3 \n";
        temp->next = mymap[head->next];
      }

      if (!head->random)
      {
        temp->random = nullptr;
        // cout << "here5 \n";
      }
      else if (mymap.find(head->random) == mymap.end())
      {
        // cout << "here4 \n";
        temp->random = new Node(head->random->val);
        mymap.insert({head->random, temp->random});
      }
      else
      {
        // cout << "here6 \n";
        temp->random = mymap[head->random];
      }
      temp = temp->next;
      head = head->next;

      // cout << temp->val << endl;
    }
    return newHead;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  // [[7,null],[13,0],[11,4],[10,2],[1,0]]

  // 0
  Node* head = new Node(7);
  head->random = nullptr;

  // 1
  head->next = new Node(13);
  head->next->random = head;

  // 2
  head->next->next = new Node(11);
  head->next->next->random = new Node(1);

  // 3
  head->next->next->next = new Node(10);
  head->next->next->next->random = head->next->next;

  // 4
  head->next->next->next->next = head->next->next->random;
  head->next->next->next->next->random = head;

  Node* out = t.copyRandomList(head);

  cout << " answer: " << out << endl;

  cout << " answer: " << endl;
  // for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  // cout << endl;

  std::cout << " done \n";
  return 0;
}
