
// babak poursartip
// Jan 03, 2023

#include <algorithm>
#include <iostream>
#include <queue>
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
  // void findLCA(TreeNode* root, TreeNode* p, TreeNode* q)
  // {
  //   if (p->val > root->val && q->val > root->val ) findLCA(root->right, p, q);
  //   else if (p->val < root->val && q->val < root->val ) findLCA(root->right, p, q);
  //   else return;
  // }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    bool con = true;
    while (con)
    {
      if (p->val > root->val && q->val > root->val)
        root = root->right;
      else if (p->val < root->val && q->val < root->val)
        root = root->left;
      else
        con = false;
    }
    return root;
  }

  void printBST_BFS(TreeNode* root)
  {
    cout << " printing BFS ... \n";
    if (!root) return;

    queue<TreeNode*> myq;
    myq.push(root);

    while (!myq.empty())
    {
      TreeNode* tmp = myq.front();
      myq.pop();
      cout << tmp->val << " ";

      if (tmp->left) myq.push(tmp->left);
      if (tmp->right) myq.push(tmp->right);
    }
    cout << endl;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  TreeNode* root = new TreeNode(6);

  root->left = new TreeNode(2);
  root->right = new TreeNode(8);

  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);

  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);

  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);

  Solution t;

  t.printBST_BFS(root);

  TreeNode* out = t.lowestCommonAncestor(root, root->left->left, root->left->right->right);

  cout << " answer: " << out->val << endl;

  std::cout << " done \n";
  return 0;
}
