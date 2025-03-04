

// babak poursartip
// Dec 03, 2022

#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// EXEC TIME EXCEEDS

//  Definition for a binary tree node.
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
 public:
  bool duplicateTree(TreeNode* t1, TreeNode* t2)
  {
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;

    if (t1->val != t2->val)
      return false;
    else
    {
      st1.push(t1);
      st2.push(t2);
    }

    while (!st1.empty())
    {
      auto n1 = st1.top();
      auto n2 = st2.top();
      st1.pop();
      st2.pop();

      if ((n1 && !n2) || (!n1 && n2))
        return false;
      else if (n1 && n2)
      {
        if (n1->val != n2->val)
          return false;
        else
        {
          st1.push(n1->left);
          st1.push(n1->right);
          st2.push(n2->left);
          st2.push(n2->right);
        }
      }
    }
    return true;
  }

  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
  {
    vector<TreeNode*> out;
    if (!root) return out;
    unordered_map<int, list<TreeNode*>> mys;
    // unordered_set<TreeNode*> mys;

    stack<TreeNode*> st;

    if (root->left) st.push(root->left);
    if (root->right) st.push(root->right);

    while (!st.empty())
    {
      // cout << " checkpoint 0\n";

      auto tmp = st.top();
      st.pop();

      auto it = mys.find(tmp->val);
      // cout << " checking: " << tmp->val << endl;
      if (it != end(mys))
      {
        // cout << " found sth \n";
        bool found = true;
        // cout << " size of the list is: " << it->second.size() << endl;
        for (auto itr = begin(it->second); itr != end(it->second); itr++)
        {
          // cout << " in the for loop " << (*itr)->val << endl;
          if (duplicateTree(tmp, *itr))
          {
            // cout << " it is a duplicate\n";
            if (find(begin(out), end(out), *itr) == end(out)) out.push_back(*itr);
            found = false;
            break;
          }
        }
        if (found)
        {
          // cout << " pushing \n";
          mys[tmp->val].push_back(tmp);
        }
      }
      else
      {
        // cout << " checkpoint 2\n";
        list<TreeNode*> tmpList;
        tmpList.push_back(tmp);
        mys.insert({tmp->val, tmpList});
      }
      if (tmp->left) st.push(tmp->left);
      if (tmp->right) st.push(tmp->right);
    }

    return out;
  }
};

void printTree(TreeNode* x)
{
  stack<TreeNode*> pr;
  pr.push(x);
  while (!pr.empty())
  {
    auto tmp = pr.top();
    pr.pop();

    cout << tmp->val << " ";
    if (tmp->left) pr.push(tmp->left);
    if (tmp->right) pr.push(tmp->right);
  }
  cout << endl;
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);

  root->right = new TreeNode(3);
  root->right->left = new TreeNode(2);
  root->right->left->left = new TreeNode(4);
  root->right->right = new TreeNode(4);

  /*
  TreeNode * root =  new TreeNode(0);
  root->left = new TreeNode(0);
  root->left->left = new TreeNode(0);
  root->right = new TreeNode(0);
  root->right->right = new TreeNode(0);
  root->right->right->right = new TreeNode(0);
  */

  printTree(root);

  Solution t;

  vector<TreeNode*> out = t.findDuplicateSubtrees(root);
  cout << " Tree: " << endl;
  for_each(out.begin(), out.end(), [](auto x) { printTree(x); });
  cout << endl;

  std::cout << " done \n";
  return 0;
}
