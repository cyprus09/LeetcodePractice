#include <algorithm>

using namespace std;

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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};