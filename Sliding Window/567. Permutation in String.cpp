using namespace std;

#include <string>

#include <unordered_map>

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> aux;

        for (char c : s1)
            aux[c]++;

        int l = 0, r = 0;

        while (r < s2.size())
        {
            char c = s2[r];
            if (aux.find(c) == aux.end())
            {
                while (l != r)
                {
                    aux[s2[l]]++;
                    l++;
                }
                l++;
                r++;
            }
            else
            {
                aux[c]--;
                while (aux[c] < 0)
                {
                    aux[s2[l]]++;
                    l++;
                }
                if (aux[c] == 0)
                {
                    bool res = true;
                    for (auto p : aux)
                    {
                        if (p.second != 0)
                        {
                            res = false;
                            break;
                        }
                    }
                    if (res)
                        return true;
                }
                r++;
            }
        }

        return false;
    }
};