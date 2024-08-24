using namespace std;

#include <string>

class Solution
{
public:
    int numDecodings(string s)
    {
        int memo[s.size() + 1];
        for (int i = 0; i < s.size() + 1; i++)
            memo[i] = 0;
        memo[s.size()] = 1;

        return recursive(s, 0, memo);
    }

private:
    int recursive(string &s, int i, int memo[])
    {
        if (memo[i] != 0)
            return memo[i];

        if (s[i] == '0')
            return 0;

        int res = recursive(s, i + 1, memo);

        if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'))
            res += recursive(s, i + 2, memo);
        memo[i] = res;

        return res;
    }
};