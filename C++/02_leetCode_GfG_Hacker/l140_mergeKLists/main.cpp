
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

// approach 1
class Solution1
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

// approach 2
class Solution2
{
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    ListNode *head = nullptr, *tmp = nullptr;
    bool cont = true;
    while (cont)
    {
      int min = 100'000;
      int index = -1;
      cont = false;
      for (int i = 0; i < lists.size(); i++)
      {
        cout << i << " " << (lists[i] ? lists[i]->val : -999) << endl;
        if (lists[i] && lists[i]->val < min)
        {
          min = lists[i]->val;
          index = i;
          cont = true;
        }
      }
      if (!cont) break;
      cout << " == " << index << " " << lists[index]->val << endl;
      if (!head)
      {
        head = lists[index];
        tmp = head;
      }
      else
      {
        tmp->next = lists[index];
        tmp = tmp->next;
      }
      lists[index] = lists[index]->next;
    }
    return head;
  }
};

// approach 3: with priority queue
class Solution
{
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    ListNode *head = new ListNode(0);
    ListNode *tmp = head;
    using mypair = pair<int, ListNode *>;
    priority_queue<mypair, vector<mypair>, greater<mypair> > pq;

    for (int i = 0; i < lists.size(); i++)
    {
      if (lists[i]) pq.push({lists[i]->val, lists[i]});
    }

    while (!pq.empty())
    {
      mypair node = pq.top();
      pq.pop();
      cout << node.first << " " << endl;
      tmp->next = node.second;
      tmp = tmp->next;
      if (node.second->next) pq.push({node.second->next->val, node.second->next});
    }
    return head->next;
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
