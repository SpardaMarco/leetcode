using namespace std;

#include <vector>
#include <unordered_map>

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> map;
        return dfs(node, map);
    }

private:
    Node *dfs(Node *node, unordered_map<Node *, Node *> &map)
    {
        if (node == nullptr)
            return nullptr;

        if (!map.count(node))
        {
            map[node] = new Node(node->val);
        }
        else
        {
            return map[node];
        }
        Node *n = map[node];
        for (Node *c : node->neighbors)
        {
            n->neighbors.push_back(dfs(c, map));
        }
        return n;
    }
};