using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        unordered_map<long, int> cache;
        return solve(nums, 1, nums.size() - 2, cache);
    }

   private:
    int solve(vector<int>& nums, int i, int j, unordered_map<long, int> cache) {
        if (i > j) {
            return 0;
        }
        long key = static_cast<long>(i) << 32 | static_cast<long>(j);
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        if (i == j) {
            return nums[i - 1] * nums[i] * nums[i + 1];
        }
        int res = 0;
        for (int k = i; k <= j; ++k) {
            int temp = nums[i - 1] * nums[k] * nums[j + 1];
            temp += solve(nums, i, k - 1, cache) + solve(nums, k + 1, j, cache);
            res = max(res, temp);
        }
        cache[key] = res;
        return res;
    }
};