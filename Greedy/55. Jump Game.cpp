using namespace std;

#include <vector>

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        int need = 1;
        for (int j = nums.size() - 2; j > 0; j--)
        {
            if (nums[j] >= need)
            {
                need = 0;
            }
            ++need;
        }

        return need <= nums[0];
    }
};