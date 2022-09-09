
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <vector>
#include <algorithm>

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

    bool univalue(TreeNode* root, int& count)
    {
      if (!root) return false;
      // cout << root->val << " " << count << endl;
      bool t1 = univalue(root->left, count);
      bool t2 = univalue(root->right, count);
      
      if (!root->left && !root->right) return ++count;
      if (root->left && root->right) {
        if (root->val == root->left->val && root->val == root->right->val && t1 && t2) return ++count;}
      else if ( root->left && root->val == root->left->val   && t1 ) return ++count;
      else if ( root->right && root->val == root->right->val && t2 ) return ++count;
      return false;
    }

    int countUnivalSubtrees(TreeNode* root) {
      int count = 0;
      univalue(root, count);
      return count;
    }
};


int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // ex1
  //TreeNode *root = nullptr;

  // ex2
  // TreeNode *root = new TreeNode{10};
  
  // ex3
  ///*
  TreeNode *root = new TreeNode{5};
  root->left  = new TreeNode(5);
  root->left->left  = new TreeNode(5);
  root->left->right = new TreeNode(5);
  
  root->right = new TreeNode(5);
  root->right->right = new TreeNode(5);
  //*/

  // ex4
  /*
  TreeNode *root = new TreeNode{5};
  
  root->left  = new TreeNode(4);
  root->left->left  = new TreeNode(11);
  root->left->left->left  = new TreeNode(7);
  root->left->left->right  = new TreeNode(2);
  
  root->right = new TreeNode(8);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(1);
  */
  
  // ex5
  /*
  TreeNode *root = new TreeNode{5};
  
  root->left  = new TreeNode(1);
  root->left->left  = new TreeNode(5);
  root->left->right = new TreeNode(5);
  
  root->right = new TreeNode(5);
  root->right->right = new TreeNode(5);
  int targetSum = 22;
  */

 
  Solution t;

  int out = t.countUnivalSubtrees(root);
  
  cout << " answer: " << out << endl;
  std::cout << " done \n";
  return 0;
}