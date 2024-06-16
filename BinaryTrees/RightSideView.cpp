#include "binaryTree.h"
#include <vector>
#include <queue>

using namespace std;

vector<int> rightSideView(TreeNode *root)
{
    vector<int> result;
    if (!root)
        return result;

    queue<TreeNode *> ans;
    ans.push(root);

    while (!ans.empty())
    {
        int size = ans.size();

        for (int i = size; i > 0; i--)
        {
            TreeNode *node = ans.front();
            ans.pop();

            if (i == size)
                result.push_back(node->val);

            if (node->right)
                ans.push(node->right);
            if (node->left)
                ans.push(node->left);
        }
    }
    return result;
}