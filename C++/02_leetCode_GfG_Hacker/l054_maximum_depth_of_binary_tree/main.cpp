
// babak poursartip
// Sept 06, 2022

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

using mypair = pair<TreeNode*,int>;
class Solution0 {
public:
    int maxDepth(TreeNode* root) {

      if (!root) return 0;
      int depth = 1;
      queue<mypair> qq;
      qq.push( make_pair(root,1));
      
      while(!qq.empty())
      {
        mypair temp = qq.front();
        qq.pop();

        if (temp.first->left) qq.push( make_pair(temp.first->left,  temp.second +1));
        if (temp.first->right) qq.push( make_pair(temp.first->right, temp.second+1));
        depth = max(depth,temp.second);
        cout << temp.first->val << " - " << temp.second << endl;
      }
      return depth;
    }
};

//top-down
class Solution {
public:
    int answer = 0;
    void findDepth(TreeNode *root, int depth)
    {
      // cout << " here " << depth << " ans: " << answer <<endl;
      if (!root)
        return;
      if ( !root->left && !root->right)
        answer = max(answer,depth);
      findDepth(root->left,  depth+1);
      findDepth(root->right, depth+1);
    }
    
    
    int maxDepth(TreeNode* root) {
      
      if (!root)
        return 1;

      int depth = 1;
      findDepth(root, depth);
      return answer;
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
  /*
  TreeNode *root = new TreeNode{1};
  root->left  = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left  = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  */

  // ex4
  /*
  TreeNode *root = new TreeNode{1};
  root->left  = new TreeNode(4);
  root->right = new TreeNode(3);
  root->left->left  = new TreeNode(2);
  */

  // ex5
  ///*
  TreeNode *root = new TreeNode{1};
  root->left  = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left  = new TreeNode(4);
  root->left->right = new TreeNode(5);
  //*/

 
  Solution t;

  int out = t.maxDepth(root);
  cout << " answer: " << out << endl;
  std::cout << " done \n";
  return 0;
}