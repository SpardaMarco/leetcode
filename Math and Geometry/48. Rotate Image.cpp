using namespace std;

#include <vector>

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix.size() - 1;

        while (l < r) {
            for (int i = 0; i < r - l; ++i) {
                int t = l;
                int b = r;

                int topLeft = matrix[t][l + i];

                matrix[t][l + i] = matrix[b - i][l];
                matrix[b - i][l] = matrix[b][r - i];
                matrix[b][r - i] = matrix[t + i][r];
                matrix[t + i][r] = topLeft;
            }
            ++l;
            --r;
        }
    }
};