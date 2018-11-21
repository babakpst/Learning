

// Tree Traversal
// Babak Poursartip

// Comments
/*
This is code is based on the following youtube clip: https://www.youtube.com/watch?v=IpyCqRmaKW4
All possible cases are discusses:
1- Level-order:   
2- Pre-ordered:   Root-Left-Right
3- In-ordered:    Left-Root-Right
4- Post-ordered:  Left-Right-Root
*/

#include <iostream>

//=================================================================================================
// defining the node of the tree

struct Node{
  int data;
  struct Node* left, * right;   // modify remove struct

  // Constructor
  Node(int data):data{data}{
    left = right = NULL;
  }
};

//=================================================================================================
// function: Level-ordered
void PrintLevelOrdered(struct Node* tree) {
  if (tree == NULL) return;

  std::cout << " Level-order:" << tree->data << std::endl;
  PrintLevelOrdered()


}

//=================================================================================================
// function: Pre-ordered:  Root-Left-Right
void PrintPreOrdered(struct Node* tree){

  if (tree==NULL) return;

  std::cout << " pre-order:" << tree->data << std::endl;

  PrintPreOrdered(tree->left);
  PrintPreOrdered(tree->right);

}

//=================================================================================================
// function: In-ordered: Left-Root-Right

void PrintInOrdered(struct Node* tree) {

  if (tree==NULL) return;

  PrintInOrdered(tree->left);
  
  std::cout << " In-order:" << tree->data << std::endl;

  PrintInOrdered(tree->right);

}


//=================================================================================================
// function: Post-ordered: Left-Right-Root
void PrintPostOrdered(struct Node* tree){

  if (tree == NULL) return;

  PrintPostOrdered(tree->left);
  PrintPostOrdered(tree->right);
  std::cout << " Post-order:" << tree->data << std::endl;
}



//=================================================================================================
// main code
int main (){

// Creating a tree linked-list
struct Node* root = new Node(1);    // modify remove struct
root->left        = new Node(2);
root->right       = new Node(3);
root->left->left  = new Node(4);
root->left->right = new Node(5);


std::cout << " Level-ordered : " << "\n";
PrintLevelOrdered(root);

std::cout << " Pre-ordered : " << "\n";
PrintPreOrdered(root);


std::cout << " In-ordered : " << "\n";
PrintInOrdered(root);

std::cout << " Post-ordered : " << "\n";
PrintPostOrdered(root);

 return 0; 
}