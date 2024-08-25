using namespace std;

#include <vector>
#include <queue>

class Solution
{
public:
    void islandsAndTreasure(vector<vector<int>> &grid)
    {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int, int>> q;
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLS; col++)
            {
                if (!grid[row][col])
                    q.push({row, col});
            }
        }

        pair<int, int> array[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int n_row = row + array[i].first;
                int n_col = col + array[i].second;

                if (n_row < 0 || n_row >= ROWS || n_col < 0 || n_col >= COLS || grid[n_row][n_col] <= grid[row][col] + 1)
                    continue;
                grid[n_row][n_col] = grid[row][col] + 1;
                q.push({n_row, n_col});
            }
        }
    }
};
