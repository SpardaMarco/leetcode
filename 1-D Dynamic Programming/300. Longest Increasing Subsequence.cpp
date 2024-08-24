using namespace std;

#include <vector>
#include <algorithm>

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> memo(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] < nums[j])
                {
                    memo[i] = max(memo[i], 1 + memo[j]);
                }
            }
        }
        int res = 1;
        for (const int &n : memo)
        {
            res = max(res, n);
        }
        return res;
    }
};