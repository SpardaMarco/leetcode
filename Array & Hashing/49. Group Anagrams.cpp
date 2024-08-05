using namespace std;
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;
        for (string s : strs)
        {
            string s_copy = s;
            sort(s.begin(), s.end());
            map[s].push_back(s_copy);
        }

        for (auto i : map)
        {
            result.push_back(i.second);
        }
        return result;
    }
};