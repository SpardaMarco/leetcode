using namespace std;

#include <vector>

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> memo(amount + 1, amount + 1);
        memo[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int &c : coins)
            {
                if (c <= i)
                {
                    memo[i] = min(memo[i], memo[i - c] + 1);
                }
            }
        }
        return memo[amount] > amount ? -1 : memo[amount];
    }
};