using namespace std;

#include <vector>
#include <deque>

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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        deque<TreeNode *> q;

        if (root)
            q.push_back(root);

        while (!q.empty())
        {
            for (int i = 0, len = q.size(); i < len; i++)
            {
                TreeNode *n = q.front();
                q.pop_front();
                if (n->left)
                    q.push_back(n->left);
                if (n->right)
                    q.push_back(n->right);
                if (i == len - 1)
                    res.push_back(n->val);
            }
        }
        return res;
    }
};
