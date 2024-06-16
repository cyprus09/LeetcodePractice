#include "binaryTree.h"

bool inorder(TreeNode *root, TreeNode *&prev)
{
    if (!root)
        return true;
    if (!inorder(root->left, prev))
        return false;
    if (prev && prev->val >= root->val)
        return false;

    prev = root;

    if (!inorder(root->right, prev))
        return false;

    return true;
}
bool isValidBST(TreeNode *root)
{
    TreeNode *prev = nullptr;
    return inorder(root, prev);
}