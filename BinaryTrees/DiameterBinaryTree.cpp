#include <algorithm>

using namespace std;

class TreeNode
{
private:
    int val;
    TreeNode *left;
    TreeNode *right;
    int dfs(TreeNode *root, int &result)
    {
        if (!root)
            return 0;

        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        result = max(result, left + right);

        return 1 + max(left, right);
    }

public:
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
    int diameterOfBinaryTree(TreeNode *root)
    {
        int result = 0;
        dfs(root, result);
        return result;
    }
};