
// Jul 23, 2022

/*

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]


Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

*/

#include <iostream>
#include <memory>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printList(ListNode* list)
{
  // cout << " checkpoint Print 001 \n";
  if (!list)
    cout << " null \n";
  else
  {
    // ListNode *list = this;
    while (list != nullptr)
    {
      cout << list->val << " ";
      list = list->next;
    }
    cout << endl;
  }
};

// non-recursive
class Solution1
{
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
  {
    // edge cases
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    // if both are not null
    ListNode *end = nullptr, *head = nullptr;
    if (list1->val < list2->val)
    {
      head = list1;
      list1 = list1->next;
    }
    else
    {
      head = list2;
      list2 = list2->next;
    }
    end = head;
    end->next = nullptr;
    while (list1 != nullptr && list2 != nullptr)
    {
      // cout << " current cumulative list: ";
      if (list1->val < list2->val)
      {
        // cout << " one \n" ;
        end->next = list1;
        list1 = list1->next;
      }
      else
      {
        // cout << " two \n" ;
        end->next = list2;
        list2 = list2->next;
      }
      end = end->next;
      end->next = nullptr;
    }
    if (list1 != nullptr)
      end->next = list1;
    else
      end->next = list2;

    return head;
  }
};

class Solution2
{
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
  {
    // edge cases
    if (list1 == nullptr && list2 == nullptr)
      return nullptr;
    else if (list1 == nullptr && list2 != nullptr)
      return list2;
    else if (list1 != nullptr && list2 == nullptr)
      return list1;

    // if both are not null
    ListNode *end = nullptr, *head = nullptr;
    if (list1->val < list2->val)
    {
      head = list1;
      end = list1;
      list1 = list1->next;
      end->next = nullptr;
    }
    else
    {
      head = list2;
      end = list2;
      list2 = list2->next;
      end->next = nullptr;
    }
    while (list1 != nullptr && list2 != nullptr)
    {
      cout << " current cumulative list: ";
      // printList(head);
      if (list1->val < list2->val)
      {
        cout << " one \n";
        end->next = list1;
        list1 = list1->next;
      }
      else
      {
        cout << " two \n";
        end->next = list2;
        list2 = list2->next;
      }
      end = end->next;
      end->next = nullptr;
      // printList(end);
    }
    if (list1 != nullptr)
      end->next = list1;
    else
      end->next = list2;

    return head;
  }
};

// recursive
class Solution
{
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
  {
    // base case
    if (!list1)
      return list2;
    else if (!list2)
      return list1;

    if (list1->val < list2->val)
    {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    }
    else
    {
      list2->next = mergeTwoLists(list1, list2->next);
      return list2;
    }
  }
};

//==========================================
int main(int argc, char* argv[])
{
  cout << " starts ... \n";

  std::unique_ptr<ListNode> h1 = nullptr, h2 = nullptr;

  h1 = std::make_unique<ListNode>(1);
  h1->next = new ListNode(2);
  h1->next->next = new ListNode(4);
  h1->next->next->next = new ListNode(5);
  h1->next->next->next->next = new ListNode(12);
  // h1=nullptr;
  cout << " list 1: \n";
  // h1->printList();
  printList(h1.get());

  h2 = std::make_unique<ListNode>(1);
  h2->next = new ListNode(3);
  h2->next->next = new ListNode(4);
  // h2=nullptr;
  cout << " list 2: \n";
  // h2->printList();
  printList(h2.get());

  // create two sorted lists
  // merging
  Solution t;
  ListNode* merged = t.mergeTwoLists(h1.get(), h2.get());

  // output
  cout << " out: \n";
  // merged->printList();
  printList(merged);

  cout << " done. \n";
  return 0;
}
