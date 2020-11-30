
/*
Babak Poursartip
11/29/2020

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
no duplicates in the tree.

For example, given



preorder = [3,9,20,15,7]  Root-Left-Right
inorder = [9,3,15,20,7]  Left-Root-Right

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7


Method from GfG:
Let us consider the below traversals:

Inorder sequence: D B E A F C
Preorder sequence: A B D E C F

In a Preorder sequence, leftmost element is the root of the tree. So we know ‘A’
is root for given sequences. By searching ‘A’ in Inorder sequence, we can find
out all elements on left side of ‘A’ are in left subtree and elements on right
are in right subtree. So we know below structure now.

                 A
               /   \
             /       \
           D B E     F C
We recursively follow above steps and get the following tree.

         A
       /   \
     /       \
    B         C
   / \        /
 /     \    /
D       E  F

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
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {

    if (inorder.size() == 0)
      return nullptr;
    return Tree(preorder, inorder, begin(inorder), end(inorder) - 1);
  }

  TreeNode *Tree(std::vector<int> &preorder, std::vector<int> &inorder,
                 std::vector<int>::iterator start,
                 std::vector<int>::iterator end) {

    // Base case
    if (start > end)
      return NULL;

    static int preIndex = 0;

    // Pick current node from Preorder traversal using preIndex and increment
    // preIndex
    TreeNode *node(new TreeNode(preorder[preIndex++]));
    // std::cout << preIndex << " " << node->val << std::endl;
    // If this node has no children then return
    if (start == end)
      return node;

    // Else find the index of this node in Inorder traversal
    auto inIndex = find(start, end, node->val);

    // Using index in Inorder traversal, construct left and right subtress
    node->left = Tree(preorder, inorder, start, inIndex - 1);
    node->right = Tree(preorder, inorder, inIndex + 1, end);

    return node;
  }

  void PrintPreOrdered(TreeNode *&tr) {

    if (tr == NULL) {
      std::cout << " null ";
      return;
    }

    std::cout << " " << tr->val;
    PrintPreOrdered(tr->left);
    PrintPreOrdered(tr->right);
  }

  void PrintInOrdered(TreeNode *&tr) {

    if (tr == NULL) {
      std::cout << " null ";
      return;
    }
    PrintInOrdered(tr->left);
    std::cout << " " << tr->val;
    PrintInOrdered(tr->right);
  }
};

int main() {
  std::cout << " now starts ...\n";

  // std::vector<int> preorder{3, 9, 20, 15, 7};
  // std::vector<int> inorder{9, 3, 15, 20, 7};

  // std::vector<int> inorder{4, 2, 5, 1, 6, 3};
  // std::vector<int> preorder{1, 2, 4, 5, 3, 6};

  std::vector<int> preorder{-1};
  std::vector<int> inorder{-1};

  // std::vector<int> preorder{};
  // std::vector<int> inorder{};

  Solution obj;
  TreeNode *tr = obj.buildTree(preorder, inorder);
  std::cout << std::endl;

  std::cout << "pre-order:";
  obj.PrintPreOrdered(tr);
  std::cout << std::endl;

  std::cout << "in-order:";
  obj.PrintInOrdered(tr);
  std::cout << std::endl;
  std::cout << " finished\n";
  return 0;
}
