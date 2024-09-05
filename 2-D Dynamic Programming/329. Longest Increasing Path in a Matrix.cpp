using namespace std;

#include <vector>

class Solution {
   public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> grid(rows, vector<int>(cols, 0));
        int res = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                res = max(res, dfs(i, j, matrix, grid));
            }
        }

        return res;
    }

   private:
    int dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& grid) {
        if (grid[row][col] != 0) return grid[row][col];

        int res = 1;
        for (const vector<int>& dir : dirs) {
            int nr = row + dir[0];
            int nc = col + dir[1];

            if (nr < 0 || nr >= matrix.size() || nc < 0 || nc >= matrix[0].size() || matrix[nr][nc] <= matrix[row][col]) continue;
            res = max(res, 1 + dfs(nr, nc, matrix, grid));
        }
        grid[row][col] = res;
        return res;
    }
};