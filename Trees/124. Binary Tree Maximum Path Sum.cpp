using namespace std;
#include <algorithm>
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
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        return max(root->val + max(dfs(root->left), 0), root->val + max(dfs(root->right), 0));
    }

    void aux(TreeNode *root, int &res)
    {
        if (root)
        {
            res = max(max(dfs(root->left), 0) + root->val + max(dfs(root->right), 0), res);
            aux(root->left, res);
            aux(root->right, res);
        }
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        aux(root, res);
        return res;
    }
};