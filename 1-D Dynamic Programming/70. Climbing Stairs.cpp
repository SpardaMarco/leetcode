using namespace std;

#include <vector>
#include <unordered_map>

class Solution
{
public:
    int climbStairs(int n)
    {
        unordered_map<int, int> options;
        options[0] = 0;
        options[1] = 1;
        options[2] = 2;
        climbStairs(n, options);
        return options[n];
    }

private:
    void climbStairs(int n, unordered_map<int, int> &options)
    {
        if (options.find(n) != options.end())
            return;
        climbStairs(n - 2, options);
        climbStairs(n - 1, options);
        options[n] = options[n - 2] + options[n - 1];
    }
};