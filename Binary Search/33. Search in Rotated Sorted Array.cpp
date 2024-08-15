using namespace std;

#include <vector>

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int midpoint = left + ((right - left) / 2);

            if (nums[midpoint] == target)
                return midpoint;
            if (nums[left] <= nums[midpoint])
            {
                if (nums[left] <= target && target <= nums[midpoint])
                {
                    right = midpoint - 1;
                }
                else
                {
                    left = midpoint + 1;
                }
            }
            else
            {
                if (nums[midpoint] <= target && target <= nums[right])
                {
                    left = midpoint + 1;
                }
                else
                {
                    right = midpoint - 1;
                }
            }
        }
        return -1;
    }
};