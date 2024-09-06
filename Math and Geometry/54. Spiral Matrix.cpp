using namespace std;

#include <vector>

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int l = 0;
        int r = cols;
        int t = 0;
        int b = rows;

        vector<int> res;

        while (l < r && t < b) {
            for (int i = l; i < r; ++i) {
                res.push_back(matrix[t][i]);
            }
            for (int i = t + 1; i < b; ++i) {
                res.push_back(matrix[i][r - 1]);
            }
            if (t != b - 1) {
                for (int i = r - 2; i >= l; --i) {
                    res.push_back(matrix[b - 1][i]);
                }
            }
            if (l != r - 1) {
                for (int i = b - 2; i > t; --i) {
                    res.push_back(matrix[i][l]);
                }
            }
            ++l;
            --r;
            ++t;
            --b;
        }
        return res;
    }
};