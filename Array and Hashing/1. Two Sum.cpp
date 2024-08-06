using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        size_t size = nums.size();
        for (int i = 0; i < size; i++)
        {
            int num = nums[i];
            int sub = target - nums[i];
            unordered_map<int, int>::iterator target_num = map.find(sub);
            if (target_num != map.end())
            {
                return vector<int>({(*target_num).second, i});
            }
            else
            {
                map.insert({num, i});
            }
        }
        return vector<int>();
    }
};
