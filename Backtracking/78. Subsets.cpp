using namespace std;

#include <vector>
#include <math.h>

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<bool> aux(nums.size(), false);
        vector<vector<int>> res = {};
        int size = (int)pow(2, nums.size());
        for (int i = 0; i < size; i++)
        {
            vector<int> subset;
            bool change = true;
            for (int j = 0; j < nums.size(); j++)
            {
                if (aux[j])
                    subset.push_back(nums[j]);
                if (change)
                {
                    aux[j] = !aux[j];
                    change = !aux[j];
                }
            }
            res.push_back(subset);
        }
        return res;
    }
};