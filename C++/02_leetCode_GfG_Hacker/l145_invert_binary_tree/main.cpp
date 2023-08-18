
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left, *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right) : val{val}, left{left}, right{right} {}
};

class Solution
{
 public:
  TreeNode *invertTree(TreeNode *root)
  {
    if (!root) return root;

    queue<TreeNode *> mq;
    mq.push(root);

    while (!mq.empty())
    {
      TreeNode *tmp = mq.front();
      mq.pop();
      TreeNode *node = tmp->left;
      tmp->left = tmp->right;
      tmp->right = node;
      if (tmp->left) mq.push(tmp->left);
      if (tmp->right) mq.push(tmp->right);
    }
    return root;
  }
};

void printTree(TreeNode *root)
{
  queue<TreeNode *> mq;
  mq.push(root);

  while (!mq.empty())
  {
    TreeNode *tmp = mq.front();
    mq.pop();

    cout << tmp->val << " ";
    if (tmp->left) mq.push(tmp->left);
    if (tmp->right) mq.push(tmp->right);
  }
  cout << endl;
}

int main(int argc, char *argv[])
{
  // ex3
  /*
  TreeNode *root = new TreeNode{1};
  root->left  = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left  = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  //*/

  // ex4
  ///*
  TreeNode *root = new TreeNode{1};
  root->left = new TreeNode(4);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  //*/

  Solution t;
  printTree(root);

  TreeNode *out = t.invertTree(root);

  printTree(out);

  cout << " end\n";
  return 0;
}
