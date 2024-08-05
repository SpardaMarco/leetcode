using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        size_t size = nums.size();
        vector<int> prefix(size);
        vector<int> suffix(size);
        vector<int> res;
        prefix[0] = 1;
        suffix[size - 1] = 1;
        for (int i = 1; i < size; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for (int i = size - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < size; i++)
        {
            res.push_back(prefix[i] * suffix[i]);
        }
        return res;
    }
};