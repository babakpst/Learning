
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
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
 public:
  int index = 0;
  vector<int> bst;

  BSTIterator(TreeNode *root)
  {
    TreeNode *cur = root;
    stack<TreeNode *> dfs;

    while (cur || !dfs.empty())
    {
      while (cur)
      {
        dfs.push(cur);
        cur = cur->left;
      }
      cur = dfs.top();
      dfs.pop();
      bst.push_back(cur->val);
      cur = cur->right;
    }
  }

  int next() { return bst[index++]; }

  bool hasNext() { return (index < bst.size()); }
};

int main(int argc, char *argv[])
{
  std::cout << " starts ... \n";

  TreeNode *root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(15);
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(20);

  BSTIterator *obj = new BSTIterator(root);
  cout << " next: " << obj->next() << endl;
  cout << " next: " << obj->next() << endl;
  cout << " has next: " << boolalpha << obj->hasNext() << endl;
  cout << " next: " << obj->next() << endl;
  cout << " has next: " << boolalpha << obj->hasNext() << endl;
  cout << " next: " << obj->next() << endl;
  cout << " has next: " << boolalpha << obj->hasNext() << endl;
  cout << " next: " << obj->next() << endl;
  cout << " has next: " << boolalpha << obj->hasNext() << endl;

  std::cout << " done \n";
  return 0;
}
