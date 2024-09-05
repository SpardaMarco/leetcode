using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<long, int> cache;
        return dfs(0, 0, nums, target, cache);
    }

   private:
    int dfs(int i, int total, vector<int>& nums, int target, unordered_map<long, int>& cache) {
        if (i == nums.size()) {
            return total == target ? 1 : 0;
        }

        long key = static_cast<long>(i) << 32 | (total & 0xffffffffL);

        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        int value = dfs(i + 1, total + nums[i], nums, target, cache) + dfs(i + 1, total - nums[i], nums, target, cache);
        cache[key] = value;
        return value;
    }
};