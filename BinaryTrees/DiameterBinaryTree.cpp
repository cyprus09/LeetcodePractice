#include <algorithm>
#include "binaryTree.h"

using namespace std;

int dfs(TreeNode *root, int &result)
{
    if (!root)
        return 0;

    int left = dfs(root->left, result);
    int right = dfs(root->right, result);
    result = max(result, left + right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int result = 0;
    dfs(root, result);
    return result;
}