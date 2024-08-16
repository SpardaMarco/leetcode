#include <limits.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    void dfs(TreeNode *root, int max, int &res)
    {
        if (!root)
            return;
        if (max <= root->val)
        {
            max = root->val;
            res++;
        }
        dfs(root->left, max, res);
        dfs(root->right, max, res);
    }

public:
    int goodNodes(TreeNode *root)
    {
        int res = 0;
        dfs(root, INT_MIN, res);
        return res;
    }
};