using namespace std;
#include <string>
#include <iostream>
#include <sstream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec
{
private:
    void dfs(TreeNode *root, string &res)
    {
        if (!root)
        {
            res.append("null\n");
        }
        else
        {
            res.append(to_string(root->val) + '\n');
            dfs(root->left, res);
            dfs(root->right, res);
        }
    }

    TreeNode *dfs_2(stringstream &ss)
    {
        string val;
        getline(ss, val);
        if (val == "null")
            return nullptr;
        int value = stoi(val);
        TreeNode *root = new TreeNode(value);
        root->left = dfs_2(ss);
        root->right = dfs_2(ss);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res = "";
        dfs(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream ss(data);
        return dfs_2(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));