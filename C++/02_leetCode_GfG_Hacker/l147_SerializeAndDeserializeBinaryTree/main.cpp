
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    string out = "";

    if (!root) return out;

    queue<TreeNode *> mq;  // level order

    mq.push(root);
    while (!mq.empty())
    {
      TreeNode *node = mq.front();
      mq.pop();

      if (node)
      {
        out += (to_string(node->val) + " ");
        mq.push(node->left);
        mq.push(node->right);
      }
      else
        out += "+ ";
    }
    return out;
  }

  TreeNode *nextNode(int &counter, string &data)
  {
    TreeNode *node = nullptr;
    int start = ++counter;
    while (data[counter] != ' ') counter++;

    string nodeval = data.substr(start, counter - start);

    // cout <<start<< " " << counter<<  " nodeval: " << nodeval << endl;
    if (nodeval != "+")
    {
      node = new TreeNode(stoi(nodeval));
    }
    return node;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    int len = data.size();
    TreeNode *root = nullptr;
    if (len == 0) return root;

    queue<TreeNode *> mq;

    int counter = -1;
    root = nextNode(counter, data);

    mq.push(root);

    while (!mq.empty())
    {
      TreeNode *tmp = mq.front();
      mq.pop();

      if (!tmp) continue;

      tmp->left = nextNode(counter, data);
      mq.push(tmp->left);

      tmp->right = nextNode(counter, data);
      mq.push(tmp->right);
    }

    return root;
  }
};

void printTree(TreeNode *root)
{
  queue<TreeNode *> mq;
  mq.push(root);

  while (!mq.empty())
  {
    TreeNode *tmp = mq.front();
    mq.pop();

    cout << tmp->val << " ";
    if (tmp->left) mq.push(tmp->left);
    if (tmp->right) mq.push(tmp->right);
  }
  cout << endl;
}

int main(int argc, char *argv[])
{
  // ex3
  ///*
  TreeNode *root = new TreeNode{1};
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  //*/

  Codec ser, deser;

  string strout = ser.serialize(root);
  cout << " output str: \n " << strout << endl;

  TreeNode *out = deser.deserialize(strout);

  printTree(out);

  strout = ser.serialize(out);
  cout << " output str: \n " << strout << endl;

  cout << " done \n";
  return 0;
}
