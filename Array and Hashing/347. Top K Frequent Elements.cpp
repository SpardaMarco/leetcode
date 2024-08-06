using namespace std;
#include <vector>
#include <map>
#include <unordered_map>

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        multimap<int, int> new_map;
        unordered_map<int, int> map;
        vector<int> res;

        for (int i : nums)
        {
            map[i]++;
        }

        for (auto i : map)
        {
            new_map.insert({i.second, i.first});
        }
        auto it = new_map.rbegin();

        while (k-- != 0)
        {
            res.push_back((*it).second);
            ++it;
        }

        return res;
    }
};