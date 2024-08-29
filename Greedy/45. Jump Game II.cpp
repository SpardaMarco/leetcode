using namespace std;

#include <vector>

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int res = 0;
        int left = 0, right = 0;

        while (right < nums.size() - 1)
        {
            int max_jump = 0;

            for (left; left <= right; ++left)
            {
                max_jump = max(max_jump, 1 + nums[left]);
            }

            right = max_jump;
            ++res;
        }
        return res;
    }
};