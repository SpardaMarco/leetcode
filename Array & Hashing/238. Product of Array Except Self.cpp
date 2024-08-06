using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        size_t size = nums.size();
        vector<int> res(size, 1);
        int acc = 1;
        for (int i = 0; i < size; i++)
        {
            res[i] *= acc;
            acc *= nums[i];
        }

        acc = 1;
        for (int i = size - 1; i >= 0; i--)
        {
            res[i] *= acc;
            acc *= nums[i];
        }

        return res;
    }
};