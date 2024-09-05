using namespace std;

#include <vector>

class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, __INT_MAX__));

        grid[m - 1][n - 1] = 1;
        return recursive(m, n, grid);
    }

   private:
    int recursive(int m, int n, vector<vector<int>>& grid) {
        if (m >= grid.size() || n >= grid[0].size()) {
            return 0;
        }
        if (grid[m][n] != __INT_MAX__) {
            return grid[m][n];
        }
        int res = 0;
        res += recursive(m + 1, n, grid);
        res += recursive(m, n + 1, grid);
        grid[m][n] = res;
        return res;
    }
};