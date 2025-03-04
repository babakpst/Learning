
// babak poursartip

// Aug 22, 2022

#include <iostream>
#include <queue>

//*
// Definition for a Node.
class Node
{
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};
//*/

class Solution
{
 public:
  Node* connect(Node* root)
  {
    std::cout << " checkpoint inside solution " << std::endl;
    if (!root) return nullptr;
    Node* ret = root;
    std::queue<std::pair<Node*, int>> qq;
    qq.push(std::make_pair(root, 0));

    while (!qq.empty())
    {
      Node* cur = qq.front().first;
      int depth = qq.front().second;
      qq.pop();
      std::cout << " node: " << cur->val << " depth: " << depth << std::endl;
      if (cur->left)
      {
        qq.push(std::make_pair(cur->left, depth + 1));
        qq.push(std::make_pair(cur->right, depth + 1));
      }
      int next = !qq.empty() ? qq.front().second : -1;
      if (next == depth) cur->next = qq.front().first;
    }
    return ret;
  }
};

void printGraph(Node* root)
{
  std::cout << "\n new \n";
  if (!root)
  {
    std::cout << " nullptr \n";
    return;
  }
  std::queue<Node*> qq;
  qq.push(root);

  while (!qq.empty())
  {
    Node* cur = qq.front();
    qq.pop();
    if (cur->left)
    {
      qq.push(cur->left);
      qq.push(cur->right);
    }

    int next = cur->next ? cur->next->val : 0;
    int left = cur->left ? cur->left->val : 0;
    int right = cur->right ? cur->right->val : 0;
    std::cout << " node: " << cur->val << " left: " << left << " right: " << right << " next: " << next << std::endl;
  }
}

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // root = [1,2,3,4,5,6,7]
  Node* n7 = new Node(7);
  Node* n6 = new Node(6);
  Node* n5 = new Node(5);
  Node* n4 = new Node(4);
  Node* n3 = new Node(3, n6, n7, nullptr);
  Node* n2 = new Node(2, n4, n5, nullptr);
  Node* n1 = new Node(1, n2, n3, nullptr);

  Solution t;
  std::cout << " checkpoint test 0 \n";
  Node* out = t.connect(n1);
  printGraph(out);

  std::cout << " checkpoint test 1 \n";
  out = t.connect(nullptr);
  printGraph(out);

  std::cout << " checkpoint test 2 \n";
  Node* zero = new Node(0);
  out = t.connect(zero);
  printGraph(out);

  std::cout << " done. \n";
  return 0;
}
