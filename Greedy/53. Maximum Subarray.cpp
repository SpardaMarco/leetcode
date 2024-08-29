using namespace std;

#include <vector>
#include <limits.h>

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int left = 0;
        int right = 1;

        int sum = nums[0];
        int max_sum = sum;
        while (right < nums.size())
        {
            if (sum < 0)
            {
                sum = 0;
                left = right;
            }
            sum += nums[right];
            max_sum = max(max_sum, sum);
            ++right;
        }
        return max_sum;
    }
};