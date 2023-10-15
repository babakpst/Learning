
// Tree Traversal
// Babak Poursartip

// Comments
/*
This is code is based on the following youtube clip:
https://www.youtube.com/watch?v=IpyCqRmaKW4


    1
   /\
  2 3
 /\  \
4 5  6

All possible cases are discussed:
1- BFS Level-order:   1 2 3 4 5 6
2- DFS Pre-ordered:   Root-Left-Right  1 2 4 5 3 6
3- DFS In-ordered:    Left-Root-Right 4 2 5  1 3 6
4- DFS Post-ordered:  Left-Right-Root  4 5 2 6 3 1

*/

#include <algorithm>
#include <iostream>
#include <queue>
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

class Solution
{
 public:
  // pre-order ===============================
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> out;

    stack<TreeNode *> myst;

    if (root) myst.push(root);
    while (!myst.empty())
    {
      TreeNode *temp = myst.top();
      // cout << " here: " << temp->val << endl;
      myst.pop();
      if (temp->right) myst.push(temp->right);
      if (temp->left) myst.push(temp->left);
      out.push_back(temp->val);
    }

    return out;
  }
  // in-order ===============================
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> out;

    stack<TreeNode *> myst;
    TreeNode *curr = root;

    while (curr != nullptr || !myst.empty())
    {
      while (curr != nullptr)
      {
        myst.push(curr);
        curr = curr->left;
      }
      curr = myst.top();
      myst.pop();
      out.push_back(curr->val);
      curr = curr->right;
    }
    return out;
  }
  // post-order ===============================
  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> out;

    if (!root) return out;

    stack<TreeNode *> myst;
    myst.push(root);
    TreeNode *prev = nullptr;

    while (!myst.empty())
    {
      TreeNode *current = myst.top();
      /* go down the tree in search of a leaf an if so
         process it and pop stack otherwise move down */
      if (prev == nullptr || prev->left == current || prev->right == current)
      {
        if (current->left)
          myst.push(current->left);
        else if (current->right)
          myst.push(current->right);
        else
        {
          myst.pop();
          out.push_back(current->val);
        }
        /* go up the tree from left node, if the child
           is right push it onto stack otherwise process
           parent and pop stack */
      }
      else if (current->left == prev)
      {
        if (current->right)
          myst.push(current->right);
        else
        {
          myst.pop();
          out.push_back(current->val);
        }

        /* go up the tree from right node and after
        coming back from right node process parent and
        pop stack */
      }
      else if (current->right == prev)
      {
        myst.pop();
        out.push_back(current->val);
      }
      prev = current;
    }
    return out;
  }

  vector<int> levelOrder(TreeNode *tree)
  {
    vector<int> out;
    queue<TreeNode *> myq;

    myq.push(tree);
    while (!myq.empty())
    {
      TreeNode *tmp = myq.front();
      myq.pop();
      out.push_back(tmp->val);
      if (tmp->left) myq.push(tmp->left);
      if (tmp->right) myq.push(tmp->right);
    }
    return out;
  }
};

//=================================================================================================
// main code
int main()
{
  // Creating a tree linked-list
  struct TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  Solution t;
  vector<int> out;

  out = t.inorderTraversal(root);
  std::cout << " In-ordered : \n";
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  out = t.preorderTraversal(root);
  std::cout << " Pre-ordered : \n";
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  out = t.postorderTraversal(root);
  std::cout << " Post-ordered : \n";
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  out = t.levelOrder(root);
  std::cout << " level-ordered : \n";
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  return 0;
}
