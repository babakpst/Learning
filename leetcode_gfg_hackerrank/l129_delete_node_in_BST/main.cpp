
// babak poursartip
// Jan 03, 2023

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
 private:
  /**
   * findSuccesor - Helper function for finding successor
   * In BST, succesor of root is the leftmost child in root's right subtree
   */
  TreeNode* findSuccessor(TreeNode* root)
  {
    TreeNode* cur = root->right;
    while (cur && cur->left)
    {
      cur = cur->left;
    }
    return cur;
  }

 public:
  TreeNode* deleteNode(TreeNode* root, int key)
  {
    // return null if root is null
    if (!root)
    {
      return root;
    }

    // delete current node if root is the target node
    if (root->val == key)
    {
      // replace root with root->right if root->left is null
      if (!root->left)
      {
        return root->right;
      }

      // replace root with root->left if root->right is null
      if (!root->right)
      {
        return root->left;
      }

      // replace root with its successor if root has two children
      TreeNode* p = findSuccessor(root);
      root->val = p->val;
      root->right = deleteNode(root->right, p->val);
      return root;
    }

    if (root->val < key)
    {
      // find target in right subtree if root->val < key
      root->right = deleteNode(root->right, key);
    }
    else
    {
      // find target in left subtree if root->val > key
      root->left = deleteNode(root->left, key);
    }
    return root;
  }

  //===================
  void printBST(TreeNode* root)
  {
    stack<TreeNode*> mBST;
    TreeNode* cur = root;

    while (cur || !mBST.empty())
    {
      while (cur)
      {
        mBST.push(cur);
        cur = cur->left;
      }
      cur = mBST.top();
      mBST.pop();
      cout << cur->val << " ";
      cur = cur->right;
    }
    cout << endl;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(6);
  root->right->right = new TreeNode(7);
  int key = 3;
  // int key = 7;

  Solution t;

  t.printBST(root);
  TreeNode* nroot = t.deleteNode(root, key);
  t.printBST(nroot);

  std::cout << " done \n";
  return 0;
}
