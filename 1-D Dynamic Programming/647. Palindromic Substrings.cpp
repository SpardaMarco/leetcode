using namespace std;

#include <string>

class Solution
{
public:
    int countSubstrings(string s)
    {
        int res = 0;
        if (s.size() == 1)
            return res + 1;
        for (int i = 0; i < s.size(); i++)
        {
            // odd
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                res++;
                left--;
                right++;
            }

            // even
            left = i;
            right = i + 1;

            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                res++;
                left--;
                right++;
            }
        }
        return res;
    }
};