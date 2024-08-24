using namespace std;

#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int res = nums[0];
        int min_res = 1;
        int max_res = 1;

        for (int &n : nums)
        {
            int prodMax = max_res * n;
            int prodMin = min_res * n;
            max_res = max(max(prodMax, prodMin), n);
            min_res = min(min(prodMin, prodMax), n);
            res = max(res, max_res);
        }
        return res;
    }
};