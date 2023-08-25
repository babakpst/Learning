
#include <iostream>
#include <queue>
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
