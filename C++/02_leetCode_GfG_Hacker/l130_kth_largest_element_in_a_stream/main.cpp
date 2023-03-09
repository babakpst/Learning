
// babak poursartip
// Jan 03, 2023

#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct node
{
  int val, count;

  node *left, *right;

  node() : val(0), count(0), right(nullptr), left(nullptr){};
  node(int val, int count) : val(val), count(count), right(nullptr), left(nullptr){};
};

class KthLargest
{
 public:
  int k;
  node* root = nullptr;

  node* insertNewNode(node* root, int val)
  {
    cout << " insert ... \n";

    // if nums is not empty
    if (!root) return new node(val, 1);

    if (val > root->val)
    {
      cout << " greater ... \n";
      root->right = insertNewNode(root->right, val);
    }
    else  //  if (*it <= tmp->val)
    {
      cout << " smaller ... \n";
      root->left = insertNewNode(root->left, val);
    }
    root->count++;
    return root;
  }

  int search(node* root, int k)
  {
    int m = root->right ? (root->right)->count : 0;
    // root is the m+1 largest node in the BST
    if (k == m + 1)
    {
      return root->val;
    }
    if (k <= m)
    {
      // find kth largest in the right subtree
      return search(root->right, k);
    }
    else
    {
      // find (k-m-1)th largest in the left subtree
      return search(root->left, k - m - 1);
    }
  }

  KthLargest(int k, vector<int>& nums) : k(k), root(nullptr)
  {
    cout << " creating the BST ... \n";
    // if nums is empty

    for (auto it = begin(nums); it != end(nums); it++) root = insertNewNode(root, *it);
  }

  int add(int val)
  {
    root = insertNewNode(root, val);
    return search(root, k);
  }

  // BFS
  void printBST_DFS()
  {
    cout << " printing DFS ... \n";
    if (!root) return;
    stack<node*> myst;
    node* tmp = root;
    while (tmp || !myst.empty())
    {
      while (tmp)
      {
        myst.push(tmp);
        tmp = tmp->left;
      }
      tmp = myst.top();
      myst.pop();
      cout << "(" << tmp->val << "," << tmp->count << ") ";
      tmp = tmp->right;
    }
    cout << endl;
  }

  void printBST_BFS()
  {
    cout << " printing BFS ... \n";
    if (!root) return;

    queue<node*> myq;
    myq.push(root);

    while (!myq.empty())
    {
      cout << " while \n";
      node* tmp = myq.front();
      myq.pop();
      cout << "(" << tmp->val << "," << tmp->count << ") ";

      if (tmp->left) myq.push(tmp->left);
      if (tmp->right) myq.push(tmp->right);
    }
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  vector<int> nums{4, 5, 8, 2};
  int k = 3;

  KthLargest* obj = new KthLargest(k, nums);

  obj->printBST_BFS();

  cout << " answer: " << obj->add(3) << endl;
  cout << " answer: " << obj->add(5) << endl;
  cout << " answer: " << obj->add(10) << endl;
  cout << " answer: " << obj->add(9) << endl;
  cout << " answer: " << obj->add(4) << endl;

  std::cout << " done \n";
  return 0;
}
