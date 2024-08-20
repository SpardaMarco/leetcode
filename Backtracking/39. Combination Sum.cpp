using namespace std;

#include <vector>

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> curr;
        vector<vector<int>> res;
        recursive(candidates, target, 0, curr, res);
        return res;
    }

private:
    void recursive(vector<int> &nums, int target, int i, vector<int> &curr, vector<vector<int>> &res)
    {
        if (i >= nums.size() || target < 0)
            return;

        if (target == 0)
        {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);

        recursive(nums, target - nums[i], i, curr, res);
        curr.pop_back();
        recursive(nums, target, i + 1, curr, res);
    }
};