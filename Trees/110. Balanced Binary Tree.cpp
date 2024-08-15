using namespace std;
#include <algorithm>
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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        int aux = maxDepth(root->left) - maxDepth(root->right);
        return (aux == 1 || aux == 0 || aux == -1) && isBalanced(root->left) && isBalanced(root->right);
    }
};