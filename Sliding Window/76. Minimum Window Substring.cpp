using namespace std;

#include <string>

#include <unordered_map>

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> chars;
        for (char c : t)
        {
            chars[c]++;
        }

        int l = 0, r = 0;
        pair<int, int> res = {0, s.size() - 1};
        bool found = false;

        while (r < s.size())
        {
            char curr = s[r];
            chars[curr]--;

            if (chars[curr] == 0)
            {
                bool valid = true;
                for (auto p : chars)
                {
                    if (p.second > 0)
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                    found = true;
                if (valid && res.second - res.first > r - l)
                    res = {l, r};
                while (valid)
                {
                    chars[s[l]]++;
                    valid = chars[s[l]] <= 0;
                    l++;
                    if (valid && res.second - res.first > r - l)
                        res = {l, r};
                }
            }
            r++;
        }
        if (!found)
            return "";
        return s.substr(res.first, res.second - res.first + 1);
    }
};
