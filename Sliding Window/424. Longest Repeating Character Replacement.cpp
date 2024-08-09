using namespace std;

#include <string>

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int aux[26] = {0};
        int l = 0, r = 0;
        int max_len = 0;
        int max_uses = 0;

        while (r < s.size())
        {
            aux[s[r] - 'A']++;
            max_uses = max(max_uses, aux[s[r] - 'A']);
            if (r - l + 1 - max_uses > k)
            {
                aux[s[r] - 'A']--;
                l++;
            }
            max_len = max(max_len, r - l + 1);
            r++;
        }
        return max_len;
    }
};
