using namespace std;
#include <vector>
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
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty())
            return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);

        int mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        vector<int> left_pre(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> right_pre(preorder.begin() + mid + 1, preorder.end());
        vector<int> left_in(inorder.begin(), inorder.begin() + mid);
        vector<int> right_in(inorder.begin() + mid + 1, inorder.end());

        root->left = buildTree(left_pre, left_in);
        root->right = buildTree(right_pre, right_in);

        return root;
    }
};