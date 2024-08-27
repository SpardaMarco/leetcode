using namespace std;

#include <vector>

class Solution
{
public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            vector<int> edge = edges[i];
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                res++;
                visit(i, adj, visited);
            }
        }

        return res;
    }

private:
    void visit(int i, vector<vector<int>> &adj, vector<bool> &visited)
    {
        if (visited[i])
            return;

        visited[i] = true;
        for (int a : adj[i])
        {
            visit(a, adj, visited);
        }
    }
};
