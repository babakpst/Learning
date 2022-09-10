
/*
Babak Poursartip
11/22/2020

updated on Sept 9, 2022

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder   = [9,3,15,20,7]: Left-Root-Right
postorder = [9,15,7,20,3]: Left-Right-Root
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

#include <algorithm>
#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

using namespace std;

class Solution0 {
public:
  TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {

    int ind = inorder.size() - 1;
    if (ind == -1)
      return nullptr;
    return Tree(inorder, postorder, inorder.begin(), inorder.end() - 1, &ind);
  }

  TreeNode *Tree(std::vector<int> &inorder, std::vector<int> &postorder,
                 std::vector<int>::iterator start,
                 std::vector<int>::iterator end, int *pIndex) {

    // Base case
    if (start > end)
      return NULL;

    // Pick current node from Postorder traversal using postIndex and decrement
    // postIndex
    TreeNode *node(new TreeNode(postorder[*pIndex]));
    (*pIndex)--;

    // If this node has no children then return
    if (start == end)
      return node;

    // Else find the index of this node in Inorder traversal
    auto iIndex = find(start, end, node->val);

    // Using index in Inorder traversal, construct left and right subtress
    node->right = Tree(inorder, postorder, iIndex + 1, end, pIndex);
    node->left = Tree(inorder, postorder, start, iIndex - 1, pIndex);

    return node;
  }

  void PrintPreOrdered(TreeNode *&tr) {

    if (tr == NULL)
      return;

    std::cout << " pre-order:" << tr->val << std::endl;

    PrintPreOrdered(tr->left);
    PrintPreOrdered(tr->right);
  }
};


class Solution {
public:

  using tp = vector<int>::iterator;
  TreeNode *root;
  TreeNode *tmp;
  int branch = 0;  // 0 root, 1 right, left 2
  tp rightInd;
  tp poLast;
  void myTree(tp inIt1, tp inIt2, tp poIt1, tp poIt2)
  {
    cout << " before if " << boolalpha << (inIt1 == inIt2)  << " " << *inIt1 << " " << *inIt2 << endl;;
    // base case
    if (inIt1 == inIt2){ return;}
    cout << " after if \n";
    cout << "inorder: ";
    for_each(inIt1, inIt2, [](auto x){cout << x << " ";}); 
    cout << endl;
    cout << "postorder: ";
    for_each(poIt1, poIt2, [](auto x){cout << x << " ";}); 
    cout << endl;
    
    poLast--;
    cout << " root: " << *poLast << endl;
    cout << endl;
    
    if (inIt1 != inIt2) {
      tmp = tmp->right;
    }
    else {
      tmp = tmp->left;
    }


    tmp = new TreeNode(*poLast);
    if (!branch)
    {
      root = tmp;
      branch++;
    }
    
    // working on the right
    rightInd = find(inIt1, inIt2, *poLast);

    PrintPreOrdered(root);
    cout << " rootInd right: " << *rightInd << endl;
    myTree( rightInd+1, inIt2, poIt1, poLast);
    cout << " ========working on the left \n";
    cout << " rootInd left: " << *inIt1<< " " <<*rightInd << " " << *poIt1 << " " << *poIt2 << endl;
    myTree(inIt1, rightInd, poIt1, poLast);
  
  }

  //============
  TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
    poLast = postorder.end();
    myTree(inorder.begin(), inorder.end(), postorder.begin(), poLast);
    return root;
  }

  //============
  void PrintPreOrdered(TreeNode *&tr) {
    if (tr == NULL) return;
    std::cout << " pre-order:" << tr->val << std::endl;
    PrintPreOrdered(tr->left);
    PrintPreOrdered(tr->right);
  }
};

int main() {
  std::cout << " starts ...\n";

  // ex1
  std::vector<int> inorder{9, 3, 15, 20, 7};
  std::vector<int> postorder{9, 15, 7, 20, 3};

  // ex2
  // std::vector<int> inorder{4, 8, 2, 5, 1, 6, 3, 7};
  // std::vector<int> postorder{8, 4, 5, 2, 6, 7, 3, 1};

  // ex3
  // std::vector<int> inorder{};
  // std::vector<int> postorder{};

  // ex4
  // std::vector<int> inorder{-1};
  // std::vector<int> postorder{-1};

  Solution obj;
  TreeNode *tr = obj.buildTree(inorder, postorder);
  obj.PrintPreOrdered(tr);

  std::cout << " finished\n";
  return 0;
}