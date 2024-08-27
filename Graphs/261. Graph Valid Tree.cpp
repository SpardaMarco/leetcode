using namespace std;

#include <vector>

class Solution
{
public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            vector<int> edge = edges[i];
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        if (hasCycle(adj, visited, -1, 0))
            return false;

        for (int i = 0; i < n; i++)
            if (!visited[i])
                return false;
        return true;
    }

private:
    bool hasCycle(vector<vector<int>> &adj, vector<bool> &visited, int parent, int curr)
    {
        if (visited[curr])
            return true;
        visited[curr] = true;

        for (int a : adj[curr])
        {
            if (parent == a && hasCycle(adj, visited, curr, a))
                return true;
        }
        return false;
    }
};