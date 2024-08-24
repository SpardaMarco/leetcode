using namespace std;

#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (const int &n : nums)
            sum += n;
        if (sum % 2)
            return false;

        unordered_set<int> memo;
        memo.insert(0);
        int target = sum / 2;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            unordered_set<int> new_memo;
            for (const int &j : memo)
            {
                if (j + nums[i] == target)
                    return true;
                new_memo.insert(j + nums[i]);
                new_memo.insert(j);
            }
            memo = new_memo;
        }
        return false;
    }
};