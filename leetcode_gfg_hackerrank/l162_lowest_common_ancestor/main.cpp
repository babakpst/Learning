
class Solution
{
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    bool con = true;
    while (con)
    {
      if (p->val > root->val && q->val > root->val)
        root = root->right;
      else if (p->val < root->val && q->val < root->val)
        root = root->left;
      else
        con = false;
    }
    return root;
  }
};

class Solution
{
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    TreeNode* node = root;
    while (node)
    {
      if (p->val > root->val && q->val > root->val)
        root = root->right;
      else if (p->val < root->val && q->val < root->val)
        root = root->left;
      else
        return node;
    }
    return nullptr;
  }
};
