
// babak poursartip
// Sept 5, 2022

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
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

// =========================================
class Solution1
{
 public:
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    queue<TreeNode *> myq;
    vector<vector<int>> out;

    int layer = 0;
    int countNodeInEachLevel = 0;
    bool cont = true;

    myq.push(root);
    while (cont)
    {
      TreeNode *cur = myq.front();
      myq.pop();
      countNodeInEachLevel++;

      cout << " checkpoint 1 " << countNodeInEachLevel << " " << (1 << layer) << endl;

      if (countNodeInEachLevel > (1 << layer))
      {
        layer++;
        countNodeInEachLevel = 1;
        if (out.size() != layer) cont = false;
      }

      cout << " checkpoint 2\n";

      if (cur)
      {
        if (out.empty() || out.size() <= layer)
          out.push_back(vector<int>{cur->val});
        else
          out[layer].push_back(cur->val);
      }

      cout << " checkpoint 3\n";

      if (cur)
      {
        myq.push(cur->left);
        myq.push(cur->right);
      }
      else
      {
        myq.push(nullptr);
        myq.push(nullptr);
      }

      cout << layer << " " << countNodeInEachLevel << " " << ((cur) ? cur->val : -9999) << endl;
      // cout << ((cur)?cur->val:"null") << endl;

      cout << " leaving the while\n";
    }
    return out;
  }
};
// =========================================

using myp = pair<TreeNode *, int>;
class Solution
{
 public:
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> out;
    queue<myp> myqq;

    if (root) myqq.push(make_pair(root, 0));
    while (!myqq.empty())
    {
      myp temp = myqq.front();
      myqq.pop();
      if (temp.first->left) myqq.push(make_pair(temp.first->left, temp.second + 1));
      if (temp.first->right) myqq.push(make_pair(temp.first->right, temp.second + 1));
      if (out.empty() || out.size() <= temp.second) out.push_back({});
      out[temp.second].push_back(temp.first->val);
    }
    return out;
  }
};

int main(int argc, char *argv[])
{
  std::cout << " starts ... \n";

  // ex1
  // TreeNode *root = nullptr;

  // ex2
  // TreeNode *root = new TreeNode{1};

  // ex3
  ///*
  TreeNode *root = new TreeNode{1};
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  //*/

  // ex4
  /*
  TreeNode *root = new TreeNode{1};
  root->left  = new TreeNode(4);
  root->right = new TreeNode(3);
  root->left->left  = new TreeNode(2);
  */

  Solution t;

  cout << " level-order \n";
  vector<vector<int>> out = t.levelOrder(root);

  cout << " answer: " << endl;

  auto lm0 = [](auto y) { cout << y << " "; };

  auto lm = [&](auto x) {
    for_each(x.begin(), x.end(), lm0);
    cout << "\n";
  };

  for_each(out.begin(), out.end(), lm);
  cout << endl;

  std::cout << " done \n";
  return 0;
}
