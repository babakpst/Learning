
// babak poursartip
// Jan 31, 2023

#include <algorithm>
#include <cmath>
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

// recursive
class Solution0
{
 public:
  bool isValidBST(TreeNode *root) { return test(root, -pow(2, 31) - 1, pow(2, 31)); }

  bool test(TreeNode *root, long low, long high)
  {
    // base
    if (!root) return true;
    // if ((root->val <= low && low != -pow(2,31))  || (high <= root->val && high != (pow(2,31)-1) ) ) return false;
    if ((root->val <= low) || (high <= root->val)) return false;
    return test(root->left, low, root->val) && test(root->right, root->val, high);
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

  // TreeNode *tr = new TreeNode(0);
  TreeNode *tr = new TreeNode(2147483647);

  // TreeNode *tr = new TreeNode(2);
  // tr->left = new TreeNode(1);
  // tr->right = new TreeNode(4);
  // tr->right->left = new TreeNode(3);
  // tr->right->right = new TreeNode(6);

  // Solution t;
  Solution0 t;

  bool out = t.isValidBST(tr);

  cout << " answer: " << boolalpha << out << endl;

  std::cout << " done \n";
  return 0;
}
