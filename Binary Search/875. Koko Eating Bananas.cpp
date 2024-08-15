using namespace std;

#include <vector>
#include <limits.h>

class Solution
{
private:
    int hours_taken(vector<int> &piles, int k)
    {
        int res = 0;
        for (int i : piles)
        {
            res += i / k + (i % k > 0) * 1;
        }
        return res;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < piles.size(); i++)
        {
            if (min > piles[i])
                min = piles[i];
            if (max < piles[i])
                max = piles[i];
        }
        min = min / h;
        if (min == 0)
            min = 1;

        if (h == piles.size())
            return max;

        while (min < max)
        {
            int midpoint = min + ((max - min) / 2);
            if (hours_taken(piles, midpoint) <= h)
            {
                max = midpoint;
            }
            else
            {
                min = midpoint + 1;
            }
        }
        return min;
    }
};