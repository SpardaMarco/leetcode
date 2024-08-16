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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        deque<TreeNode *> queue;

        if (root)
            queue.push_back(root);

        while (!queue.empty())
        {
            vector<int> values;

            for (int i = 0, len = queue.size(); i < len; i++)
            {
                TreeNode *v = queue.front();
                queue.pop_front();
                values.push_back(v->val);

                if (v->left)
                    queue.push_back(v->left);
                if (v->right)
                    queue.push_back(v->right);
            }
            res.push_back(values);
        }
        return res;
    }
};