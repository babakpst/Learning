
#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val{0}, next{nullptr} {}
  ListNode(int val) : val{val}, next{nullptr} {}
  ListNode(int val, ListNode *next) : val{val}, next{next} {}
};

void printList(ListNode *list)
{
  cout << " list: \n";
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

class Solution
{
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    ListNode *head = nullptr;
    ListNode *curr = nullptr;
    int max = 100000;
    int ind = -1;

    bool allNull = true;
    for (int i = 0; i < lists.size(); ++i)
    {
      if (lists[i] && lists[i]->val < max)
      {
        max = lists[i]->val;
        ind = i;
        allNull = false;
      }
    }
    if (ind > -1)
    {
      head = lists[ind];
      // head->next = nullptr;
      lists[ind] = lists[ind]->next;
    }

    curr = head;

    while (!allNull)
    {
      allNull = true;
      max = 10000;
      ind = -1;
      for (int i = 0; i < lists.size(); ++i)
      {
        if (lists[i] && lists[i]->val < max)
        {
          max = lists[i]->val;
          ind = i;
          allNull = false;
        }
      }
      if (ind > -1)
      {
        // cout << " adding: "<< ind << " " << lists[ind]->val << "  " << max << endl;
        curr->next = lists[ind];
        lists[ind] = lists[ind]->next;
        curr = curr->next;
        // curr->next = nullptr;
      }
      // printList(head);
    }

    // cout << " end of sol\n";
    // printList(head);

    return head;
  }
};

int main(int argc, char *argv[])
{
  vector<ListNode *> lists(3);
  ListNode *head;

  head = new ListNode(1);
  head->next = new ListNode(4);
  head->next->next = new ListNode(5);
  lists[0] = head;
  head = nullptr;  // memory leakage

  head = new ListNode(1);
  head->next = new ListNode(3);
  head->next->next = new ListNode(4);
  lists[1] = head;
  head = nullptr;

  head = new ListNode(2);
  head->next = new ListNode(6);
  lists[2] = head;
  head = nullptr;

  // print lists
  for (auto list : lists) printList(list);

  Solution sol;
  ListNode *out = sol.mergeKLists(lists);

  cout << "output: \n";
  printList(out);

  cout << " end\n";
  return 0;
}
