using namespace std;

#include <vector>

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeroes;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    zeroes.push_back({i, j});
                }
            }
        }

        for (const pair<int, int>& p : zeroes) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][p.second] = 0;
            }
            for (int i = 0; i < matrix[0].size(); ++i) {
                matrix[p.first][i] = 0;
            }
        }
    }
};