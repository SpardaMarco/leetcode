using namespace std;

#include <vector>
#include <unordered_set>

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        unordered_set<int> p_set, a_set;

        for (int r = 0; r < ROWS; r++)
        {
            dfs(r, 0, p_set, heights[r][0], ROWS, COLS, heights);
            dfs(r, COLS - 1, a_set, heights[r][COLS - 1], ROWS, COLS, heights);
        }

        for (int c = 0; c < COLS; c++)
        {
            dfs(0, c, p_set, heights[0][c], ROWS, COLS, heights);
            dfs(ROWS - 1, c, a_set, heights[ROWS - 1][c], ROWS, COLS, heights);
        }

        vector<vector<int>> res;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                int coord = i * COLS + j;
                if (p_set.count(coord) && a_set.count(coord))
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

private:
    void dfs(int r, int c, unordered_set<int> &set, int p_h, int ROWS, int COLS, vector<vector<int>> &h)
    {
        int coord = r * COLS + c;
        if (r < 0 || c < 0 || r == ROWS || c == COLS || h[r][c] < p_h || set.count(coord))
        {
            return;
        }
        set.insert(coord);
        dfs(r + 1, c, set, h[r][c], ROWS, COLS, h);
        dfs(r - 1, c, set, h[r][c], ROWS, COLS, h);
        dfs(r, c + 1, set, h[r][c], ROWS, COLS, h);
        dfs(r, c - 1, set, h[r][c], ROWS, COLS, h);
    }
};