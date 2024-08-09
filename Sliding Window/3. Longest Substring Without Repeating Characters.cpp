using namespace std;

#include <string>

#include <unordered_map>

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> used;
        int l = 0, r = 0;
        int max_len = 0;
        while (r < s.size())
        {
            max_len = max(max_len, r - l);

            if (used.find(s[r]) != used.end())
            {
                used.erase(s[l]);
                l++;
            }
            else
            {
                used.insert({s[r], 1});
                r++;
            }
        }
        max_len = max(max_len, r - l);

        return max_len;
    }
};