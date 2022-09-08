
// babak poursartip
// Aug 28, 2022

#include <ios>
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

using mypair =pair<TreeNode*,int>;
class Solution0 {
public:
  bool isSymmetric(TreeNode* root) {
    vector<vector<int>> out;

    // level order search
    queue<mypair> qq;

    qq.push(make_pair(root,1));
    while (!qq.empty()) 
    {
      mypair temp = qq.front();
      qq.pop();

      if (temp.first) qq.push(make_pair(temp.first->left, temp.second+1));
      if (temp.first) qq.push(make_pair(temp.first->right,temp.second+1));
      if (out.size() != temp.second ) out.push_back({});
      out[temp.second-1].push_back(temp.first==nullptr?-110:temp.first->val);
    }

    /*
    auto lm0 = [](auto y){cout << y << " ";};
    auto lm = [&](auto x)
    {
      for_each(x.begin(),x.end(),lm0);
      cout << endl;
    };
    for_each(out.begin(), out.end(), lm);
    cout << endl;
    */

    for(auto it1 = out.begin()+1; it1 !=out.end(); it1++)
    {
      int size = (*it1).size();
      for(int it2 = 0; it2 <size/2; it2++)
        if ((*it1)[it2] != (*it1)[ size-1-it2]  )
          return false;
    }

    return true;
  }
};

// sol iterative
class Solution1 {
public:
  bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> qq;
    qq.push(root);
    qq.push(root);
    while(!qq.empty())
    {
      TreeNode *temp1 = qq.front();
      qq.pop();
      TreeNode *temp2 = qq.front();
      qq.pop();

      if (!temp1 && !temp2) continue;;
      if ((temp1 && !temp2) || (!temp1 && temp2) || (temp1->val != temp2->val) ) return false;
      qq.push(temp1->left);
      qq.push(temp2->right);
      qq.push(temp1->right);
      qq.push(temp2->left);
    }
    return true;
  }
};


// recursive
class Solution {
public:
  
  bool mirror(TreeNode *left, TreeNode *right)
  {
    if (!left && !right) return true;
    if (!left || !right ) return false;
    return (left->val == right->val) && mirror(left->left, right->right) && mirror(left->right, right->left);
  }
  
  bool isSymmetric(TreeNode* root) {
    return mirror(root->left, root->right);

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
  /*
  TreeNode *root = new TreeNode{1};
  root->left  = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left  = new TreeNode(4);
  root->left->right = new TreeNode(5);
  */

  // ex6
  ///*
  TreeNode *root = new TreeNode{1};
  root->left  = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left  = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);
  //*/

 
  Solution t;

  bool out = t.isSymmetric(root);
  cout << " answer: " << boolalpha << out << endl;

  std::cout << " done \n";
  return 0;
}