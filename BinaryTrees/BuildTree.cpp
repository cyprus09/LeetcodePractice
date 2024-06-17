#include "binaryTree.h"
#include <vector>

using namespace std;

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int index = 0;
    return tree(preorder, inorder, index, 0, inorder.size() - 1);
}

TreeNode *tree(vector<int> &preorder, vector<int> &inorder, int &index,
               int i, int j)
{
    if (i > j)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[index]);

    int split = 0;
    for (int i = 0; i < inorder.size(); i++)
    {
        if (preorder[index] == inorder[i])
        {
            split = i;
            break;
        }
    }

    index++;

    root->left = tree(preorder, inorder, index, i, split - 1);
    root->right = tree(preorder, inorder, index, split + 1, j);

    return root;
}