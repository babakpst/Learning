


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


//=================================================================================================
// Find the min of a tree iterative solution- going the left
 int FindMin(node* root){
   if (root == NULL){
     std::cout << " Tree is empty! " << std::endl;
     return -1;
    }
   while (root->left != NULL){
     root = root->left;
   };
   return root->key;
 }

// Find the min of a tree recursive solution-
int FindMinR(node* root){
  if (root == NULL){
    std::cout << " The tree in empty! " << std::endl;
  }else if (root->left == NULL) {
    return root->key;
  }
  return FindMinR(root->left);
}


//=================================================================================================
// Find the max of a tree iterative solution- going the right
 int FindMax(node* root){
   if (root == NULL){
     std::cout << " Tree is empty! " << std::endl;
     return -1;
    }
   while (root->right != NULL){
     root = root->right;
   };
   return root->key;
 }


//=================================================================================================
// Find height
int FindHeight(node* root){
  if (root == NULL) return -1; // should not be 0 bcs we call left and right.  // base
                               // if height is number of nodes, change it to 0;
  int leftHeight = FindHeight(root->left);
  int rightHeight = FindHeight(root->right);
  return std::max(leftHeight, rightHeight)+1;
}


//=================================================================================================
// Check if a tree is a binary search tree
bool IsSubtreeLesser(node* root, int Value){
  if (root == NULL) return true;
  if (root->key <= Value
     && IsSubtreeLesser(root->left, Value)
     && IsSubtreeLesser(root->right, Value)    ) return true;
  else return false;
}

bool IsSubtreeGreater(node* root, int Value){
  if (root == NULL) return true;
    if (root->key > Value
     && IsSubtreeGreater(root->left, Value)
     && IsSubtreeGreater(root->right, Value)    ) return true;
    else return false;
}


bool IsBinarySearchTree(node* root){

  // returen ture if BST, false if not

 if (root == NULL) return true;  // base case
 if  (   IsSubtreeLesser (root->left, root->key) 
      && IsSubtreeGreater(root->right, root->key)
      && IsBinarySearchTree(root->left)
      && IsBinarySearchTree(root->right)
       ) return true;
  else return false;

}


//=================================================================================================
// delete a node
// Find the min of a tree iterative solution- going the left
 node* FindMinNode(node* root){
   if (root == NULL){
     std::cout << " Tree is empty! " << std::endl;
     return NULL;
    }
   while (root->left != NULL){
     root = root->left;
   };
   return root;
 }



node* Delete(node* root, int data){

  if (root == NULL) return root; // or return Null;
  else if (data < root->key) root->left = Delete(root->left, data);
  else if (data > root->key) root->right = Delete(root->right, data);
  else  // Wohoo, I found you, Get ready to be deleted.
  {
    // case 1: no child
    if (root->left == NULL && root->right == NULL){
      delete root; // remove from heap
      root = NULL; // root still has its address. 
    }
    // case 2: there is only one child 
    //else if (root->left == NULL || root->right == NULL )
    else if (root->left == NULL ){
      node* temp = root;
      root = root->right;
      delete temp;
    }
    // case 2: there is only one child 
    else if (root->right == NULL ){
      node* temp = root;
      root = root->left;
      delete temp;
    }
    // case 3: 2 children
    else
    {
      node* temp = FindMinNode(root->right); 
      root->key = temp->key;
      root->right = Delete(root->right, temp->key);
    }
  }
  return root;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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
root = insert(root, 5);
root = insert(root, 13);
root = insert(root, 14);

std::cout << " Done inserting " << std::endl;

std::cout << " Level-ordered : " << "\n";
PrintLevelOrdered(root);

std::cout << " Pre-ordered : " << "\n";
PrintPreOrdered(root);

std::cout << " In-ordered : " << "\n";
PrintInOrdered(root);

std::cout << " Post-ordered : " << "\n";
PrintPostOrdered(root);

//  ============================================================================== 
// search
int numberToBeSearched;
std::cout << " Enter a number ... " << std::endl;
std::cin >> numberToBeSearched;
std::cout << " the entered is in the tree?  " << search(root, numberToBeSearched) << std::endl;
if ( search(root, numberToBeSearched) == true ) std::cout << " Number is in the tree! " << std::endl;
else std::cout << " Number is not in the tree! " << std::endl;

// ================================================================================================
// min
std::cout << " The min in the tree iterative: " << FindMin(root) << std::endl;
std::cout << " The min in the tree recursive: " << FindMinR(root) << std::endl;

// max
std::cout << " The max in the tree: " << FindMax(root) << std::endl;

// ================================================================================================
// height
std::cout << " The height in the tree: " << FindHeight(root) << std::endl;

// ================================================================================================
// IsBinarySearchTree
std::cout << " The tree is a binary search tree? " << IsBinarySearchTree(root) << std::endl;

// ================================================================================================
// Delete a node from a binary search tree 
std::cout << " deleting a node .. " << std::endl;
Delete(root, 10);
std::cout << " Level-ordered : " << "\n";
PrintLevelOrdered(root);

return 0;
}
