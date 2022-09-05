
// babak poursartip
// Sept 5, 2022

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // pre-order ===============================
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> out;
      
      stack<TreeNode*> myst;

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
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> out;
      
      stack<TreeNode*> myst;
      TreeNode *curr = root;

      while (curr != nullptr || !myst.empty())
      {
        while (curr != nullptr){
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
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> out;
      
      if (!root) return out;

      stack<TreeNode*> myst;
      myst.push(root);
      TreeNode *prev = nullptr;

      while (!myst.empty())
      {
        TreeNode *current = myst.top();
        /* go down the tree in search of a leaf an if so
           process it and pop stack otherwise move down */
        if (prev == nullptr || prev->left == current || prev->right == current) {
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
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // ex1
  // TreeNode *root = nullptr;

  // ex2
  // TreeNode *root = new TreeNode{1};
  
  // ex3
  ///*
  TreeNode *root = new TreeNode{1};
  root->left  = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left  = new TreeNode(4);
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

  cout << " pre-order \n";
  vector<int> out = t.preorderTraversal(root);
  for_each(out.begin(), out.end(), [](auto x){cout << x << " ";});
  cout << endl;
 
  cout << " in-order \n";
  out = t.inorderTraversal(root);
  for_each(out.begin(), out.end(), [](auto x){cout << x << " ";});
  cout << endl; 
 
  cout << " post-order \n";
  out = t.postorderTraversal(root);
  for_each(out.begin(), out.end(), [](auto x){cout << x << " ";});
  cout << endl; 

  std::cout << " done \n";
  return 0;
}