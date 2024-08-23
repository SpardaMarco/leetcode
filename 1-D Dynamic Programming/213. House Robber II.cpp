using namespace std;

#include <vector>

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        vector<int> nums1(nums.begin() + 1, nums.end());
        vector<int> nums2(nums.begin(), nums.end() - 1);
        return max(aux(nums1), aux(nums2));
    }

private:
    int aux(vector<int> &nums)
    {
        int two_before = 0;
        int before = 0;

        for (int n : nums)
        {
            int temp = max(n + two_before, before);
            two_before = before;
            before = temp;
        }

        return before;
    }
};