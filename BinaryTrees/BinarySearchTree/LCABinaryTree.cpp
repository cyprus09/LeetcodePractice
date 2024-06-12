struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // 1st approach, non-recursive method
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root)
        {
            if (p->val < root->val && q->val < root->val)
            {
                root = root->left;
            }
            else if (p->val > root->val && q->val > root->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return nullptr;
    }

    // 2nd approach recursive tree
    TreeNode *lowestCommonAncestorRecursive(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestorRecursive(root->left, p, q);
        }
        else if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestorRecursive(root->right, p, q);
        }
        else
        {
            return root;
        }
    }
};