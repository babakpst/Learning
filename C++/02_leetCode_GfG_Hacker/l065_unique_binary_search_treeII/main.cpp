
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//  * Definition for a binary tree node.
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

    void BST(TreeNode* root, int n)
    {
      if (n==0) return nullptr;
      TreeNode *tmp = new TreeNode(n);
      n--;
      BST(roo)
    }


    vector<TreeNode*> generateTrees(int n) {
      vector<TreeNode*> out;
      out.push_back();
      return out;
    }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";
 
  Solution t;

  vector<TreeNode*> out = t.generateTrees(atoi(argv[1]));

  cout << " answer: "<< endl;
  for_each(out.begin(), out.end(), [](auto x){cout << x << " ";});
  cout << endl;

  std::cout << " done \n";
  return 0;
}