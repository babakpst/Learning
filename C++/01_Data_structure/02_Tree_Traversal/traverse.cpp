

// Tree Traversal
// Babak Poursartip

// Comments
/*
This is code is based on the following youtube clip:
https://www.youtube.com/watch?v=IpyCqRmaKW4


    1
   /\
  2 3
 /\  \
4 5  6 

All possible cases are discussed:
1- Level-order:   1 2 3 4 5 6
2- Pre-ordered:   Root-Left-Right  1 2 4 5 3 6 
3- In-ordered:    Left-Root-Right 4 2 5  1 3 6
4- Post-ordered:  Left-Right-Root  4 5 2 6 3 1

*/

#include <iostream>

#include <queue>

//=================================================================================================
// defining the node of the tree

struct Node {
  int data;
  Node *left, *right; // modify remove struct

  // Constructor
  Node(int data) : data{data} { left = right = NULL; }
};

//=================================================================================================
// function: Level-ordered  BFS
void PrintLevelOrdered(struct Node *tree) {

  // Base case
  if (tree == NULL)
    return;

  // Creating an empty queue
  std::queue<Node *> myQ;

  // Enqueueuing root and initialize the height
  myQ.push(tree);

  while (!myQ.empty()) {

    // Indicating total number of nodes at the current level
    int queueSize = myQ.size();

    //  Dequeuing all nodes of the current level and Enqueuing all nodes of the
    //  next level
    while (queueSize > 0) {
      Node *frontNode = myQ.front();
      std::cout << "level-order: " << frontNode->data << std::endl;
      myQ.pop();

      if (frontNode->left != NULL)
        myQ.push(frontNode->left);
      if (frontNode->right != NULL)
        myQ.push(frontNode->right);
      queueSize--;
    }
  }
}

//=================================================================================================
// function: Pre-ordered:  Root-Left-Right
void PrintPreOrdered(struct Node *tree) {

  if (tree == NULL)
    return;

  std::cout << " pre-order:" << tree->data << std::endl;

  PrintPreOrdered(tree->left);
  PrintPreOrdered(tree->right);
}

//=================================================================================================
// function: In-ordered: Left-Root-Right

void PrintInOrdered(struct Node *tree) {

  if (tree == NULL)
    return;

  PrintInOrdered(tree->left);

  std::cout << " In-order:" << tree->data << std::endl;

  PrintInOrdered(tree->right);
}

//=================================================================================================
// function: Post-ordered: Left-Right-Root
void PrintPostOrdered(struct Node *tree) {

  if (tree == NULL)
    return;

  PrintPostOrdered(tree->left);
  PrintPostOrdered(tree->right);
  std::cout << " Post-order:" << tree->data << std::endl;
}

//=================================================================================================
// main code
int main() {

  // Creating a tree linked-list
  struct Node *root = new Node(1); // modify remove struct
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(6);

  std::cout << " Level-ordered : "
            << "\n";
  PrintLevelOrdered(root);

  std::cout << " Pre-ordered : "
            << "\n";
  PrintPreOrdered(root);

  std::cout << " In-ordered : "
            << "\n";
  PrintInOrdered(root);

  std::cout << " Post-ordered : "
            << "\n";
  PrintPostOrdered(root);

  return 0;
}
