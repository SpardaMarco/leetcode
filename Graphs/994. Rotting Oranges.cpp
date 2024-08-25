using namespace std;

#include <vector>
#include <queue>

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        pair<int, int> array[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            if (grid[row][col] == 2)
                grid[row][col] = 3;
            for (int i = 0; i < 4; i++)
            {
                int r = row + array[i].first;
                int c = col + array[i].second;

                if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == 0 || grid[r][c] == 2)
                    continue;

                if (grid[r][c] == 1 || grid[r][c] > grid[row][col] + 1)
                {
                    grid[r][c] = grid[row][col] + 1;
                    q.push({r, c});
                }
            }
        }
        int res = 0;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
                else if (grid[i][j] > res)
                    res = grid[i][j];
            }
        }
        return res > 3 ? res - 3 : 0;
    }
};