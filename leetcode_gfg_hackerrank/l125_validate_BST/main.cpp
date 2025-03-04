
// babak poursartip
// Jan 31, 2023

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
  bool isValidBST(TreeNode *root)
  {
    if (!root) return true;

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

    for (auto it = begin(out); it != end(out) - 1; it++)
      if (*it >= *(it + 1)) return false;

    return true;
  }
};

int main(int argc, char *argv[])
{
  std::cout << " starts ... \n";

  // TreeNode *tr = new TreeNode(5);
  // tr->left = new TreeNode(1);
  // tr->right = new TreeNode(4);
  // tr->right->left = new TreeNode(3);
  // tr->right->right = new TreeNode(6);

  TreeNode *tr = new TreeNode(2);
  tr->left = new TreeNode(1);
  tr->right = new TreeNode(4);
  tr->right->left = new TreeNode(3);
  tr->right->right = new TreeNode(6);

  Solution t;

  bool out = t.isValidBST(tr);

  cout << " answer: " << boolalpha << out << endl;

  std::cout << " done \n";
  return 0;
}
