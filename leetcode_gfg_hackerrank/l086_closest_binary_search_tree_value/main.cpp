
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <limits>
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
  int closestValue(TreeNode *root, double target)
  {
    int out = root->val;
    double dis = abs(root->val - target);
    bool dir = true;

    while (dir)
    {
      if (root->left && target < root->val)
        root = root->left;
      else if (root->right && target > root->val)
        root = root->right;
      else
        dir = false;

      if (dir && abs(root->val - target) < dis)
      {
        dis = abs(root->val - target);
        out = root->val;
      }
    }

    return out;
  }
};

int main(int argc, char *argv[])
{
  std::cout << " starts ... \n";

  TreeNode *root = new TreeNode(4);
  root->right = new TreeNode(5);
  root->left = new TreeNode(2);
  root->left->right = new TreeNode(3);
  root->left->left = new TreeNode(1);

  double target = -1;

  // [36, 13,37, 4,20,null,48,
  // 1,5,17,33,43,49,0,2,null,9,14,18,22,34,40,46,null,null,null,null,null,3,7,11,null,16,null,19,21,27,null,35,39,42,45,47,null,null,6,8,10,12,15,null,null,null,null,null,26,32,null,null,38,null,41,null,44,null,null,null,null,null,null,null,null,null,null,null,null,null,24,null,28,null,null,null,null,null,null,null,23,25,null,29,null,null,null,null,null,31,30]
  // 3.142857

  Solution t;

  int out = t.closestValue(root, target);

  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
