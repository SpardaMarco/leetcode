using namespace std;

#include <vector>

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> map(numCourses);
        for (vector<int> &p : prerequisites)
            map[p[0]].push_back(p[1]);

        vector<int> res;
        vector<bool> visited(numCourses, false);
        vector<bool> cycle(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(i, visited, map, res, cycle))
                return {};
        }

        return res;
    }

private:
    bool dfs(int curr, vector<bool> &visited, vector<vector<int>> &map, vector<int> &res, vector<bool> &cycle)
    {
        if (cycle[curr])
            return false;
        if (map[curr].empty())
        {
            if (!visited[curr])
            {
                visited[curr] = true;
                res.push_back(curr);
            }
            return true;
        }

        cycle[curr] = true;

        for (int i : map[curr])
        {
            if (!dfs(i, visited, map, res, cycle))
                return false;
        }

        cycle[curr] = false;
        map[curr].clear();
        visited[curr] = true;
        res.push_back(curr);

        return true;
    }
};