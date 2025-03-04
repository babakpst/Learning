
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
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
  {
    TreeNode* out = nullptr;
    if (!root || !p) return out;

    if (p->right)
    {
      TreeNode* cur = p->right;
      while (cur->left)
      {
        cur = cur->left;
      }
      return cur;
    }
    else
    {
      TreeNode* cur = root;
      stack<TreeNode*> mys;

      while (root->val < p->val) root = root->right;

      bool check = false;
      while (cur || !mys.empty())
      {
        while (cur)
        {
          mys.push(cur);
          if (cur->val == p->val)
          {
            check = true;
            break;
          }
          cur = cur->left;
        }
        cur = mys.top();
        if (check && cur->val > p->val) return cur;
        mys.pop();
        cur = cur->right;
      }
    }
    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // TreeNode *root = new TreeNode(5);
  // root->left = new TreeNode(3);
  // root->left->left = new TreeNode(2);
  // root->left->left->left = new TreeNode(1);
  // root->left->right = new TreeNode(4);
  // root->left = new TreeNode(6);

  TreeNode* root = new TreeNode(8);
  root->right = new TreeNode(9);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(6);
  root->left->right->right = new TreeNode(7);
  root->left->right->left = new TreeNode(4);
  root->left->right->left->left = new TreeNode(3);
  root->left->right->left->right = new TreeNode(5);

  Solution t;

  TreeNode* out = t.inorderSuccessor(root, root->left);
  // TreeNode* out = t.inorderSuccessor(root, root->left->right);
  // TreeNode* out = t.inorderSuccessor(root, root->left->right->right);

  cout << " answer: " << out->val << endl;

  std::cout << " done \n";
  return 0;
}
