using namespace std;

#include <vector>
#include <string>

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> memo(s.size() + 1, false);
        memo[s.size()] = true;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (const string &w : wordDict)
            {
                if ((i + w.size()) <= s.size() && s.substr(i, w.size()) == w)
                {
                    memo[i] = memo[i + w.size()];
                }

                if (memo[i])
                    break;
            }
        }

        return memo[0];
    }
};