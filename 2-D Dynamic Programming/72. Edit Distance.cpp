using namespace std;

#include <string>
#include <vector>

class Solution {
   public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> grid(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for (int i = 0; i <= word1.size(); ++i) {
            grid[i][word2.size()] = word1.size() - i;
        }

        for (int i = 0; i <= word2.size(); ++i) {
            grid[word1.size()][i] = word2.size() - i;
        }

        for (int i = word1.size() - 1; i >= 0; --i) {
            for (int j = word2.size() - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    grid[i][j] = grid[i + 1][j + 1];
                } else {
                    int minimum = min(__INT_MAX__, grid[i + 1][j]);
                    minimum = min(minimum, grid[i][j + 1]);
                    minimum = min(minimum, grid[i + 1][j + 1]);
                    grid[i][j] = 1 + minimum;
                }
            }
        }
        return grid[0][0];
    }
};