/*

Given a binary tree (not a binary search tree) and two values say n1 and n2, write a program to find the least common
ancestor.

07/17/2021
*/

#include <iostream>

struct node
{
  int data;
  node* left;
  node* right;
};

node* newNode(int data)
{
  node* Node = new node;
  Node->data = data;
  Node->left = nullptr;
  Node->right = nullptr;
  return Node;
}

// =======================
node* findLCA0(node* root, int n1, int n2)
{
  // base case
  if (root == nullptr) return nullptr;
  std::cout << root->data << std::endl;

  if (root->data == n1 || root->data == n2) return root;
  node* left = findLCA0(root->left, n1, n2);
  node* right = findLCA0(root->right, n1, n2);
  if (left && right) return root;

  return (left ? left : right);
}

int main()
{
  node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);

  root->left->left = newNode(4);
  root->left->right = newNode(5);

  root->right->left = newNode(6);
  root->right->right = newNode(7);

  std::cout << "LCA(4,5)= " << findLCA0(root, 4, 5)->data << std::endl;

  return 0;
}
