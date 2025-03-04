
// babak poursartip
// Sept 8, 2022

#include <algorithm>
#include <iostream>
#include <stack>
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

using mypair = pair<TreeNode *, int>;
class Solution
{
 public:
  bool hasPathSum(TreeNode *root, int targetSum)
  {
    if (!root) return false;

    stack<mypair> myst;

    myst.push(make_pair(root, root->val));
    // int sum = root->val;
    int sum = 0;
    while (!myst.empty())
    {
      mypair temp = myst.top();
      myst.pop();

      cout << temp.second << endl;
      if (!temp.first->left && !temp.first->right && temp.second == targetSum) return true;

      if (temp.first->left) myst.push(make_pair(temp.first->left, temp.second + temp.first->left->val));
      if (temp.first->right) myst.push(make_pair(temp.first->right, temp.second + temp.first->right->val));
    }
    return false;
  }
};

int main(int argc, char *argv[])
{
  std::cout << " starts ... \n";

  // ex1
  // TreeNode *root = nullptr;
  // int targetSum = 22;

  // ex2
  TreeNode *root = new TreeNode{10};
  int targetSum = 1;

  // ex3
  /*
  TreeNode *root = new TreeNode{1};
  root->left  = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left  = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  */

  // ex4
  /*
  TreeNode *root = new TreeNode{5};

  root->left  = new TreeNode(4);
  root->left->left  = new TreeNode(11);
  root->left->left->left  = new TreeNode(7);
  root->left->left->right  = new TreeNode(2);

  root->right = new TreeNode(8);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(1);
  int targetSum = 22;

  */

  Solution t;

  bool out = t.hasPathSum(root, targetSum);
  cout << " answer: " << out << endl;
  std::cout << " done \n";
  return 0;
}
