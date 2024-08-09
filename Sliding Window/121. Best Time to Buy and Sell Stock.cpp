using namespace std;

#include <vector>

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_res = 0;
        int l = 0, r = 0;
        while (r < prices.size())
        {
            max_res = max(max_res, prices[r] - prices[l]);
            if (prices[r] < prices[l])
            {
                l = r;
            }
            r++;
        }
        return max_res;
    }
};