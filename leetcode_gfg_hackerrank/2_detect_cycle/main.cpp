// C++ program to return first node of loop.
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int key;
  ListNode *next;
  ListNode(int key) : key{key}, next{nullptr} {}
};

class Solution
{
 public:
  // Function to detect and remove loop in a linked list that may contain loop
  ListNode *detectCycle(ListNode *head)
  {
    // If list is empty or has only one node without loop
    if (head == NULL || head->next == NULL) return NULL;

    ListNode *slow = head, *fast = head;

    // Move slow and fast 1 and 2 steps ahead respectively.
    slow = slow->next;
    fast = fast->next->next;

    // Search for loop using slow and
    // fast pointers
    while (fast && fast->next)
    {
      if (slow == fast) break;
      slow = slow->next;
      fast = fast->next->next;
    }

    // If loop does not exist: for the case that there are two nodes in the list
    if (slow != fast) return NULL;

    // If loop exists. Start slow from head and fast from meeting point.
    slow = head;
    while (slow != fast)
    {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }

  // A utility function to print a linked list
  void printList(ListNode *head)
  {
    while (head != NULL)
    {
      cout << head->key << " ";
      head = head->next;
    }
    cout << endl;
  }
};

/* Driver program to test above function*/
int main()
{
  ListNode *head = new ListNode(50);
  head->next = new ListNode(20);
  head->next->next = new ListNode(15);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(10);

  /* Create a loop for testing */
  head->next->next->next->next->next = head->next->next;
  Solution obj;
  ListNode *res = obj.detectCycle(head);
  if (res == NULL)
    cout << "Loop does not exist" << endl;
  else
    cout << "Loop starting node is " << res->key << endl;

  return 0;
}
