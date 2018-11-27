


// Binary search tree
// Babak Poursartip


#include <iostream>
#include <queue>


// defining the key in BST
struct node{
  public:
  int key;
  node *left, *right; // modify without class

  // Constructor
  //node();
  //node(int key):key{key}{
  //  left = right = NULL;
  //}
};

//=================================================================================================
//=================================================================================================
//=================================================================================================
// function: Level-ordered
void PrintLevelOrdered(node* tree) {

  // Base case
  if (tree == NULL) return;

  // Creating an empty queue
  std::queue<node*>  myQ;

// Enqueueuing root and initialize the height
  myQ.push(tree);

  while(!myQ.empty()){

    // Indicating total number of nodes at the current level
    int queueSize = myQ.size();
    
    //  Dequeuing all nodes of the current level and Enqueuing all nodes of the next level
    while (queueSize > 0){
      node* frontNode = myQ.front();
      std::cout << "level-order: " << frontNode->key << std::endl;
      myQ.pop();
      if (frontNode->left  != NULL) myQ.push(frontNode->left);
      if (frontNode->right != NULL) myQ.push(frontNode->right);
      queueSize--;
    }

  }
}

//=================================================================================================
// function: Pre-ordered:  Root-Left-Right
void PrintPreOrdered(node* tree){

  if (tree==NULL) return;

  std::cout << " pre-order:" << tree->key << std::endl;

  PrintPreOrdered(tree->left);
  PrintPreOrdered(tree->right);

}

//=================================================================================================
// function: In-ordered: Left-Root-Right

void PrintInOrdered(node* tree) {

  if (tree==NULL) return;

  PrintInOrdered(tree->left);
  
  std::cout << " In-order:" << tree->key << std::endl;

  PrintInOrdered(tree->right);

}


//=================================================================================================
// function: Post-ordered: Left-Right-Root
void PrintPostOrdered(node* tree){

  if (tree == NULL) return;

  PrintPostOrdered(tree->left);
  PrintPostOrdered(tree->right);
  std::cout << " Post-order:" << tree->key << std::endl;
}
//=================================================================================================
//=================================================================================================
//=================================================================================================


// creating a new node
node* GetNewNode(int key){
  node* NewNode = new node();
  NewNode->key   = key;
  NewNode->left  = NULL;
  NewNode->right = NULL;
  return NewNode;
}


node* insert(node* root, int key){  // address of the root node to be inserted - the key to be inserted
  if (root == NULL) {
    root = GetNewNode(key);    // empty tree
  } else if (key < root->key){
    root->left =insert(root->left, key);
  } else if (key > root->key){
    root->right =insert(root->right, key);
  }

  return root;
}


bool search(node* root, int key){
  if (root == NULL) return false;
  else if (root->key == key) return true;
  else if (root->key < key) return search(root->right, key);
  else    return search(root->left,  key);
}


int main(){

// creating a binary search tree
node* root; // address of the root node
root = NULL;  // initialize the tree -  setting the tree as empty




// the idea of insert: first we create a new node in dynamic memory
std::cout << " Creating the binary search tree ... " << std::endl;
root = insert(root, 15);
root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 25);
root = insert(root, 8 );
root = insert(root, 12);
root = insert(root, 19);
std::cout << " Done inserting " << std::endl;

std::cout << " Level-ordered : " << "\n";
PrintLevelOrdered(root);

std::cout << " Pre-ordered : " << "\n";
PrintPreOrdered(root);

std::cout << " In-ordered : " << "\n";
PrintInOrdered(root);

std::cout << " Post-ordered : " << "\n";
PrintPostOrdered(root);

//  ==================
// search
int numberToBeSearched;
std::cout << " Enter a number ... " << std::endl;
std::cin >> numberToBeSearched;
std::cout << " the entered is in the tree?  " << search(root, numberToBeSearched) << std::endl;
if ( search(root, numberToBeSearched) == true ) std::cout << " Number is in the tree! " << std::endl;
else std::cout << " Number is not in the tree! " << std::endl;

return 0;
}