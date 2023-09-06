
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>

using namespace std;

// /**
//  * Definition for a binary tree node.
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
  int kthSmallest(TreeNode *root, int k)
  {
    // vector<int> nums;
    stack<TreeNode *> ms;

    int counter = 0;
    TreeNode *cur = root;
    while (cur || !ms.empty())
    {
      while (cur)
      {
        ms.push(cur);
        cur = cur->left;
      }
      cur = ms.top();
      ms.pop();
      counter++;
      // if (counter==k) cout <<  "answer: " << cur->val << endl;
      if (counter == k) return cur->val;
      // nums.push_back(cur->val);
      cur = cur->right;
    }

    // sort(begin(nums),end(nums));

    // return nums[k-1];
    return 0;
  }
};

int main()
{
  TreeNode *root = new TreeNode(5);
  root->right = new TreeNode(6);
  root->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->left->left = new TreeNode(2);
  root->left->left->left = new TreeNode(1);

  int k = 3;

  Solution t;
  int out = t.kthSmallest(root, k);
  cout << out << endl;

  cout << " end\n";
  return 0;
}
