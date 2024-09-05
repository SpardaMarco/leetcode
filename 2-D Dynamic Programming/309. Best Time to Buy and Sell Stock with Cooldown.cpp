using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        unordered_map<long, int> cache;

        return dfs(0, true, prices, cache);
    }

    int dfs(int i, bool buying, vector<int>& prices, unordered_map<long, int>& cache) {
        if (i >= prices.size()) {
            return 0;
        }

        long key = static_cast<long>(i) << 1 | static_cast<long>(buying);
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        if (buying) {
            int buy = dfs(i + 1, !buying, prices, cache) - prices[i];
            int cooldown = dfs(i + 1, buying, prices, cache);
            cache[key] = max(buy, cooldown);
        } else {
            int sell = dfs(i + 2, !buying, prices, cache) + prices[i];
            int cooldown = dfs(i + 1, buying, prices, cache);
            cache[key] = max(sell, cooldown);
        }
        return cache[key];
    }
};