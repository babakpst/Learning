
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
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    if (!p && !q) return true;
    if (!p || !q) return false;

    queue<TreeNode *> qOne, qTwo;

    qOne.push(p);
    qTwo.push(q);

    while (!qOne.empty() && !qTwo.empty())
    {
      TreeNode *tmp1 = qOne.front();
      TreeNode *tmp2 = qTwo.front();

      qOne.pop();
      qTwo.pop();

      if (tmp1->val != tmp2->val) return false;

      if (tmp1->left && tmp2->left)
      {
        qOne.push(tmp1->left);
        qTwo.push(tmp2->left);
      }
      else if ((!tmp1->left && tmp2->left) || (tmp1->left && !tmp2->left))
        return false;

      if (tmp1->right && tmp2->right)
      {
        qOne.push(tmp1->right);
        qTwo.push(tmp2->right);
      }
      else if ((!tmp1->right && tmp2->right) || (tmp1->right && !tmp2->right))
        return false;
    }

    return (qOne.empty() && qTwo.empty());
  }
};

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
  root->left->left = new TreeNode(2);

  TreeNode *root1 = new TreeNode{1};
  root1->left = new TreeNode(4);
  root1->right = new TreeNode(3);
  root1->left->left = new TreeNode(2);
  root1->left->left->left = new TreeNode(5);
  //*/

  Solution t;

  bool out = t.isSameTree(root, root1);

  cout << " answer: " << boolalpha << out << endl;

  cout << " end\n";
  return 0;
}
