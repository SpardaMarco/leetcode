using namespace std;

#include <string>
#include <vector>

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> grid(text1.size() + 1, vector<int>(text2.size() + 1));

        for (int i = text1.size() - 1; i >= 0; --i) {
            for (int j = text2.size() - 1; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    grid[i][j] = 1 + grid[i + 1][j + 1];
                } else {
                    grid[i][j] = max(grid[i + 1][j], grid[i][j + 1]);
                }
            }
        }

        return grid[0][0];
    }
};