#include <algorithm>

using namespace std;

class TreeNode
{
private:
    int val;
    TreeNode *left;
    TreeNode *right;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftHeight = dfs(root->left);
        if (leftHeight == -1)
            return -1;

        int rightHeight = dfs(root->right);
        if (rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
    }

public:
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
    bool isBalanced(TreeNode *root)
    {
        return dfs(root) != -1;
    }
};