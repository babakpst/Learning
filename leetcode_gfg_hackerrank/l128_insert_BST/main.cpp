
// babak poursartip
// Jan 03, 2023

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

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
  TreeNode *insertIntoBST(TreeNode *root, int val)
  {
    TreeNode *nLeaf = new TreeNode(val);

    if (!root) return nLeaf;

    TreeNode *cur = root;

    bool con = true;
    while (con)
    {
      if (cur->val > val)
      {
        if (cur->left)
          cur = cur->left;
        else
        {
          cur->left = nLeaf;
          con = false;
        }
      }
      else
      {
        if (cur->right)
          cur = cur->right;
        else
        {
          cur->right = nLeaf;
          con = false;
        }
      }
    }
    return root;
  }

  void printBST(TreeNode *root)
  {
    if (!root)
    {
      cout << " null tree \n";
      return;
    }

    // DFS:in-order
    stack<TreeNode *> mys;
    vector<int> out;

    TreeNode *cur = root;
    while (cur || !mys.empty())
    {
      while (cur)
      {
        mys.push(cur);
        cur = cur->left;
      }
      cur = mys.top();
      mys.pop();
      out.push_back(cur->val);
      cur = cur->right;
    }

    for (auto it = begin(out); it != end(out); it++) cout << *it << " ";
    cout << "\n";

    return;
  }
};

int main(int argc, char *argv[])
{
  std::cout << " starts ... \n";

  TreeNode *root = new TreeNode(4);
  root->right = new TreeNode(7);
  root->left = new TreeNode(2);
  root->left->right = new TreeNode(3);
  root->left->left = new TreeNode(1);

  Solution t;
  t.printBST(root);

  TreeNode *out = t.insertIntoBST(root, atoi(argv[1]));
  t.printBST(out);

  std::cout << " done \n";
  return 0;
}
