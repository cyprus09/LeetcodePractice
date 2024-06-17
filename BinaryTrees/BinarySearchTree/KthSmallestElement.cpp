#include "binaryTree.h"

void inorder(TreeNode *root, int &result, int &k)
{
    if (!root)
        return;
    inorder(root->left, result, k);
    k--;
    if (k == 0)
    {
        result = root->val;
        return;
    }
    inorder(root->right, result, k);
}

int kthSmallest(TreeNode *root, int k)
{
    int result = 0;
    inorder(root, result, k);
    return result;
}