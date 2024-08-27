using namespace std;

#include <vector>

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> map(numCourses);
        for (vector<int> &p : prerequisites)
        {
            map[p[0]].push_back(p[1]);
        }

        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(i, visited, map))
                return false;
        }

        return true;
    }

private:
    bool dfs(int curr, vector<bool> &visited, vector<vector<int>> &map)
    {
        if (visited[curr])
            return false;
        if (map[curr].empty())
            return true;
        visited[curr] = true;

        for (int r : map[curr])
        {
            if (!dfs(r, visited, map))
                return false;
        }
        visited[curr] = false;
        map[curr].clear();
        return true;
    }
};