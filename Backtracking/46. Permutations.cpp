using namespace std;

#include <vector>

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (nums.size() == 1)
            return {nums};
        vector<vector<int>> res;
        vector<int> rem = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> prev = permute(rem);
        for (int i = 0; i < prev.size(); i++)
        {
            vector<int> perm = prev[i];
            for (int j = 0; j < perm.size(); j++)
            {
                perm.insert(perm.begin() + j, nums[0]);
                res.push_back(perm);
                perm.erase(perm.begin() + j);
            }
            perm.push_back(nums[0]);
            res.push_back(perm);
        }
        return res;
    }
};