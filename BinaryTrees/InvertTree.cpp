class TreeNode
{
private:
    int val;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};

    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
    }

    TreeNode *invertTree1(TreeNode *root)
    {
        if (root)
        {
            TreeNode *temp = invertTree1(root->left);
            root->left = invertTree1(root->right);
            root->right = temp;
        }

        return root;
    }
};
