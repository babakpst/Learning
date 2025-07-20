

struct TreeNode
{
  int val;
  TreeNode *left, *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
  TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(nullptr), right(nullptr) {}
};

class Solution
{
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
  {
    if (!list1) return list2;
    if (!list2) return list1;
    ListNode* head = nullptr;

    if (list1->value > list2->value)
    {
      head = list1;
      head->next = mergeTwoLists(list1->next, list2);
    }
    else
    {
      head = list2;
      head->next = list2;
      mergeTwoLists(list1, list2->next);
    }
    return head = head->next;
  }
}
}
