using namespace std;

#include <vector>

class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, __INT_MAX__);
        prices[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> tmpPrices = prices;
            for (const auto& flight : flights) {
                if (prices[flight[0]] == __INT_MAX__)
                    continue;
                else if (prices[flight[0]] + flight[2] < tmpPrices[flight[1]]) {
                    tmpPrices[flight[1]] = prices[flight[0]] + flight[2];
                }
            }
            prices = tmpPrices;
        }

        return prices[dst] == __INT_MAX__ ? -1 : prices[dst];
    }
};