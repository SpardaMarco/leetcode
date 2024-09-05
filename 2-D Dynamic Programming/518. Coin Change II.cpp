using namespace std;

#include <vector>

class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        vector<int> row(amount + 1, 0);
        row[0] = 1;
        for (int i = coins.size() - 1; i >= 0; --i) {
            vector<int> nextRow(amount + 1, 0);
            nextRow[0] = 1;

            for (int a = 1; a <= amount; ++a) {
                nextRow[a] = row[a];
                if (a - coins[i] >= 0) {
                    nextRow[a] += nextRow[a - coins[i]];
                }
            }
            row = nextRow;
        }

        return row[amount];
    }
};
