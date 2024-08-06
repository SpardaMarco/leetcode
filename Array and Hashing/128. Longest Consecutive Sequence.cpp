using namespace std;

#include <vector>
#include <unordered_set>

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int res = 0;
        if (nums.empty())
            return res;

        unordered_set<int> set = unordered_set<int>(nums.begin(), nums.end());

        for (int i : set)
        {
            if (set.find(i - 1) == set.end())
            {
                int curr_seq = 1;
                while (set.find(i + 1) != set.end())
                {
                    curr_seq++;
                    i++;
                }
                res = max(curr_seq, res);
            }
        }

        return res;
    }
};