
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

class Solution {
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

int main() {
  std::cout << " starts ...\n";

  // std::vector<int> inorder{9, 3, 15, 20, 7};
  // std::vector<int> postorder{9, 15, 7, 20, 3};

  // std::vector<int> inorder{4, 8, 2, 5, 1, 6, 3, 7};
  // std::vector<int> postorder{8, 4, 5, 2, 6, 7, 3, 1};

  std::vector<int> inorder{};
  std::vector<int> postorder{};

  Solution obj;
  TreeNode *tr = obj.buildTree(inorder, postorder);
  obj.PrintPreOrdered(tr);

  std::cout << " finished\n";
  return 0;
}