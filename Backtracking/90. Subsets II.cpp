using namespace std;

#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        recursive(0, {}, nums, res);
        return res;
    }

private:
    void recursive(int start, vector<int> subset, vector<int> &nums, vector<vector<int>> &res)
    {
        res.push_back(subset);
        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            subset.push_back(nums[i]);
            recursive(i + 1, subset, nums, res);
            subset.pop_back();
        }
    }
};