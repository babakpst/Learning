
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
1- BFS Level-order:   1 2 3 4 5 6
2- DFS Pre-ordered:   Root-Left-Right  1 2 4 5 3 6 
3- DFS In-ordered:    Left-Root-Right 4 2 5  1 3 6
4- DFS Post-ordered:  Left-Right-Root  4 5 2 6 3 1

*/

#include <iostream>

#include <queue>


//Definition for a binary tree node.
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
    // pre-order ===============================
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> out;
      
      stack<TreeNode*> myst;

      if (root) myst.push(root);
      while (!myst.empty())
      {
        TreeNode *temp = myst.top();
        // cout << " here: " << temp->val << endl;
        myst.pop();
        if (temp->right) myst.push(temp->right);
        if (temp->left) myst.push(temp->left);
        out.push_back(temp->val);
      }
      
      return out;
    }
    // in-order ===============================
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> out;
      
      stack<TreeNode*> myst;
      TreeNode *curr = root;

      while (curr != nullptr || !myst.empty())
      {
        while (curr != nullptr){
          myst.push(curr);
          curr = curr->left;
        }
        curr = myst.top();
        myst.pop();
        out.push_back(curr->val);
        curr = curr->right;
      }
      return out;
    }
    // post-order ===============================
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> out;
      
      if (!root) return out;

      stack<TreeNode*> myst;
      myst.push(root);
      TreeNode *prev = nullptr;

      while (!myst.empty())
      {
        TreeNode *current = myst.top();
        /* go down the tree in search of a leaf an if so
           process it and pop stack otherwise move down */
        if (prev == nullptr || prev->left == current || prev->right == current) {
            if (current->left)
              myst.push(current->left);
            else if (current->right)
              myst.push(current->right);
            else 
            {
              myst.pop();
              out.push_back(current->val);
            }
            /* go up the tree from left node, if the child
               is right push it onto stack otherwise process
               parent and pop stack */
        } 
        else if (current->left == prev) 
        {
            if (current->right)
                myst.push(current->right);
            else 
            {
              myst.pop();
              out.push_back(current->val);
            }
 
            /* go up the tree from right node and after
            coming back from right node process parent and
            pop stack */
        }
        else if (current->right == prev) 
        {
            myst.pop();
            out.push_back(current->val);
        }
        prev = current;
      }
      return out;   
    }
};




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

// recursive ===============================================================================================
// function: DFS Pre-ordered:  Root-Left-Right
void PrintPreOrdered(struct Node *tree) {

  if (tree == NULL)
    return;

  std::cout << " pre-order:" << tree->data << std::endl;

  PrintPreOrdered(tree->left);
  PrintPreOrdered(tree->right);
}

// function: DFS In-ordered: Left-Root-Right

void PrintInOrdered(struct Node *tree) {

  if (tree == NULL)
    return;

  PrintInOrdered(tree->left);

  std::cout << " In-order:" << tree->data << std::endl;

  PrintInOrdered(tree->right);
}

// function: DFS Post-ordered: Left-Right-Root
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

  std::cout << " Level-ordered : "  << "\n";
  PrintLevelOrdered(root);

  std::cout << " Pre-ordered : "  << "\n";
  PrintPreOrdered(root);

  std::cout << " In-ordered : "  << "\n";
  PrintInOrdered(root);

  std::cout << " Post-ordered : "  << "\n";
  PrintPostOrdered(root);

  return 0;
}
