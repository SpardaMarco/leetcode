using namespace std;

#include <vector>

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int max = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j])
                {
                    int area = dfs(grid, i, j);
                    max = max < area ? area : max;
                }
            }
        }
        return max;
    }

private:
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || !grid[i][j])
            return 0;

        grid[i][j] = 0;
        return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
    }
};