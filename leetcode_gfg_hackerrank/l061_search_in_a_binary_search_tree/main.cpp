
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
 public:
  TreeNode *searchBST(TreeNode *root, int val)
  {
    cout << root->val << endl;
    if (val > root->val && root->right)
      return searchBST(root->right, val);
    else if (val < root->val && root->left)
      return searchBST(root->left, val);
    else if (val == root->val)
      return root;
    return nullptr;
  }

  TreeNode *searchBST2(TreeNode *root, int val)
  {
    TreeNode *cur = root;

    while (cur && cur->val != val)
    {
      cout << cur->val << endl;
      if (val > cur->val)
        cur = cur->right;
      else
        cur = cur->left;
    }
    return cur;
  }

  //============
  void PrintPreOrdered(TreeNode *&tr)
  {
    if (tr == NULL) return;
    std::cout << " pre-order:" << tr->val << std::endl;
    PrintPreOrdered(tr->left);
    PrintPreOrdered(tr->right);
  }
};

int main(int argc, char *argv[])
{
  std::cout << " starts ... \n";

  TreeNode *root = new TreeNode(4);
  root->right = new TreeNode(7);
  root->left = new TreeNode(2);

  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  int val = 2;

  Solution t;
  TreeNode *out = t.searchBST(root, val);
  TreeNode *out2 = t.searchBST2(root, val);

  cout << " answer: " << out->val << endl;
  cout << boolalpha << (out == out2) << endl << endl;

  t.PrintPreOrdered(out);

  std::cout << " done \n";
  return 0;
}
