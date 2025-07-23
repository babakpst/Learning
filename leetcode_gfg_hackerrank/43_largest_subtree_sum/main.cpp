
// babak poursartip
// Jan 03, 2023

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left, *right;
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

int cal(TreeNode *root, int &ans)
{
  if (root == nullptr) return 0;
  int currSum = root->val + cal(root->left, ans) + cal(root->right, ans);
  ans = max(ans, currSum);
  cout << "hhh " << ans << " " << currSum << endl;
  return currSum;
};

int LargestSubtreeSum(TreeNode *root)
{
  // if (!root) return 0;
  // int maxSum = -1000;
  // cal(root, maxSum);
  // return maxSum;
  if (root == nullptr) return 0;
  int ans = -1000;
  cal(root, ans);
  // findLargestSubtreeSumUtil(root, ans);
  return ans;
};

int main(int argc, char *argv[])
{
  std::cout << " starts ... \n";
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(-2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(-6);
  root->right->right = new TreeNode(2);

  int out = LargestSubtreeSum(root);

  cout << " answer: " << out << endl;
  std::cout << " done \n";
  return 0;
}
